/**
    copyright  (C) 2004
    the IceCube collaboration
    $Id: I3StoppingMuon.h,v 1.4 2004/04/27 13:35:23 pretz Exp $

    @file I3StoppingMuon.h
    @version $Revision: 1.4 $
    @date $Date: 2004/04/27 13:35:23 $
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

#endif
