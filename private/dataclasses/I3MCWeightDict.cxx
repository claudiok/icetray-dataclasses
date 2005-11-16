#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3MCWeightDict.h>

template <class Archive>
  void I3MCWeightDict::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3MCWeightDict", base_object< STLMapStoragePolicy<string, float> >(*this));
  }
  

I3_SERIALIZABLE(I3MCWeightDict);
