/**
    copyright  (C) 2004
    the IceCube collaboration
    $Id: I3StoppingMuon.h,v 1.1.2.1 2004/04/16 20:27:05 deyoung Exp $

    @version $Revision: 1.1.2.1 $
    @date $Date: 2004/04/16 20:27:05 $
    @author deyoung

    @todo

*/

#include "I3TrackImpl.h"
#include "I3Identifiable.h"
#include "I3Stopping.h"
#include "I3NonEnergetic.h"
#include "I3NonComposite.h"

#ifndef I3STOPPINGMUON_H
#define I3STOPPINGMUON_H

#include "dataclasses/I3Track.h"

class I3StoppingMuon : public I3TrackImpl<I3Identifiable,
                                          I3Stopping,
                                          I3NonEnergetic,
                                          I3NonComposite>
{
 public:
  I3StoppingMuon(){};
  virtual ~I3StoppingMuon(){}
  ClassDef(I3StoppingMuon,1);
};

#endif
