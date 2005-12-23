#include <dataclasses/BoostHeaders.h>
#include <dataclasses/physics/I3MCParticleData.h>

I3MCParticleData::~I3MCParticleData(){}

template <class Archive>
  void I3MCParticleData::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("Primary", primary_);
    ar & make_nvp("InIceParticles", inIceParticles_);
    ar & make_nvp("IceTopParticle",iceTopParticles_ );
  }

  

I3_SERIALIZABLE(I3MCParticleData);
