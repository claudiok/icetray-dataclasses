/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Distance.h,v 1.3 2004/06/17 22:37:15 dule Exp $
 *
 * @file I3TrackImpl.h
 * @version $Revision: 1.3 $
 * @date $Date: 2004/06/17 22:37:15 $
 * @author pretz
 */
#ifndef I3DISTANCE_H
#define I3DISTANCE_H

#include <TObject.h>
#include <cmath>
#include "dataclasses/I3Track.h"
#include "dataclasses/I3Units.h"

#include <iostream>

/**
 * @brief A class for the service that calculates various distances 
 * between a track and a position.
 *
 * This class is intended to be a service, separate from dataclasses.
 * 
 * @todo Migrate this whole class out of dataclasses and into services.
 */
class I3Distance
{

 public:
  /**
   * constructor
   */
  I3Distance() {};

  /**
   * destructor
   */
  virtual ~I3Distance() {};

  /**
   * Distance between position P and position Pos() on track
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
   * position of closest approach: 'appos'
   * distance of closest approach: 'apdist'
   * position of origin of Cherenkov photon: 'chpos'
   * time of photon from track Pos() until the Position (pos): 'chtime'
   */
  void CherenkovLight(I3Track* track,     // input track
		      I3Position& pos,    // input position
		      I3Position& appos,  // output closest distance position
		      Double_t& apdist,   // output closest distance
		      I3Position& chpos,  // output Cherenkov position
		      Double_t& chtime,   // output Cherenkov time
		      Double_t ChAngle=41*I3Units::degree);

  /**
   * Calculate a position on track, which is a distance 'dist'
   * away from track.Pos().
   */
  I3Position ShiftAlongTrack(I3Track* track, 
			     Double_t dist);

  /**
   * Check is Position is on Track within the given Precision.
   * Default Precision is 10cm, but can be given by user.
   */
  Bool_t IsOnTrack(I3Track* track, 
		   I3Position& pos,
		   Double_t Precision=0.1*I3Units::meter);


 protected:

  // ROOT macro
  ClassDef(I3Distance,1);
};


#endif
