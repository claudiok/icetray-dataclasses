/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3BasicTrack.h,v 1.1.2.6 2004/04/16 17:10:56 pretz Exp $

    @version $Revision: 1.1.2.6 $
    @date $Date: 2004/04/16 17:10:56 $
    @author

    @todo

    Currently BasicTrack defines all the most common track member
    variable.  This could be split up a bit more so people can see
    what they are doing.

*/

#include "I3TrackImpl.h"
#include "I3Identifiable.h"
#include "I3Starting.h"
#include "I3Energetic.h"
#include "I3Relativistic.h"
#include "I3NonComposite.h"

#ifndef I3BASICTRACK_H
#define I3BASICTRACK_H

#include "dataclasses/I3Track.h"

class I3BasicTrack : public I3TrackImpl<I3Identifiable,
                                      I3Starting,
                                      I3Energetic,
                                      I3Relativistic,
                                      I3NonComposite>
{
 public:
  I3BasicTrack(){};
  virtual ~I3BasicTrack(){}
  ClassDef(I3BasicTrack,1);
};

#endif
