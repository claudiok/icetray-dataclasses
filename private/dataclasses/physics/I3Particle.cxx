#include <dataclasses/BoostHeaders.h>
#include <dataclasses/physics/I3Particle.h>

I3Particle::~I3Particle() {}

template <class Archive>
  void I3Particle::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("TObject", base_object<TObject>(*this));
    ar & make_nvp("type",type_);
    ar & make_nvp("parentID",parentID_);
    ar & make_nvp("primaryID",primaryID_);
    ar & make_nvp("myID",myID_);
    ar & make_nvp("recoName",recoName_);
    ar & make_nvp("mcTruth",mcTruthID_);
  }

I3_SERIALIZABLE(I3Particle);
