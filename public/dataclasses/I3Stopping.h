#ifndef I3STOPPING_H
#define I3STOPPING_H

#include <cmath>
#include "I3Units.h"
#include "NanPolicy.h"

class I3Stopping{
 private:
  Double_t fStopX;
  Double_t fStopY;
  Double_t fStopZ;
  Double_t fStopT;
  Double_t fZenith;
  Double_t fAzimuth;
 public:
  Bool_t IsStopping() const {return true;}
  Bool_t IsStarting() const {return false;}
  Bool_t IsDirectional() const {return true;}

  Double_t StartX() const 
    {
      NanPolicy::Fatal();
      return NAN;
    }
  void StartX(Double_t)
    {
      NanPolicy::Fatal();
    }

  Double_t StartY() const     
    {
      NanPolicy::Fatal();
      return NAN;
    }

  void StartY(Double_t)
    {
      NanPolicy::Fatal();
    }
  
  Double_t StartZ() const 
    {
      NanPolicy::Fatal();
      return NAN;
    }
  
  void StartZ(Double_t) 
    {
      NanPolicy::Fatal();
    }

  Double_t StartT() const
    {
      NanPolicy::Fatal();
      return NAN;
    }
  void StartT(Double_t) 
    {
      NanPolicy::Fatal();
    }


  Double_t X() const {return fStopX;}
  void X(Double_t) {return;}

  Double_t Y() const {return fStopY;}
  void Y(Double_t) {return;}

  Double_t Z() const {return fStopZ;}
  void Z(Double_t){return;}

  Double_t T() const {return fStopT;}
  void T(Double_t){return;}

  Double_t Zenith() const {return fZenith;}
  void Zenith(Double_t theta){fZenith = theta;}

  Double_t Azimuth() const {return fAzimuth;}
  void Azimuth(Double_t phi){fAzimuth = phi;}

  Double_t Length() const {return INFINITY;}
  void Length(Double_t) {return;}

  Double_t StopX() const {return fStopX;}
  void StopX(Double_t stopx) {fStopX = stopx;}

  Double_t StopY() const {return fStopX;}
  void StopY(Double_t stopy) {fStopY = stopy;}

  Double_t StopZ() const {return fStopX;}
  void StopZ(Double_t stopz) {fStopZ = stopz;}

  Double_t StopT() const {return fStopT;}
  void StopT(Double_t stopt) {fStopT = stopt;}

  Double_t Speed() const {return 300000000 * I3Units::m / I3Units::s;}
  void Speed(Double_t) {return;}

  void CopyTo(I3Particle& destination) const
    {
      I3Stopping* stopping = dynamic_cast<I3Stopping*>(&destination);
      if(stopping){
	stopping->fStopX = fStopX;
	stopping->fStopY = fStopY;
	stopping->fStopZ = fStopZ;
	stopping->fStopT = fStopT;
	stopping->fZenith = fZenith;
	stopping->fAzimuth = fAzimuth;
      }
    }

  ClassDef(I3Stopping,1)
};

#endif //I3STOPPING_H
