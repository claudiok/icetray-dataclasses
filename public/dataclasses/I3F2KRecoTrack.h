/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3F2KRecoTrack.h,v 1.1 2004/04/25 20:44:30 ehrlich Exp $

    @file I3F2KTrack.h
    @version $Revision: 1.1 $
    @date $Date: 2004/04/25 20:44:30 $
    @author deyoung

    @todo
*/

#include "I3TrackImpl.h"
#include "I3Contained.h"
#include "I3NonEnergetic.h"
#include "I3NonComposite.h"

#ifndef I3F2KRECOTRACK_H
#define I3F2KRECOTRACK_H

#include "dataclasses/I3Track.h"

/**
 * F2KTrack contains the parameter set corresponding to the F2000
 * track variables.  It is intended primarily for backward compatibility.
 */
class I3F2KRecoTrack : public I3TrackImpl<I3Contained,
                                          I3NonEnergetic,
                                          I3NonComposite>
{
 public:
  I3F2KRecoTrack(){};
  virtual ~I3F2KRecoTrack(){}
  ClassDef(I3F2KRecoTrack,1);
};

typedef PtrPolicy<I3F2KRecoTrack>::ThePolicy I3F2KRecoTrackPtr;

#endif
