#include <icetray/serialization.h>
#include <dataclasses/physics/I3DOMLaunch.h>

I3DOMLaunch::I3DOMLaunch() 
  : startTime_(0.0),
    trigger_(TEST_PATTERN),
    mode_(UNDEFINED),
    whichATWD_(ATWDa),
    localCoincidence_(false)
{
  rawATWD_.resize(4);
}


I3DOMLaunch::~I3DOMLaunch() {}


template <class Archive>
void I3DOMLaunch::serialize(Archive& ar, unsigned version)
{
  ar & make_nvp("StartTime", startTime_);
  // ignore the "Trigger" information of old data
  if(version < 1)
  {
    int tmp;
    ar & make_nvp("Trigger", tmp);
  }
  // for version > 0 there is a trigger type and mode to be serialized
  if(version > 0)
  {
    ar & make_nvp("TriggerType", trigger_);
    ar & make_nvp("TriggerSituation", mode_);
  }
  // for version <= 0 there is no trigger type and mode available
  // use default values instead
  else
  {
    trigger_ = TEST_PATTERN;
    mode_ = UNDEFINED;
  }
  ar & make_nvp("WhichATWD", whichATWD_);
  ar & make_nvp("RawATWD", rawATWD_);
  ar & make_nvp("RawFADC", rawFADC_);
  ar & make_nvp("LocalCoincidence", localCoincidence_);
  ar & make_nvp("RawChargeStamp", rawChargeStamp_);    
  // ignore the range for the raw charge stamp of old data
  if(version < 2)
  {
    bool tmp;
    ar & make_nvp("ChargeStampRange", tmp);
  }
  // for version > 1 there is an index to be serialized,
  // addressing the highest sample of the charge stamp
  if(version > 1)
  {
    ar & make_nvp("ChargeStampHighestSample", chargeStampHighestSample_);    
  }
  // for version <= 1 there is no index available
  // use a value of 0 instead - should be fine since rawChargeStamp_ is empty
  else
  {
    if(!rawChargeStamp_.empty()) log_warn("oops, coarse charge stamp is not empty");
    chargeStampHighestSample_ = 0u;
  }
}

I3_SERIALIZABLE(I3DOMLaunch);

I3_SERIALIZABLE(I3DOMLaunchSeries);
I3_SERIALIZABLE(I3DOMLaunchSeriesMap);
