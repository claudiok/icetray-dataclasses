#ifndef I3LOCALIZED_H
#define I3LOCALIZED_H

#include "I3Cascade.h"

class I3Localized{
 private:
  Double_t fX;
  Double_t fY;
  Double_t fZ;
  Double_t fT;
 public:
  virtual Bool_t IsLocalized() const { return true;}

  Double_t X() const{ return fX;}
  void X(Double_t x) {fX = x;}

  Double_t Y() const{return fY;}
  void Y(Double_t y) {fY = y;}

  Double_t Z() const{return fZ; }
  void Z(Double_t z) {fZ = z;}

  Double_t T() const{return fT;}
  void T(Double_t t){fT = t;}

  void CopyTo(I3Particle& destination)
    {
      I3Localized *localized = dynamic_cast<I3Localized*>(&destination);
      if(localized)
	{
	  localized->fX = fX;
	  localized->fY = fY;
	  localized->fZ = fZ;
	  localized->fT = fT;
	}
    }

  ClassDef(I3Localized,1);
};

#endif //I3LOCALIZED_H
