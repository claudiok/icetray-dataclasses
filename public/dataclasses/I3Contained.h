#ifndef I3CONTAINED_H
#define I3CONTAINED_H

#include <cmath>

class I3Contained{
 private:
  double fStartX;
  double fStartY;
  double fStartZ;
  double fStartT;
  double fZenith;
  double fAzimuth;
  double fLength;
 public:
  bool IsStarting() const {return true;}
  bool IsStopping() const {return true;}
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

  double Length() const {return fLength;}
  void Length(double length) {fLength = length;}

  double StopX() const {
    return fStartX + fLength * sin(fZenith) * cos (fAzimuth);
  }
  void StopX(double) {return;}

  double StopY() const 
    {
      return fStartX + fLength * sin(fZenith) * sin(fAzimuth);
    }
  void StopY(double) {return;}

  double StopZ() const 
    {
      return fStartZ + fLength * cos(fZenith);
    }
  void StopZ(double) {return;}

  double StopT() const 
    {
      return fStartT + fLength / Speed();
    }
  void StopT(double) {return;}

  double Speed() const {return 300000000 * I3Units::m / I3Units::s;}

  void Speed(double) {return;}

  ClassDef(I3Contained,1)
};

#endif //I3CONTAINED_H
