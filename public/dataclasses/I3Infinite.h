/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Infinite.h,v 1.7 2004/06/30 17:20:26 pretz Exp $
 *
 * @file I3Infinite.h
 * @version $Revision: 1.7 $
 * @date $Date: 2004/06/30 17:20:26 $
 * @author 
 */

#ifndef I3INFINITE_H
#define I3INFINITE_H

#include <cmath>
#include "I3Units.h"
#include "NanPolicy.h"
#include "I3Constants.h"

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
  Double_t GetStartX() const 
    {
      NanPolicy::Fatal();
      return NAN;
    }

  /**
   * should not be used.  Calls Fatal().
   */
  Double_t GetStartY() const 
    {
      NanPolicy::Fatal();
      return NAN;
    }

  /**
   * should not be used.  Calls Fatal().
   */
  Double_t GetStartZ() const 
    {
      NanPolicy::Fatal();
      return NAN;
    }

  /**
   * should not be used.  Calls Fatal().
   */
  Double_t GetStartT() const 
    {
      NanPolicy::Fatal();
      return NAN;
    }

  /**
   * should not be used.  Calls Fatal().
   */
  I3Position GetStartPos() const 
    {
      NanPolicy::Fatal();
      I3Position p;
      p.NullPosition();
      return p;
    }

  /**
   * gives an x position of the track
   */
  Double_t GetX() const {return fPos.GetX();}

  /**
   * gives an y position of the track
   */
  Double_t GetY() const {return fPos.GetY();}

  /**
   * gives an z position of the track
   */
  Double_t GetZ() const {return fPos.GetZ();}

  /**
   * sets an x position for the track
   */
  void SetX(Double_t x) {fPos.SetX(x);}

  /**
   * sets an y position for the track
   */
  void SetY(Double_t y) {fPos.SetY(y);}

  /**
   * sets an z position for the track
   */
  void SetZ(Double_t z){fPos.SetZ(z);}

  /**
   * the time the track was at X(), Y(), and Z()
   */ 
  Double_t GetT() const {return fT;}

  /**
   * sets the time the track was at X(), Y(), Z()
   */
  void SetT(Double_t t){fT = t;}

  /**
   * gets a position along the track.
   */
  I3Position GetPos() const {return fPos;}

  /**
   * sets a position along the track.
   */
  void SetPos(I3Position& p) {fPos.SetPosition(p);}

  /**
   * sets a position along the track in any reference frame.
   */
  void SetPos(Double_t p1, Double_t p2, Double_t p3, 
	      I3Position::RefFrame frame)
    {fPos.SetPosition(p1,p2,p3,frame);}

  /**
   * gets the zenith of the track
   */
  Double_t GetZenith() const {return fZenith;}

  /**
   * gets the azimuth of the track
   */
  Double_t GetAzimuth() const {return fAzimuth;}

  /**
   * sets the zenith of the track
   */
  void SetZenith(Double_t zenith) {fZenith = zenith;}

  /**
   * sets the azimuth of the track
   */
  void SetAzimuth(Double_t azimuth) {fAzimuth = azimuth;}

  /**
   * returns the length of the track ... infinite
   */
  Double_t GetLength() const {return INFINITY;}

  /**
   * should not be used.  Calls Fatal().
   */
  Double_t GetStopX() const 
    {
      NanPolicy::Fatal();
      return NAN;
    }

  /**
   * should not be used.  Calls Fatal().
   */
  Double_t GetStopY() const 
    {
      NanPolicy::Fatal();
      return NAN;
    }

  /**
   * should not be used.  Calls Fatal().
   */
  Double_t GetStopZ() const 
    {
      NanPolicy::Fatal();
      return NAN;
    }

  /**
   * should not be used.  Calls Fatal().
   */
  Double_t GetStopT() const 
    {
      NanPolicy::Fatal();
      return NAN;
    }

  /**
   * should not be used.  Calls Fatal().
   */
  I3Position GetStopPos() const 
    {
      NanPolicy::Fatal();
      I3Position p;
      p.NullPosition();
      return p;
    }

  /**
   * returns the speed of light
   */
  Double_t GetSpeed() const {return I3Constants::c;}

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
