/**
    copyright  (C) 2004
    the IceCube collaboration
    $Id: I3DecayingMuon.h,v 1.6.4.1 2005/02/04 21:51:03 troy Exp $

    @file I3DecayingMuon.h
    @version $Revision: 1.6.4.1 $
    @date $Date: 2005/02/04 21:51:03 $
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

};

typedef PtrPolicy<I3DecayingMuon>::ThePolicy I3DecayingMuonPtr;

#endif
