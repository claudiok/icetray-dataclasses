#ifndef I3NONENERGETIC_H
#define I3NONENERGETIC_H

#include "Rtypes.h"
#include <cmath>
#include "NanPolicy.h"

class I3NonEnergetic
{
 public:
  bool IsEnergetic() const {return false;}

  double Energy() const 
    {
      NanPolicy::Fatal();
      return NAN;
    }
  void Energy(double energy) 
    {
      NanPolicy::Fatal();
    }

  void CopyTo(I3Particle&) const {}

  ClassDef(I3NonEnergetic,1);

};

#endif // I3ENERGETIC_H
