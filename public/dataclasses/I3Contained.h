/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Contained.h,v 1.22 2005/04/04 15:49:25 pretz Exp $
 *
 * @file I3Contained.h
 * @version $Revision: 1.22 $
 * @date $Date: 2005/04/04 15:49:25 $
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
  double fStartT;
  //double fZenith;
  //double fAzimuth;
  double fLength;

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
  double GetStartT() const {return fStartT;}

  /**
   * sets the starting time
   */
  void SetStartT(double startt) {fStartT = startt;}

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
  void SetStartPos(double startp1, double startp2, double startp3, 
		I3Position::RefFrame frame=I3Position::car)
    {fStartPos.SetPosition(startp1,startp2,startp3,frame);}

  /**
   * returns the starting time as corresponding to X,Y,Z
   */
  double GetT() const {return fStartT;}

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
  void SetPos(double startp1, double startp2, double startp3, 
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
  void SetDir(double zen, double azi) {fDir.SetDirection(zen,azi);}

  /**
   * sets the direction of the track
   */
  void SetDir(double x, double y, double z) 
    {fDir.SetDirection(x,y,z);}

  /**
   * gives the zenith of the track
   */
  //double GetZenith() const {return fZenith;}
  double GetZenith() const {return fDir.GetZenith();}

  /**
   * gives the azimuth of the track
   */
  //double GetAzimuth() const {return fAzimuth;}
  double GetAzimuth() const {return fDir.GetAzimuth();}

  /**
   * sets the zenith of the track
   */
  //void SetZenith(double theta){fZenith = theta;}
  void SetZenith(double zen) {
    fDir.SetDirection(zen,fDir.GetAzimuth());}

  /**
   * sets the azimuth of the track
   */
  //void SetAzimuth(double phi){fAzimuth = phi;}
  void SetAzimuth(double azi) {
    fDir.SetDirection(fDir.GetZenith(),azi);}

  /**
   * gives the length of the track
   */
  double GetLength() const {return fLength;}

  /**
   * sets the length of the track
   */
  void SetLength(double length) {fLength = length;}

  /**
   * computes the stopping t of the track
   */
  double GetStopT() const 
    {
      return fStartT + fLength / GetSpeed();
    }
  
  /**
   * computes the stopping position of the track
   */
  I3Position GetStopPos() const
    {
      I3Position p;
      double x,y,z;
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
  double GetSpeed() const {return I3Constants::c;}

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
      o<<"Geometry: Contained\n"
       <<"StartPosition:\n"<<fStartPos
       <<"StopPosition:\n"<<GetStopPos()
       <<"Direction:\n"<<fDir
       <<"StartTime: "<<fStartT<<"\n"
       <<"StopTime: "<<GetStopT()<<"\n";
    }

  private:
    //ROOT macro
  ClassDef(I3Contained,1)
};

#endif //I3CONTAINED_H
