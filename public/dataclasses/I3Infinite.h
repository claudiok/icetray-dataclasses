#ifndef I3INFINITE_H
#define I3INFINITE_H

#include <cmath>
#include "I3Units.h"
#include "NanPolicy.h"

class I3Infinite{
 private:
  Double_t fX;
  Double_t fY;
  Double_t fZ;
  Double_t fT;
  Double_t fZenith;
  Double_t fAzimuth;
 public:
  Bool_t IsStarting() const {return false;}
  Bool_t IsStopping() const {return false;}
  Bool_t IsDirectional() const {return true;}

  Double_t StartX() const 
    {
      NanPolicy::Fatal();
      return NAN;
    }
  void StartX(Double_t startx)
    {
      NanPolicy::Fatal();
    }

  Double_t StartY() const 
    {
      NanPolicy::Fatal();
      return NAN;
    }
  void StartY(Double_t starty)
    {
      NanPolicy::Fatal();
    }
  
  Double_t StartZ() const 
    {
      NanPolicy::Fatal();
      return NAN;
    }
  void StartZ(Double_t startz) 
    {
      NanPolicy::Fatal();
    }

  Double_t StartT() const 
    {
      NanPolicy::Fatal();
      return NAN;
    }
  void StartT(Double_t startt) 
    {
      NanPolicy::Fatal();
    }

  Double_t X() const {return fX;}
  void X(Double_t x) {fX = x;}

  Double_t Y() const {return fY;}
  void Y(Double_t y) {fY = y;}

  Double_t Z() const {return fZ;}
  void Z(Double_t z){fZ = z;}

  Double_t T() const {return fT;}
  void T(Double_t t){fT = t;}

  Double_t Zenith() const {return fZenith;}
  void Zenith(Double_t theta){fZenith = theta;}

  Double_t Azimuth() const {return fAzimuth;}
  void Azimuth(Double_t phi){fAzimuth = phi;}

  Double_t Length() const {return INFINITY;}
  void Length(Double_t) {return;}

  Double_t StopX() const 
    {
      NanPolicy::Fatal();
      return NAN;
    }
  void StopX(Double_t) 
    {
      NanPolicy::Fatal();
    }

  Double_t StopY() const 
    {
      NanPolicy::Fatal();
      return NAN;
    }
  void StopY(Double_t) 
    {
      NanPolicy::Fatal();
    }

  Double_t StopZ() const 
    {
      NanPolicy::Fatal();
      return NAN;
    }
  void StopZ(Double_t) 
    {
      NanPolicy::Fatal();
    }

  Double_t StopT() const 
    {
      NanPolicy::Fatal();
      return NAN;
    }
  void StopT(Double_t)
    {
      NanPolicy::Fatal();
    }

  Double_t Speed() const {return 300000000 * I3Units::m / I3Units::s;}
  void Speed(Double_t) {return;}

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
