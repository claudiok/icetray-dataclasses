/**
    copyright  (C) 2004
    the IceCube collaboration
    $Id: I3DecayingMuon.h,v 1.5 2004/04/28 12:20:27 pretz Exp $

    @file I3DecayingMuon.h
    @version $Revision: 1.5 $
    @date $Date: 2004/04/28 12:20:27 $
    @author deyoung
*/


#include "I3TrackImpl.h"
#include "I3Stopping.h"
#include "I3Composite.h"
#include "I3Energetic.h"

#ifndef I3DECAYINGMUON_H
#define I3DECAYINGMUON_H

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
