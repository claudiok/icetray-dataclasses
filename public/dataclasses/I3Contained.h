/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Contained.h,v 1.16 2004/09/24 22:48:14 dule Exp $
 *
 * @file I3Contained.h
 * @version $Revision: 1.16 $
 * @date $Date: 2004/09/24 22:48:14 $
 * @author pretz
 */
#ifndef I3CONTAINED_H
#define I3CONTAINED_H

#include "I3Units.h"
#include "I3Constants.h"
#include <cmath>
/**
 * @brief This class services the 'geometrical' part of an I3Track interface.
 *
 * Has a starting postion, a length, and a direction.  So the full interface
 * is implemented.  Assumes the particle is relativistic.
 */
class I3Contained
{
 private:
  I3Position fStartPos;
  I3Direction fDir;
  Double_t fStartT;
  //Double_t fZenith;
  //Double_t fAzimuth;
  Double_t fLength;
 public:
  /**
   * indicates that the track is starting
   */
  Bool_t IsStarting() const {return true;}

  /**
   * indicates that the track is stopping
   */
  Bool_t IsStopping() const {return true;}

  /**
   * indicates that the track has a direction
   */
  Bool_t HasDirection() const {return true;}

  /**
   * gets the starting time
   */
  Double_t GetStartT() const {return fStartT;}

  /**
   * sets the starting time
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
		I3Position::RefFrame frame=I3Position::car)
    {fStartPos.SetPosition(startp1,startp2,startp3,frame);}

  /**
   * returns the starting time as corresponding to X,Y,Z
   */
  Double_t GetT() const {return fStartT;}

  /**
   * gives the starting positition as a position on the track
   */
  I3Position GetPos() const {return fStartPos;}

  /**
   * sets the starting positition as a position on the track
   */
  void SetPos(I3Position& p) {fStartPos = p;}

  /**
   * sets the starting position as a position along the track
   * in any reference frame
   */
  void SetPos(Double_t startp1, Double_t startp2, Double_t startp3, 
		I3Position::RefFrame frame=I3Position::car)
    {fStartPos.SetPosition(startp1,startp2,startp3,frame);}

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
   * gives the zenith of the track
   */
  //Double_t GetZenith() const {return fZenith;}
  Double_t GetZenith() const {return GetDir().GetZenith();}

  /**
   * gives the azimuth of the track
   */
  //Double_t GetAzimuth() const {return fAzimuth;}
  Double_t GetAzimuth() const {return GetDir().GetAzimuth();}

  /**
   * sets the zenith of the track
   */
  //void SetZenith(Double_t theta){fZenith = theta;}
  void SetZenith(Double_t zen) {
    GetDir().SetDirection(zen,GetDir().GetAzimuth());}

  /**
   * sets the azimuth of the track
   */
  //void SetAzimuth(Double_t phi){fAzimuth = phi;}
  void SetAzimuth(Double_t azi) {
    GetDir().SetDirection(GetDir().GetZenith(),azi);}

  /**
   * gives the length of the track
   */
  Double_t GetLength() const {return fLength;}

  /**
   * sets the length of the track
   */
  void SetLength(Double_t length) {fLength = length;}

  /**
   * computes the stopping t of the track
   */
  Double_t GetStopT() const 
    {
      return fStartT + fLength / GetSpeed();
    }
  
  /**
   * computes the stopping position of the track
   */
  I3Position GetStopPos() const
    {
      I3Position p;
      Double_t x,y,z;
      x=fStartPos.GetX()-fLength*sin(fDir.GetZenith())*cos(fDir.GetAzimuth());
      y=fStartPos.GetY()-fLength*sin(fDir.GetZenith())*sin(fDir.GetAzimuth());
      z=fStartPos.GetZ()-fLength*cos(fDir.GetZenith());
      // According to IceCube angle definitions, zenith and azimuth are
      // defined for the minus track direction, i.e. where the track came from
      // This means that there is a minus sign in the calculations.
      p.SetPosition(x,y,z,I3Position::car);
      return p;
/*       return I3Distance::ShiftAlongTrack(this, fLength); */
    }

  /**
   * returns the speed of light
   */
  Double_t GetSpeed() const {return I3Constants::c;}

  /**
   * copies all the interal data into destination if a dynamic cast
   * to I3Contained succeeds
   */
  void CopyTo(I3Particle& destination) const
    {
      I3Contained* contained = dynamic_cast<I3Contained*>(&destination);
      if(contained){
	contained->fStartPos = fStartPos;
	contained->fDir = fDir;
	contained->fStartT = fStartT;
	contained->fLength = fLength;
      }
    }

  virtual void ToStream(ostream& o) const
    {
      o<<"Starting Position:\n"<<fStartPos
       <<"Direction:\n"<<fDir
       <<"Starting Time:"<<fStartT<<"\n";
    }

  private:
    //ROOT macro
  ClassDef(I3Contained,1)
};

#endif //I3CONTAINED_H
