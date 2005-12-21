#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3RecoResultCutParameters.h>

I3RecoResultCutParameters::~I3RecoResultCutParameters() {}

void I3RecoResultCutParameters::ToStream(ostream& o) const {
  I3RecoResult::ToStream(o);
  o<<"The Particle:\n";
  if(particle_) {
    o<<*particle_<<"\n";
    o<<"Ndir: "<<Ndir_<<"\n";
    o<<"Ldir: "<<Ldir_<<"\n";
    o<<"Sdir: "<<Sdir_<<"\n";
    o<<"Sall: "<<Sall_<<"\n";
  }
  else {
    o<<"NULL Particle\n";
  }
}

template <class Archive>
  void I3RecoResultCutParameters::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3RecoResultSingleParticle", base_object<I3RecoResultSingleParticle>(*this));
    ar & make_nvp("Ndir", Ndir_);
    ar & make_nvp("Ldir", Ldir_);
    ar & make_nvp("Sdir", Sdir_);
    ar & make_nvp("Sall", Sall_);
  }

I3_SERIALIZABLE(I3RecoResultCutParameters);
