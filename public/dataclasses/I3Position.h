#ifndef I3POSITION_H
#define I3POSITION_H

#include "TObject.h"

class I3Position : public TObject
{
 private:
  double fX;
  double fY;
  double fZ;
  double fT;
 public:
  I3Position() : fX(0),fY(0),fZ(0),fT(0){}
  I3Position(double x,double y,double z,double t) :fX(x),fY(y),fZ(z),fT(0) {}

  double X() {return fX;}
  void X(double x) {fX = x;}

  double Y() {return fY;}
  void Y(double y) {fY = y;}

  double Z() {return fZ;}
  void Z(double z) {fZ = z;}

  double T() {return fT;}
  void T(double t) {fT = t;}
 private:
  ClassDef(I3Position,1);
};

#endif // I3POSITION
