#include <dataclasses/BoostHeaders.h>
#include <dataclasses/status/I3TriggerStatus.h>

I3TriggerStatus::~I3TriggerStatus() {}

template <class Archive>
void 
I3TriggerStatus::serialize(Archive& ar, unsigned version)
{
  ar & make_nvp("TObject", base_object< TObject >(*this));
  ar & make_nvp("TriggerName",triggerName_);
  ar & make_nvp("TriggerSettings",triggerSettings_);
}



I3_SERIALIZABLE(I3TriggerStatus);
