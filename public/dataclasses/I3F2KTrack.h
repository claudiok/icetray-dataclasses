/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3F2KTrack.h,v 1.3 2004/04/22 16:55:52 pretz Exp $

    @file I3F2KTrack.h
    @version $Revision: 1.3 $
    @date $Date: 2004/04/22 16:55:52 $
    @author deyoung

    @todo
*/

#include "I3TrackImpl.h"
#include "I3Starting.h"
#include "I3Energetic.h"
#include "I3NonComposite.h"

#ifndef I3F2KTRACK_H
#define I3F2KTRACK_H

#include "dataclasses/I3Track.h"

/**
 * F2KTrack contains the parameter set corresponding to the F2000
 * track variables.  It is intended primarily for backward compatibility.
 */
class I3F2KTrack : public I3TrackImpl<I3Starting,
                                      I3Energetic,
                                      I3NonComposite>
{
 public:
  I3F2KTrack(){};
  virtual ~I3F2KTrack(){}
  ClassDef(I3F2KTrack,1);
};

#endif
