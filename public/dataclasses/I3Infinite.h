#ifndef I3INFINITE_H
#define I3INFINITE_H

#include <cmath>
#include "I3Units.h"

class I3Infinite{
 private:
  double fX;
  double fY;
  double fZ;
  double fT;
  double fZenith;
  double fAzimuth;
 public:
  bool IsStarting() const {return false;}
  bool IsStopping() const {return false;}
  bool IsDirectional() const {return true;}

  double StartX() const {return NAN;}
  void StartX(double startx){return;}

  double StartY() const {return NAN;}
  void StartY(double starty){return;}
  
  double StartZ() const {return NAN;}
  void StartZ(double startz) {return;}

  double StartT() const {return NAN;}
  void StartT(double startt) {return;}

  double X() const {return fX;}
  void X(double x) {fX = x;}

  double Y() const {return fY;}
  void Y(double y) {fY = y;}

  double Z() const {return fZ;}
  void Z(double z){fZ = z;}

  double T() const {return fT;}
  void T(double t){fT = t;}

  double Zenith() const {return fZenith;}
  void Zenith(double theta){fZenith = theta;}

  double Azimuth() const {return fAzimuth;}
  void Azimuth(double phi){fAzimuth = phi;}

  double Length() const {return INFINITY;}
  void Length(double) {return;}

  double StopX() const {return NAN;}
  void StopX(double) {return;}

  double StopY() const {return NAN;}
  void StopY(double) {return;}

  double StopZ() const {return NAN;}
  void StopZ(double) {return;}

  double StopT() const {return NAN;}
  void StopT(double) {return;}

  double Speed() const {return 300000000 * I3Units::m / I3Units::s;}
  void Speed(double) {return;}

  ClassDef(I3Infinite,1)
};

#endif //I3INFINITE_H
