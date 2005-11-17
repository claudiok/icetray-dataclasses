#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3FilterDict.h>

I3FilterDict::~I3FilterDict() {}

template <class Archive> void I3FilterDict::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3FilterDict", base_object< STLMapStoragePolicy<string, I3FilterPtr>  >(*this));
  }

  

I3_SERIALIZABLE(I3FilterDict);
