/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Stopping.h,v 1.20 2005/04/04 15:49:25 pretz Exp $
 *
 * @file I3Stopping.h
 * @version $Revision: 1.20 $
 * @date $Date: 2005/04/04 15:49:25 $
 * @author pretz
 */
#ifndef I3STOPPING_H
#define I3STOPPING_H

#include <cmath>
#include "I3Units.h"
#include "I3Constants.h"

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
  I3Position fStopPos;
  I3Direction fDir;
  double fStopT;
  //double fZenith;
  //double fAzimuth;
 public:
  virtual ~I3Stopping() {}
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
  double GetT() const {return fStopT;}

  /**
   * gives the stopping positition as a position on the track
   */
  I3Position GetPos() const {return fStopPos;}

  /**
   * sets the stopping positition as a position on the track
   */
  void SetPos(I3Position& p) {fStopPos = p;}

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
   * returns the length of the track as infinite
   */
  double GetLength() const {return INFINITY;}

  /**
   * gives the stopping t of the track
   */
  double GetStopT() const {return fStopT;}

  /**
   * sets the stoppign t of the track
   */
  void SetStopT(double stopt) {fStopT = stopt;}

  /**
   * gets the stopping position
   */
  I3Position GetStopPos() const {return fStopPos;}

  /**
   * sets the stopping position
   */
  void SetStopPos(I3Position& p) {fStopPos = p;}

  /**
   * sets the stopping position in any reference frame
   */
  void SetStopPos(double stopp1, double stopp2, double stopp3, 
		I3Position::RefFrame frame=I3Position::car)
    {fStopPos.SetPosition(stopp1,stopp2,stopp3,frame);}

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
	stopping->fStopPos = fStopPos;
	stopping->fDir = fDir;
	stopping->fStopT = fStopT;
      }
    }

  virtual void ToStream(ostream& o) const
    {
      o<<"Geometry: Stopping\n"
       <<"StopPosition:\n"<<fStopPos
       <<"Direction:\n"<<fDir
       <<"StopTime: "<<fStopT<<"\n";
    }
 private:
  // ROOT macro
  ClassDef(I3Stopping,1)
};

#endif //I3STOPPING_H
