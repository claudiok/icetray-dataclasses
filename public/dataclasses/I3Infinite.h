/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Infinite.h,v 1.1.2.5 2004/04/21 20:17:43 pretz Exp $
 *
 * @file 
 * @version $Revision: 1.1.2.5 $
 * @date $Date: 2004/04/21 20:17:43 $
 * @author 
 *
 * @todo
 *
 */

#ifndef I3INFINITE_H
#define I3INFINITE_H

#include <cmath>
#include "I3Units.h"
#include "NanPolicy.h"

class I3Infinite{
 private:
  Double_t fX;
  Double_t fY;
  Double_t fZ;
  Double_t fT;
  Double_t fZenith;
  Double_t fAzimuth;
 public:
  /**
   * indicates that this is not a starting track
   */ 
  Bool_t IsStarting() const {return false;}

  /**
   * indicates that this is not a stopping track
   */
  Bool_t IsStopping() const {return false;}

  /**
   * indicates that this is a directional track
   */ 
  Bool_t IsDirectional() const {return true;}

  /**
   * should not be used.  Calls Fatal().
   */
  Double_t StartX() const 
    {
      NanPolicy::Fatal();
      return NAN;
    }

  /**
   * should not be used.  Calls Fatal().
   */
  Double_t StartY() const 
    {
      NanPolicy::Fatal();
      return NAN;
    }
  
  /**
   * should not be used.  Calls Fatal().
   */
  Double_t StartZ() const 
    {
      NanPolicy::Fatal();
      return NAN;
    }

  /**
   * should not be used.  Calls Fatal().
   */
  Double_t StartT() const 
    {
      NanPolicy::Fatal();
      return NAN;
    }

  /**
   * gives an x position of the track
   */
  Double_t X() const {return fX;}

  /**
   * sets an x position for the track
   */
  void X(Double_t x) {fX = x;}

  /**
   * returns a y position of the track
   */
  Double_t Y() const {return fY;}

  /**
   * sets a y position of the track
   */
  void Y(Double_t y) {fY = y;}

  /**
   * gets a z position along the track.
   */
  Double_t Z() const {return fZ;}

  /**
   * sets a z position along the track
   */
  void Z(Double_t z){fZ = z;}

  /**
   * the time the track was at X(), Y(), and Z()
   */ 
  Double_t T() const {return fT;}

  /**
   * sets the time the track was at X(), Y(), Z()
   */
  void T(Double_t t){fT = t;}

  Double_t Zenith() const {return fZenith;}
  void Zenith(Double_t zenith) {fZenith = zenith;}

  Double_t Azimuth() const {return fAzimuth;}
  void Azimuth(Double_t azimuth) {fAzimuth = azimuth;}

  Double_t Length() const {return INFINITY;}

  /**
   * should not be used.  Calls Fatal().
   */
  Double_t StopX() const 
    {
      NanPolicy::Fatal();
      return NAN;
    }

  /**
   * should not be used.  Calls Fatal().
   */
  Double_t StopY() const 
    {
      NanPolicy::Fatal();
      return NAN;
    }

  /**
   * should not be used.  Calls Fatal().
   */
  Double_t StopZ() const 
    {
      NanPolicy::Fatal();
      return NAN;
    }

  /**
   * should not be used.  Calls Fatal().
   */
  Double_t StopT() const 
    {
      NanPolicy::Fatal();
      return NAN;
    }

  Double_t Speed() const {return 300000000 * I3Units::m / I3Units::s;}

  void CopyTo(I3Particle& destination) const
    {
      I3Infinite* infinite = dynamic_cast<I3Infinite*>(&destination);
      if(infinite){
	infinite->fX = fX;
	infinite->fY = fY;
	infinite->fZ = fZ;
	infinite->fZenith = fZenith;
	infinite->fAzimuth = fAzimuth;
      }
    }

  ClassDef(I3Infinite,1)
};

#endif //I3INFINITE_H
