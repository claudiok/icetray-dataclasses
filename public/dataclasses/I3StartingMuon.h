/**
    copyright  (C) 2004
    the IceCube collaboration
    $Id: I3StartingMuon.h,v 1.3 2004/04/22 16:55:52 pretz Exp $

    @file I3StartingMuon.h
    @version $Revision: 1.3 $
    @date $Date: 2004/04/22 16:55:52 $
    @author deyoung

    @todo

*/

#include "I3TrackImpl.h"
#include "I3Starting.h"
#include "I3NonEnergetic.h"
#include "I3Composite.h"

#ifndef I3STARTINGMUON_H
#define I3STARTINGMUON_H

#include "dataclasses/I3Track.h"

/**
 * StartingMuon is to hold tracks which start inside the detector.
 * It is composite so that the hadronic vertex can be added.
 */
class I3StartingMuon : public I3TrackImpl<I3Starting,
                                          I3NonEnergetic,
                                          I3Composite>
{
 public:
  I3StartingMuon(){};
  virtual ~I3StartingMuon(){}
  ClassDef(I3StartingMuon,1);
};

#endif
