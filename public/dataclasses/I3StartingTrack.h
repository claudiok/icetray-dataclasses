/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3StartingTrack.h,v 1.1 2004/06/09 21:56:34 dule Exp $

    @file I3StartingTrack.h
    @version $Revision: 1.1 $
    @date $Date: 2004/06/09 21:56:34 $
    @author dule
*/

#include "I3TrackImpl.h"
#include "I3Starting.h"
#include "I3NonEnergetic.h"
#include "I3NonComposite.h"

#ifndef I3STARTINGTRACK_H
#define I3STARTINGTRACK_H

#include "dataclasses/I3Track.h"

/**
 * @brief StartingTrack is for vanilla track (i.e. not cascade)
 * particles.  No starting, stopping points, no energy, etc.
  */
class I3StartingTrack : public I3TrackImpl<I3Starting,
	                              I3NonEnergetic,
                                      I3NonComposite>
{
 public:
  /**
   * constructor
   */
  I3StartingTrack(){};
  
  /**
   * destructor
   */
  virtual ~I3StartingTrack(){}
 private:
  // ROOT macro
  ClassDef(I3StartingTrack,1);
};

#endif
