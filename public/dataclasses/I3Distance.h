/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Distance.h,v 1.1 2004/06/09 21:56:34 dule Exp $
 *
 * @file I3TrackImpl.h
 * @version $Revision: 1.1 $
 * @date $Date: 2004/06/09 21:56:34 $
 * @author pretz
 */
#ifndef I3DISTANCE_H
#define I3DISTANCE_H

#include <TObject.h>
//#include <vector>
#include <cmath>
#include "dataclasses/I3Track.h"

#include <iostream>

/**
 * @brief A class for the service that calculates various distances 
 * between a track and a position.
 *
 * 
 * 
 */
class I3Distance
{
/*  private: */
/*   I3Position fPos; */
/*   I3Track fTrack; */

 private:
  /**
   * precision in deciding if position is on track
   */

 public:
  static Double_t pi() { return 3.14159265358979323846; } // define PI
  static Double_t Precision() {return 0.001;}

  /**
   * constructor
   */
  I3Distance() {};

  /**
   * destructor
   */
  virtual ~I3Distance() {};

  /**
   * Distance between position P and position on track
   */
  Double_t Distance(I3Track* track, I3Position& pos);

  /**
   * Distance between position P and start position on track
   */
  Double_t StartDistance(I3Track* track, I3Position& pos);

  /**
   * Distance between position P and stop position on track
   */
  Double_t StopDistance(I3Track* track, I3Position& pos);

  /**
   * Distance between position P and closest approach position on track
   * Input a position 'pos' and a track 'track', and output 
   * position-of-closest-approach 'appos'
   * distance-of-closest-approach 'apdist'
   * is 'appos' on 'track'? - kTrue/kFalse
   */
  void ClosestApproach(I3Track* track,   // input
		       I3Position& pos,    // input
		       I3Position& appos,  // output
		       Double_t& apdist,   // output
		       Bool_t& ontrack);   // output

  /**
   * Calculate a position on track, which is a distance 'dist'
   * away from track.Pos().
   */
  I3Position ShiftAlongTrack(I3Track* track, Double_t dist);

  /**
   * Is a given position on a given track?
   */
  Bool_t IsOnTrack(I3Track* track, I3Position& pos);

 protected:

  // ROOT macro
  ClassDef(I3Distance,1);
};


#endif
