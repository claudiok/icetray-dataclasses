#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3DOMStatus.h>

template <class Archive>
  void I3DOMStatus::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("rawStatus",rawStatus_);
    ar & make_nvp("calibratedStatus",calibratedStatus_);
  }



I3_SERIALIZABLE(I3DOMStatus);
