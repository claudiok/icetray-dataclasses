/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3NonEnergetic.h,v 1.7.4.1 2005/01/26 03:59:37 troy Exp $
 *
 * @file I3NonEnergetic.h
 * @version $Revision: 1.7.4.1 $
 * @date $Date: 2005/01/26 03:59:37 $
 * @author pretz
 */
#ifndef I3NONENERGETIC_H
#define I3NONENERGETIC_H

#include "dataclasses/StoragePolicy.h"
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
  Bool_t HasEnergy() const {return false;}

  /**
   * doesn't do anything.  There's nothing to copy.
   */
  void CopyTo(I3Particle&) const {}

  virtual void ToStream(ostream& o) const
    {
      o<<"Energy: Non-energetic\n";
    }

 private:
  //ROOT macro
  ClassDef(I3NonEnergetic,1);

};

#endif // I3ENERGETIC_H
