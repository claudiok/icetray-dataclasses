/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3TopShower.h,v 1.3.4.1 2005/01/26 03:59:37 troy Exp $
 *
 * @file I3TopShower.h
 * @version $Revision: 1.3.4.1 $
 * @date $Date: 2005/01/26 03:59:37 $
 * @author blaufuss
  */

#ifndef I3TOPSHOWER_H
#define I3TOPSHOWER_H

#include "dataclasses/StoragePolicy.h"
#include "I3IceTopParticle.h"

/**
 * @brief Represents a particle which can appear in the IceTop array
 */
class I3TopShower : public I3IceTopParticle{
 public:
   
  /**
   * indicatess that the particle has a core position, and so
   * asking CoreX, and CoreY and CoreT is legit.
   */
  virtual Bool_t HasCorePosition() const = 0;

  /**
   * Copies over data from the source particle to this particle.
   * Only copies that data which the two have in common.
   */
  virtual void CopyFrom(const I3Particle& source)
    {
      source.CopyTo(*this);
    } 
  
 private:
  // ROOT macro
  ClassDef(I3TopShower,1);
};

/**
 * pointer type to insulate users from memory management
 */
typedef PtrPolicy<I3TopShower>::ThePolicy I3TopShowerPtr;

#endif
