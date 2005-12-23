/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file I3Stopping.h
 * @version $Revision: 1.21 $
 * @date $Date$
 * @author pretz
 */
#ifndef I3STOPPING_H
#define I3STOPPING_H

#include <cmath>
#include "dataclasses/I3Constants.h"
#include "dataclasses/I3Position.h"
#include "dataclasses/I3Direction.h"
#include "dataclasses/physics/I3Particle.h"

/**
 * @brief This class services the 'geometrical' part of the I3Track interface.
 *
 * Defines a stopping position, and stopping time.  Also, a Zenith and Azimuth
 * But if you mess with StartX, StartY, StartZ or StartT, you get a fatal error
 *
 */
class I3Stopping
{
 private:
  I3Position stopPos_;
  I3Direction dir_;
  double stopT_;

 public:
  virtual ~I3Stopping();
  /**
   * indicates that the particle is stopping
   */
  bool IsStopping() const {return true;}

  /**
   * indicates that the particle isn't starting
   */
  bool IsStarting() const {return false;}

  /**
   * indicates that the particle is directional
   */
  bool HasDirection() const {return true;}

  /**
   * A t along the track.  Gives the stopping t.
   */
  double GetT() const {return stopT_;}

  /**
   * gives the stopping positition as a position on the track
   */
  const I3Position& GetPos() const {return stopPos_;}

  /**
   * sets the stopping positition as a position on the track
   */
  void SetPos(const I3Position& p) {stopPos_ = p;}

  /**
   * gets the direction of the track
   */
  const I3Direction& GetDir() const {return dir_;}

  /**
   * sets the direction of the track
   */
  void SetDir(const I3Direction& d) {dir_.SetDirection(d);}

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
   * returns the length of the track as infinite
   */
  double GetLength() const {return INFINITY;}

  /**
   * gives the stopping t of the track
   */
  double GetStopT() const {return stopT_;}

  /**
   * sets the stoppign t of the track
   */
  void SetStopT(double stopt) {stopT_ = stopt;}

  /**
   * gets the stopping position
   */
  const I3Position& GetStopPos() const {return stopPos_;}

  /**
   * sets the stopping position
   */
  void SetStopPos(const I3Position& p) {stopPos_ = p;}

  /**
   * sets the stopping position in any reference frame
   */
  void SetStopPos(double stopp1, double stopp2, double stopp3, 
		I3Position::RefFrame frame=I3Position::car)
    {stopPos_.SetPosition(stopp1,stopp2,stopp3,frame);}

  /**
   * gives the speed of light for the speed.
   */
  double GetSpeed() const {return I3Constants::c;}

  /**
   * copies the 'stopping' data into  the destination particle if a 
   * dynamic cast succeeds.  just returns otherwise.
   */ 
  void CopyTo(I3Particle& destination) const
    {
      I3Stopping* stopping = dynamic_cast<I3Stopping*>(&destination);
      if(stopping){
	stopping->stopPos_ = stopPos_;
	stopping->dir_ = dir_;
	stopping->stopT_ = stopT_;
      }
    }

  virtual void ToStream(ostream& o) const
    {
      o<<"Geometry: Stopping\n"
       <<"StopPosition:\n"<<stopPos_
       <<"Direction:\n"<<dir_
       <<"StopTime: "<<stopT_<<"\n";
    }
 private:

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
// ROOT macro
  //ClassDef(I3Stopping,1)
};

#endif //I3STOPPING_H

