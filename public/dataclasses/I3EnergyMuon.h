/**
    copyright  (C) 2004
    the IceCube collaboration
    $Id: I3EnergyMuon.h,v 1.3 2004/04/22 16:55:52 pretz Exp $

    @file I3EnergyMuon.h
    @version $Revision: 1.3 $
    @date $Date: 2004/04/22 16:55:52 $
    @author deyoung

    @todo
*/

#include "I3TrackImpl.h"
#include "I3Infinite.h"
#include "I3NonComposite.h"
#include "I3Energetic.h"

#ifndef I3ENERGYMUON_H
#define I3ENERGYMUON_H

#include "dataclasses/I3Track.h"

/**
 * Class for infinite muon tracks with a known energy. 
 */
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
