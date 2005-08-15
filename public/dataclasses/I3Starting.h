/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file I3Starting.h
 * @version $Revision: 1.22 $
 * @date $Date$
 * @author pretz
 */
#ifndef I3STARTING_H
#define I3STARTING_H

#include <cmath>
#include "I3Units.h"
#include "I3Constants.h"
#include "I3Position.h"
#include "I3Direction.h"
#include "I3Particle.h"

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
  I3Position startPos_;
  I3Direction dir_;
  double startT_;

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
  double GetStartT() const {return startT_;}

  /**
   * sets the starting t
   */
  void SetStartT(double startt) {startT_ = startt;}

  /**
   * gets the starting position
   */
  const I3Position& GetStartPos() const {return startPos_;}

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
   * gives the starting t time as a time corresponding to X(), Y(), Z()
   */
  double GetT() const {return startT_;}

  /**
   * gives the starting positition as a position on the track
   */
  const I3Position& GetPos() const {return startPos_;}

  /**
   * sets the starting positition as a position on the track
   */
  void SetPos(I3Position &p) {startPos_ = p;}

  /**
   * gets the direction of the track
   */
  const I3Direction& GetDir() const {return dir_;}

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
    {
      dir_.SetDirection(x,y,z);
    }

  /**
   * gives the zenith of the track
   */
  //double GetZenith() const {return fZenith;}
  double GetZenith() const {return dir_.GetZenith();}

  /**
   * gives the azimuth of the track
   */
  //double GetAzimuth() const {return fAzimuth;}
  double GetAzimuth() const {return dir_.GetAzimuth();}

  /** 
   * sets the zenith of the track
   */
  //void SetZenith(double theta){fZenith = theta;}
  void SetZenith(double zen) {
    dir_.SetDirection(zen,dir_.GetAzimuth());}

  /** 
   * sets the azimuth of the track
   */
  //void SetAzimuth(double phi){fAzimuth = phi;}
  void SetAzimuth(double azi) {
    dir_.SetDirection(dir_.GetZenith(),azi);}

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
      starting->startPos_ = startPos_;
      starting->dir_ = dir_;
      starting->startT_ = startT_;
    }
  }

  virtual void ToStream(ostream& o) const
    {
      o<<"Geometry: Starting\n"
       <<"StartPosition:\n"<<startPos_
       <<"Direction:\n"<<dir_
       <<"StartTime: "<<startT_<<"\n";
    }

 protected:

  friend class boost::serialization::access;

  template <class Archive>
  void serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("StartPos",startPos_);
    ar & make_nvp("Dir",dir_);
    ar & make_nvp("StartT",startT_);
  }

  // ROOT macro
  ClassDef(I3Starting,1)
};

#endif //I3STARTING_H
