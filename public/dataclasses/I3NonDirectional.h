#ifndef I3NONDIRECTIONAL_H
#define I3NONDIRECTIONAL_H

#include "Rtypes.h"

class I3NonDirectional 
{
 public:
  virtual Bool_t IsDirectional() const {return true;}

  virtual Double_t Zenith() const {return NAN;}

  virtual Double_t Azimuth() const {return NAN;}

  void CopyTo(I3Particle&) const {}

  ClassDef(I3NonDirectional,1);
};

#endif // I3NONDIRECTIONAL
