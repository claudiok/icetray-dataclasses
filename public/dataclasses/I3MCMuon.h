/**
    copyright  (C) 2004
    the IceCube collaboration
    $Id: I3MCMuon.h,v 1.6 2004/04/27 13:35:23 pretz Exp $

    @file I3MCMuon.h
    @version $Revision: 1.6 $
    @date $Date: 2004/04/27 13:35:23 $
    @author deyoung
*/

#include "I3TrackImpl.h"
#include "I3Contained.h"
#include "I3Composite.h"
#include "I3Energetic.h"

#ifndef I3MCMUON_H
#define I3MCMUON_H

#include "dataclasses/I3Track.h"

/**
 * @brief For representing muons from Monte Carlo, where we have all
 * possible information.
 */
class I3MCMuon : public I3TrackImpl<I3Contained,
                                    I3Energetic,
                                    I3Composite>
{
  Double_t     fWeight;
  
  public:
  /**
   * constructor
   */
  I3MCMuon() {fWeight=1;};

  /**
   * destructor
   */
  virtual ~I3MCMuon(){}
  
  /**
   * gives the weight of the track
   */
  Double_t Weight() const { return fWeight; }

  /**
   * sets the weight of the track
   */
  void  Weight(Double_t weight_) { fWeight = weight_; }

 private:
  //ROOT macro
  ClassDef(I3MCMuon,1);
};

#endif
