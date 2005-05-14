/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file I3Directional.h
 * @version $Revision: 1.11 $
 * @date $Date$
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
  virtual Bool_t HasDirection() const {log_debug ("Are you there?");
  return true;}

  /**
   * gets the direction of the track
   */
  I3Direction GetDir() const {return dir_;}

  /**
   * sets the direction of the track
   */
  void SetDir(I3Direction& d) {dir_.SetDirection(d);}

  /**
   * sets the direction of the track
   */
  void SetDir(Double_t zen, Double_t azi) {
    log_debug ("SETTING DIR %f, %f", zen, azi);
    dir_.SetDirection(zen,azi);
  }

  /**
   * sets the direction of the track
   */
  void SetDir(Double_t x, Double_t y, Double_t z) 
    {dir_.SetDirection(x,y,z);}

  /**
   * gets the zenith of the cascade
   */
  Double_t GetZenith() const {
    log_debug ("GETTING ZEN: %f",
	       GetDir ().GetZenith ());
    return GetDir().GetZenith();}

  /**
   * sets the zenith of the cascade
   */
  void SetZenith(Double_t zen) {
    log_debug ("SETTING ZEN: %f", zen);
    SetDir (zen, dir_.GetAzimuth());}

  /**
   * gets the azimuth of the cascade
   */
  Double_t GetAzimuth() const {
    log_debug ("GETTING AZI: %f",
	       GetDir ().GetAzimuth ());
    return GetDir().GetAzimuth();}

  /**
   * sets the Azimuth of the cascade
   */
  void SetAzimuth(Double_t azi) {
    log_debug ("SETTING AZI: %f", azi);
    SetDir (dir_.GetZenith (), azi);
  }

  /**
   * copies over all the interal data to the destination particle
   * if a dynamic_cast<>() succeeds
   */
  virtual void CopyTo(I3Particle& destination) const
    {
      I3Directional* directional = dynamic_cast<I3Directional*>(&destination);
      if(directional)
	{
	  directional->dir_ = dir_;
	}
    }

  virtual void ToStream(ostream& o) const
    {
      o<<"Direction:"<<dir_<<"\n";
    }
 private:

  friend class boost::serialization::access;

  template <class Archive>
    void serialize(Archive& ar, unsigned version){
    ar & make_nvp("Dir",dir_);
  }
  //ROOT macro
  ClassDef(I3Directional,1);
};

#endif // I3DIRECTIONAL
