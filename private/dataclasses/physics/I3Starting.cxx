#include <dataclasses/BoostHeaders.h>
#include <dataclasses/physics/I3Starting.h>

I3Starting::~I3Starting() {}

template <class Archive>
  void I3Starting::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("StartPos",startPos_);
    ar & make_nvp("Dir",dir_);
    ar & make_nvp("StartT",startT_);
  }

  

I3_SERIALIZABLE(I3Starting);
