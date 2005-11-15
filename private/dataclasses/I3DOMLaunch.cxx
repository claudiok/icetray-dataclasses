#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3DOMLaunch.h>

I3DOMLaunch::I3DOMLaunch() 
    : startTime_(0.0)
{}

template <class Archive>
    void I3DOMLaunch::serialize(Archive& ar, unsigned version)
	{
	    ar & make_nvp("I3DigitalLaunch", base_object<I3DigitalLaunch>(*this) );
	    ar & make_nvp("StartTime", startTime_);
	    ar & make_nvp("ATWDBinSize", aTWDBinSize_);
	    ar & make_nvp("Trigger", trigger_);
	    ar & make_nvp("WhichATWD", whichATWD_);
	    ar & make_nvp("RawATWD0", rawATWD0_);
	    ar & make_nvp("RawATWD1", rawATWD1_);
	    ar & make_nvp("RawATWD2", rawATWD2_);
	    ar & make_nvp("RawATWD3", rawATWD3_);
	    ar & make_nvp("RawFADC", rawFADC_);
	    ar & make_nvp("CalibratedATWD", calibratedATWD_);
	    ar & make_nvp("CalibratedFADC", calibratedFADC_);
	    ar & make_nvp("LocalCoincidence", localCoincidence_);
	    ar & make_nvp("ChargeStampRange", chargeStampRange_);
	    ar & make_nvp("RawChargeStamp", rawChargeStamp_);
	    ar & make_nvp("CalibratedChargeStamp", calibratedChargeStamp_);
	}

I3_SERIALIZABLE(I3DOMLaunch);
