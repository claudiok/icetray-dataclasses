/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Infinite.h,v 1.6 2004/06/14 22:28:14 dule Exp $
 *
 * @file I3Infinite.h
 * @version $Revision: 1.6 $
 * @date $Date: 2004/06/14 22:28:14 $
 * @author 
 */

#ifndef I3INFINITE_H
#define I3INFINITE_H

#include <cmath>
#include "I3Units.h"
#include "NanPolicy.h"

/**
 * @brief The geometrical part of an I3Track implementation, representing an 
 * infinite track.
 */
class I3Infinite{
 private:
/*   Double_t fX; */
/*   Double_t fY; */
/*   Double_t fZ; */
  I3Position fPos;
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
  Bool_t HasDirection() const {return true;}

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
   * should not be used.  Calls Fatal().
   */
  I3Position StartPos() const 
    {
      NanPolicy::Fatal();
      I3Position p;
      p.NullPosition();
      return p;
    }

  /**
   * gives an x position of the track
   */
  Double_t X() const {return fPos.X();}

  /**
   * gives an y position of the track
   */
  Double_t Y() const {return fPos.Y();}

  /**
   * gives an z position of the track
   */
  Double_t Z() const {return fPos.Z();}

  /**
   * sets an x position for the track
   */
  void X(Double_t x) {fPos.X(x);}

  /**
   * sets an y position for the track
   */
  void Y(Double_t y) {fPos.Y(y);}

  /**
   * sets an z position for the track
   */
  void Z(Double_t z){fPos.Z(z);}

  /**
   * the time the track was at X(), Y(), and Z()
   */ 
  Double_t T() const {return fT;}

  /**
   * sets the time the track was at X(), Y(), Z()
   */
  void T(Double_t t){fT = t;}

  /**
   * gets a position along the track.
   */
  I3Position Pos() const {return fPos;}

  /**
   * sets a position along the track.
   */
  void Pos(I3Position& p) {fPos.SetPosition(p);}

  /**
   * sets a position along the track in any reference frame.
   */
  void Pos(Double_t p1, Double_t p2, Double_t p3, 
		I3Position::RefFrame frame)
    {fPos.SetPosition(p1,p2,p3,frame);}

  /**
   * gets the zenith of the track
   */
  Double_t Zenith() const {return fZenith;}

  /**
   * gets the azimuth of the track
   */
  Double_t Azimuth() const {return fAzimuth;}

  /**
   * sets the zenith of the track
   */
  void Zenith(Double_t zenith) {fZenith = zenith;}

  /**
   * sets the azimuth of the track
   */
  void Azimuth(Double_t azimuth) {fAzimuth = azimuth;}

  /**
   * returns the length of the track ... infinite
   */
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

  /**
   * should not be used.  Calls Fatal().
   */
  I3Position StopPos() const 
    {
      NanPolicy::Fatal();
      I3Position p;
      p.NullPosition();
      return p;
    }

  /**
   * returns the speed of light
   */
  Double_t Speed() const {return 300000000 * I3Units::m / I3Units::s;}

  /**
   * copys this particle's data to the destination particle if the destination
   * particle can be dynamic_cast to I3Infinite
   */
  void CopyTo(I3Particle& destination) const
    {
      I3Infinite* infinite = dynamic_cast<I3Infinite*>(&destination);
      if(infinite){
	infinite->fPos = fPos;
	infinite->fZenith = fZenith;
	infinite->fAzimuth = fAzimuth;
      }
    }

  private:
  //ROOT Macro
  ClassDef(I3Infinite,1)
};

#endif //I3INFINITE_H
