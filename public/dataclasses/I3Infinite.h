/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file I3Infinite.h
 * @version $Revision: 1.23 $
 * @date $Date$
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
class I3Infinite
{
 private:
  I3Position pos_;
  I3Direction dir_;
  double time_;

 public:

  virtual ~I3Infinite() {}
  /**
   * indicates that this is not a starting track
   */ 
  bool IsStarting() const {return false;}

  /**
   * indicates that this is not a stopping track
   */
  bool IsStopping() const {return false;}

  /**
   * indicates that this is a directional track
   */ 
  bool HasDirection() const {return true;}

  /**
   * the time the track was at X(), Y(), and Z()
   */ 
  double GetT() const {return time_;}

  /**
   * sets the time the track was at X(), Y(), Z()
   */
  void SetT(double t){time_ = t;}

  /**
   * gets a position along the track.
   */
  const I3Position& GetPos() const {return pos_;}

  /**
   * sets a position along the track.
   */
  void SetPos(I3Position& p) {pos_.SetPosition(p);}

  /**
   * sets a position along the track in any reference frame.
   */
  void SetPos(double p1, double p2, double p3, 
	      I3Position::RefFrame frame=I3Position::car)
    {pos_.SetPosition(p1,p2,p3,frame);}

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
    {dir_.SetDirection(x,y,z);}

  /**
   * gets the zenith of the track
   */
  double GetZenith() const {return dir_.GetZenith();}

  /**
   * gets the azimuth of the track
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
   * returns the length of the track ... infinite
   */
  double GetLength() const {return INFINITY;}

  /**
   * returns the speed of light
   */
  double GetSpeed() const {return I3Constants::c;}

  /**
   * copys this particle's data to the destination particle if the destination
   * particle can be dynamic_cast to I3Infinite
   */
  void CopyTo(I3Particle& destination) const
    {
      I3Infinite* infinite = dynamic_cast<I3Infinite*>(&destination);
      if(infinite){
	infinite->pos_ = pos_;
	infinite->dir_ = dir_;
	infinite->time_ = time_;
      }
    }

  virtual void ToStream(ostream& o) const
    {
      o<<"Geometry: Infinite\n"
       <<"Position:\n"<<pos_
       <<"Direction:\n"<<dir_
       <<"Time: "<<time_<<"\n";
    }

  private:
  friend class boost::serialization::access;

  template <class Archive>
  void serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("Pos", pos_ );
    ar & make_nvp("Dir", dir_ );
    ar & make_nvp("Time", time_ );
  }
  //ROOT Macro
  ClassDef(I3Infinite,1)
};

#endif //I3INFINITE_H
