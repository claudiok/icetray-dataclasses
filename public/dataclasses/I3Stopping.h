#ifndef I3STOPPING_H
#define I3STOPPING_H

#include <cmath>
#include "I3Units.h"

class I3Stopping{
 private:
  double fStopX;
  double fStopY;
  double fStopZ;
  double fStopT;
  double fZenith;
  double fAzimuth;
 public:
  bool IsStopping() const {return true;}
  bool IsStarting() const {return false;}
  bool IsDirectional() const {return true;}

  double StartX() const {return NAN;}
  void StartX(double){return;}

  double StartY() const {return NAN;}
  void StartY(double){return;}
  
  double StartZ() const {return NAN;}
  void StartZ(double) {return;}

  double StartT() const {return NAN;}
  void StartT(double) {return;}

  double X() const {return fStopX;}
  void X(double) {return;}

  double Y() const {return fStopY;}
  void Y(double) {return;}

  double Z() const {return fStopZ;}
  void Z(double){return;}

  double T() const {return fStopT;}
  void T(double){return;}

  double Zenith() const {return fZenith;}
  void Zenith(double theta){fZenith = theta;}

  double Azimuth() const {return fAzimuth;}
  void Azimuth(double phi){fAzimuth = phi;}

  double Length() const {return INFINITY;}
  void Length(double) {return;}

  double StopX() const {return fStopX;}
  void StopX(double stopx) {fStopX = stopx;}

  double StopY() const {return fStopX;}
  void StopY(double stopy) {fStopY = stopy;}

  double StopZ() const {return fStopX;}
  void StopZ(double stopz) {fStopZ = stopz;}

  double StopT() const {return fStopT;}
  void StopT(double stopt) {fStopT = stopt;}

  double Speed() const {return 300000000 * I3Units::m / I3Units::s;}
  void Speed(double) {return;}

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
