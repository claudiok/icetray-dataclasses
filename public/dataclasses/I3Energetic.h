/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file I3Energetic.h
 * @version $Revision: 1.7 $
 * @date $Date$
 * @author pretz
 */
#ifndef I3ENERGETIC_H
#define I3ENERGETIC_H

#include "Rtypes.h"
#include "I3Particle.h"

/**
 * @brief The energy part of tracks and cascades, should they have a valid 
 * energy
 */
class I3Energetic
{
 private:

  double energy_;

 public:
  /**
   * indicates that this particle has a valid energy
   */
  bool HasEnergy() const {return true;}

  /**
   * gives the energy of the particle.
   */
  double GetEnergy() const {return energy_;}

  /**
   * sets the energy of the track
   */
  void SetEnergy(double energy){energy_ = energy;}

  /**
   * copies all this particles data to destination if a dynamic cast to
   * I3Energetic succeeds
   */
  void CopyTo(I3Particle& destination) const
    {
      I3Energetic* energetic = dynamic_cast<I3Energetic*>(&destination);
      if(energetic)
	{
	  energetic->energy_ = energy_;
	}
    }

  virtual void ToStream(ostream& o) const
    {
      o<<"Energy:"<<energy_<<"\n";
    }

 private:

  friend class boost::serialization::access;

  template <class Archive>
  void serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("Energy", energy_);
  }

  // ROOT macro
  ClassDef(I3Energetic,1);
};

#endif // I3ENERGETIC_H
