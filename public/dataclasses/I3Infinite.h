/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Infinite.h,v 1.22 2005/04/04 15:49:25 pretz Exp $
 *
 * @file I3Infinite.h
 * @version $Revision: 1.22 $
 * @date $Date: 2005/04/04 15:49:25 $
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
  I3Position fPos;
  I3Direction fDir;
  double fT;
  //double fZenith;
  //double fAzimuth;
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
  double GetT() const {return fT;}

  /**
   * sets the time the track was at X(), Y(), Z()
   */
  void SetT(double t){fT = t;}

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
  void SetPos(double p1, double p2, double p3, 
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
  void SetDir(double zen, double azi) {fDir.SetDirection(zen,azi);}

  /**
   * sets the direction of the track
   */
  void SetDir(double x, double y, double z) 
    {fDir.SetDirection(x,y,z);}

  /**
   * gets the zenith of the track
   */
  double GetZenith() const {return fDir.GetZenith();}

  /**
   * gets the azimuth of the track
   */
  double GetAzimuth() const {return fDir.GetAzimuth();}

  /**
   * sets the zenith of the track
   */
  void SetZenith(double zen) {
    fDir.SetDirection(zen,fDir.GetAzimuth());}

  /**
   * sets the azimuth of the track
   */
  void SetAzimuth(double azi) {
    fDir.SetDirection(fDir.GetZenith(),azi);}

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
	infinite->fPos = fPos;
	infinite->fDir = fDir;
	infinite->fT = fT;
      }
    }

  virtual void ToStream(ostream& o) const
    {
      o<<"Geometry: Infinite\n"
       <<"Position:\n"<<fPos
       <<"Direction:\n"<<fDir
       <<"Time: "<<fT<<"\n";
    }

  private:
  //ROOT Macro
  ClassDef(I3Infinite,1)
};

#endif //I3INFINITE_H
