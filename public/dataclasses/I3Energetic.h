/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Energetic.h,v 1.2 2004/04/22 15:55:44 pretz Exp $
 *
 * @file I3Energetic.h
 * @version $Revision: 1.2 $
 * @date $Date: 2004/04/22 15:55:44 $
 * @author 
 *
 * @todo
 *
 */
#ifndef I3ENERGETIC_H
#define I3ENERGETIC_H

#include "Rtypes.h"

/**
 * The energy part of tracks and cascades, should they have a valid energy
 */
class I3Energetic
{
 private:
  Double_t fEnergy;
 public:
  /**
   * indicates that this particle has a valid energy
   */
  Bool_t IsEnergetic() const {return true;}

  /**
   * gives the energy of the particle.
   */
  Double_t Energy() const {return fEnergy;}

  /**
   * sets the energy of the track
   */
  void Energy(Double_t energy){fEnergy = energy;}

  /**
   * copies all this particles data to destination if a dynamic cast to
   * I3Energetic succeeds
   */
  void CopyTo(I3Particle& destination) const
    {
      I3Energetic* energetic = dynamic_cast<I3Energetic*>(&destination);
      if(energetic)
	{
	  energetic->fEnergy = fEnergy;
	}
    }

 private:
  // ROOT macro
  ClassDef(I3Energetic,1);
};

#endif // I3ENERGETIC_H
