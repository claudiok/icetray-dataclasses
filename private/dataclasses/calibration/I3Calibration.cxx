#include <dataclasses/BoostHeaders.h>
#include <dataclasses/calibration/I3Calibration.h>

const char* I3FrameTraits<I3Calibration>::defaultName = "Calibration";

const char* I3FrameTraits<const I3Calibration>::defaultName = "Calibration";

I3Calibration::~I3Calibration() {}

template <class Archive>
  void I3Calibration::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("TObject", base_object< TObject >(*this));
    ar & make_nvp("domcal",domcal);
    ar & make_nvp("amandacal",amandacal);
    ar & make_nvp("StartTime",startTime);
    ar & make_nvp("EndTime",endTime);
  }



I3_SERIALIZABLE(I3Calibration);
