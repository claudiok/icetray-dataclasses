/**
    copyright  (C) 2004
    the IceCube collaboration
    $Id: I3StoppingMuon.h,v 1.3 2004/04/22 16:55:52 pretz Exp $

    @file I3StoppingMuon.h
    @version $Revision: 1.3 $
    @date $Date: 2004/04/22 16:55:52 $
    @author deyoung

    @todo

*/

#include "I3TrackImpl.h"
#include "I3Stopping.h"
#include "I3NonEnergetic.h"
#include "I3NonComposite.h"

#ifndef I3STOPPINGMUON_H
#define I3STOPPINGMUON_H

#include "dataclasses/I3Track.h"

/**
 * an muon which has a stopping position
 */
class I3StoppingMuon : public I3TrackImpl<I3Stopping,
                                          I3NonEnergetic,
                                          I3NonComposite>
{
 public:
  I3StoppingMuon(){};
  virtual ~I3StoppingMuon(){}
  ClassDef(I3StoppingMuon,1);
};

#endif
