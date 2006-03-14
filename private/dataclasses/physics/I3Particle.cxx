#include <dataclasses/BoostHeaders.h>
#include <dataclasses/physics/I3Particle.h>

I3Particle::~I3Particle() { }

template <class Archive>
  void I3Particle::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3FrameObject", base_object<I3FrameObject>(*this));
    ar & make_nvp("ID",ID_);
    ar & make_nvp("parentID",parentID_);
    ar & make_nvp("primaryID",primaryID_);
    ar & make_nvp("type",type_);
    ar & make_nvp("shape",shape_);
    ar & make_nvp("fitStatus",status_);
    ar & make_nvp("pos",pos_);
    ar & make_nvp("dir",dir_);
    ar & make_nvp("time",time_);
    ar & make_nvp("energy",energy_);
    ar & make_nvp("length",length_);
    ar & make_nvp("speed",speed_);
    ar & make_nvp("composite",composite_);
  }
  

I3_SERIALIZABLE(I3Particle);

I3_SERIALIZABLE(I3ParticleVect);
