/**
    copyright  (C) 2004
    the IceCube collaboration
    $Id: I3EnergyMuon.h,v 1.1.2.2 2004/04/20 16:51:16 pretz Exp $

    @version $Revision: 1.1.2.2 $
    @date $Date: 2004/04/20 16:51:16 $
    @author deyoung

    @todo

    Class for infinite muon tracks with a known energy. 

*/

#include "I3TrackImpl.h"
#include "I3Infinite.h"
#include "I3NonComposite.h"
#include "I3Energetic.h"

#ifndef I3ENERGYMUON_H
#define I3ENERGYMUON_H

#include "dataclasses/I3Track.h"

class I3EnergyMuon : public I3TrackImpl<I3Infinite,
                                        I3Energetic,
                                        I3NonComposite>
{
 public:
  I3EnergyMuon(){};
  virtual ~I3EnergyMuon(){}
  ClassDef(I3EnergyMuon,1);
};

#endif
