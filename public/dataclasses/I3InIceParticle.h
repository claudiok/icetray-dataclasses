/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3InIceParticle.h,v 1.2 2005/04/04 15:49:25 pretz Exp $
 *
 * @file I3InIceParticle.h
 * @version $Revision: 1.2 $
 * @date $Date: 2005/04/04 15:49:25 $
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
  virtual bool IsObservable() const {return kTRUE;}

  /**
   * indicates that this track is InIce.
   */
  virtual bool IsInIce() const {return kTRUE;}

  /**
   * indicates that this track is not IceTop.
   */
  virtual bool IsIceTop() const {return kFALSE;}

  
  /**
   * indicates that this particle is a Cascade, and so dynamic casting to
   * I3Cascade should be ok
   */
  virtual bool IsCascade() = 0;

  /**
   * indicates that this particle is a track and so dynamic casting to I3Track
   * should be ok
   */
  virtual bool IsTrack() = 0;

  /**
   * Gives an position along the track, at time T.
   */
  virtual I3Position GetPos() const = 0;

  /**
   * Gives a T along the track, corresponding to X,Y and Z
   */
  virtual double GetT() const = 0;
 private:
  //ROOT macro
  ClassDef(I3InIceParticle,1);
};

/**
 * pointer type to insulate users from memory management issues
 */
typedef PtrPolicy<I3InIceParticle>::ThePolicy I3InIceParticlePtr;

#endif //I3INICEPARTICLE_H
