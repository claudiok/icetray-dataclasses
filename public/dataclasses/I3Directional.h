#ifndef I3DIRECTIONAL_H
#define I3DIRECTIONAL_H

#include "Rtypes.h"

class I3Directional 
{
 private:
  Double_t fTheta;
  Double_t fPhi;
 public:
  virtual Bool_t IsDirectional() const {return true;}

  virtual Double_t Theta() const {return fTheta;}
  virtual void Theta(Double_t theta) {fTheta = theta;}

  virtual Double_t Phi() const {return fPhi;}
  virtual void Phi(Double_t phi) {fPhi = phi;}

  virtual void CopyTo(I3Position& destination)
    {
      I3Directional* directional = dynamic_cast<I3Directional*>(&destination);
      if(directional)
	{
	  directional->fTheta = fTheta;
	  directional->fPhi = fPhi;
	}
    }

  ClassDef(I3Directional,1);
};

#endif // I3DIRECTIONAL
