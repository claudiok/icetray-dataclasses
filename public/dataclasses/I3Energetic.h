#ifndef I3ENERGETIC_H
#define I3ENERGETIC_H

#include "Rtypes.h"

class I3Energetic
{
 private:
  Double_t fEnergy;
 public:
  Bool_t IsEnergetic() const {return true;}

  Double_t Energy() const {return fEnergy;}
  void Energy(Double_t energy){fEnergy = energy;}

  void CopyTo(I3Particle& destination) const
    {
      I3Energetic* energetic = dynamic_cast<I3Energetic*>(&destination);
      if(energetic)
	{
	  energetic->fEnergy = fEnergy;
	}
    }

  ClassDef(I3Energetic,1);
};

#endif // I3ENERGETIC_H
