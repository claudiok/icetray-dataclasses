/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Stopping.h,v 1.5 2004/06/09 21:56:34 dule Exp $
 *
 * @file I3Stopping.h
 * @version $Revision: 1.5 $
 * @date $Date: 2004/06/09 21:56:34 $
 * @author pretz
 */
#ifndef I3STOPPING_H
#define I3STOPPING_H

#include <cmath>
#include "I3Units.h"
#include "NanPolicy.h"

/**
 * @brief This class services the 'geometrical' part of the I3Track interface.
 *
 * Defines a stopping position, and stopping time.  Also, a Zenith and Azimuth
 * But if you mess with StartX, StartY, StartZ or StartT, you get a fatal error
 *
 */
class I3Stopping{
 private:
/*   Double_t fStopX; */
/*   Double_t fStopY; */
/*   Double_t fStopZ; */
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
  
  /**
   * shouldn't be used.  Calls Fatal.
   */
  I3Position StartPos() const
    {
      NanPolicy::Fatal();
      I3Position p(999,999,999);
      return p;
    }

  /**
   * A x position along the track. Gives the stopping x position. 
   */
  Double_t X() const {return fStopPos.X();}

  /**
   * A y position along the track. Gives the stopping y position. 
   */
  Double_t Y() const {return fStopPos.Y();}

  /**
   * A z position along the track. Gives the stopping z position. 
   */
  Double_t Z() const {return fStopPos.Z();}

  /**
   * A t along the track.  Gives the stopping t.
   */
  Double_t T() const {return fStopT;}

  /**
   * gives the stopping positition as a position on the track
   */
  I3Position Pos() const {return fStopPos;}

  /**
   * sets the stopping positition as a position on the track
   */
  void Pos(I3Position& p) {fStopPos = p;}

  /**
   * gives the zenith of the track
   */
  Double_t Zenith() const {return fZenith;}

  /**
   * gives the azimuth of the track
   */
  Double_t Azimuth() const {return fAzimuth;}

  /**
   * sets the zenith of the track
   */
  void Zenith(Double_t theta){fZenith = theta;}

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
  Double_t StopX() const {return fStopPos.X();}

  /**
   * gives the stopping y position of the track
   */
  Double_t StopY() const {return fStopPos.Y();}

  /**
   * gives the stopping z position of the track
   */
  Double_t StopZ() const {return fStopPos.Z();}

  /**
   * sets the stopping x position of the track
   */
  void StopX(Double_t stopx) {fStopPos.SetX(stopx);}

  /**
   * sets the stopping y position of the track
   */
  void StopY(Double_t stopy) {fStopPos.SetY(stopy);}

  /**
   * sets the stopping z position of the track
   */
  void StopZ(Double_t stopz) {fStopPos.SetZ(stopz);}

  /**
   * gives the stopping t of the track
   */
  Double_t StopT() const {return fStopT;}

  /**
   * sets the stoppign t of the track
   */
  void StopT(Double_t stopt) {fStopT = stopt;}

  /**
   * gets the stopping position
   */
  I3Position StopPos() const {return fStopPos;}

  /**
   * sets the stopping position
   */
  void StopPos(I3Position& p) {fStopPos = p;}

  /**
   * sets the stopping position in any reference frame
   */
  void StopPos(Double_t stopp1, Double_t stopp2, Double_t stopp3, 
		I3Position::RefFrame frame)
    {fStopPos.SetPosition(stopp1,stopp2,stopp3,frame);}

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
