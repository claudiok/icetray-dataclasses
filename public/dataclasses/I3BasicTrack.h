/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3BasicTrack.h,v 1.7.4.1 2005/02/04 21:49:05 troy Exp $

    @file I3BasicTrack.h
    @version $Revision: 1.7.4.1 $
    @date $Date: 2005/02/04 21:49:05 $
    @author deyoung
*/

#include "I3TrackImpl.h"
#include "I3Infinite.h"
#include "I3NonEnergetic.h"
#include "I3NonComposite.h"

#ifndef I3BASICTRACK_H
#define I3BASICTRACK_H

#include "dataclasses/I3Track.h"

/**
 * @brief BasicTrack is for vanilla track (i.e. not cascade)
 * particles.  No starting, stopping points, no energy, etc.
  */
class I3BasicTrack : public I3TrackImpl<I3Infinite,
	                              I3NonEnergetic,
                                      I3NonComposite>
{
 public:
  /**
   * constructor
   */
  I3BasicTrack(){};
  
  /**
   * destructor
   */
  virtual ~I3BasicTrack(){}
 private:
  // ROOT macro
};

/**
 * pointer typedeffed away to insulate users from memory management
 */
typedef PtrPolicy<I3BasicTrack>::ThePolicy I3BasicTrackPtr;
#endif
