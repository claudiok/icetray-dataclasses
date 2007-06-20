#include <icetray/serialization.h>
#include <dataclasses/status/I3DetectorStatus.h>

I3DetectorStatus::~I3DetectorStatus() {}

template <class Archive>
void
I3DetectorStatus::serialize(Archive& ar, unsigned version)
{
  if (version>i3detectorstatus_version_)
    log_fatal("Attempting to read version %u from file but running version %u of I3DetectorStatus class.",version,i3detectorstatus_version_);

  ar & make_nvp("I3FrameObject", base_object<I3FrameObject>(*this));
  ar & make_nvp("DOMStatus", domStatus);
  // for version > 0 there are TWR AOM stati to be serialized
  if(version > 0)
  {
    ar & make_nvp("AOMStatus", aomStatus);
  }
  // for version <= 0 there are no TWR AOM stati available
  else
  {
    aomStatus.clear();
  }  
  ar & make_nvp("TriggerStatus", triggerStatus);
  // for version > 1 there are Amanda trigger stati to be serialized
  if(version > 1)
  {
    ar & make_nvp("AmandaTriggerStatus", amandaTriggerStatus);
  }
  // for version <= 1 there are noAmanda trigger stati available
  else
  {
    amandaTriggerStatus.clear();
  }  
  ar & make_nvp("StartTime", startTime);
  ar & make_nvp("EndTime", endTime);
  //ar & make_nvp("DaqMode", daqMode_);
  //ar & make_nvp("FilterMode", filterMode_);
}


I3_SERIALIZABLE(I3DetectorStatus);
