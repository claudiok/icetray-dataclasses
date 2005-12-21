#include <dataclasses/BoostHeaders.h>
#include <dataclasses/calibration/I3Calibration.h>

I3Calibration::~I3Calibration() {}

template <class Archive>
  void I3Calibration::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("InIceCalibration",inIceCalibration_);
    ar & make_nvp("AMANDACalibration",AMANDACalibration_);
    ar & make_nvp("IceTopCalibration",iceTopCalibration_);
  }



I3_SERIALIZABLE(I3Calibration);
