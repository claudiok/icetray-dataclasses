/**
    copyright  (C) 2004
    the IceCube collaboration
    $Id: I3Lollipop.h,v 1.3 2004/04/22 16:55:52 pretz Exp $

    @file I3Lollipop.h
    @version $Revision: 1.3 $
    @date $Date: 2004/04/22 16:55:52 $
    @author deyoung

    @todo
*/


#include "I3TrackImpl.h"
#include "I3Stopping.h"
#include "I3Composite.h"
#include "I3Energetic.h"

#ifndef I3LOLLIPOP_H
#define I3LOLLIPOP_H

#include "dataclasses/I3Track.h"

/**
 * For tau leptons which enter the detector and then decay (single
 * bang events).
 */
class I3Lollipop : public I3TrackImpl<I3Stopping,
                                      I3Energetic,
                                      I3Composite>
{
 public:
  I3Lollipop(){};
  virtual ~I3Lollipop(){}
  ClassDef(I3Lollipop,1);
};

#endif
