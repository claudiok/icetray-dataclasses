#ifndef I3ENERGETIC_H
#define I3ENERGETIC_H

#include "Rtypes.h"

class I3Energetic
{
 private:
  double fEnergy;
 public:
  virtual bool IsEnergetic() const {return true;}

  virtual double Energy() const {return fEnergy;}
  virtual void Energy(double energy){fEnergy = energy;}

  ClassDef(I3Energetic,1);
};

#endif // I3ENERGETIC_H
