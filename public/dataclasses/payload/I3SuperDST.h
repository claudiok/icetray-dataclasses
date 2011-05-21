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

#ifndef I3SUPERDST_I3SUPERDST_H_INCLUDED
#define I3SUPERDST_I3SUPERDST_H_INCLUDED

/* standard library stuff */
#include <map>
#include <vector>

/* IceTray stuff */
#include "icetray/I3FrameObject.h"
#include "icetray/IcetrayFwd.h"

#include "dataclasses/physics/I3RecoPulse.h"
#include "dataclasses/physics/I3TriggerHierarchy.h"

/* Forward declarations of real classes (not typedef'd templates) */
class OMKey;
class I3EventHeader;
class I3Time;

static const unsigned i3superdst_version_ = 0;

class I3SuperDSTChargeStamp {
public:
	enum LCType {HLC, SLC};
	
	I3SuperDSTChargeStamp(double time, double charge, bool hlc);
	I3SuperDSTChargeStamp(uint32_t timecode, uint32_t chargecode, bool hlc)
	    : timecode_(timecode), chargecode_(chargecode), charge_overflow_(0),
	    kind_(hlc ? HLC : SLC) {};
	
	double GetTime() const;
	double GetCharge() const;
	
	uint32_t GetTimeCode() const { return timecode_; };
	uint32_t GetChargeCode() const { return chargecode_; };
	uint32_t GetChargeOverflow() const { return charge_overflow_; };
	
	uint32_t TruncateTimeCode(unsigned maxbits);
	void TruncateChargeCode(unsigned maxbits);
	
	LCType GetKind() const { return kind_; };
	bool GetLCBit() const { return (kind_ == HLC); };
	
	void SetTimeReference(const I3SuperDSTChargeStamp &other);

private:
	uint32_t timecode_;
	uint32_t chargecode_;
	uint32_t charge_overflow_;
	LCType kind_;
	
	SET_LOGGER("I3SuperDST");
};

struct I3SuperDSTReadout {
	
	OMKey om_;
	double start_time_;
	std::vector<I3SuperDSTChargeStamp> stamps_;
	I3SuperDSTChargeStamp::LCType kind_;
	uint32_t time_overflow_;
	
	I3SuperDSTReadout(const OMKey &om, bool hlc,
	    const std::list<I3RecoPulse>::const_iterator &start, 
	    const std::list<I3RecoPulse>::const_iterator &end, double t0 = 0.0);
	I3SuperDSTReadout() : om_(), start_time_(0.0), stamps_(), kind_(),
	    time_overflow_(0) {};
	
	void SetTimeReference(const I3SuperDSTReadout &other);
	void Relativize();
	void TruncateCodes();
	
	double GetTime() const;
	
	bool GetLCBit() const { return (kind_ == I3SuperDSTChargeStamp::HLC); };
	
	bool operator<(const I3SuperDSTReadout &other)
	    { return start_time_ < other.start_time_; };
	
	SET_LOGGER("I3SuperDST");
};


class I3SuperDST : public I3FrameObject {
public:
	I3SuperDST() { InitDebug(); };
	
	/** 
	 * Create a compressed representation of an event from HLC and SLC pulse maps.
	 * NB: since there is no commonly agreed-upon way to distiguish between
	 * pulses from HLC launches and [coarser, less reliable] pulses from SLC
	 * launches, the arguments must be in the proper order and the sets must
	 * be disjoint. If this is not true, the subsequent behavior is undefined.
	 * 
	 * @param hlc_pulses	Map containing pulses extracted from HLC launches.
	 * @param slc_pulses	Map containing pulses extracted from SLC launches.
	 * 
	 * @see Unpack()
	 */
	I3SuperDST(const I3RecoPulseSeriesMap &hlc_pulses,
	    const I3RecoPulseSeriesMap &slc_pulses);
	
	/**
	 * Expand charge stamps into fake I3RecoPulses.
	 *
	 * @param hlc_pulses	Map to fill with pulses derived from HLC launches.
	 * @param slc_pulses	Map to fill with pulses derived from SLC launches.
	 * @param subevent	Which subevent (portion of the event separated from
	 *                      preceding launches by more than 131 microseconds) to
	 *                      extract. -1 mean extract the entire event.
	 */
	bool Unpack(I3RecoPulseSeriesMapPtr &hlc_pulses,
	    I3RecoPulseSeriesMapPtr &slc_pulses, int subevent=-1) const;
	
	/**
	 * Expand charge stamps into fake I3RecoPulses, packing everything into
	 * a single map.
	 */
	I3RecoPulseSeriesMapConstPtr Unpack() const;
	
	std::list<I3SuperDSTReadout> GetHLCReadouts() const
	    { return GetReadouts(true); };
	std::list<I3SuperDSTReadout> GetSLCReadouts() const
	    { return GetReadouts(false); };

#ifndef NDEBUG
	double *serialization_time_;
	unsigned *serialization_counter_;
	void InitDebug() { serialization_time_ = NULL; serialization_counter_ = NULL; };
#else
	void InitDebug() {};
#endif
		
	unsigned GetSubEvents() const { return subevent_ranges_.size(); }; 
	
	static uint32_t EncodeOMKey(const OMKey &key, unsigned int maxbits=16,
	    unsigned int version=i3superdst_version_);
	static OMKey DecodeOMKey(uint32_t number,
	    unsigned int version=i3superdst_version_);
	
	static uint32_t EncodeTime(double time, unsigned int maxbits=16,
	    unsigned int version=i3superdst_version_);
	static double DecodeTime(uint32_t dt,
	    unsigned int version=i3superdst_version_);
	
	static uint32_t EncodeCharge(double charge, unsigned int maxbits=16,
	    unsigned int version=i3superdst_version_);
	static double DecodeCharge(uint32_t logcharge,
	    unsigned int version=i3superdst_version_);
	
	static double FindStartTime(const I3RecoPulseSeriesMap &pmap);

private:
	std::list<I3SuperDSTReadout> readouts_;
	std::deque<std::pair<std::list<I3SuperDSTReadout>::const_iterator,
	    std::list<I3SuperDSTReadout>::const_iterator> > subevent_ranges_;
	mutable I3RecoPulseSeriesMapPtr unpacked_;
	
	void AddPulseMap(const I3RecoPulseSeriesMap &pulses, bool hlc, double t0);
	std::list<I3SuperDSTReadout> GetReadouts(bool hlc) const;
	
	static const double tmin_;
	
	friend class boost::serialization::access;

	template <class Archive> void save(Archive & ar, unsigned version) const;
	template <class Archive> void load(Archive & ar, unsigned version);
	BOOST_SERIALIZATION_SPLIT_MEMBER();
	
	SET_LOGGER("I3SuperDST");
};


BOOST_CLASS_VERSION(I3SuperDST, i3superdst_version_);

I3_POINTER_TYPEDEFS(I3SuperDST);

#endif
