#ifndef I3POSITION_H
#define I3POSITION_H

#include "TObject.h"

class I3Position : public TObject
{
 private:
  Double_t fX;
  Double_t fY;
  Double_t fZ;
 public:
  I3Position() : fX(0),fY(0),fZ(0){}
  I3Position(Double_t x,Double_t y,Double_t z) :fX(x),fY(y),fZ(z){}

  Double_t X() {return fX;}
  void X(Double_t x) {fX = x;}

  Double_t Y() {return fY;}
  void Y(Double_t y) {fY = y;}

  Double_t Z() {return fZ;}
  void Z(Double_t z) {fZ = z;}

 private:
  ClassDef(I3Position,1);
};

#endif // I3POSITION
