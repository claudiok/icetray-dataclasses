#ifndef I3ENERGETIC_H
#define I3ENERGETIC_H

#include "Rtypes.h"

class I3Energetic
{
 private:
  double fEnergy;
 public:
  bool IsEnergetic() const {return true;}

  double Energy() const {return fEnergy;}
  void Energy(double energy){fEnergy = energy;}

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
