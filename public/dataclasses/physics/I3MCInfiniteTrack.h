/**
    copyright  (C) 2004
    the IceCube collaboration
    @version $Id: I3MCTrack.h 7619 2005-05-14 18:52:55Z olivas $
    @file I3MCTrack.h
    @date $Date: 2005-05-14 14:52:55 -0400 (Sat, 14 May 2005) $
*/

#include "I3TrackImpl.h"
#include "I3Infinite.h"
#include "I3Composite.h"
#include "I3Energetic.h"

#ifndef I3MCINFINITETRACK_H_INCLUDED
#define I3MCINFINITETRACK_H_INCLUDED

#include "dataclasses/physics/I3Track.h"

/**
 * @brief For representing infinite tracks from Monte Carlo, where we have all
 * possible information. There are F2k files which have infinite MC tracks, which are not primaries.
 */
class I3MCInfiniteTrack : public I3TrackImpl<I3Infinite,
                                             I3Energetic,
                                             I3Composite>
{
  double     weight_;
  
  public:

  I3MCInfiniteTrack() {weight_=1;};

  virtual ~I3MCInfiniteTrack();
  
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
  //ClassDef(I3MCInfiniteTrack,1);
};

/** 
 * pointer type to insulate users from memory management
 */
typedef shared_ptr<I3MCInfiniteTrack>  I3MCInfiniteTrackPtr;

#endif //I3MCINFINITETRACK_H_INCLUDED

