#ifndef I3CONTAINED_H
#define I3CONTAINED_H

#include <cmath>

class I3Contained{
 private:
  Double_t fStartX;
  Double_t fStartY;
  Double_t fStartZ;
  Double_t fStartT;
  Double_t fZenith;
  Double_t fAzimuth;
  Double_t fLength;
 public:
  Bool_t IsStarting() const {return true;}
  Bool_t IsStopping() const {return true;}
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

  Double_t Length() const {return fLength;}
  void Length(Double_t length) {fLength = length;}

  Double_t StopX() const {
    return fStartX + fLength * sin(fZenith) * cos (fAzimuth);
  }
  void StopX(Double_t) {return;}

  Double_t StopY() const 
    {
      return fStartX + fLength * sin(fZenith) * sin(fAzimuth);
    }
  void StopY(Double_t) {return;}

  Double_t StopZ() const 
    {
      return fStartZ + fLength * cos(fZenith);
    }
  void StopZ(Double_t) {return;}

  Double_t StopT() const 
    {
      return fStartT + fLength / Speed();
    }
  void StopT(Double_t) {return;}

  Double_t Speed() const {return 300000000 * I3Units::m / I3Units::s;}

  void Speed(Double_t) {return;}

  void CopyTo(I3Particle& destination) const
    {
      I3Contained* contained = dynamic_cast<I3Contained*>(&destination);
      if(contained){
	contained->fStartX = fStartX;
	contained->fStartY = fStartY;
	contained->fStartZ = fStartZ;
	contained->fStartT = fStartT;
	contained->fAzimuth = fAzimuth;
	contained->fZenith = fZenith;
	contained->fLength = fLength;
      }
    }

  ClassDef(I3Contained,1)
};

#endif //I3CONTAINED_H
