#ifndef I3STARTING_H
#define I3STARTING_H

#include <cmath>
#include "I3Units.h"
#include "I3Particle.h"

#include "NanPolicy.h"

class I3Starting{
 private:
  Double_t fStartX;
  Double_t fStartY;
  Double_t fStartZ;
  Double_t fStartT;
  Double_t fZenith;
  Double_t fAzimuth;
 public:
  Bool_t IsStarting() const {return true;}
  Bool_t IsStopping() const {return false;}
  Bool_t IsDirectional() const {return true;}

  Double_t StartX() const {return fStartX;}
  void StartX(Double_t startx){fStartX = startx;}

  Double_t StartY() const {return fStartY;}
  void StartY(Double_t starty){fStartY = starty;}
  
  Double_t StartZ() const {return fStartZ;}
  void StartZ(Double_t startz) {fStartZ = startz;}

  Double_t StartT() const {return fStartT;}
  void StartT(Double_t startt) {fStartT = startt;}

  Double_t X() const {return fStartX;}
  void X(Double_t) {return;}

  Double_t Y() const {return fStartY;}
  void Y(Double_t) {return;}

  Double_t Z() const {return fStartZ;}
  void Z(Double_t){return;}

  Double_t T() const {return fStartT;}
  void T(Double_t){return;}

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
  void StopY(Double_t) {return;}

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

 protected:

  ClassDef(I3Starting,1)
};

#endif //I3STARTING_H
