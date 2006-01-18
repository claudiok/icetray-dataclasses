/**
 * copyright  (C) 2004
 * the icecube collaboration
 * @version $Id$
 * @file I3InIceParticle.h
 * @date $Date$
 */

#ifndef I3INICEPARTICLE_H_INCLUDED
#define I3INICEPARTICLE_H_INCLUDED

#include "dataclasses/physics/I3Particle.h"

/**
 * @brief This class is a base class for the different particles that can 
 * appear in the physical detector (as opposed to Primaries).
 */
class I3InIceParticle : public I3Particle
{
 public:
  virtual ~I3InIceParticle();
  /**
   * indicates that this track is observable.
   */
  virtual bool IsObservable() const {return true;}

  /**
   * indicates that this track is InIce.
   */
  virtual bool IsInIce() const {return true;}

  /**
   * indicates that this track is not IceTop.
   */
  virtual bool IsIceTop() const {return false;}

  
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
  virtual const I3Position& GetPos() const = 0;

  /**
   * Gives a T along the track, corresponding to X,Y and Z
   */
  virtual double GetT() const = 0;
 private:
  friend class boost::serialization::access;

  template <class Archive>
  void serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3Particle",base_object<I3Particle>(*this));
  }
  //ROOT macro
  //ClassDef(I3InIceParticle,1);
};

BOOST_IS_ABSTRACT(I3InIceParticle);

/**
 * pointer type to insulate users from memory management issues
 */
typedef shared_ptr<I3InIceParticle>  I3InIceParticlePtr;

#endif //I3INICEPARTICLE_H_INCLUDED
