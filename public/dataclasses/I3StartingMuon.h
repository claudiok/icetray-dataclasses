/**
    copyright  (C) 2004
    the IceCube collaboration
    $Id: I3StartingMuon.h,v 1.1.2.1 2004/04/16 20:27:05 deyoung Exp $

    @version $Revision: 1.1.2.1 $
    @date $Date: 2004/04/16 20:27:05 $
    @author deyoung

    @todo

    StartingMuon is to hold tracks which start inside the detector.
    It is composite so that the hadronic vertex can be added.

*/

#include "I3TrackImpl.h"
#include "I3Identifiable.h"
#include "I3Starting.h"
#include "I3NonEnergetic.h"
#include "I3Composite.h"

#ifndef I3STARTINGMUON_H
#define I3STARTINGMUON_H

#include "dataclasses/I3Track.h"

class I3StartingMuon : public I3TrackImpl<I3Identifiable,
                                          I3Starting,
                                          I3NonEnergetic,
                                          I3Composite>
{
 public:
  I3StartingMuon(){};
  virtual ~I3StartingMuon(){}
  ClassDef(I3StartingMuon,1);
};

#endif
