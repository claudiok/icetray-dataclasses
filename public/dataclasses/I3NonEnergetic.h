#ifndef I3NONENERGETIC_H
#define I3NONENERGETIC_H

#include "Rtypes.h"
#include <cmath>

class I3NonEnergetic
{
 public:
  virtual bool IsEnergetic() const {return false;}

  virtual double Energy() const {return NAN;}

  ClassDef(I3NonEnergetic,1);

};

#endif // I3ENERGETIC_H
