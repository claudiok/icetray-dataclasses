/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Localized.h,v 1.2 2004/04/22 15:55:44 pretz Exp $
 *
 * @file 
 * @version $Revision: 1.2 $
 * @date $Date: 2004/04/22 15:55:44 $
 * @author 
 *
 * @todo
 *
 */
#ifndef I3LOCALIZED_H
#define I3LOCALIZED_H

#include "I3Cascade.h"

/**
 * A class which satisfies the "Localization" part of an I3Cascade, and 
 * allows X,Y,Z, and T to be set and got.
 */
class I3Localized{
 private:
  Double_t fX;
  Double_t fY;
  Double_t fZ;
  Double_t fT;
 public:
  /**
   * indicates that this class has a localization
   */
  virtual Bool_t IsLocalized() const { return true;}

  /**
   * gives the X position of the Cascade
   */
  Double_t X() const{ return fX;}

  /**
   * sets the x position of the cascade
   */
  void X(Double_t x) {fX = x;}

  /**
   * gives the y position of the cascade
   */
  Double_t Y() const{return fY;}

  /**
   * sets the y position of the cascade
   */
  void Y(Double_t y) {fY = y;}

  /**
   * gets the z position of the cascade
   */
  Double_t Z() const{return fZ; }

  /**
   * sets the z position of the cascade 
   */
  void Z(Double_t z) {fZ = z;}

  /**
   * gets the time of the cascade
   */
  Double_t T() const{return fT;}

  /**
   * sets the time of the cascade
   */
  void T(Double_t t){fT = t;}

  /**
   * copies all of this cascade's data into 'destination' if a dynamic_cast
   * to I3Localized succeeds.
   */
  void CopyTo(I3Particle& destination) const
    {
      I3Localized *localized = dynamic_cast<I3Localized*>(&destination);
      if(localized)
	{
	  localized->fX = fX;
	  localized->fY = fY;
	  localized->fZ = fZ;
	  localized->fT = fT;
	}
    }
 private:
  //ROOT macro
  ClassDef(I3Localized,1);
};

#endif //I3LOCALIZED_H
