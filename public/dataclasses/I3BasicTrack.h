/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3BasicTrack.h,v 1.3 2004/04/22 16:55:52 pretz Exp $

    @file I3BasicTrack.h
    @version $Revision: 1.3 $
    @date $Date: 2004/04/22 16:55:52 $
    @author deyoung

    @todo Is this class needed anymore?

*/

#include "I3TrackImpl.h"
#include "I3Starting.h"
#include "I3Energetic.h"
#include "I3NonComposite.h"

#ifndef I3BASICTRACK_H
#define I3BASICTRACK_H

#include "dataclasses/I3Track.h"

/**
 * Currently BasicTrack defines all the most common track member
 * variable.  This could be split up a bit more so people can see
 * what they are doing.
 */
class I3BasicTrack : public I3TrackImpl<I3Starting,
	                              I3Energetic,
                                      I3NonComposite>
{
 public:
  I3BasicTrack(){};
  virtual ~I3BasicTrack(){}
  ClassDef(I3BasicTrack,1);
};

#endif
