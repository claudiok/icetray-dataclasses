#ifndef I3STARTING_H
#define I3STARTING_H

#include <cmath>
#include "I3Units.h"
#include "I3Particle.h"

class I3Starting{
 private:
  double fStartX;
  double fStartY;
  double fStartZ;
  double fStartT;
  double fZenith;
  double fAzimuth;
 public:
  bool IsStarting() const {return true;}
  bool IsStopping() const {return false;}
  bool IsDirectional() const {return true;}

  double StartX() const {return fStartX;}
  void StartX(double startx){fStartX = startx;}

  double StartY() const {return fStartY;}
  void StartY(double starty){fStartY = starty;}
  
  double StartZ() const {return fStartZ;}
  void StartZ(double startz) {fStartZ = startz;}

  double StartT() const {return fStartT;}
  void StartT(double startt) {fStartT = startt;}

  double X() const {return fStartX;}
  void X(double) {return;}

  double Y() const {return fStartY;}
  void Y(double) {return;}

  double Z() const {return fStartZ;}
  void Z(double){return;}

  double T() const {return fStartT;}
  void T(double){return;}

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

  void CopyTo(I3Particle& destination) const{
    I3Starting* starting = dynamic_cast<I3Starting*>(&destination);
    if(starting){
      starting->fStartX = fStartX;
      starting->fStartY = fStartY;
      starting->fStartZ = fStartZ;
      starting->fZenith = fZenith;
      starting->fAzimuth = fAzimuth;
    }
  }

  ClassDef(I3Starting,1)
};

#endif //I3STARTING_H
