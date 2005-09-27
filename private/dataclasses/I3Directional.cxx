#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3Directional.h>

template <class Archive>
    void I3Directional::serialize(Archive& ar, unsigned version){
    ar & make_nvp("Dir",dir_);
  }
  

I3_SERIALIZABLE(I3Directional);
