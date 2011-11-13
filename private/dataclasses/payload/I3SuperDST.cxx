/**
 * @file 
 * @brief 
 *
 * (c) 2010 the IceCube Collaboration
 *
 * $Id:$
 * @version $Revision$
 * @date $Date$
 * @author Jakob van Santen <vansanten@wisc.edu>
 *
 */

#include <cassert>

#include <boost/serialization/binary_object.hpp>
#include <boost/static_assert.hpp>
#include <boost/utility.hpp>
#include <boost/foreach.hpp>

#include "icetray/OMKey.h"
#include "icetray/I3Units.h"

#include "dataclasses/payload/I3SuperDST.h"
#include "dataclasses/physics/I3Waveform.h"

/* Maximum bit widths used in discretization */
#define I3SUPERDSTCHARGESTAMP_TIME_BITS_V0   8
#define I3SUPERDSTCHARGESTAMP_CHARGE_BITS_V0 6
#define I3SUPERDSTCHARGESTAMP_BYTESIZE_V0    2

#define I3SUPERDST_DOMID_BITS_V0     13
#define I3SUPERDST_SLOP_BITS_V0       3
#define I3SUPERDST_HEADER_BYTESIZE_V0 2

/* Earliest representable time (relative to the readout window) */
const double I3SuperDST::tmin_ = -512.0;

I3SuperDSTChargeStamp::I3SuperDSTChargeStamp(double time, double charge,
    bool hlc) : timecode_(0), chargecode_(0), charge_overflow_(0),
    kind_(hlc ? HLC : SLC)
{
	assert( time >= 0.0 );
	assert( charge >= 0.0 );
	
	/* Don't truncate integer codes, since we need to relativize the times later. */
	timecode_ = I3SuperDST::EncodeTime(time, 31, i3superdst_version_);
	chargecode_ = I3SuperDST::EncodeCharge(charge, 31, i3superdst_version_);
}

uint32_t
I3SuperDSTChargeStamp::TruncateTimeCode(unsigned maxbits)
{
	assert(maxbits < 32);
	uint32_t overflow = 0;
	const uint32_t maxi((uint32_t(1) << maxbits)-1);
	
	if (timecode_ > maxi) {
		overflow = timecode_ - maxi;
		timecode_ = maxi;
	}
	
	return (overflow);
}

void
I3SuperDSTChargeStamp::TruncateChargeCode(unsigned maxbits)
{
	assert(maxbits < 32);
	const uint32_t maxi((uint32_t(1) << maxbits)-1);
	if (chargecode_ > maxi) {
		charge_overflow_ = chargecode_ - maxi;
		chargecode_ = maxi;
	}
}

void
I3SuperDSTChargeStamp::SetTimeReference(const I3SuperDSTChargeStamp &other)
{
	assert(timecode_ >= other.timecode_);
	
	timecode_ -= other.timecode_;
}

double
I3SuperDSTChargeStamp::GetTime() const
{
	return I3SuperDST::DecodeTime(timecode_, i3superdst_version_);
}

double
I3SuperDSTChargeStamp::GetCharge() const
{
	return I3SuperDST::DecodeCharge(chargecode_ + charge_overflow_, i3superdst_version_);
}

I3SuperDSTReadout::I3SuperDSTReadout(const OMKey &om, bool hlc,
    const std::list<I3RecoPulse>::const_iterator &start,
    const std::list<I3RecoPulse>::const_iterator &end, double t0)
{
	std::list<I3RecoPulse>::const_iterator pulse_it = start;
	
	for ( ; pulse_it != end; pulse_it++) {
		stamps_.push_back(I3SuperDSTChargeStamp(pulse_it->GetTime()-t0,
		    pulse_it->GetCharge(), hlc));
	}
	
	om_ = om;
	kind_ = hlc ? I3SuperDSTChargeStamp::HLC : I3SuperDSTChargeStamp::SLC;
	assert(start != end);
	start_time_ = start->GetTime()-t0;
}

void
I3SuperDSTReadout::SetTimeReference(const I3SuperDSTReadout &other)
{
	std::vector<I3SuperDSTChargeStamp>::reverse_iterator stamp_rit = stamps_.rbegin();
	const I3SuperDSTChargeStamp &other_stamp = other.stamps_.front();
	
	assert(start_time_ >= other.start_time_);
	assert(other.stamps_.size() > 0);
	
	/* 
	 * Set the times of any secondary stamp relative to the one prior to
	 * it, then set the time of the first stamp relative to first
	 * stamp in the other readout.
	 */
	Relativize();
	stamps_.front().SetTimeReference(other_stamp);
	/* 
	 * We've done everything we can to reduce times to a representable range.
	 * Truncate the rest at their maximum representable values and return
	 * the overflow.
	 */
	TruncateCodes();
}

void
I3SuperDSTReadout::TruncateCodes()
{
	assert(stamps_.size() > 0);
	std::vector<I3SuperDSTChargeStamp>::reverse_iterator stamp_rit = stamps_.rbegin();
	
	for ( ; stamp_rit != stamps_.rend()-1; stamp_rit++) {
		stamp_rit->TruncateChargeCode(I3SUPERDSTCHARGESTAMP_CHARGE_BITS_V0);
		stamp_rit->TruncateTimeCode(I3SUPERDSTCHARGESTAMP_TIME_BITS_V0);
	}
	stamp_rit->TruncateChargeCode(I3SUPERDSTCHARGESTAMP_CHARGE_BITS_V0);	
	/* 
	 * The first stamp gets a little more dynamic range. If we _still_
	 * can't represent the time difference to the previous stamp, store
	 * the overflow for later.
	 */
	time_overflow_ = stamp_rit->TruncateTimeCode(
	    I3SUPERDSTCHARGESTAMP_TIME_BITS_V0 + I3SUPERDST_SLOP_BITS_V0);
}

void
I3SuperDSTReadout::Relativize()
{
	std::vector<I3SuperDSTChargeStamp>::reverse_iterator stamp_rit = stamps_.rbegin();
	/* 
	 * Set the time of each secondary stamp relative to the one
	 * preceding it. (Reverse iterators are fun!)
	 */
	for ( ; stamp_rit != stamps_.rend()-1; stamp_rit++) {
		assert(stamp_rit->GetTimeCode() >= (stamp_rit+1)->GetTimeCode());
		stamp_rit->SetTimeReference(*(stamp_rit+1));
	}
}

double
I3SuperDSTReadout::GetTime() const
{
	assert(stamps_.size() != 0);
	
	return (stamps_.front().GetTime() +
	    I3SuperDST::DecodeTime(time_overflow_, i3superdst_version_));
}

struct I3SuperDSTRecoPulseUtils {
	static bool
	TimeOrdering(const I3RecoPulse &p1, const I3RecoPulse &p2)
	{ return p1.GetTime() < p2.GetTime(); }
	
	static bool
	IsBorked(const I3RecoPulse &p1)
	{
		return (!std::isfinite(p1.GetTime()) || !std::isfinite(p1.GetCharge())
		    || (p1.GetCharge() < 0.0));
	}
};

void
I3SuperDST::AddPulseMap(const I3RecoPulseSeriesMap &pulses, bool hlc, double t0)
{
	I3RecoPulseSeriesMap::const_iterator map_iter;
	std::list<I3RecoPulse> pulse_list;
	std::list<I3RecoPulse>::const_iterator pulse_head, pulse_tail;
	
	unpacked_.reset();
	
	/* Find the maximum time difference we can represent within a single readout. */
	const unsigned max_timecode = (1 << I3SUPERDSTCHARGESTAMP_TIME_BITS_V0) - 1;
	const double tmax = I3SuperDST::DecodeTime(max_timecode, i3superdst_version_);
	
	/* 
	 * Convert the pulse series map to a list of "readouts"
	 * (pulses spaced closely in time in a single DOM)
	 */ 
	for (map_iter = pulses.begin(); map_iter != pulses.end(); map_iter++) {
		/*
		 * Get a time-ordered representation of the pulse series,
		 * except those pulses with nonsensical charges or times.
		 */
		pulse_list.clear();
		std::remove_copy_if(map_iter->second.begin(),
		    map_iter->second.end(), std::back_inserter(pulse_list),
		    I3SuperDSTRecoPulseUtils::IsBorked);
		if (pulse_list.size() == 0) continue;
		pulse_list.sort(I3SuperDSTRecoPulseUtils::TimeOrdering);
		
		pulse_head = pulse_list.begin();
		pulse_tail = boost::next(pulse_head);
		
		for ( ; pulse_tail != pulse_list.end(); pulse_tail++) {
			/* 
			 * If the gap between pulses is unrepresentably large,
			 * split the preceding pulses into a separate block.
			 */
			if ((pulse_tail->GetTime() - boost::prior(pulse_tail)->GetTime()) > tmax) {
				readouts_.push_back(I3SuperDSTReadout(
				    map_iter->first, hlc, pulse_head, pulse_tail, t0));
				pulse_head = pulse_tail;
				
			}
		}
		
		/* Push the remaining pulses into a readout. */
		readouts_.push_back(I3SuperDSTReadout(
		    map_iter->first, hlc, pulse_head, pulse_tail, t0));
	}
}

std::list<I3SuperDSTReadout>
I3SuperDST::GetReadouts(bool hlc) const
{
	std::list<I3SuperDSTReadout> filtered;
	std::list<I3SuperDSTReadout>::const_iterator list_it;
	
	for (list_it = readouts_.begin(); list_it != readouts_.end(); list_it++)
		if (hlc == (list_it->kind_ == I3SuperDSTChargeStamp::HLC))
			filtered.push_back(*list_it);
			
	return filtered;
}

I3SuperDST::I3SuperDST(const I3RecoPulseSeriesMap &hlc_pulses,
    const I3RecoPulseSeriesMap &slc_pulses)
{
	I3RecoPulseSeriesMap::const_iterator hlc_iter, slc_iter;
	I3RecoPulseSeries::const_iterator pulse_head, pulse_tail;
	std::list<I3SuperDSTReadout>::const_iterator list_it, subevent_end;
	std::list<I3SuperDSTReadout>::reverse_iterator list_rit;
	
	/* 
	 * Get the earliest leading-edge time present in the input.
	 * This must be >= -512 ns to be representable.
	 */
	const double t0 = std::min(FindStartTime(hlc_pulses), FindStartTime(slc_pulses));
	assert(t0 >= tmin_);
	
	/* 
	 * Convert the HLC pulse series map to a list of "readouts"
	 * (pulses spaced closely in time in a single DOM)
	 */ 
	AddPulseMap(hlc_pulses, true, tmin_);
	
	/* Repeat the exercise with the SLC pulses */
	AddPulseMap(slc_pulses, false, tmin_);
	
	/* Sort the readouts by start time */
	readouts_.sort();
	
	/* Convert the absolute times in each readout to time deltas. */
	list_rit = readouts_.rbegin();
	subevent_end = readouts_.end();
	if (list_rit != readouts_.rend()) {
		for ( ; boost::next(list_rit) != readouts_.rend(); list_rit++) {
			list_rit->SetTimeReference(*boost::next(list_rit));
			if (list_rit->time_overflow_ > 0) {
				log_info("Readouts at %f (%s) and %f (%s) ns saturate "
				    "delta-t (%f ns)! You may have coincident events...",
				    boost::next(list_rit)->start_time_,
				    (boost::next(list_rit)->kind_ == I3SuperDSTChargeStamp::HLC ? "HLC" : "SLC"),
				    list_rit->start_time_, 
				    (list_rit->kind_ == I3SuperDSTChargeStamp::HLC ? "HLC" : "SLC"),
				    DecodeTime(list_rit->stamps_.front().GetTimeCode()));
				/*
				 * NB: reverse_iterator::base() returns a
				 * forward iterator at the _next_ element in
				 * the unreversed sequence, so we increment
				 * to get an iterator to _this_ element.
				 */
				subevent_ranges_.push_front(std::make_pair(
				    boost::next(list_rit).base(), subevent_end));
				subevent_end = boost::next(list_rit).base();
			}
		}
		list_rit->Relativize(); /* Relativize the first readout as well. */
		list_rit->TruncateCodes();
		assert(boost::next(list_rit).base() == readouts_.begin());
		subevent_ranges_.push_front(std::make_pair(
		    readouts_.begin(), subevent_end));
	}
	
	InitDebug();
}

/* Expand charge stamps into fake I3RecoPulses */
bool
I3SuperDST::Unpack(I3RecoPulseSeriesMapPtr &hlc_pulses,
    I3RecoPulseSeriesMapPtr &slc_pulses, int subevent) const
{
	std::map<OMKey, I3SuperDSTReadout>::const_iterator map_it;
	std::vector<I3SuperDSTChargeStamp>::const_iterator stamp_it;
	std::list<I3SuperDSTReadout>::const_iterator readout_it, read_start, read_end;
	double t_ref;
	bool success = true;
	
	hlc_pulses = I3RecoPulseSeriesMapPtr(new I3RecoPulseSeriesMap);
	slc_pulses = I3RecoPulseSeriesMapPtr(new I3RecoPulseSeriesMap);

	if (subevent < 0) { /* Smush all subevents together */
		read_start = readouts_.begin();
		read_end = readouts_.end();
	} else if (unsigned(subevent) >= GetSubEvents()) {
		log_error("Tried to unpack subevent %d, but we only have %u",
		    subevent, GetSubEvents());
		return false;
	} else {
		read_start = (subevent_ranges_.begin() + subevent)->first;
		read_end = (subevent_ranges_.begin() + subevent)->second;
	}
	
	assert((readouts_.size() == 0) || (read_start != read_end));

	t_ref = tmin_;
	
	/* Get accumulated time from the preceding subevents */
	for (readout_it = readouts_.begin(); readout_it != read_start; readout_it++) {
		t_ref += readout_it->GetTime();
	}
	
	for (readout_it = read_start; readout_it != read_end; readout_it++) {
		I3RecoPulseSeriesMapPtr target_map = 
		    (readout_it->kind_ == I3SuperDSTChargeStamp::HLC) ?
		    hlc_pulses : slc_pulses;
		int flags = (readout_it->kind_ == I3SuperDSTChargeStamp::HLC) ?
		    I3RecoPulse::ATWD | I3RecoPulse::FADC | I3RecoPulse::LC : I3RecoPulse::FADC;
		I3RecoPulseSeries &target = target_map->operator[](readout_it->om_);
		
		/* Use the discretization step as the pulse width. Hacky. */
		const double PULSE_WIDTH(DecodeTime(1));
		
		t_ref += readout_it->GetTime();
		double t_ref_internal = t_ref;
		
		stamp_it = readout_it->stamps_.begin();
		
		if (stamp_it != readout_it->stamps_.end()) {
			I3RecoPulse pulse;
			
			pulse.SetTime(t_ref);
			pulse.SetCharge(stamp_it->GetCharge());
			pulse.SetWidth(PULSE_WIDTH);
			pulse.SetFlags(flags);
			target.push_back(pulse);
			
			stamp_it++;
		}
	
		for ( ; stamp_it != readout_it->stamps_.end(); stamp_it++) {
			I3RecoPulse pulse;
			
			t_ref_internal += stamp_it->GetTime();
			pulse.SetTime(t_ref_internal);
			pulse.SetCharge(stamp_it->GetCharge());
			pulse.SetWidth(PULSE_WIDTH);
			pulse.SetFlags(flags);
			target.push_back(pulse);
		}
	}

	return success;
}

I3RecoPulseSeriesMapConstPtr
I3SuperDST::Unpack() const
{
	if (unpacked_)
		return unpacked_;
	
	I3RecoPulseSeriesMapPtr hlc_pulses, slc_pulses;
	
	Unpack(hlc_pulses, slc_pulses);
	
	I3RecoPulseSeriesMap::iterator hlc_map_it, slc_map_it;
	for (hlc_map_it = hlc_pulses->begin(); hlc_map_it != hlc_pulses->end(); hlc_map_it++) {
		slc_map_it = slc_pulses->find(hlc_map_it->first);
		
		if (slc_map_it == slc_pulses->end())
			continue;
		
		BOOST_FOREACH(I3RecoPulse &pulse, slc_map_it->second) {
			I3RecoPulseSeries::iterator insertion_point =
			    std::lower_bound(hlc_map_it->second.begin(),
			    hlc_map_it->second.end(), pulse,
			    I3SuperDSTRecoPulseUtils::TimeOrdering);
			hlc_map_it->second.insert(insertion_point, pulse);
		}
	}
	
	unpacked_ = hlc_pulses;
	
	return unpacked_;
}

uint32_t
I3SuperDST::EncodeOMKey(const OMKey &key, unsigned int maxbits, unsigned int version)
{
	uint32_t encoded(0);
	int string = key.GetString();
	int om = key.GetOM();

	assert(string >= 0);
	assert(om > 0);
	assert(om <= 64);
	assert(maxbits <= 31);
	
	switch (version) {
		case 0:
			/*
			 * NB: this is the same encoding scheme as the DAQ:
			 * upper 7 bits: string number, lower 6 bits: OM number
			 */
			encoded |= ((unsigned(string) << 6) & ~((1<<6)-1));
			encoded |= ((unsigned(om)-1) & ((1<<6)-1));
			assert( encoded <= uint32_t((1<<maxbits)-1) );
			break;
		default:
			break;
	}
	
	return (encoded);
}

OMKey
I3SuperDST::DecodeOMKey(uint32_t dom_id, unsigned int version)
{
	int string(0), om(0);
	
	switch (version) {
		case 0:
			string = unsigned((dom_id >> 6) & ((1<<7)-1));
			om = unsigned(dom_id & ((1<<6)-1))+1;
			break;
		default:
			break;
	}
	
	return OMKey(string, om);
}

inline uint32_t
truncate(double val, unsigned int maxbits)
{
	uint32_t code(lround(val)); /* Round to nearest integer */
	assert(maxbits <= 31);
	
	/* Truncate if greater than 2^(maxbits)-1 */
	if (code > uint32_t((1<<maxbits)-1))
		code = uint32_t((1<<maxbits)-1);
	
	return (code);
}

uint32_t
I3SuperDST::EncodeTime(double time, unsigned int maxbits,
    unsigned int version)
{
	uint32_t encoded(0);
	
	assert( time >= 0.0 );
	switch (version) {
		case 0:
			encoded = truncate(time / (4.0*I3Units::ns), maxbits);
			break;
		default:
			break;
	}
	
	return (encoded);
}

double
I3SuperDST::DecodeTime(uint32_t dt, unsigned int version)
{
	double decoded(0);
	
	switch (version) {
		case 0:
			decoded = dt*4.0*I3Units::ns;
			break;
		default:
			break;
	}
	
	return (decoded);
}

uint32_t
I3SuperDST::EncodeCharge(double charge, unsigned int maxbits, unsigned int version)
{
	uint32_t encoded(0);
	
	assert( charge >= 0 );
	switch (version) {
		case 0:
			encoded = truncate(charge/0.15, maxbits);
			break;
		default:
			break;
	}
	
	return (encoded);
}

double
I3SuperDST::DecodeCharge(uint32_t chargecode, unsigned int version)
{
	double decoded(0);
	
	switch (version) {
		case 0:
			decoded = chargecode*0.15;
			break;
		default:
			break;
	}
	
	return (decoded);
}

double
I3SuperDST::FindStartTime(const I3RecoPulseSeriesMap &pmap)
{
	double tmin = std::numeric_limits<double>::max();
	I3RecoPulseSeriesMap::const_iterator map_it = pmap.begin();
	I3RecoPulseSeries::const_iterator pulse_it;
	
	for ( ; map_it != pmap.end() ; map_it++)
		for (pulse_it = map_it->second.begin();
		    pulse_it != map_it->second.end(); pulse_it++)
			if (std::isfinite(pulse_it->GetTime()) &&
			    pulse_it->GetTime() < tmin)
				tmin = pulse_it->GetTime();
				
	return (tmin);
}


/* 
 * NB: While the internal layout of bitfields is implementation-defined,
 * (see ISO 14882 [http://www-d0.fnal.gov/~dladams/cxx_standard.pdf] p. 159)
 * GCC >= 3.4.6 obeys the following conventions under __attribute((packed)):
 *
 * - on little-endian platforms, fields are laid out in native byte order
 *   starting from the least significant bit of the parent struct
 * 
 * - on big-endian platforms, fields are laid out starting from the most
 *   significant bit of the parent struct
 *
 * To properly interpet the binary representation of a bitfield from a little-
 * endian platform on a big-endian one (and vice versa), it is necessary not
 * only to swap the order of the bytes in memory, but also to reverse the
 * order of the fields.
 */

namespace I3SuperDSTSerialization {

struct DOMHeader {
#if BYTE_ORDER == BIG_ENDIAN
	uint16_t slop      : I3SUPERDST_SLOP_BITS_V0; /* most significant 3 bits of first HLC time */
	uint16_t dom_id    : I3SUPERDST_DOMID_BITS_V0;
#else
	uint16_t dom_id    : I3SUPERDST_DOMID_BITS_V0;
	uint16_t slop      : I3SUPERDST_SLOP_BITS_V0; /* most significant 3 bits of first HLC time */
#endif
} __attribute((packed));

BOOST_STATIC_ASSERT( sizeof(DOMHeader) == I3SUPERDST_HEADER_BYTESIZE_V0 );

union ChargeStamp {
	struct {
#if BYTE_ORDER == BIG_ENDIAN
		uint16_t stop     : 1;
		uint16_t hlc_bit  : 1;
		uint16_t charge   : I3SUPERDSTCHARGESTAMP_CHARGE_BITS_V0;
		uint16_t rel_time : I3SUPERDSTCHARGESTAMP_TIME_BITS_V0;
#else
		uint16_t rel_time : I3SUPERDSTCHARGESTAMP_TIME_BITS_V0;
		uint16_t charge   : I3SUPERDSTCHARGESTAMP_CHARGE_BITS_V0;
		uint16_t hlc_bit  : 1;
		uint16_t stop     : 1;
#endif
	} stamp;
	struct {
#if BYTE_ORDER == BIG_ENDIAN
		uint16_t stop : 1; /* The stop bit is always valid. */
		uint16_t code : 15;
#else
		uint16_t code : 15;
		uint16_t stop : 1; /* The stop bit is always valid. */
#endif
	} overflow;
} __attribute((packed));

BOOST_STATIC_ASSERT( sizeof(ChargeStamp) == I3SUPERDSTCHARGESTAMP_BYTESIZE_V0 );

}

#ifndef NDEBUG
#include <sys/resource.h>
class I3SuperDSTTimer {
public:
	I3SuperDSTTimer(double *acc, unsigned *counter)
	: acc_(acc), counter_(counter)
	{
		if (acc_)
			err_ = getrusage(RUSAGE_SELF, &start_);
	}
	~I3SuperDSTTimer()
	{
		if ((acc_) && !err_ && !getrusage(RUSAGE_SELF, &end_)) {
			*acc_ += double(end_.ru_utime.tv_sec + end_.ru_stime.tv_sec
			    - start_.ru_utime.tv_sec - start_.ru_stime.tv_sec)
			    + double(end_.ru_utime.tv_usec + end_.ru_stime.tv_usec
			    - start_.ru_utime.tv_usec - start_.ru_stime.tv_usec)
			    *1e-6;
		}
		if (counter_)
			*counter_ += 1;
	}
private:
	double *acc_;
	unsigned *counter_;
	int err_;
	rusage start_, end_;
};
#endif

template <class T>
static void
swap_vector(std::vector<T> &vec)
{
#if BYTE_ORDER == BIG_ENDIAN
	BOOST_STATIC_ASSERT(sizeof(T) == 2);
	typename std::vector<T>::iterator it = vec.begin();
	for ( ; it != vec.end(); it++) {
		uint16_t *swapit = (uint16_t*)(&*it);
		*swapit = ((*swapit & 0x00FF) << 8) | ((*swapit & 0xFF00) >> 8);	
	}
#endif
};

I3MapKeyVectorInt
I3SuperDST::GetEncodedSizes() const
{
	I3MapKeyVectorInt sizes;
	std::ostringstream oarchive_stream;
	boost::archive::portable_binary_oarchive oarchive(oarchive_stream);

	/* Piggy-back on the current implementation of save() */
	this->save(oarchive, boost::serialization::version<I3SuperDST>::value,
	    &sizes);

	return sizes;
}

template <class Archive>
void
I3SuperDST::save(Archive& ar, unsigned version,
    std::map<OMKey, std::vector<int > > *sizes) const
{
#ifndef NDEBUG
	I3SuperDSTTimer timer(serialization_time_, serialization_counter_);
#endif
	std::vector<I3SuperDSTSerialization::DOMHeader> header_stream;
	std::vector<I3SuperDSTSerialization::ChargeStamp> stamp_stream;
	
	std::list<I3SuperDSTReadout>::const_iterator readout_it;
	std::vector<I3SuperDSTChargeStamp>::const_iterator stamp_it;
	
	const unsigned max_timecode = (1u << (I3SUPERDSTCHARGESTAMP_TIME_BITS_V0
	    + I3SUPERDST_SLOP_BITS_V0)) - 1;
	const unsigned max_chargecode = (1u << I3SUPERDSTCHARGESTAMP_CHARGE_BITS_V0) - 1;
	
	for (readout_it = readouts_.begin();
	    readout_it != readouts_.end(); readout_it++) {
		
		I3SuperDSTSerialization::DOMHeader header;
		
		header.dom_id = EncodeOMKey(readout_it->om_, 13, version);
		size_t readout_bytes = sizeof(header);
		
		/*
		 * Special case for the first stamp in the series:
		 * use the slop space in the header to extend the time range.
		 */
		stamp_it = readout_it->stamps_.begin();
		if (stamp_it != readout_it->stamps_.end()) {
			const unsigned timecode = stamp_it->GetTimeCode();
			const unsigned chargecode = stamp_it->GetChargeCode();
			const bool stop = (boost::next(stamp_it) == readout_it->stamps_.end());
			header.slop = (timecode >> I3SUPERDSTCHARGESTAMP_TIME_BITS_V0)
			    & ((1 << I3SUPERDST_SLOP_BITS_V0)-1);
			
			I3SuperDSTSerialization::ChargeStamp stampytown; /* Population: 5! */
			stampytown.stamp.rel_time = timecode
			    & ((1 << I3SUPERDSTCHARGESTAMP_TIME_BITS_V0)-1);
			stampytown.stamp.charge = truncate(stamp_it->GetChargeCode(), 
			    I3SUPERDSTCHARGESTAMP_CHARGE_BITS_V0);
			stampytown.stamp.hlc_bit = stamp_it->GetLCBit();
			
			/* Defer the stop bit if we have overflow to record. */
			stampytown.stamp.stop = (stop && (timecode < max_timecode) &&
			    (chargecode < max_chargecode));
			stamp_stream.push_back(stampytown);
			readout_bytes += sizeof(stampytown);
			
			/*
			 * Even specialer case: on rare occasions, readouts
			 * can be more than 8 musec apart. In such cases we leave
			 * the timecode saturated and slip the actual (untruncated)
			 * time code into the stamp stream. The saturated timecode
			 * in the regular stream serves as a sentinel for this case.
			 */
			if (timecode == max_timecode) {
				I3SuperDSTSerialization::ChargeStamp hammertime;
				if (readout_it->time_overflow_ <= (UINT16_MAX >> 1))
					hammertime.overflow.code =
					    readout_it->time_overflow_;
				else
					hammertime.overflow.code = (UINT16_MAX >> 1);
				
				/* Keep deferring if the charge overflows as well. */
				hammertime.overflow.stop = (stop &&
				    (chargecode < max_chargecode));
				stamp_stream.push_back(hammertime);
				readout_bytes += sizeof(hammertime);
			}

			/*
			 * Equivalently specialer case: if the stamp's charge
			 * is unrepresentably large, add another overflow.
			 */
			if (chargecode == max_chargecode) {
				I3SuperDSTSerialization::ChargeStamp hammertime;
				if (stamp_it->GetChargeOverflow() <= (UINT16_MAX >> 1))
					hammertime.overflow.code =
					    stamp_it->GetChargeOverflow();
				else
					hammertime.overflow.code = (UINT16_MAX >> 1);
				
				hammertime.overflow.stop = stop;
				stamp_stream.push_back(hammertime);
				readout_bytes += sizeof(hammertime);
			}
			
			stamp_it++;
		}
		
		header_stream.push_back(header);
		
		for ( ; stamp_it != readout_it->stamps_.end(); ) {
			I3SuperDSTSerialization::ChargeStamp stampytown;
			const bool stop = (boost::next(stamp_it)
			    == readout_it->stamps_.end());
			const unsigned chargecode = stamp_it->GetChargeCode();
			
			stampytown.stamp.rel_time = stamp_it->GetTimeCode();
			stampytown.stamp.charge = truncate(stamp_it->GetChargeCode(), 
			    I3SUPERDSTCHARGESTAMP_CHARGE_BITS_V0);
			stampytown.stamp.hlc_bit = stamp_it->GetLCBit();
			
			/* Defer stop bit if we have overflow to encode. */
			stampytown.stamp.stop = (stop
			    && (chargecode < max_chargecode));
			stamp_stream.push_back(stampytown);
			readout_bytes += sizeof(stampytown);
			
			/* Encode any charge overflow. */
			if (chargecode == max_chargecode) {
				I3SuperDSTSerialization::ChargeStamp hammertime;
				if (stamp_it->GetChargeOverflow() <= (UINT16_MAX >> 1))
					hammertime.overflow.code =
					    stamp_it->GetChargeOverflow();
				else
					hammertime.overflow.code = (UINT16_MAX >> 1);
				
				hammertime.overflow.stop = stop;
				stamp_stream.push_back(hammertime);
				readout_bytes += sizeof(hammertime);
			}
			
			stamp_it++;
		}

		if (sizes != NULL)
			(*sizes)[readout_it->om_].push_back(readout_bytes);
	}
	/* Let's not run over a cliff. */
	assert((stamp_stream.size() == 0) || stamp_stream.back().stamp.stop );
	
	ar & make_nvp("I3FrameObject", base_object<I3FrameObject>(*this));
	
	/*
	 * Serialize the packed bytestream. While doing this "by hand" makes 
	 * for obfuscated code, we can save 6 bytes over the vector
	 * serialization by storing the length as a short.
	 */
	assert( stamp_stream.size() < UINT16_MAX );	
	uint16_t stream_size = stamp_stream.size();
	size_t n_headers = header_stream.size();
	ar & make_nvp("NRecords", stream_size);
	
	swap_vector(stamp_stream);
	ar & make_nvp("ChargeStamps",
	    boost::serialization::make_binary_object(&stamp_stream.front(),
	    stream_size*sizeof(I3SuperDSTSerialization::ChargeStamp)));
	
	swap_vector(header_stream);
	ar & make_nvp("DOMHeaders",
	    boost::serialization::make_binary_object(&header_stream.front(),
	    n_headers*sizeof(I3SuperDSTSerialization::DOMHeader)));
	
	return;
}

template <class Archive>
void
I3SuperDST::load(Archive& ar, unsigned version)
{
	uint16_t stream_size = 0;
	size_t n_headers = 0;
	std::vector<I3SuperDSTSerialization::DOMHeader> header_stream;
	std::vector<I3SuperDSTSerialization::DOMHeader>::const_iterator header_it;
	std::vector<I3SuperDSTSerialization::ChargeStamp> stamp_stream;
	std::vector<I3SuperDSTSerialization::ChargeStamp>::const_iterator stamp_it;
	std::list<I3SuperDSTReadout>::const_iterator subevent_begin;
	std::list<I3SuperDSTReadout>::iterator readout_it;
	
	ar & make_nvp("I3FrameObject", base_object<I3FrameObject>(*this));
	
	ar & make_nvp("NRecords", stream_size);
	
	/* Resurrect the packed ChargeStamps from the archive */
	stamp_stream.resize(stream_size);
	ar & make_nvp("ChargeStamps",
	    boost::serialization::make_binary_object(&stamp_stream.front(),
	    stream_size*sizeof(I3SuperDSTSerialization::ChargeStamp)));
	swap_vector(stamp_stream);
	
	/* Count the number of distinct units in the stamp stream */
	for (stamp_it = stamp_stream.begin(); stamp_it != stamp_stream.end(); stamp_it++)
		if (stamp_it->stamp.stop)
			n_headers++;
		
	/* Now that we know the length of the header stream, resurrect it. */
	header_stream.resize(n_headers);
	ar & make_nvp("DOMHeaders",
	    boost::serialization::make_binary_object(&header_stream.front(),
	    n_headers*sizeof(I3SuperDSTSerialization::DOMHeader)));
	swap_vector(header_stream);
	
	/* Saturation value */
	const unsigned max_timecode_header = (1 << (I3SUPERDSTCHARGESTAMP_TIME_BITS_V0
	    + I3SUPERDST_SLOP_BITS_V0)) - 1;
	const unsigned max_chargecode = (1u << I3SUPERDSTCHARGESTAMP_CHARGE_BITS_V0) - 1;
	
	stamp_it = stamp_stream.begin();
	header_it = header_stream.begin();
	
	for ( ; header_it != header_stream.end(); header_it++) {
		I3SuperDSTReadout readout;
		
		readout.om_ = DecodeOMKey(header_it->dom_id, version);
		bool hlc = stamp_it->stamp.hlc_bit;
		bool subevent = false;
		
		/* 
		 * Use the slop bits in the header as the most significant
		 * bits for the time of the first header.
		 */
		unsigned timecode = stamp_it->stamp.rel_time;
		unsigned chargecode = stamp_it->stamp.charge;
		timecode |= (unsigned(header_it->slop) <<
		    I3SUPERDSTCHARGESTAMP_TIME_BITS_V0);
		
		/* If the time is saturated, add the next 15 bits. */
		if (timecode == max_timecode_header) {
			subevent = true;
			stamp_it++;
			readout.time_overflow_ = stamp_it->overflow.code;
		}
		
		/* If the time is saturated, add the next 15 bits. */
		if (chargecode == max_chargecode) {
			stamp_it++;
			chargecode += stamp_it->overflow.code;
		}
		
		I3SuperDSTChargeStamp stamp(timecode, chargecode, hlc);
		stamp.TruncateChargeCode(I3SUPERDSTCHARGESTAMP_CHARGE_BITS_V0);
		
		readout.stamps_.push_back(stamp);

		/* Read in the remaining stamps until we hit a stop. */
		while (!stamp_it->stamp.stop) {
			stamp_it++;
			
			/* No funny schtuff, ja Lebovski? */
			assert( stamp_it->stamp.hlc_bit == hlc );
			
			timecode = stamp_it->stamp.rel_time;
			chargecode = stamp_it->stamp.charge;
			
			/* Add charge overflow if we have it */
			if (chargecode == max_chargecode) {
				stamp_it++;
				chargecode += stamp_it->overflow.code;
			}
			
			I3SuperDSTChargeStamp stamp(timecode, chargecode, hlc);
			stamp.TruncateChargeCode(I3SUPERDSTCHARGESTAMP_CHARGE_BITS_V0);
			
			readout.stamps_.push_back(stamp);
		}
		assert( stamp_it != stamp_stream.end() );
		stamp_it++; /* Advance for the next readout */
		
		readout.kind_ = hlc ? I3SuperDSTChargeStamp::HLC : I3SuperDSTChargeStamp::SLC;
		readouts_.push_back(readout);
		
		/* Set up the subevent start iterator once readouts_ contains something */
		if (header_it == header_stream.begin())
			subevent_begin = readouts_.begin();
		
		/* Check for saturation in the timecode. This marks a distinct subevent. */
		if (subevent) {
			subevent_ranges_.push_back(std::make_pair(
			    subevent_begin, boost::prior(readouts_.end())));
			subevent_begin = boost::prior(readouts_.end());
		}
	}

	/* Complete the last subevent. */
	subevent_ranges_.push_back(std::make_pair(
	    subevent_begin, readouts_.end()));
	
	/* Populate the start_time_ fields of the readouts for consistency. */
	double t_ref = 0.0;
	for (readout_it = readouts_.begin(); readout_it != readouts_.end(); readout_it++) {
		assert( readout_it->stamps_.size() > 0 );
		t_ref += readout_it->GetTime();
		readout_it->start_time_ = t_ref;
	}
	
	return;
}

I3_SERIALIZABLE(I3SuperDST);
