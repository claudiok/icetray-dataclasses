#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3TriggerDict.h>

template <class Archive> void I3TriggerDict::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3TriggerDict", base_object< STLMapStoragePolicy<string, I3TriggerPtr>  >(*this));
  }

  

I3_SERIALIZABLE(I3TriggerDict);
