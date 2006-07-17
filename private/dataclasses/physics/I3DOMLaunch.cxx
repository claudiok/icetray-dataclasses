#include <dataclasses/BoostHeaders.h>
#include <dataclasses/physics/I3DOMLaunch.h>

//hack to make a failing test
//for serialization
namespace temp_hack{
  const unsigned DOMLAUNCH_VERSION = 1;
}

I3DOMLaunch::I3DOMLaunch() 
  : startTime_(0.0),
    trigger_(TEST_PATTERN),
    mode_(UNDEFINED),
    whichATWD_(ATWDa),
    localCoincidence_(false),
    chargeStampRange_(false)
{
  rawATWD_.resize(4);
}


I3DOMLaunch::~I3DOMLaunch() {}


template <class Archive>
void I3DOMLaunch::serialize(Archive& ar, unsigned version)
{
  if(version != temp_hack::DOMLAUNCH_VERSION) 
    log_fatal("I3DOMLaunch:class versioning does not appear to work.");
  ar & make_nvp("StartTime", startTime_);
  // ignore the "Trigger" information from serialization of old data
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
  ar & make_nvp("ChargeStampRange", chargeStampRange_);
}

BOOST_CLASS_VERSION(I3DOMLaunch, temp_hack::DOMLAUNCH_VERSION);
I3_SERIALIZABLE(I3DOMLaunch);

I3_SERIALIZABLE(I3DOMLaunchSeries);
I3_SERIALIZABLE(I3DOMLaunchSeriesMap);
