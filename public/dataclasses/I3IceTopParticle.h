/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3IceTopParticle.h,v 1.3 2005/04/04 15:49:25 pretz Exp $
 *
 * @file I3IceTopParticle.h
 * @version $Revision: 1.3 $
 * @date $Date: 2005/04/04 15:49:25 $
 * @author blaufuss
 */
#ifndef I3ICETOPPARTICLE_H
#define I3ICETOPPARTICLE_H

#include "dataclasses/I3Particle.h"

/**
 * @brief This class is a base class for the different particles that can 
 * appear in the physical detector (as opposed to Primaries).
 */
class I3IceTopParticle : public I3Particle
{
 public:
  /**
   * indicates that this track is observable.
   */
  virtual bool IsObservable() const {return kTRUE;}

  /**
   * indicates that this track is not InIce.
   */
  virtual bool IsInIce() const {return kFALSE;}

  /**
   * indicates that this track is IceTop.
   */
  virtual bool IsIceTop() const {return kTRUE;}

  
 private:
  //ROOT macro
  ClassDef(I3IceTopParticle,1);
};

/**
 * pointer type to insulate users from memory management issues
 */
typedef PtrPolicy<I3IceTopParticle>::ThePolicy I3IceTopParticlePtr;

#endif //I3ICETOPPARTICLE_H
