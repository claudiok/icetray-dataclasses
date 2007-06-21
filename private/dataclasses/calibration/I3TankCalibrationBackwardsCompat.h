#ifndef I3TANKCALIBRATION_H_INCLUDED
#define I3TANKCALIBRATION_H_INCLUDED

#include "dataclasses/Utility.h"
//#include <icetray/serialization.h>

struct I3TankCalibrationBackwardsCompat
{

  double avgMuonPE;
  double avgMuonRisetime;
  double avgMuonWidth;
  template <class Archive>
  void serialize (Archive& ar, unsigned version){
    ar & make_nvp("AvgMuonPE",avgMuonPE);
    ar & make_nvp("AvgMuonRisetime",avgMuonRisetime);
    ar & make_nvp("AvgMuonWidth",avgMuonWidth);
  }
};
I3_SERIALIZABLE(I3TankCalibrationBackwardsCompat);

#endif //I3TANKCALIBRATION_H_INCLUDED