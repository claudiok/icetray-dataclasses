#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3TriggerStatusDict.h>

I3TriggerStatusDict::~I3TriggerStatusDict() {}

template <class Archive>
  void I3TriggerStatusDict::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3TriggerStatus",
		  base_object< STLMapStoragePolicy<TriggerKey,I3TriggerStatusPtr> >(*this));
  }


I3_SERIALIZABLE(I3TriggerStatusDict);
