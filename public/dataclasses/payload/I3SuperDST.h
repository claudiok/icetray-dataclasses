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

static const unsigned i3superdst_version_ = 1;

namespace I3SuperDSTUtils {
	enum Discretization { LINEAR, FLOATING_POINT };

	/*
	 * Hobo run-length encoding for 4-bit numbers.
	 *
	 * Runs of 4-bit codes are encoded in single-byte instructions.
	 * The lower 4 bits hold the code, and the upper 4 bits hold
	 * a run length. If successive bytes contain the same code, then
	 * the run lengths are concatenated to form a wider number. This
	 * way, a run of 16 fits in 1 byte, a run of 256 in 2 bytes,
	 * 4096 in 3, etc.
	 *
	 * As with any run-length encoding, this does worst when there
	 * are no runs to encode. In the worst case where the code
	 * switches at every element, this encoding exactly doubles
	 * the size of the encoded data.
	 */ 
	struct RunCodec {
		typedef std::vector<uint8_t> vector_t;
		vector_t values_;
		RunCodec() : values_() {};

		void EncodeRun(vector_t &codes, uint8_t val, unsigned len) const;
		void DecodeRun(vector_t &target,
		    const vector_t::const_iterator &head,
		    const vector_t::const_iterator &tail) const;

		vector_t Encode() const;
		void Decode(const vector_t &codes);

		friend class boost::serialization::access;
		template <class Archive>
		void load(Archive &ar, unsigned version);
		template <class Archive>
		void save(Archive &ar, unsigned version) const;
		BOOST_SERIALIZATION_SPLIT_MEMBER();
	};

	/* Stupid GNU libc, not having fls() */
	inline unsigned fls(unsigned i)
	{
		return i == 0 ? 0 : (8*sizeof(i)-__builtin_clz(i));
	}
	
}

class I3SuperDSTChargeStamp {
public:
	enum LCType {HLC, SLC};
	
	I3SuperDSTChargeStamp(double time, double charge, double width, bool hlc,
	    I3SuperDSTUtils::Discretization format=I3SuperDSTUtils::LINEAR);
	I3SuperDSTChargeStamp(uint32_t timecode, uint32_t chargecode, uint32_t widthcode,
	    bool hlc, I3SuperDSTUtils::Discretization format=I3SuperDSTUtils::LINEAR, 
	    unsigned version=i3superdst_version_) : timecode_(timecode), widthcode_(widthcode),
	    chargecode_(chargecode), charge_overflow_(0),
	    version_(version), kind_(hlc ? HLC : SLC), charge_format_(format) {};
	
	double GetTime() const;
	double GetWidth() const;
	double GetCharge() const;
	
	uint32_t GetTimeCode() const { return timecode_; };
	uint32_t GetChargeCode() const { return chargecode_; };
	uint32_t GetWidthCode() const { return widthcode_; };
	uint32_t GetChargeOverflow() const { return charge_overflow_; };
	I3SuperDSTUtils::Discretization GetChargeFormat() const
	{ return charge_format_; };
	
	uint32_t TruncateTimeCode(unsigned maxbits);
	void TruncateChargeCode(unsigned maxbits);
	
	LCType GetKind() const { return kind_; };
	bool GetLCBit() const { return (kind_ == HLC); };
	
	void SetTimeReference(const I3SuperDSTChargeStamp &other);

private:
	uint32_t timecode_;
	uint32_t widthcode_;
	uint32_t chargecode_;
	uint32_t charge_overflow_;
	unsigned version_;
	LCType kind_;
	I3SuperDSTUtils::Discretization charge_format_;
	
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
	I3SuperDST() : version_(i3superdst_version_) { InitDebug(); };
	
	/** 
	 * Create a compressed representation of an event from a pulse map.
	 *
	 * @param pulses	Map containing pulses extracted from all
	 *                      InIce and IceTop launches.
	 * 
	 * @see Unpack()
	 */
	I3SuperDST(const I3RecoPulseSeriesMap &pulses);
	
	/**
	 * Expand charge stamps into fake I3RecoPulses, packing everything into
	 * a single map.
	 */
	I3RecoPulseSeriesMapConstPtr Unpack() const;

	I3MapKeyVectorInt GetEncodedSizes() const;
	
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
		
	static uint32_t EncodeOMKey(const OMKey &key, unsigned int maxbits=16,
	    unsigned int version=i3superdst_version_);
	static OMKey DecodeOMKey(uint32_t number,
	    unsigned int version=i3superdst_version_);
	
	static uint32_t EncodeTime(double time, unsigned int maxbits=16,
	    unsigned int version=i3superdst_version_);
	static double DecodeTime(uint32_t dt,
	    unsigned int version=i3superdst_version_);
	static uint32_t EncodeWidth(double width, unsigned int maxbits=16,
	    unsigned int version=i3superdst_version_);
	static double DecodeWidth(uint32_t code,
	    unsigned int version=i3superdst_version_);
	
	static uint32_t EncodeCharge(double charge, unsigned int maxbits=16,
	    unsigned int version=i3superdst_version_,
	    I3SuperDSTUtils::Discretization mode=I3SuperDSTUtils::LINEAR);
	static double DecodeCharge(uint32_t logcharge,
	    unsigned int version=i3superdst_version_,
	    I3SuperDSTUtils::Discretization mode=I3SuperDSTUtils::LINEAR);
	
	static double FindStartTime(const I3RecoPulseSeriesMap &pmap);

private:
	std::list<I3SuperDSTReadout> readouts_;
	mutable I3RecoPulseSeriesMapPtr unpacked_;
	
	void AddPulseMap(const I3RecoPulseSeriesMap &pulses, double t0);
	std::list<I3SuperDSTReadout> GetReadouts(bool hlc) const;
	
	static const double tmin_;
	
	unsigned version_;
	
	friend class boost::serialization::access;

	template <class Archive> void save(Archive & ar, unsigned version,
	    std::map<OMKey, std::vector<int > > *sizes=NULL) const;
	template <class Archive> void load(Archive & ar, unsigned version);
	BOOST_SERIALIZATION_SPLIT_MEMBER();
	
	SET_LOGGER("I3SuperDST");
};


BOOST_CLASS_VERSION(I3SuperDST, i3superdst_version_);

I3_POINTER_TYPEDEFS(I3SuperDST);

#endif
