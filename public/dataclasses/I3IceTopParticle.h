/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3IceTopParticle.h,v 1.1 2004/08/02 19:59:58 blaufuss Exp $
 *
 * @file I3IceTopParticle.h
 * @version $Revision: 1.1 $
 * @date $Date: 2004/08/02 19:59:58 $
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
  virtual Bool_t IsObservable() const {return kTRUE;}

  /**
   * indicates that this track is not InIce.
   */
  virtual Bool_t IsInIce() const {return kFALSE;}

  /**
   * indicates that this track is IceTop.
   */
  virtual Bool_t IsIceTop() const {return kTRUE;}

  
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
 private:
  //ROOT macro
  ClassDef(I3IceTopParticle,1);
};

/**
 * pointer type to insulate users from memory management issues
 */
typedef PtrPolicy<I3IceTopParticle>::ThePolicy I3IceTopParticlePtr;

#endif //I3ICETOPPARTICLE_H
