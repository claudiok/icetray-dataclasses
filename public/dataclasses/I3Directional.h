#ifndef I3DIRECTIONAL_H
#define I3DIRECTIONAL_H

#include "Rtypes.h"

class I3Directional 
{
 private:
  double fTheta;
  double fPhi;
 public:
  virtual bool IsDirectional() const {return true;}

  virtual double Theta() const {return fTheta;}
  virtual void Theta(double theta) {fTheta = theta;}

  virtual double Phi() const {return fPhi;}
  virtual void Phi(double phi) {fPhi = phi;}

  ClassDef(I3Directional,1);
};

#endif // I3DIRECTIONAL
