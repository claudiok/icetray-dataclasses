#ifndef I3LOCALIZED_H
#define I3LOCALIZED_H

#include "I3Cascade.h"

class I3Localized{
 private:
  double fX;
  double fY;
  double fZ;
  double fT;
 public:
  virtual bool IsLocalized() const { return true;}

  double X() const{ return fX;}
  void X(double x) {fX = x;}

  double Y() const{return fY;}
  void Y(double y) {fY = y;}

  double Z() const{return fZ; }
  void Z(double z) {fZ = z;}

  double T() const{return fT;}
  void T(double t){fT = t;}

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
