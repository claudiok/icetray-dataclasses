/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Primary.h,v 1.11 2005/04/04 15:49:25 pretz Exp $
 *
 * @file I3Primary.h
 * @version $Revision: 1.11 $
 * @date $Date: 2005/04/04 15:49:25 $
 * @author pretz
  */

#ifndef I3PRIMARY_H
#define I3PRIMARY_H

#include "Rtypes.h"
#include "I3Particle.h"

/**
 * @brief Represents a particle which induces an event in the detector.
 */
class I3Primary : public I3Particle{
 public:
  /**
   * indicates that the particle is not an observable particle
   */
  virtual bool IsObservable() const {return false;}
   
  /**
   * indicates whether the particle has a core position, and so
   * asking CoreX, and CoreY and CoreT is legit.
   */
  virtual bool IsCoreLocalized() const = 0;

  /**
   * indicates whether the particle has a inice position, and so
   * asking X, Y, Z and T is legit.
   */
  virtual bool IsLocalized() const = 0;

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
