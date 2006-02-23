#include <dataclasses/BoostHeaders.h>
#include <dataclasses/status/I3DetectorStatus.h>

const char* I3FrameTraits<I3DetectorStatus>::defaultName = "DetectorStatus";

const char* I3FrameTraits<const I3DetectorStatus>::defaultName = "DetectorStatus";

//I3DetectorStatus::~I3DetectorStatus() {}

template <class Archive>
void 
I3DetectorStatus::serialize(Archive& ar, unsigned version)
{
  ar & make_nvp("TObject", base_object<TObject>(*this));
  ar & make_nvp("DOMStatus",domStatus);
  ar & make_nvp("TriggerStatus",triggerStatus);
  ar & make_nvp("StartTime",startTime);
  ar & make_nvp("EndTime",endTime);
  //ar & make_nvp("DaqMode",daqMode_);
  //ar & make_nvp("FilterMode",filterMode_);
}



I3_SERIALIZABLE(I3DetectorStatus);
