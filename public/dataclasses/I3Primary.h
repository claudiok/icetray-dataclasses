/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Primary.h,v 1.9.4.2 2005/02/04 06:11:43 troy Exp $
 *
 * @file I3Primary.h
 * @version $Revision: 1.9.4.2 $
 * @date $Date: 2005/02/04 06:11:43 $
 * @author pretz
  */

#ifndef I3PRIMARY_H
#define I3PRIMARY_H

#include "dataclasses/StoragePolicy.h"
#include "I3Particle.h"

/**
 * @brief Represents a particle which induces an event in the detector.
 */
class I3Primary : public I3Particle{
 public:
  /**
   * indicates that the particle is not an observable particle
   */
  virtual Bool_t IsObservable() const {return false;}
   
  /**
   * indicates whether the particle has a core position, and so
   * asking CoreX, and CoreY and CoreT is legit.
   */
  virtual Bool_t IsCoreLocalized() const = 0;

  /**
   * indicates whether the particle has a inice position, and so
   * asking X, Y, Z and T is legit.
   */
  virtual Bool_t IsLocalized() const = 0;

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
  ClassDef(I3Primary,1);
};


#endif
