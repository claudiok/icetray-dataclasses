#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3DetectorStatus.h>

template <class Archive>
  void I3DetectorStatus::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("IcecubeDOMStatus",icecubeDOMStatus_);
    ar & make_nvp("IcetopDOMStatus",icetopDOMStatus_);
    ar & make_nvp("IcecubeTriggerStatus",icecubeTrigStatus_);
    ar & make_nvp("IcetopTriggerStatus",icetopTrigStatus_);
    //ar & make_nvp("DaqMode",daqMode_);
    //ar & make_nvp("FilterMode",filterMode_);
  }



I3_SERIALIZABLE(I3DetectorStatus);
