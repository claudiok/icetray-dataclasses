/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Starting.h,v 1.8 2004/07/26 13:53:55 pretz Exp $
 *
 * @file I3Starting.h
 * @version $Revision: 1.8 $
 * @date $Date: 2004/07/26 13:53:55 $
 * @author pretz
 */
#ifndef I3STARTING_H
#define I3STARTING_H

#include <cmath>
#include "I3Units.h"
#include "I3Particle.h"
#include "I3Position.h"
#include "I3Constants.h"


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
  Double_t GetStartX() const {return fStartPos.GetX();}

  /**
   * gives the starting y position of the particle
   */
  Double_t GetStartY() const {return fStartPos.GetY();}

  /**
   * gives the starting z position of the particle
   */
  Double_t GetStartZ() const {return fStartPos.GetZ();}

  /**
   * sets the starting x position of the particle
   */
  void GetStartX(Double_t startx){fStartPos.SetX(startx);}

  /**
   * sets the starting y position of the particle
   */
  void GetStartY(Double_t starty){fStartPos.SetY(starty);}

  /**
   * sets the starting z position of the particle
   */
  void SetStartZ(Double_t startz){fStartPos.SetZ(startz);}

  /**
   * gets the starting t
   */
  Double_t GetStartT() const {return fStartT;}

  /**
   * sets the starting t
   */
  void SetStartT(Double_t startt) {fStartT = startt;}

  /**
   * gets the starting position
   */
  I3Position GetStartPos() const {return fStartPos;}

  /**
   * sets the starting position
   */
  void SetStartPos(I3Position& p) {fStartPos = p;}

  /**
   * sets the starting position in any reference frame
   */
  void SetStartPos(Double_t startp1, Double_t startp2, Double_t startp3, 
		I3Position::RefFrame frame)
    {fStartPos.SetPosition(startp1,startp2,startp3,frame);}

  /**
   * gives the starting x position as a position on the track
   */
  Double_t GetX() const {return fStartPos.GetX();}

  /**
   * gives the starting y position as a position on the track
   */
  Double_t GetY() const {return fStartPos.GetY();}

  /**
   * gives the starting z position as a position on the track
   */
  Double_t GetZ() const {return fStartPos.GetZ();}

  /**
   * gives the starting t time as a time corresponding to X(), Y(), Z()
   */
  Double_t GetT() const {return fStartT;}

  /**
   * gives the starting positition as a position on the track
   */
  I3Position GetPos() const {return fStartPos;}

  /**
   * sets the starting positition as a position on the track
   */
  void SetPos(I3Position &p) {fStartPos = p;}

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
   * returns Infinity for the length of the track
   */
  Double_t GetLength() const {return INFINITY;}

  /**
   * returns the speed of light
   */ 
  Double_t GetSpeed() const {return I3Constants::c;}

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
