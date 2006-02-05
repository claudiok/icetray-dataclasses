#include <dataclasses/BoostHeaders.h>
#include <dataclasses/physics/I3Cascade.h>

I3Cascade::~I3Cascade() {}

void I3Cascade::ToStream(ostream& o) const
{
  o<<"Position:\n"<<pos_;
  o<<"Direction:\n"<<dir_;
  o<<"Time: "<<time_<<"\n";
  o<<"Energy: "<<energy_<<"\n";
  map<string,double>::const_iterator iter;
  for (iter=user_.begin(); iter!=user_.end(); iter++) {
    o<<iter->first<<": "<<iter->second<<"\n";
  }
  //o<<"\n";
}

template <class Archive>
  void I3Cascade::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3Particle", base_object<I3Particle>(*this));
    ar & make_nvp("pos",pos_);
    ar & make_nvp("dir",dir_);
    ar & make_nvp("time",time_);
    ar & make_nvp("energy",energy_);
    ar & make_nvp("user",user_);
  }
  

I3_SERIALIZABLE(I3Cascade);
