/**
    copyright  (C) 2004
    the IceCube collaboration
    $Id: I3BasicMuon.h,v 1.1.2.1 2004/04/16 20:27:05 deyoung Exp $

    @version $Revision: 1.1.2.1 $
    @date $Date: 2004/04/16 20:27:05 $
    @author deyoung

    @todo

    BasicMuon is intended for plain vanilla muon reconstruction
    results -- infinite tracks, no energy information, etc.

*/

#include "I3TrackImpl.h"
#include "I3Identifiable.h"
#include "I3Infinite.h"
#include "I3NonEnergetic.h"
#include "I3NonComposite.h"

#ifndef I3BASICMUON_H
#define I3BASICMUON_H

#include "dataclasses/I3Track.h"

class I3BasicMuon : public I3TrackImpl<I3Identifiable,
                                       I3Infinite,
                                       I3NonEnergetic,
	                               I3NonComposite>
{
 public:
  I3BasicMuon(){};
  virtual ~I3BasicMuon(){}
  ClassDef(I3BasicMuon,1);
};

#endif
