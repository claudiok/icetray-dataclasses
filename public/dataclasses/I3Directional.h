/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Directional.h,v 1.9 2005/04/04 15:49:25 pretz Exp $
 *
 * @file I3Directional.h
 * @version $Revision: 1.9 $
 * @date $Date: 2005/04/04 15:49:25 $
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
  I3Direction fDir;
  //double fZenith;
  //double fAzimuth;
 public:

  virtual ~I3Directional() {}
  /**
   * indicates that this cascade has a direction
   */
  virtual bool HasDirection() const {return true;}

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
   * gets the zenith of the cascade
   */
  //virtual double GetZenith() const {return fZenith;}
  double GetZenith() const {return GetDir().GetZenith();}

  /**
   * sets the zenith of the cascade
   */
  //virtual void SetZenith(double zenith) {fZenith = zenith;}
  void SetZenith(double zen) {
    GetDir().SetDirection(zen,GetDir().GetAzimuth());}

  /**
   * gets the azimuth of the cascade
   */
  //virtual double GetAzimuth() const {return fAzimuth;}
  double GetAzimuth() const {return GetDir().GetAzimuth();}

  /**
   * sets the Azimuth of the cascade
   */
  //virtual void SetAzimuth(double azimuth) {fAzimuth = azimuth;}
  void SetAzimuth(double azi) {
    GetDir().SetDirection(GetDir().GetZenith(),azi);}

  /**
   * copies over all the interal data to the destination particle
   * if a dynamic_cast<>() succeeds
   */
  virtual void CopyTo(I3Particle& destination) const
    {
      I3Directional* directional = dynamic_cast<I3Directional*>(&destination);
      if(directional)
	{
	  directional->fDir = fDir;
	}
    }

  virtual void ToStream(ostream& o) const
    {
      o<<"Direction:"<<fDir<<"\n";
    }
 private:
  //ROOT macro
  ClassDef(I3Directional,1);
};

#endif // I3DIRECTIONAL
