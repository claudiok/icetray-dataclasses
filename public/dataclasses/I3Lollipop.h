/**
    copyright  (C) 2004
    the IceCube collaboration
    $Id: I3Lollipop.h,v 1.1.2.1 2004/04/20 13:38:59 pretz Exp $

    @version $Revision: 1.1.2.1 $
    @date $Date: 2004/04/20 13:38:59 $
    @author deyoung

    @todo

    For tau leptons which enter the detector and then decay (single
    bang events).

*/

#include "I3TrackImpl.h"
#include "I3Identifiable.h"
#include "I3Stopping.h"
#include "I3Composite.h"
#include "I3Energetic.h"

#ifndef I3LOLLIPOP_H
#define I3LOLLIPOP_H

#include "dataclasses/I3Track.h"

class I3Lollipop : public I3TrackImpl<I3Identifiable,
                                          I3Stopping,
                                          I3Energetic,
                                          I3Composite>
{
 public:
  I3Lollipop(){};
  virtual ~I3Lollipop(){}
  ClassDef(I3Lollipop,1);
};

#endif
