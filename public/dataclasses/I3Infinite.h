#ifndef I3INFINITE_H
#define I3INFINITE_H

#include <cmath>
#include "I3Units.h"
#include "NanPolicy.h"

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

  double StartX() const 
    {
      NanPolicy::Fatal();
      return NAN;
    }
  void StartX(double startx)
    {
      NanPolicy::Fatal();
    }

  double StartY() const 
    {
      NanPolicy::Fatal();
      return NAN;
    }
  void StartY(double starty)
    {
      NanPolicy::Fatal();
    }
  
  double StartZ() const 
    {
      NanPolicy::Fatal();
      return NAN;
    }
  void StartZ(double startz) 
    {
      NanPolicy::Fatal();
    }

  double StartT() const 
    {
      NanPolicy::Fatal();
      return NAN;
    }
  void StartT(double startt) 
    {
      NanPolicy::Fatal();
    }

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

  double StopX() const 
    {
      NanPolicy::Fatal();
      return NAN;
    }
  void StopX(double) 
    {
      NanPolicy::Fatal();
    }

  double StopY() const 
    {
      NanPolicy::Fatal();
      return NAN;
    }
  void StopY(double) 
    {
      NanPolicy::Fatal();
    }

  double StopZ() const 
    {
      NanPolicy::Fatal();
      return NAN;
    }
  void StopZ(double) 
    {
      NanPolicy::Fatal();
    }

  double StopT() const 
    {
      NanPolicy::Fatal();
      return NAN;
    }
  void StopT(double)
    {
      NanPolicy::Fatal();
    }

  double Speed() const {return 300000000 * I3Units::m / I3Units::s;}
  void Speed(double) {return;}

  void CopyTo(I3Particle& destination) const
    {
      I3Infinite* infinite = dynamic_cast<I3Infinite*>(&destination);
      if(infinite){
	infinite->fX = fX;
	infinite->fY = fY;
	infinite->fZ = fZ;
	infinite->fZenith = fZenith;
	infinite->fAzimuth = fAzimuth;
      }
    }

  ClassDef(I3Infinite,1)
};

#endif //I3INFINITE_H
