#ifndef I3NONENERGETIC_H
#define I3NONENERGETIC_H

#include "Rtypes.h"
#include <cmath>

class I3NonEnergetic
{
 public:
  bool IsEnergetic() const {return false;}

  double Energy() const {return NAN;}
  void Energy(double energy) {return;}

  void CopyTo(I3Particle&) {}

  ClassDef(I3NonEnergetic,1);

};

#endif // I3ENERGETIC_H
