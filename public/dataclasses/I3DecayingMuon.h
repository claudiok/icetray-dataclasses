/**
    copyright  (C) 2004
    the IceCube collaboration
    $Id: I3DecayingMuon.h,v 1.4 2004/04/27 18:12:20 deyoung Exp $

    @file I3DecayingMuon.h
    @version $Revision: 1.4 $
    @date $Date: 2004/04/27 18:12:20 $
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
 * @brief For muons which decay in flight, with an EM shower at the
 * decay vertex.
 */
class I3DecayingMuon : public I3TrackImpl<I3Stopping,
                                      I3Energetic,
                                      I3Composite>
{
 public:
  /**
   * constructor
   */
  I3DecayingMuon(){};

  /**
   * destructor
   */
  virtual ~I3DecayingMuon(){}

 private:
  //ROOT macro
  ClassDef(I3DecayingMuon,1);
};

#endif
