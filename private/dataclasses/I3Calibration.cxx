#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3Calibration.h>

template <class Archive>
  void I3Calibration::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("InIceCalibration",inIceCalibration_);
    ar & make_nvp("AMANDACalibration",AMANDACalibration_);
    ar & make_nvp("IceTopCalibration",iceTopCalibration_);
  }



I3_SERIALIZABLE(I3Calibration);
