/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3TopShower.h,v 1.1 2004/08/03 18:06:17 blaufuss Exp $
 *
 * @file I3TopShower.h
 * @version $Revision: 1.1 $
 * @date $Date: 2004/08/03 18:06:17 $
 * @author blaufuss
  */

#ifndef I3TOPSHOWER_H
#define I3TOPSHOWER_H

#include "Rtypes.h"
#include "I3Particle.h"

/**
 * @brief Represents a particle which can appear in the IceTop array
 */
class I3TopShower : public I3Particle{
 public:
  /**
   * indicates that the particle is not an observable particle
   */
  virtual Bool_t IsObservable() const {return true;}
   
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


#endif
