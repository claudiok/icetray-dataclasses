/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3InIceParticle.h,v 1.1.4.1 2005/02/04 21:51:03 troy Exp $
 *
 * @file I3InIceParticle.h
 * @version $Revision: 1.1.4.1 $
 * @date $Date: 2005/02/04 21:51:03 $
 * @author blaufuss
 */
#ifndef I3INICEPARTICLE_H
#define I3INICEPARTICLE_H

#include "dataclasses/I3Particle.h"

/**
 * @brief This class is a base class for the different particles that can 
 * appear in the physical detector (as opposed to Primaries).
 */
class I3InIceParticle : public I3Particle
{
 public:
  /**
   * indicates that this track is observable.
   */
  virtual Bool_t IsObservable() const {return kTRUE;}

  /**
   * indicates that this track is InIce.
   */
  virtual Bool_t IsInIce() const {return kTRUE;}

  /**
   * indicates that this track is not IceTop.
   */
  virtual Bool_t IsIceTop() const {return kFALSE;}

  
  /**
   * indicates that this particle is a Cascade, and so dynamic casting to
   * I3Cascade should be ok
   */
  virtual Bool_t IsCascade() = 0;

  /**
   * indicates that this particle is a track and so dynamic casting to I3Track
   * should be ok
   */
  virtual Bool_t IsTrack() = 0;

  /**
   * Gives an position along the track, at time T.
   */
  virtual I3Position GetPos() const = 0;

  /**
   * Gives a T along the track, corresponding to X,Y and Z
   */
  virtual Double_t GetT() const = 0;

};

/**
 * pointer type to insulate users from memory management issues
 */
typedef PtrPolicy<I3InIceParticle>::ThePolicy I3InIceParticlePtr;

#endif //I3INICEPARTICLE_H
