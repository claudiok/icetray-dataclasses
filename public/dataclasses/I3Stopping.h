/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Stopping.h,v 1.9 2004/07/30 19:15:59 dule Exp $
 *
 * @file I3Stopping.h
 * @version $Revision: 1.9 $
 * @date $Date: 2004/07/30 19:15:59 $
 * @author pretz
 */
#ifndef I3STOPPING_H
#define I3STOPPING_H

#include <cmath>
#include "I3Units.h"
#include "I3Constants.h"

/**
 * @brief This class services the 'geometrical' part of the I3Track interface.
 *
 * Defines a stopping position, and stopping time.  Also, a Zenith and Azimuth
 * But if you mess with StartX, StartY, StartZ or StartT, you get a fatal error
 *
 */
class I3Stopping{
 private:
  I3Position fStopPos;
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
  Bool_t HasDirection() const {return true;}

  /**
   * A t along the track.  Gives the stopping t.
   */
  Double_t GetT() const {return fStopT;}

  /**
   * gives the stopping positition as a position on the track
   */
  I3Position GetPos() const {return fStopPos;}

  /**
   * sets the stopping positition as a position on the track
   */
  void SetPos(I3Position& p) {fStopPos = p;}

  /**
   * gives the zenith of the track
   */
  Double_t GetZenith() const {return fZenith;}

  /**
   * gives the azimuth of the track
   */
  Double_t GetAzimuth() const {return fAzimuth;}

  /**
   * sets the zenith of the track
   */
  void SetZenith(Double_t theta){fZenith = theta;}

  /**
   * sets the azimuth of the track
   */
  void SetAzimuth(Double_t phi){fAzimuth = phi;}

  /**
   * returns the length of the track as infinite
   */
  Double_t GetLength() const {return INFINITY;}

  /**
   * gives the stopping t of the track
   */
  Double_t GetStopT() const {return fStopT;}

  /**
   * sets the stoppign t of the track
   */
  void SetStopT(Double_t stopt) {fStopT = stopt;}

  /**
   * gets the stopping position
   */
  I3Position GetStopPos() const {return fStopPos;}

  /**
   * sets the stopping position
   */
  void SetStopPos(I3Position& p) {fStopPos = p;}

  /**
   * sets the stopping position in any reference frame
   */
  void SetStopPos(Double_t stopp1, Double_t stopp2, Double_t stopp3, 
		I3Position::RefFrame frame=I3Position::car)
    {fStopPos.SetPosition(stopp1,stopp2,stopp3,frame);}

  /**
   * gives the speed of light for the speed.
   */
  Double_t GetSpeed() const {return I3Constants::c;}

  /**
   * copies the 'stopping' data into  the destination particle if a 
   * dynamic cast succeeds.  just returns otherwise.
   */ 
  void CopyTo(I3Particle& destination) const
    {
      I3Stopping* stopping = dynamic_cast<I3Stopping*>(&destination);
      if(stopping){
	stopping->fStopPos = fStopPos;
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
