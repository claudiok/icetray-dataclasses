/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Infinite.h,v 1.17 2004/09/24 22:48:14 dule Exp $
 *
 * @file I3Infinite.h
 * @version $Revision: 1.17 $
 * @date $Date: 2004/09/24 22:48:14 $
 * @author 
 */

#ifndef I3INFINITE_H
#define I3INFINITE_H

#include <cmath>
#include "I3Units.h"
#include "I3Constants.h"

/**
 * @brief The geometrical part of an I3Track implementation, representing an 
 * infinite track.
 */
class I3Infinite{
 private:
  I3Position fPos;
  I3Direction fDir;
  Double_t fT;
  //Double_t fZenith;
  //Double_t fAzimuth;
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
	      I3Position::RefFrame frame=I3Position::car)
    {fPos.SetPosition(p1,p2,p3,frame);}

  /**
   * gets the direction of the track
   */
  I3Direction GetDir() const {return fDir;}

  /**
   * sets the direction of the track
   */
  void SetDir(I3Direction& d) {fDir.SetDirection(d);}

  /**
   * sets the direction of the track
   */
  void SetDir(Double_t zen, Double_t azi) {fDir.SetDirection(zen,azi);}

  /**
   * sets the direction of the track
   */
  void SetDir(Double_t x, Double_t y, Double_t z) 
    {fDir.SetDirection(x,y,z);}

  /**
   * gets the zenith of the track
   */
  Double_t GetZenith() const {return GetDir().GetZenith();}

  /**
   * gets the azimuth of the track
   */
  Double_t GetAzimuth() const {return GetDir().GetAzimuth();}

  /**
   * sets the zenith of the track
   */
  void SetZenith(Double_t zen) {
    GetDir().SetDirection(zen,GetDir().GetAzimuth());}

  /**
   * sets the azimuth of the track
   */
  void SetAzimuth(Double_t azi) {
    GetDir().SetDirection(GetDir().GetZenith(),azi);}

  /**
   * returns the length of the track ... infinite
   */
  Double_t GetLength() const {return INFINITY;}

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
	infinite->fDir = fDir;
	infinite->fT = fT;
      }
    }

  virtual void ToStream(ostream& o) const
    {
      o<<"Position:\n"<<fPos
       <<"Direction:\n"<<fDir
       <<"Time: "<<fT<<"\n";
    }

  private:
  //ROOT Macro
  ClassDef(I3Infinite,1)
};

#endif //I3INFINITE_H
