/**
    copyright  (C) 2004
    the icecube collaboration
    @version $Id$
    @file I3BasicTrack.h
    @date $Date$
*/

#ifndef I3BASICTRACK_H_INCLUDED
#define I3BASICTRACK_H_INCLUDED

#include "dataclasses/physics/I3TrackImpl.h"
#include "dataclasses/physics/I3Infinite.h"
#include "dataclasses/physics/I3NonEnergetic.h"
#include "dataclasses/physics/I3NonComposite.h"

#include "dataclasses/physics/I3Track.h"

/**
 * @brief BasicTrack is for vanilla track (i.e. not cascade)
 * particles.  No starting, stopping points, no energy, etc.
  */
class I3BasicTrack : public I3TrackImpl<I3Infinite,
	                              I3NonEnergetic,
                                      I3NonComposite>
{
 public:

  I3BasicTrack(){};
  
  virtual ~I3BasicTrack();

 private:
  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
// ROOT macro
  //ClassDef(I3BasicTrack,1);
};

/**
 * pointer typedeffed away to insulate users from memory management
 */
typedef shared_ptr<I3BasicTrack>  I3BasicTrackPtr;
#endif //I3BASICTRACK_H_INCLUDED


