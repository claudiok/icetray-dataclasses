#include <dataclasses/BoostHeaders.h>
#include <dataclasses/status/I3DetectorStatus.h>

const char* I3FrameTraits<I3DetectorStatus>::defaultName = "DetectorStatus";

I3DetectorStatus::~I3DetectorStatus() {}

template <class Archive>
void 
I3DetectorStatus::serialize(Archive& ar, unsigned version)
{
  ar & make_nvp("TObject", base_object<TObject>(*this));
  ar & make_nvp("IcecubeDOMStatus",icecubeDOMStatus_);
  ar & make_nvp("IcetopDOMStatus",icetopDOMStatus_);
  ar & make_nvp("IcecubeTriggerStatus",icecubeTrigStatus_);
  ar & make_nvp("IcetopTriggerStatus",icetopTrigStatus_);
  ar & make_nvp("StartTime",startTime_);
  ar & make_nvp("EndTime",endTime_);
  //ar & make_nvp("DaqMode",daqMode_);
  //ar & make_nvp("FilterMode",filterMode_);
}



I3_SERIALIZABLE(I3DetectorStatus);
