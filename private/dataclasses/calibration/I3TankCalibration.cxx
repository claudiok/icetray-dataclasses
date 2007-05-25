#include <icetray/serialization.h>
#include <dataclasses/calibration/I3TankCalibration.h>

I3TankCalibration::~I3TankCalibration() {}

template <class Archive>
void I3TankCalibration::serialize (Archive& ar, unsigned version)
{
  if (version>i3tankcalibration_version_)
    log_fatal("Attempting to read version %zu from file but running version %zu of I3TankCalibration class.",version,i3tankcalibration_version_);

  ar & make_nvp("AvgMuonPE",avgMuonPE);
  ar & make_nvp("AvgMuonRisetime",avgMuonRisetime);
  ar & make_nvp("AvgMuonWidth",avgMuonWidth);

}
I3_SERIALIZABLE(I3TankCalibration);
