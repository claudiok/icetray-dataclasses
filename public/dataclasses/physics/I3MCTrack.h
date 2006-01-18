/**
    copyright  (C) 2004
    the IceCube collaboration
    @version $Id$
    @file I3MCTrack.h
    @date $Date$
*/

#ifndef I3MCTRACK_H_INCLUDED
#define I3MCTRACK_H_INCLUDED

#include "dataclasses/physics/I3TrackImpl.h"
#include "dataclasses/physics/I3Contained.h"
#include "dataclasses/physics/I3Composite.h"
#include "dataclasses/physics/I3Energetic.h"

#include "dataclasses/physics/I3Track.h"

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

  I3MCTrack() {weight_=1;};

  virtual ~I3MCTrack();
  
  /**
   * gives the weight of the track
   */
  double GetWeight() const { return weight_; }

  /**
   * sets the weight of the track
   */
  void  SetWeight(double weight) { weight_ = weight; }

 private:

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
//ROOT macro
  //ClassDef(I3MCTrack,1);
};

/** 
 * pointer type to insulate users from memory management
 */
typedef shared_ptr<I3MCTrack>  I3MCTrackPtr;

#endif //I3MCTRACK_H_INCLUDED

