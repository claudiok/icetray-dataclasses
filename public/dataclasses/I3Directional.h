/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Directional.h,v 1.11 2005/04/08 19:33:23 dule Exp $
 *
 * @file I3Directional.h
 * @version $Revision: 1.11 $
 * @date $Date: 2005/04/08 19:33:23 $
 * @author pretz
 */
#ifndef I3DIRECTIONAL_H
#define I3DIRECTIONAL_H

#include "Rtypes.h"
#include "dataclasses/I3Direction.h"

/**
 * @brief A class which implements the 'directional' aspect of an I3Cascade.
 */
class I3Directional 
{
 private:
  I3Direction dir_;

 public:
  virtual ~I3Directional() {}
  /**
   * indicates that this cascade has a direction
   */
  virtual bool HasDirection() const { return true; }

  /**
   * gets the direction of the track
   */
  I3Direction GetDir() const { return dir_; }

  /**
   * sets the direction of the track
   */
  void SetDir(I3Direction& d) { dir_.SetDirection(d); }

  /**
   * sets the direction of the track
   */
  void SetDir(double zen, double azi) { dir_.SetDirection(zen,azi); }

  /**
   * sets the direction of the track
   */
  void SetDir(double x, double y, double z) { dir_.SetDirection(x,y,z); }

  /**
   * gets the zenith of the cascade
   */
  double GetZenith() const { return dir_.GetZenith(); }

  /**
   * sets the zenith of the cascade
   */
  void SetZenith(double zen) { SetDir(zen,dir_.GetAzimuth()); }

  /**
   * gets the azimuth of the cascade
   */
  double GetAzimuth() const { return dir_.GetAzimuth(); }

  /**
   * sets the Azimuth of the cascade
   */
  void SetAzimuth(double azi) { SetDir(dir_.GetZenith(),azi); }

  /**
	* sets all direction variables to NAN
	*/
  void ResetDir() { dir_.ResetDirection(); }

  /**
   * copies over all the interal data to the destination particle
   * if a dynamic_cast<>() succeeds
   */
  virtual void CopyTo(I3Particle& destination) const {
	  I3Directional* directional = dynamic_cast<I3Directional*>(&destination);
	  if(directional) {
		  directional->dir_ = dir_;
	  }
  }

  virtual void ToStream(ostream& o) const {
	  o<<"Direction:\n"<<dir_<<"\n";
  }

 private:
  //ROOT macro
  ClassDef(I3Directional,1);
};

#endif // I3DIRECTIONAL
