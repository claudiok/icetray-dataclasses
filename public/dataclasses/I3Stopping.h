/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Stopping.h,v 1.2 2004/04/22 15:55:44 pretz Exp $
 *
 * @file 
 * @version $Revision: 1.2 $
 * @date $Date: 2004/04/22 15:55:44 $
 * @author 
 *
 * @todo
 *
 */
#ifndef I3STOPPING_H
#define I3STOPPING_H

#include <cmath>
#include "I3Units.h"
#include "NanPolicy.h"

/**
 * This class services the 'geometrical' part of the I3Track interface.
 * Defines a stopping position, and stopping time.  Also, a Zenith and Azimuth
 * But if you mess with StartX, StartY, StartZ or StartT, you get a fatal error
 *
 */
class I3Stopping{
 private:
  Double_t fStopX;
  Double_t fStopY;
  Double_t fStopZ;
  Double_t fStopT;
  Double_t fZenith;
  Double_t fAzimuth;
 public:
  /**
   * indicates that the particle is stopping
   */
  Bool_t IsStopping() const {return true;}

  /**
   * indicates that the particle isn't starting
   */
  Bool_t IsStarting() const {return false;}

  /**
   * indicates that the particle is directional
   */
  Bool_t IsDirectional() const {return true;}

  /**
   * shouldn't be used.  Calls Fatal.
   */
  Double_t StartX() const 
    {
      NanPolicy::Fatal();
      return NAN;
    }

  /**
   * shouldn't be used.  Calls Fatal.
   */
  Double_t StartY() const     
    {
      NanPolicy::Fatal();
      return NAN;
    }

  /**
   * shouldn't be used.  Calls Fatal.
   */
  Double_t StartZ() const 
    {
      NanPolicy::Fatal();
      return NAN;
    }
  
  /**
   * shouldn't be used.  Calls Fatal.
   */
  Double_t StartT() const
    {
      NanPolicy::Fatal();
      return NAN;
    }

  Double_t X() const {return fStopX;}

  Double_t Y() const {return fStopY;}

  Double_t Z() const {return fStopZ;}

  Double_t T() const {return fStopT;}

  /**
   * gives the zenith of the track
   */
  Double_t Zenith() const {return fZenith;}

  /**
   * sets the zenith of the track
   */
  void Zenith(Double_t theta){fZenith = theta;}

  /**
   * gives the azimuth of the track
   */
  Double_t Azimuth() const {return fAzimuth;}

  /**
   * sets the azimuth of the track
   */
  void Azimuth(Double_t phi){fAzimuth = phi;}

  /**
   * returns the length of the track as infinite
   */
  Double_t Length() const {return INFINITY;}

  /**
   * gives the stopping x position of the track
   */
  Double_t StopX() const {return fStopX;}

  /**
   * sets the stopping X position of the track
   */
  void StopX(Double_t stopx) {fStopX = stopx;}

  /**
   * gives the stopping y position of the track
   */
  Double_t StopY() const {return fStopX;}

  /**
   * sets the stopping y position of the track
   */
  void StopY(Double_t stopy) {fStopY = stopy;}

  /**
   * gives the stopping z position of the track.
   */
  Double_t StopZ() const {return fStopX;}

  /**
   * sets the stopping z position of the track
   */
  void StopZ(Double_t stopz) {fStopZ = stopz;}

  /**
   * gives the stopping t of the track
   */
  Double_t StopT() const {return fStopT;}

  /**
   * sets the stoppign t of the track
   */
  void StopT(Double_t stopt) {fStopT = stopt;}

  /**
   * gives the speed of light for the speed.
   */
  Double_t Speed() const {return 300000000 * I3Units::m / I3Units::s;}

  /**
   * shouldn't be used.  Calls fatal
   */
  void Speed(Double_t) 
    {
      NanPolicy::Fatal();
    }

  /**
   * copies the 'stopping' data into  the destination particle if a 
   * dynamic cast succeeds.  just returns otherwise.
   */ 
  void CopyTo(I3Particle& destination) const
    {
      I3Stopping* stopping = dynamic_cast<I3Stopping*>(&destination);
      if(stopping){
	stopping->fStopX = fStopX;
	stopping->fStopY = fStopY;
	stopping->fStopZ = fStopZ;
	stopping->fStopT = fStopT;
	stopping->fZenith = fZenith;
	stopping->fAzimuth = fAzimuth;
      }
    }
 private:
  // ROOT macro
  ClassDef(I3Stopping,1)
};

#endif //I3STOPPING_H
