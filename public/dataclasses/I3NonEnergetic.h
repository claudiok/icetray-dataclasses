/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3NonEnergetic.h,v 1.3 2004/04/23 21:10:25 deyoung Exp $
 *
 * @file I3NonEnergetic.h
 * @version $Revision: 1.3 $
 * @date $Date: 2004/04/23 21:10:25 $
 * @author pretz
 *
 * @todo
 *
 */
#ifndef I3NONENERGETIC_H
#define I3NONENERGETIC_H

#include "Rtypes.h"
#include <cmath>
#include "NanPolicy.h"

/**
 * This is the 'Energy' part of an I3Track or I3Cascade implementation.  This 
 * class represents a particle that doesn't have any energy information.
 */
class I3NonEnergetic
{
 public:
  /**
   * Indicates that the particle has no energy information.
   */
  Bool_t HasEnergy() const {return false;}

  /**
   * Shouldn't be used.  Calls fatal.
   */
  Double_t Energy() const 
    {
      NanPolicy::Fatal();
      return NAN;
    }

  /**
   * doesn't do anything.  There's nothing to copy.
   */
  void CopyTo(I3Particle&) const {}

 private:
  //ROOT macro
  ClassDef(I3NonEnergetic,1);

};

#endif // I3ENERGETIC_H
