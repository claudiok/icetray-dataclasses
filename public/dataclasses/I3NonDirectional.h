#ifndef I3NONDIRECTIONAL_H
#define I3NONDIRECTIONAL_H

#include "Rtypes.h"

class I3NonDirectional 
{
 public:
  virtual Bool_t IsDirectional() const {return true;}

  virtual Double_t Theta() const {return NAN;}
  virtual void Theta(Double_t theta) {return;}

  virtual Double_t Phi() const {return NAN;}
  virtual void Phi(Double_t phi) {return;}

  void CopyTo(I3Particle&) const {}

  ClassDef(I3NonDirectional,1);
};

#endif // I3NONDIRECTIONAL
