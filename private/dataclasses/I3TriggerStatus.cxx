#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3TriggerStatus.h>

template <class Archive>
  void I3TriggerStatus::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("TriggerType",triggerType_);
    ar & make_nvp("TriggerSourceID",trigSourceID_);
    ar & make_nvp("TriggerSettings",triggerSettings_);
  }



I3_SERIALIZABLE(I3TriggerStatus);
