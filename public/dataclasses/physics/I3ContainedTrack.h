/**
    copyright  (C) 2004
    the icecube collaboration
    @version $Id: I3ContainedTrack.h 11091 2005-09-27 09:32:13Z troy $
    @file I3ContainedTrack.h
    @date $Date: 2005-09-27 05:32:13 -0400 (Tue, 27 Sep 2005) $
*/

#include "I3TrackImpl.h"
#include "I3Contained.h"
#include "I3NonEnergetic.h"
#include "I3NonComposite.h"

#ifndef I3CONTAINEDTRACK_H_INCLUDED
#define I3CONTAINEDTRACK_H_INCLUDED

#include "dataclasses/physics/I3Track.h"

/**
 * @brief Basic track implementaion.  Contained, Non-energetic, non-composite
 *    track.  Similiar to the I3BasicTrack, but contained.
 *
 * 
 */
class I3ContainedTrack : public I3TrackImpl<I3Contained,
                                          I3NonEnergetic,
                                          I3NonComposite>
{
 public:
  /**
   * constructor
   */
  I3ContainedTrack(){};

  /**
   * destructor
   */
  virtual ~I3ContainedTrack();

 private:

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
//ROOT macro
  //ClassDef(I3ContainedTrack,1);
};

/**
 * pointer typedeffed away to insulate users from memory management
 */
typedef shared_ptr<I3ContainedTrack>  I3ContainedTrackPtr;

#endif //I3CONTAINEDTRACK_H_INCLUDED

