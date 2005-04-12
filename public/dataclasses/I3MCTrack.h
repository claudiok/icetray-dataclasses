/**
    copyright  (C) 2004
    the IceCube collaboration
    $Id: I3MCTrack.h,v 1.14 2005/04/12 18:55:28 dule Exp $

    @file I3MCTrack.h
    @version $Revision: 1.14 $
    @date $Date: 2005/04/12 18:55:28 $
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
  double     weight_;
  
  public:
  /**
   * constructor
   */
  I3MCTrack() {weight_=1;};

  /**
   * destructor
   */
  virtual ~I3MCTrack(){}
  
  /**
   * gives the weight of the track
   */
  double GetWeight() const { return weight_; }

  /**
   * sets the weight of the track
   */
  void  SetWeight(double weight_) { weight_ = weight_; }

 private:
  //ROOT macro
  ClassDef(I3MCTrack,1);
};

/** 
 * pointer type to insulate users from memory management
 */
typedef shared_ptr<I3MCTrack>  I3MCTrackPtr;

#endif
