/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Starting.h,v 1.21 2005/04/04 15:49:25 pretz Exp $
 *
 * @file I3Starting.h
 * @version $Revision: 1.21 $
 * @date $Date: 2005/04/04 15:49:25 $
 * @author pretz
 */
#ifndef I3STARTING_H
#define I3STARTING_H

#include <cmath>
#include "I3Units.h"
#include "I3Constants.h"


/**
 * @brief This class services the 'geometrical' part of the I3Track interface.
 *
 * Defines a starting position, and starting time.  Also, a Zenith and Azimuth
 * But if you mess with StopX, StopY, StopZ or StopT, you get a fatal error
 *
 */
class I3Starting 
{
 private:
  I3Position fStartPos;
  I3Direction fDir;
  double fStartT;
  //double fZenith;
  //double fAzimuth;
 public:

  virtual ~I3Starting() {}
  /**
   * indicates that the particle is starting
   */
  bool IsStarting() const {return true;}

  /**
   * indicates that the particle is not stopping
   */
  bool IsStopping() const {return false;}

  /**
   * indicates that the particle has a direction
   */
  bool HasDirection() const {return true;}

  /**
   * gets the starting t
   */
  double GetStartT() const {return fStartT;}

  /**
   * sets the starting t
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
   * gives the starting t time as a time corresponding to X(), Y(), Z()
   */
  double GetT() const {return fStartT;}

  /**
   * gives the starting positition as a position on the track
   */
  I3Position GetPos() const {return fStartPos;}

  /**
   * sets the starting positition as a position on the track
   */
  void SetPos(I3Position &p) {fStartPos = p;}

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
    {
      fDir.SetDirection(x,y,z);
    }

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
   * returns Infinity for the length of the track
   */
  double GetLength() const {return INFINITY;}

  /**
   * returns the speed of light
   */ 
  double GetSpeed() const {return I3Constants::c;}

  /**
   * copies the data to the destination particle, if a dynamic cast succeeds
   */
  void CopyTo(I3Particle& destination) const{
    I3Starting* starting = dynamic_cast<I3Starting*>(&destination);
    if(starting){
      starting->fStartPos = fStartPos;
      starting->fDir = fDir;
      starting->fStartT = fStartT;
    }
  }

  virtual void ToStream(ostream& o) const
    {
      o<<"Geometry: Starting\n"
       <<"StartPosition:\n"<<fStartPos
       <<"Direction:\n"<<fDir
       <<"StartTime: "<<fStartT<<"\n";
    }

 protected:
  // ROOT macro
  ClassDef(I3Starting,1)
};

#endif //I3STARTING_H
