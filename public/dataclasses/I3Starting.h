/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Starting.h,v 1.1.2.7 2004/04/21 20:17:43 pretz Exp $
 *
 * @file I3Starting.h
 * @version $Revision: 1.1.2.7 $
 * @date $Date: 2004/04/21 20:17:43 $
 * @author pretz
 *
 * @todo
 */
#ifndef I3STARTING_H
#define I3STARTING_H

#include <cmath>
#include "I3Units.h"
#include "I3Particle.h"

#include "NanPolicy.h"

/**
 * This class services the 'geometrical' part of the I3Track interface.
 * Defines a starting position, and starting time.  Also, a Zenith and Azimuth
 * But if you mess with StopX, StopY, StopZ or StopT, you get a fatal error
 *
 */
class I3Starting{
 private:
  Double_t fStartX;
  Double_t fStartY;
  Double_t fStartZ;
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
  Bool_t IsDirectional() const {return true;}

  /**
   * gives the starting x of the particle
   */
  Double_t StartX() const {return fStartX;}

  /**
   * sets the starting x of the particle
   */
  void StartX(Double_t startx){fStartX = startx;}

  /**
   * gets the starting y of the particle
   */
  Double_t StartY() const {return fStartY;}

  /**
   * sets the starting y of the particle
   */
  void StartY(Double_t starty){fStartY = starty;}
  
  /**
   * gets the starting z position
   */
  Double_t StartZ() const {return fStartZ;}

  /**
   * sets the starting z position
   */
  void StartZ(Double_t startz) {fStartZ = startz;}

  /**
   * gets the starting t
   */
  Double_t StartT() const {return fStartT;}

  /**
   * sets the starting t
   */
  void StartT(Double_t startt) {fStartT = startt;}

  /**
   * gives the starting x position as a position on the track
   */
  Double_t X() const {return fStartX;}

  /**
   * gives the starting y position a  a position on the track
   */
  Double_t Y() const {return fStartY;}

  /**
   * gives the starting z positition as a position on the track
   */
  Double_t Z() const {return fStartZ;}

  /**
   * gives the starting t time as a time corresponding to X(), Y() and Z()
   */
  Double_t T() const {return fStartT;}

  /**
   * gives the zenith of the track
   */
  Double_t Zenith() const {return fZenith;}

  /** 
   * sets the zenith of the track
   */
  void Zenith(Double_t theta){fZenith = theta;}

  /**
   * gives the Azimuth of the track
   */
  Double_t Azimuth() const {return fAzimuth;}

  /**
   * sets the Azimuth of the track
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
   * returns the speed of light
   */ 
  Double_t Speed() const {return 300000000 * I3Units::m / I3Units::s;}

  /**
   * copies the data to the destination particle, if a dynamic cast succeeds
   */
  void CopyTo(I3Particle& destination) const{
    I3Starting* starting = dynamic_cast<I3Starting*>(&destination);
    if(starting){
      starting->fStartX = fStartX;
      starting->fStartY = fStartY;
      starting->fStartZ = fStartZ;
      starting->fZenith = fZenith;
      starting->fAzimuth = fAzimuth;
    }
  }

 protected:
  // ROOT macro
  ClassDef(I3Starting,1)
};

#endif //I3STARTING_H
