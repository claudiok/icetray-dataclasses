/**
    copyright  (C) 2004
    the IceCube collaboration
    $Id: I3MCMuon.h,v 1.4 2004/04/23 20:30:06 ehrlich Exp $

    @file I3MCMuon.h
    @version $Revision: 1.4 $
    @date $Date: 2004/04/23 20:30:06 $
    @author deyoung

    @todo
*/

#include "I3TrackImpl.h"
#include "I3Contained.h"
#include "I3Composite.h"
#include "I3Energetic.h"

#ifndef I3MCMUON_H
#define I3MCMUON_H

#include "dataclasses/I3Track.h"

/**
 * For representing muons from Monte Carlo, where we have all
 * possible information.
 */
class I3MCMuon : public I3TrackImpl<I3Contained,
                                    I3Energetic,
                                    I3Composite>
{
  Double_t     fWeight;
  
  public:
  I3MCMuon() {fWeight=1;};
  virtual ~I3MCMuon(){}
  
  Double_t Weight() const { return fWeight; }
  void  Weight(Double_t weight_) { fWeight = weight_; }
  
  ClassDef(I3MCMuon,1);
};

#endif
