/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Directional.h,v 1.8.2.2 2005/02/04 21:51:03 troy Exp $
 *
 * @file I3Directional.h
 * @version $Revision: 1.8.2.2 $
 * @date $Date: 2005/02/04 21:51:03 $
 * @author pretz
 */
#ifndef I3DIRECTIONAL_H
#define I3DIRECTIONAL_H

#include "dataclasses/I3Direction.h"

/**
 * @brief A class which implements the 'directional' aspect of an I3Cascade.
 */
class I3Directional 
{
 private:
  I3Direction fDir;
  //Double_t fZenith;
  //Double_t fAzimuth;
 public:

  virtual ~I3Directional() {}
  /**
   * indicates that this cascade has a direction
   */
  virtual Bool_t HasDirection() const {return true;}

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
  void SetDir(Double_t zen, Double_t azi) {fDir.SetDirection(zen,azi);}

  /**
   * sets the direction of the track
   */
  void SetDir(Double_t x, Double_t y, Double_t z) 
    {fDir.SetDirection(x,y,z);}

  /**
   * gets the zenith of the cascade
   */
  //virtual Double_t GetZenith() const {return fZenith;}
  Double_t GetZenith() const {return GetDir().GetZenith();}

  /**
   * sets the zenith of the cascade
   */
  //virtual void SetZenith(Double_t zenith) {fZenith = zenith;}
  void SetZenith(Double_t zen) {
    GetDir().SetDirection(zen,GetDir().GetAzimuth());}

  /**
   * gets the azimuth of the cascade
   */
  //virtual Double_t GetAzimuth() const {return fAzimuth;}
  Double_t GetAzimuth() const {return GetDir().GetAzimuth();}

  /**
   * sets the Azimuth of the cascade
   */
  //virtual void SetAzimuth(Double_t azimuth) {fAzimuth = azimuth;}
  void SetAzimuth(Double_t azi) {
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
};

#endif // I3DIRECTIONAL
