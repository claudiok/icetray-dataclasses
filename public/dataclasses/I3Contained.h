/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Contained.h,v 1.23 2005/04/12 18:55:28 dule Exp $
 *
 * @file I3Contained.h
 * @version $Revision: 1.23 $
 * @date $Date: 2005/04/12 18:55:28 $
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
  I3Position startPos_;
  I3Direction dir_;
  double startT_;
  double length_;

 public:

  virtual ~I3Contained() {}

  /**
   * indicates that the track is starting
   */
  bool IsStarting() const {return true;}

  /**
   * indicates that the track is stopping
   */
  bool IsStopping() const {return true;}

  /**
   * indicates that the track has a direction
   */
  bool HasDirection() const {return true;}

  /**
   * gets the starting time
   */
  double GetStartT() const {return startT_;}

  /**
   * sets the starting time
   */
  void SetStartT(double startt) {startT_ = startt;}

  /**
   * gets the starting position
   */
  I3Position GetStartPos() const {return startPos_;}

  /**
   * sets the starting position
   */
  void SetStartPos(I3Position& p) {startPos_ = p;}

  /**
   * sets the starting position in any reference frame
   */
  void SetStartPos(double startp1, double startp2, double startp3, 
		I3Position::RefFrame frame=I3Position::car)
    {startPos_.SetPosition(startp1,startp2,startp3,frame);}

  /**
   * returns the starting time as corresponding to X,Y,Z
   */
  double GetT() const {return startT_;}

  /**
   * gives the starting positition as a position on the track
   */
  I3Position GetPos() const {return startPos_;}

  /**
   * sets the starting positition as a position on the track
   */
  void SetPos(I3Position& p) {startPos_ = p;}

  /**
   * sets the starting position as a position along the track
   * in any reference frame
   */
  void SetPos(double startp1, double startp2, double startp3, 
		I3Position::RefFrame frame=I3Position::car)
    {startPos_.SetPosition(startp1,startp2,startp3,frame);}

  /**
   * gets the direction of the track
   */
  I3Direction GetDir() const {return dir_;}

  /**
   * sets the direction of the track
   */
  void SetDir(I3Direction& d) {dir_.SetDirection(d);}

  /**
   * sets the direction of the track
   */
  void SetDir(double zen, double azi) {dir_.SetDirection(zen,azi);}

  /**
   * sets the direction of the track
   */
  void SetDir(double x, double y, double z) 
    {dir_.SetDirection(x,y,z);}

  /**
   * gives the zenith of the track
   */
  double GetZenith() const {return dir_.GetZenith();}

  /**
   * gives the azimuth of the track
   */
  double GetAzimuth() const {return dir_.GetAzimuth();}

  /**
   * sets the zenith of the track
   */
  void SetZenith(double zen) {
    dir_.SetDirection(zen,dir_.GetAzimuth());}

  /**
   * sets the azimuth of the track
   */
  void SetAzimuth(double azi) {
    dir_.SetDirection(dir_.GetZenith(),azi);}

  /**
   * gives the length of the track
   */
  double GetLength() const {return length_;}

  /**
   * sets the length of the track
   */
  void SetLength(double length) {length_ = length;}

  /**
   * computes the stopping t of the track
   */
  double GetStopT() const 
    {
      return startT_ + length_ / GetSpeed();
    }
  
  /**
   * computes the stopping position of the track
   */
  I3Position GetStopPos() const
    {
      I3Position p;
      double x,y,z;
      x=startPos_.GetX()-length_*sin(dir_.GetZenith())*cos(dir_.GetAzimuth());
      y=startPos_.GetY()-length_*sin(dir_.GetZenith())*sin(dir_.GetAzimuth());
      z=startPos_.GetZ()-length_*cos(dir_.GetZenith());
      // According to IceCube angle definitions, zenith and azimuth are
      // defined for the minus track direction, i.e. where the track came from
      // This means that there is a minus sign in the calculations.
      p.SetPosition(x,y,z,I3Position::car);
      return p;
/*       return I3Distance::ShiftAlongTrack(this, length_); */
    }

  /**
   * returns the speed of light
   */
  double GetSpeed() const {return I3Constants::c;}

  /**
   * copies all the interal data into destination if a dynamic cast
   * to I3Contained succeeds
   */
  void CopyTo(I3Particle& destination) const
    {
      I3Contained* contained = dynamic_cast<I3Contained*>(&destination);
      if(contained){
	contained->startPos_ = startPos_;
	contained->dir_ = dir_;
	contained->startT_ = startT_;
	contained->length_ = length_;
      }
    }

  virtual void ToStream(ostream& o) const
    {
      o<<"Geometry: Contained\n"
       <<"StartPosition:\n"<<startPos_
       <<"StopPosition:\n"<<GetStopPos()
       <<"Direction:\n"<<dir_
       <<"StartTime: "<<startT_<<"\n"
       <<"StopTime: "<<GetStopT()<<"\n";
    }

  private:
    //ROOT macro
  ClassDef(I3Contained,1)
};

#endif //I3CONTAINED_H
