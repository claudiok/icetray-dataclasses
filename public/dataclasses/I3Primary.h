/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Primary.h,v 1.7.2.1 2004/07/29 18:56:57 ehrlich Exp $
 *
 * @file I3Primary.h
 * @version $Revision: 1.7.2.1 $
 * @date $Date: 2004/07/29 18:56:57 $
 * @author pretz
  */

#ifndef I3PRIMARY_H
#define I3PRIMARY_H

#include "Rtypes.h"
#include "I3Particle.h"

/**
 * @brief Represents a particle which induces an event in the detector.
 * @todo implement fatal calls
 */
class I3Primary : public I3Particle{
 public:
  /**
   * indicates that the particle is not an observable particle
   */
  virtual Bool_t IsObservable() const {return false;}
   
  /**
   * indicates whether or not the particle has a valid energy
   */
  virtual Bool_t HasEnergy() const = 0;

  /**
   * indicatess that the particle has a core position, and so
   * asking CoreX, and CoreY and CoreT is legit.
   */
  virtual Bool_t HasCorePosition() const = 0;

  /**
   * the core X position of the particle
   */
  virtual Double_t CoreX() const =0;

  /**
   * the position of the core y position of the particle
   */
  virtual Double_t CoreY() const =0;

  /**
   * the time the particle was at CoreX and CoreY
   */
  virtual Double_t CoreT() const =0;

  /**
   * gives the energy of the particle
   */
  virtual Double_t Energy() const = 0;

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
