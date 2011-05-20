#include <map>
#include <icetray/serialization.h>
#include <dataclasses/calibration/I3Calibration.h>
#include "I3TankCalibrationBackwardsCompat.h"

I3Calibration::I3Calibration()
  : TWRGlobalT0(0), TWRI3TimeOffset(0) 
{ }

I3Calibration::~I3Calibration() 
{ }

template <class Archive>
void 
I3Calibration::serialize(Archive& ar, unsigned version)
{
  if (version>i3calibration_version_)
    log_fatal("Attempting to read version %u from file but running version %u of I3Calibration class.",version,i3calibration_version_);

  ar & make_nvp("I3FrameObject", base_object<I3FrameObject>(*this));
  ar & make_nvp("domcal",domCal);
  ar & make_nvp("amandacal",amandaCal);
  if(version == 1)
    {
      std::map<TankKey, I3TankCalibrationBackwardsCompat> garbage;
      ar & make_nvp("tankcal",garbage);
    }
  if(version > 1)
    {
      ar & make_nvp("vemcal",vemCal);
    }
  if(version > 2)
    {
      ar & make_nvp("twrcal",twrCal);
      ar & make_nvp("TWRGlobalT0",TWRGlobalT0);
      ar & make_nvp("TWRI3TimeOffset",TWRI3TimeOffset);
    }
  ar & make_nvp("StartTime",startTime);
  ar & make_nvp("EndTime",endTime);
}

I3_SERIALIZABLE(I3Calibration);

