#ifndef I3TANKCALIBRATION_H_INCLUDED
#define I3TANKCALIBRATION_H_INCLUDED

#include "dataclasses/Utility.h"

struct I3TankCalibrationBackwardsCompat
{

  I3TankCalibrationBackwardsCompat():
    avgMuonPE(NAN),
       avgMuonRisetime(NAN),
       avgMuonWidth(NAN)
  {};
  
  virtual ~I3TankCalibrationBackwardsCompat();
  double avgMuonPE;
  double avgMuonRisetime;
  double avgMuonWidth;
  template <class Archive> void serialize(Archive & ar, unsigned version);
  
};

//I3_POINTER_TYPEDEFS(I3TankCalibration);
BOOST_CLASS_VERSION(I3TankCalibrationBackwardsCompat, 0);
#endif //I3TANKCALIBRATION_H_INCLUDED
