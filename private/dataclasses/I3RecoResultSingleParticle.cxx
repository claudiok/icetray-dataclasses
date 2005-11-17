#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3RecoResultSingleParticle.h>

I3RecoResultSingleParticle::~I3RecoResultSingleParticle() {}

template <class Archive>
  void I3RecoResultSingleParticle::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3RecoResult", base_object<I3RecoResult>(*this));
    ar & make_nvp("Particle", particle_);
  }
  
  

I3_SERIALIZABLE(I3RecoResultSingleParticle);
