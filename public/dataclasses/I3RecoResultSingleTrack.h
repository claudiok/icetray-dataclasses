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

#include "I3RecoResult.h"
#include "I3Particle.h"

/**
 * @brief This is a reco result which just contains a single track
 */
class I3RecoResultSingleTrack : public I3RecoResult
{
  I3ParticlePtr track_;
  
  // TDS FIXME most of this has/get/set stuff can go away.  You just
  // get the pointer out, it either points to something valid or it
  // points to nothing.

  public:
  /**
   * constructor
   */
  I3RecoResultSingleTrack() {}; //track_ will automatically be "NULL" 

  /**
   * destructor
   */
  virtual ~I3RecoResultSingleTrack() {}

  /**
   * Retrieves the track in this reco result as a constant object
   */
  const I3ParticlePtr GetTrack() const 
  {
    if (track_) 
      return (track_);

    log_fatal("I3RecoResultSingleTrack::Track() asked for a track which doesn't exist");
    return I3ParticlePtr();
  }

  /**
   * Retrieves the track of this solution as a non-const object
   */
  I3ParticlePtr GetTrack()
  {
    if (track_) 
      return track_;

    log_fatal("I3RecoResultSingleTrack::Track() asked for a track which doesn't exist");
    return I3ParticlePtr();
  }

  /**
   * indicates that there is a track in the result
   */
  bool HasTrack() const {
    //TDS: the smart pointer automagically converts to bool
    return track_;
  }
  
  /**
   * sets the track in the result
   * Fails the program if it is already set.
   */
  void SetTrack(I3ParticlePtr track)
  {
    if(track_)
    {
      log_fatal("I3RecoResultSingleTrack::Track() track exists already");
      return;
    }
    track_=track;
  }

  virtual void ToStream(ostream& o) const
    {
      I3RecoResult::ToStream(o);
      o<<"The Track:\n";
      if(track_)
	o<<*track_<<"\n";
      else
	o<<"NULL Track\n";
    }
  
  private:

  friend class boost::serialization::access;

  template <class Archive>
  void serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3RecoResult", base_object<I3RecoResult>(*this));
    ar & make_nvp("Track", track_);
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
