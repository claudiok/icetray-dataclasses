#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3Stopping.h>

template <class Archive>
  void I3Stopping::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("StopPos",stopPos_);
    ar & make_nvp("Dir",dir_);
    ar & make_nvp("StopT",stopT_);
  }

  

I3_SERIALIZABLE(I3Stopping);