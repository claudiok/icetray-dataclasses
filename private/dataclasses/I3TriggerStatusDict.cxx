#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3TriggerStatusDict.h>

template <class Archive>
  void I3TriggerStatusDict::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3TriggerStatus",
		  base_object< STLMapStoragePolicy<OMKey,I3TriggerStatus> >(*this));
  }


I3_SERIALIZABLE(I3TriggerStatusDict);
