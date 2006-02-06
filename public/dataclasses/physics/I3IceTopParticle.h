/**
 * copyright  (C) 2004
 * the icecube collaboration
 * @version $Id$
 * @file I3IceTopParticle.h
 * @date $Date$
 */

#ifndef I3ICETOPPARTICLE_H_INCLUDED
#define I3ICETOPPARTICLE_H_INCLUDED

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
      ar & make_nvp("I3Particle", base_object<I3Particle>(*this));
    }

  //ROOT macro
  //ClassDef(I3IceTopParticle,1);
};

I3_POINTER_TYPEDEFS(I3IceTopParticle);

#endif //I3ICETOPPARTICLE_H_INCLUDED
