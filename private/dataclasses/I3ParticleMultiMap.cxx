#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3ParticleMultiMap.h>

I3ParticleMultiMap::~I3ParticleMultiMap() {}

template <class Archive>
  void I3ParticleMultiMap::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3ParticleMultiMap", 
		  base_object< multimap<string, I3ParticlePtr>  >(*this));
  }

  

I3_SERIALIZABLE(I3ParticleMultiMap);
