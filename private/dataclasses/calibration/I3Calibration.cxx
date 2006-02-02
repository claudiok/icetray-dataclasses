#include <dataclasses/BoostHeaders.h>
#include <dataclasses/calibration/I3Calibration.h>

const char* I3FrameTraits<I3Calibration>::defaultName = "Calibration";

I3Calibration::~I3Calibration() {}

template <class Archive>
  void I3Calibration::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("TObject", base_object< TObject >(*this));
    ar & make_nvp("InIceCalibration",inIceCalibration_);
    ar & make_nvp("AMANDACalibration",AMANDACalibration_);
    ar & make_nvp("IceTopCalibration",iceTopCalibration_);
    ar & make_nvp("StartTime",startTime_);
    ar & make_nvp("EndTime",endTime_);
  }



I3_SERIALIZABLE(I3Calibration);
