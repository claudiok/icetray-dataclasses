#ifndef I3DIRECTIONAL_H
#define I3DIRECTIONAL_H

#include "Rtypes.h"

class I3Directional 
{
 private:
  Double_t fZenith;
  Double_t fAzimuth;
 public:
  virtual Bool_t IsDirectional() const {return true;}

  virtual Double_t Zenith() const {return fZenith;}
  virtual void Zenith(Double_t zenith) {fZenith = zenith;}

  virtual Double_t Azimuth() const {return fAzimuth;}
  virtual void Azimuth(Double_t azimuth) {fAzimuth = azimuth;}

  virtual void CopyTo(I3Position& destination)
    {
      I3Directional* directional = dynamic_cast<I3Directional*>(&destination);
      if(directional)
	{
	  directional->fZenith = fZenith;
	  directional->fAzimuth = fAzimuth;
	}
    }

  ClassDef(I3Directional,1);
};

#endif // I3DIRECTIONAL
