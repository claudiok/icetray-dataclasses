/**
    copyright  (C) 2004
    the IceCube collaboration
    $Id: I3MCTrack.h,v 1.10 2004/07/19 16:46:01 pretz Exp $

    @file I3MCTrack.h
    @version $Revision: 1.10 $
    @date $Date: 2004/07/19 16:46:01 $
    @author deyoung
*/

#include "I3TrackImpl.h"
#include "I3Contained.h"
#include "I3Composite.h"
#include "I3Energetic.h"

#ifndef I3MCTRACK_H
#define I3MCTRACK_H

#include "dataclasses/I3Track.h"

/**
 * @brief For representing tracks from Monte Carlo, where we have all
 * possible information.
 */
class I3MCTrack : public I3TrackImpl<I3Contained,
                                    I3Energetic,
                                    I3Composite>
{
  Double_t     fWeight;
  
  public:
  /**
   * constructor
   */
  I3MCTrack() {fWeight=1;};

  /**
   * destructor
   */
  virtual ~I3MCTrack(){}
  
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
  ClassDef(I3MCTrack,1);
};

/** 
 * pointer type to insulate users from memory management
 */
typedef PtrPolicy<I3MCTrack>::ThePolicy I3MCTrackPtr;

#endif
