#ifndef I3TANKCALIBRATION_H_INCLUDED
#define I3TANKCALIBRATION_H_INCLUDED

#include "dataclasses/Utility.h"

struct I3TankCalibration
{

  I3TankCalibration():
    avgMuonPE(NAN),
       avgMuonRisetime(NAN),
       avgMuonWidth(NAN)
  {};
  
  virtual ~I3TankCalibration();
   /**
   * ASME: average single muon equivalent 
   */
  double avgMuonPE;
   /**
   * Risetime of the the average muon pulse for this tank
   */
  double avgMuonRisetime;
   /**
   * Width of the the average muon pulse for this tank
   */
  double avgMuonWidth;
  

  template <class Archive> void serialize(Archive & ar, unsigned version);
  
};

I3_POINTER_TYPEDEFS(I3TankCalibration);

#endif //I3TANKCALIBRATION_H_INCLUDED
