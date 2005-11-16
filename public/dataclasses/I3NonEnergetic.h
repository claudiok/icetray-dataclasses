/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file I3NonEnergetic.h
 * @version $Revision: 1.8 $
 * @date $Date$
 * @author pretz
 */
#ifndef I3NONENERGETIC_H
#define I3NONENERGETIC_H

#include "dataclasses/I3Particle.h"
#include "Rtypes.h"
#include <cmath>

/**
 * @brief This is the 'Energy' part of an I3Track or I3Cascade implementation. 
 *  This class represents a particle that doesn't have any energy information.
 */
class I3NonEnergetic
{
 public:
  /**
   * Indicates that the particle has no energy information.
   */
  bool HasEnergy() const {return false;}

  /**
   * doesn't do anything.  There's nothing to copy.
   */
  void CopyTo(I3Particle&) const {}

  virtual void ToStream(ostream& o) const
    {
      o<<"Energy: Non-energetic\n";
    }

  virtual ~I3NonEnergetic();

 private:

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);

  //ROOT macro
  //ClassDef(I3NonEnergetic,1);

};

#endif // I3ENERGETIC_H
