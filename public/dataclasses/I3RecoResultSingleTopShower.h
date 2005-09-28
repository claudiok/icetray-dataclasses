/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file I3RecoResultSingleTopShower.h
 * @version $Revision: 1.8 $
 * @date $Date$
 * @author Peter Niessen
 * @author dule
 */

#ifndef I3RECORESULTSINGLETOPSHOWER_H
#define I3RECORESULTSINGLETOPSHOWER_H

#include "dataclasses/I3RecoResultSingleParticle.h"

/**
 * @brief This is a reco result which just contains a single IceTop shower
 */
class I3RecoResultSingleTopShower : public I3RecoResultSingleParticle
{
  
 public:
  I3RecoResultSingleTopShower() { } //particle will automatically be "NULL" 
  virtual ~I3RecoResultSingleTopShower() { }
  
  /**
   * Retrieves the track in this reco result as a constant object
   */
  const I3ParticlePtr GetShower() const { 
    return I3RecoResultSingleParticle::GetParticle(); 
  }
  
  /**
   * Retrieves the track of this reco result as a non-const object
   */
  I3ParticlePtr GetShower() {
    return I3RecoResultSingleParticle::GetParticle(); 
  }
  
  /**
   * indicates that there is a particle in the result
   */
  bool HasShower () const { 
    return I3RecoResultSingleParticle::HasParticle(); 
  }
  
  /**
   * sets the particle in the result
   */
  void SetShower (I3ParticlePtr shower) {
    I3RecoResultSingleParticle::SetParticle(shower);
  }
  
  /**
   * Puts the contents of the container (a TopShower reco result) 
   * into the stream
   */
  virtual void ToStream(ostream& o) const {
    I3RecoResultSingleParticle::ToStream(o);
  }
  
 private:
  // copy and assignment are private
  I3RecoResultSingleTopShower (const I3RecoResultSingleTopShower& rhs);
  const I3RecoResultSingleTopShower& operator= (const I3RecoResultSingleTopShower&);

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
// ROOT macro
  ClassDef(I3RecoResultSingleTopShower, 1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef shared_ptr<I3RecoResultSingleTopShower>  I3RecoResultSingleTopShowerPtr;

#endif

