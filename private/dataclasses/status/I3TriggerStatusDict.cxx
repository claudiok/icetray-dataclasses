#include <dataclasses/BoostHeaders.h>
#include <dataclasses/status/I3TriggerStatusDict.h>

I3TriggerStatusDict::~I3TriggerStatusDict() {}

template <class Archive>
  void I3TriggerStatusDict::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3TriggerStatus",
		  base_object< map<TriggerKey,I3TriggerStatusPtr> >(*this));
  }


I3_SERIALIZABLE(I3TriggerStatusDict);
