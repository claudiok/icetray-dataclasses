#ifndef I3NONENERGETIC_H
#define I3NONENERGETIC_H

#include "Rtypes.h"
#include <cmath>
#include "NanPolicy.h"

class I3NonEnergetic
{
 public:
  Bool_t IsEnergetic() const {return false;}

  Double_t Energy() const 
    {
      NanPolicy::Fatal();
      return NAN;
    }

  void CopyTo(I3Particle&) const {}

  ClassDef(I3NonEnergetic,1);

};

#endif // I3ENERGETIC_H
