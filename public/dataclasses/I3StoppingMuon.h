/**
    copyright  (C) 2004
    the IceCube collaboration
    $Id: I3StoppingMuon.h,v 1.5 2004/08/12 17:33:33 pretz Exp $

    @file I3StoppingMuon.h
    @version $Revision: 1.5 $
    @date $Date: 2004/08/12 17:33:33 $
    @author deyoung
*/

#include "I3TrackImpl.h"
#include "I3Stopping.h"
#include "I3NonEnergetic.h"
#include "I3NonComposite.h"

#ifndef I3STOPPINGMUON_H
#define I3STOPPINGMUON_H

#include "dataclasses/I3Track.h"

/**
 * @brief A muon which has a stopping position
 */
class I3StoppingMuon : public I3TrackImpl<I3Stopping,
                                          I3NonEnergetic,
                                          I3NonComposite>
{
 public:
  /**
   * constructor
   */
  I3StoppingMuon(){};

  /**
   * destructor
   */
  virtual ~I3StoppingMuon(){}

 private:
  //ROOT macro
  ClassDef(I3StoppingMuon,1);
};

/**
 * pointer type to insulate users from memory management
 */
typedef PtrPolicy<I3StoppingMuon>::ThePolicy I3StoppingMuonPtr;

#endif
