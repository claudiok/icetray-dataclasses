#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3DetectorStatus.h>

template <class Archive>
  void I3DetectorStatus::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("IcecubeStatus",icecubeStatus_);
  }



I3_SERIALIZABLE(I3DetectorStatus);
