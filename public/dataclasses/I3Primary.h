/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Primary.h,v 1.9 2004/07/26 13:53:55 pretz Exp $
 *
 * @file I3Primary.h
 * @version $Revision: 1.9 $
 * @date $Date: 2004/07/26 13:53:55 $
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
  virtual Bool_t IsObservable() const {return false;}
   
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
  ClassDef(I3Primary,1);
};


#endif
