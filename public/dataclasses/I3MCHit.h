/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3MCHit.h,v 1.16.4.2 2005/02/04 21:49:05 troy Exp $
 *
 * @file I3MCHit.h
 * @version $Revision: 1.16.4.2 $
 * @date $Date: 2005/02/04 21:49:05 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 */
#ifndef I3MCHIT_H
#define I3MCHIT_H

#include "I3Hit.h"
#include "StoragePolicy.h"

/**
 * @brief Derived I3Hit class with additional 'Weight' and 'Parent
 * track' info
 * 
 * This class records the true (simulated) time at which a
 * photoelectron was produced.  In addition to the time, it contains
 * the identity of the track which was responsible for the hit, and a
 * statistical weight to assign to the hit (default 1).
 */
class I3MCHit : public I3Hit
{
  Float_t  fWeight;
  Int_t    fParticleID;

 public:
  /**
   * constructor
   */
  I3MCHit() {fWeight = 0; fParticleID=0;}

  /**
   * copy constructor just uses assignment operator
   */
  I3MCHit(const I3MCHit &rhs) { *this = rhs; } 

  /**
   * assignment operator is a member-wise assignment
   */
  const I3MCHit& operator=(const I3MCHit &rhs) { 
    if (this == &rhs) return *this; // check for assignment to self
    I3Hit::operator=(rhs); // call base class assignment operator
    fWeight = rhs.fWeight;
    fParticleID = rhs.fParticleID; 
    return *this;
  }

  /**
   * @return the weight contributed by this MCHit
   */
  Float_t GetWeight() const { return fWeight; }

  /**
   * @param weight the new weight for the hit
   */
  void SetWeight(Float_t weight) { fWeight = weight; }

  /**
   * @return the track number which caused this hit
   */
  Int_t GetParticleID() const { return fParticleID; }

  /**
   * @param ParticleID set the track which caused this hit
   */
  void SetParticleID(Int_t ParticleID) { fParticleID = ParticleID; }

 private:

};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3MCHit>::ThePolicy I3MCHitPtr;

#endif

