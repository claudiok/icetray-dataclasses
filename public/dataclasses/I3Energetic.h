/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Energetic.h,v 1.6.4.1 2005/01/26 03:59:37 troy Exp $
 *
 * @file I3Energetic.h
 * @version $Revision: 1.6.4.1 $
 * @date $Date: 2005/01/26 03:59:37 $
 * @author pretz
 */
#ifndef I3ENERGETIC_H
#define I3ENERGETIC_H

#include "dataclasses/StoragePolicy.h"

/**
 * @brief The energy part of tracks and cascades, should they have a valid 
 * energy
 */
class I3Energetic
{
 private:
  Double_t fEnergy;
 public:
  /**
   * indicates that this particle has a valid energy
   */
  Bool_t HasEnergy() const {return true;}

  /**
   * gives the energy of the particle.
   */
  Double_t GetEnergy() const {return fEnergy;}

  /**
   * sets the energy of the track
   */
  void SetEnergy(Double_t energy){fEnergy = energy;}

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

  virtual void ToStream(ostream& o) const
    {
      o<<"Energy:"<<fEnergy<<"\n";
    }

 private:
  // ROOT macro
  ClassDef(I3Energetic,1);
};

#endif // I3ENERGETIC_H
