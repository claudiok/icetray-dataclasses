#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3ParticleMultiMap.h>

template <class Archive>
  void I3ParticleMultiMap::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3ParticleMultiMap", 
		  base_object< STLMultiMapStoragePolicy<string, I3ParticlePtr>  >(*this));
  }

  

I3_SERIALIZABLE(I3ParticleMultiMap);
