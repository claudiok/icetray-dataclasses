#ifndef I3NONDIRECTIONAL_H
#define I3NONDIRECTIONAL_H

#include "Rtypes.h"

class I3NonDirectional 
{
 public:
  virtual bool IsNonDirectional() const {return true;}

  virtual double Theta() const {return NAN;}
  virtual void Theta(double theta) {return;}

  virtual double Phi() const {return NAN;}
  virtual void Phi(double phi) {return;}

  void CopyTo(I3Particle&) const {}

  ClassDef(I3NonDirectional,1);
};

#endif // I3NONDIRECTIONAL
