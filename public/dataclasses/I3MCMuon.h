/**
    copyright  (C) 2004
    the IceCube collaboration
    $Id: I3MCMuon.h,v 1.1.2.2 2004/04/20 16:51:16 pretz Exp $

    @version $Revision: 1.1.2.2 $
    @date $Date: 2004/04/20 16:51:16 $
    @author deyoung

    @todo

    For representing muons from Monte Carlo, where we have all
    possible information.

*/

#include "I3TrackImpl.h"
#include "I3Contained.h"
#include "I3Composite.h"
#include "I3Energetic.h"

#ifndef I3MCMUON_H
#define I3MCMUON_H

#include "dataclasses/I3Track.h"

class I3MCMuon : public I3TrackImpl<I3Contained,
                                    I3Energetic,
                                    I3Composite>
{
 public:
  I3MCMuon(){};
  virtual ~I3MCMuon(){}
  ClassDef(I3MCMuon,1);
};

#endif
