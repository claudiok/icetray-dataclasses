/**
    copyright  (C) 2004
    the IceCube collaboration
    $Id: I3DecayingMuon.h,v 1.6 2004/08/12 17:33:33 pretz Exp $

    @file I3DecayingMuon.h
    @version $Revision: 1.6 $
    @date $Date: 2004/08/12 17:33:33 $
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

typedef PtrPolicy<I3DecayingMuon>::ThePolicy I3DecayingMuonPtr;

#endif
