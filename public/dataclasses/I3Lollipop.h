/**
    copyright  (C) 2004
    the IceCube collaboration
    $Id: I3Lollipop.h,v 1.5 2004/04/27 13:35:23 pretz Exp $

    @file I3Lollipop.h
    @version $Revision: 1.5 $
    @date $Date: 2004/04/27 13:35:23 $
    @author deyoung
*/


#include "I3TrackImpl.h"
#include "I3Stopping.h"
#include "I3Composite.h"
#include "I3Energetic.h"

#ifndef I3LOLLIPOP_H
#define I3LOLLIPOP_H

#include "dataclasses/I3Track.h"

/**
 * @brief For tau leptons which enter the detector and then decay (single
 * bang events).
 */
class I3Lollipop : public I3TrackImpl<I3Stopping,
                                      I3Energetic,
                                      I3Composite>
{
 public:
  /**
   * constructor
   */
  I3Lollipop(){};

  /**
   * destructor
   */
  virtual ~I3Lollipop(){}

 private:
  //ROOT macro
  ClassDef(I3Lollipop,1);
};

#endif
