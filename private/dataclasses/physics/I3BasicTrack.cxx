#include <dataclasses/BoostHeaders.h>
#include <dataclasses/physics/I3BasicTrack.h>

I3BasicTrack::~I3BasicTrack() {}

template <class Archive>
  void I3BasicTrack::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("pos",pos_);
    ar & make_nvp("dir",dir_);
    ar & make_nvp("time",time_);
    ar & make_nvp("energy",energy_);
    ar & make_nvp("length",length_);
    ar & make_nvp("type",type_);
    ar & make_nvp("user",user_);
  }
  

I3_SERIALIZABLE(I3BasicTrack);
