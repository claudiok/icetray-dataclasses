/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Starting.h,v 1.6 2004/06/14 22:28:14 dule Exp $
 *
 * @file I3Starting.h
 * @version $Revision: 1.6 $
 * @date $Date: 2004/06/14 22:28:14 $
 * @author pretz
 */
#ifndef I3STARTING_H
#define I3STARTING_H

#include <cmath>
#include "I3Units.h"
#include "I3Particle.h"
#include "I3Position.h"

#include "NanPolicy.h"

/**
 * @brief This class services the 'geometrical' part of the I3Track interface.
 *
 * Defines a starting position, and starting time.  Also, a Zenith and Azimuth
 * But if you mess with StopX, StopY, StopZ or StopT, you get a fatal error
 *
 */
class I3Starting{
 private:
/*   Double_t fStartX; */
/*   Double_t fStartY; */
/*   Double_t fStartZ; */
  I3Position fStartPos;
  Double_t fStartT;
  Double_t fZenith;
  Double_t fAzimuth;
 public:
  /**
   * indicates that the particle is starting
   */
  Bool_t IsStarting() const {return true;}

  /**
   * indicates that the particle is not stopping
   */
  Bool_t IsStopping() const {return false;}

  /**
   * indicates that the particle has a direction
   */
  Bool_t HasDirection() const {return true;}

  /**
   * gives the starting x position of the particle
   */
  Double_t StartX() const {return fStartPos.X();}

  /**
   * gives the starting y position of the particle
   */
  Double_t StartY() const {return fStartPos.Y();}

  /**
   * gives the starting z position of the particle
   */
  Double_t StartZ() const {return fStartPos.Z();}

  /**
   * sets the starting x position of the particle
   */
  void StartX(Double_t startx){fStartPos.X(startx);}

  /**
   * sets the starting y position of the particle
   */
  void StartY(Double_t starty){fStartPos.Y(starty);}

  /**
   * sets the starting z position of the particle
   */
  void StartZ(Double_t startz){fStartPos.Z(startz);}

  /**
   * gets the starting t
   */
  Double_t StartT() const {return fStartT;}

  /**
   * sets the starting t
   */
  void StartT(Double_t startt) {fStartT = startt;}

  /**
   * gets the starting position
   */
  I3Position StartPos() const {return fStartPos;}

  /**
   * sets the starting position
   */
  void StartPos(I3Position& p) {fStartPos = p;}

  /**
   * sets the starting position in any reference frame
   */
  void StartPos(Double_t startp1, Double_t startp2, Double_t startp3, 
		I3Position::RefFrame frame)
    {fStartPos.SetPosition(startp1,startp2,startp3,frame);}

  /**
   * gives the starting x position as a position on the track
   */
  Double_t X() const {return fStartPos.X();}

  /**
   * gives the starting y position as a position on the track
   */
  Double_t Y() const {return fStartPos.Y();}

  /**
   * gives the starting z position as a position on the track
   */
  Double_t Z() const {return fStartPos.Z();}

  /**
   * gives the starting t time as a time corresponding to X(), Y(), Z()
   */
  Double_t T() const {return fStartT;}

  /**
   * gives the starting positition as a position on the track
   */
  I3Position Pos() const {return fStartPos;}

  /**
   * sets the starting positition as a position on the track
   */
  void Pos(I3Position &p) {fStartPos = p;}

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
   * returns Infinity for the length of the track
   */
  Double_t Length() const {return INFINITY;}

  /**
   * shouldn't be used.  Calls fatal.
   */
  Double_t StopX() const 
    {
      NanPolicy::Fatal();
      return NAN;
    }

  /**
   * shouldn't be used.  Calls fatal.
   */
  Double_t StopY() const 
    {
      NanPolicy::Fatal();
      return NAN;
    }

  /**
   * shouldn't be used.  Calls fatal.
   */
  Double_t StopZ() const 
    {
      NanPolicy::Fatal();
      return NAN;
    }


  /**
   * shouldn't be used.  Calls fatal.
   */
  Double_t StopT() const 
    {
      NanPolicy::Fatal();
      return NAN;
    }

  /**
   * shouldn't be used.  Calls fatal.
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
   * copies the data to the destination particle, if a dynamic cast succeeds
   */
  void CopyTo(I3Particle& destination) const{
    I3Starting* starting = dynamic_cast<I3Starting*>(&destination);
    if(starting){
      starting->fStartPos = fStartPos;
      starting->fZenith = fZenith;
      starting->fAzimuth = fAzimuth;
    }
  }

 protected:
  // ROOT macro
  ClassDef(I3Starting,1)
};

#endif //I3STARTING_H
