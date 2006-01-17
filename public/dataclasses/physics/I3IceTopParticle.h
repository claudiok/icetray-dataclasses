/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file I3IceTopParticle.h
 * @version $Revision: 1.5 $
 * @date $Date$
 * @author blaufuss
 */
#ifndef I3ICETOPPARTICLE_H
#define I3ICETOPPARTICLE_H

#include "dataclasses/physics/I3Particle.h"

/**
 * @brief This class is a base class for the different particles that can 
 * appear in the physical detector (as opposed to Primaries).
 */
class I3IceTopParticle : public I3Particle
{
 public:
  virtual ~I3IceTopParticle();
  /**
   * indicates that this track is observable.
   */
  virtual bool IsObservable() const {return true;}

  /**
   * indicates that this track is not InIce.
   */
  virtual bool IsInIce() const {return false;}

  /**
   * indicates that this track is IceTop.
   */
  virtual bool IsIceTop() const {return true;}

  
 private:

  friend class boost::serialization::access;

  template <class Archive>
    void serialize(Archive& ar, unsigned version)
    {
      ar & make_nvp("I3IceTopParticle", base_object<I3Particle>(*this));
    }

  //ROOT macro
  //ClassDef(I3IceTopParticle,1);
};

BOOST_IS_ABSTRACT(I3IceTopParticle);

/**
 * pointer type to insulate users from memory management issues
 */
typedef shared_ptr<I3IceTopParticle>  I3IceTopParticlePtr;

#endif //I3ICETOPPARTICLE_H