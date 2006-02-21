#include <dataclasses/BoostHeaders.h>
#include <dataclasses/physics/I3Particle.h>

ClassImp(I3Particle);

I3Particle::~I3Particle() {}

void I3Particle::ToStream(ostream& o) const
{
  o<<"ID: "<<id_<<"\n";
  o<<"Type: "<<type_<<"\n";
  o<<"Position:\n"<<pos_;
  o<<"Direction:\n"<<dir_;
  o<<"Time: "<<time_<<"\n";
  o<<"Energy: "<<energy_<<"\n";
  o<<"Length: "<<length_<<"\n";
  o<<"Speed: "<<speed_<<"\n";
  if (composite_.size()>0) {
    o<<"[ Composite Particle ]: "<<endl;
    for (unsigned int i=0; i<composite_.size(); i++)
      composite_[i].ToStream(o);
  }
}

template <class Archive>
  void I3Particle::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("TObject", base_object<TObject>(*this));
    ar & make_nvp("id",id_);
    ar & make_nvp("type",type_);
    ar & make_nvp("pos",pos_);
    ar & make_nvp("dir",dir_);
    ar & make_nvp("time",time_);
    ar & make_nvp("energy",energy_);
    ar & make_nvp("length",length_);
    ar & make_nvp("speed",speed_);
    ar & make_nvp("composite",composite_);
  }
  

I3_SERIALIZABLE(I3Particle);
