#include <dataclasses/BoostHeaders.h>
#include <dataclasses/calibration/I3Calibration.h>

I3Calibration::~I3Calibration() {}

template <class Archive>
void 
I3Calibration::serialize(Archive& ar, unsigned version)
{
  ar & make_nvp("I3FrameObject", base_object<I3FrameObject>(*this));
  ar & make_nvp("domcal",domCal);
  ar & make_nvp("amandacal",amandaCal);
  ar & make_nvp("StartTime",startTime);
  ar & make_nvp("EndTime",endTime);
}

I3_SERIALIZABLE(I3Calibration);
