#include <dataclasses/BoostHeaders.h>
#include <dataclasses/physics/I3DOMLaunch.h>

I3DOMLaunch::~I3DOMLaunch() {}

I3DOMLaunch::I3DOMLaunch() 
    : startTime_(0.0),
      trigger_(0),
      whichATWD_(ATWDa),
      localCoincidence_(false),
      chargeStampRange_(false)
{
  rawATWD_.resize(4);
}

template <class Archive>
    void I3DOMLaunch::serialize(Archive& ar, unsigned version)
	{
	  ar & make_nvp("TObject", base_object< TObject >(*this));
	    ar & make_nvp("StartTime", startTime_);
	    ar & make_nvp("Trigger", trigger_);
	    ar & make_nvp("WhichATWD", whichATWD_);
	    ar & make_nvp("RawATWD", rawATWD_);
	    ar & make_nvp("RawFADC", rawFADC_);
	    ar & make_nvp("LocalCoincidence", localCoincidence_);
	    ar & make_nvp("RawChargeStamp", rawChargeStamp_);
	    ar & make_nvp("ChargeStampRange", chargeStampRange_);
	}

I3_SERIALIZABLE(I3DOMLaunch);
