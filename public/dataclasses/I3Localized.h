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

  virtual double X() const{ return fX;}
  virtual void X(double x) {fX = x;}

  virtual double Y() const{return fY;}
  virtual void Y(double y) {fY = y;}

  virtual double Z() const{return fZ; }
  virtual void Z(double z) {fZ = z;}

  virtual double T() const{return fT;}
  virtual void T(double t){fT = t;}

  ClassDef(I3Localized,1);
};

#endif //I3LOCALIZED_H
