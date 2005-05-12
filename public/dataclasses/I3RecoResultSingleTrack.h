/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file I3RecoResultSingleTrack.h
 * @version $Revision: 1.19 $
 * @date $Date$
 * @author ehrlich
 * @author troy
 * @author pretz
 */

#ifndef I3RECORESULTSINGLETRACK_H
#define I3RECORESULTSINGLETRACK_H

#include "dataclasses/I3RecoResultSingleParticle.h"

/**
 * @brief This is a reco result which just contains a single track
 */
class I3RecoResultSingleTrack : public I3RecoResultSingleParticle
{
 public:
  I3RecoResultSingleTrack() {}; //track_ will automatically be "NULL" 
  virtual ~I3RecoResultSingleTrack() {}

  /**
   * Retrieves the track in this reco result as a constant object
   */
  const I3ParticlePtr GetTrack() const 
  {
    return I3RecoResultSingleParticle::GetParticle(); 
  }

  /**
   * Retrieves the track of this solution as a non-const object
   */
  I3ParticlePtr GetTrack()
  {
    return I3RecoResultSingleParticle::GetParticle(); 
  }

  /**
   * indicates that there is a track in the result
   */
  bool HasTrack() const {
    //TDS: the smart pointer automagically converts to bool
    return I3RecoResultSingleParticle::HasParticle(); 
  }
  
  /**
   * sets the track in the result
   * Fails the program if it is already set.
   */
  void SetTrack(I3ParticlePtr track) {
    I3RecoResultSingleParticle::SetParticle(track);
  }

  /**
   * Send the contents of the container to the stream
   */
  virtual void ToStream(ostream& o) const {
      I3RecoResultSingleParticle::ToStream(o);
  }
  
 private:
  I3RecoResultSingleTrack (const I3RecoResultSingleTrack& rhs);
  const I3RecoResultSingleTrack& operator= (const I3RecoResultSingleTrack&);

  friend class boost::serialization::access;

  template <class Archive>
  void serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3RecoResultSingleTopShower", 
		  base_object<I3RecoResultSingleParticle>(*this));
  }

  // ROOT macro
  ClassDef(I3RecoResultSingleTrack, 1);
};

BOOST_SHARED_POINTER_EXPORT(I3RecoResultSingleTrack);

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef shared_ptr<I3RecoResultSingleTrack>  I3RecoResultSingleTrackPtr;

#endif
