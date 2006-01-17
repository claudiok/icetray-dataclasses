#include <dataclasses/BoostHeaders.h>
#include <dataclasses/physics/I3Directional.h>

I3Directional::~I3Directional(){ }

template <class Archive>
    void I3Directional::serialize(Archive& ar, unsigned version){
    ar & make_nvp("Dir",dir_);
  }
  

I3_SERIALIZABLE(I3Directional);