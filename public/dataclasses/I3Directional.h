/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Directional.h,v 1.5 2004/06/30 17:20:26 pretz Exp $
 *
 * @file I3Directional.h
 * @version $Revision: 1.5 $
 * @date $Date: 2004/06/30 17:20:26 $
 * @author pretz
 */
#ifndef I3DIRECTIONAL_H
#define I3DIRECTIONAL_H

#include "Rtypes.h"

/**
 * @brief A class which implements the 'directional' aspect of an I3Cascade.
 */
class I3Directional 
{
 private:
  Double_t fZenith;
  Double_t fAzimuth;
 public:
  /**
   * indicates that this cascade has a direction
   */
  virtual Bool_t HasDirection() const {return true;}

  /**
   * gets the zenith of the cascade
   */
  virtual Double_t GetZenith() const {return fZenith;}

  /**
   * sets the zenith of the cascade
   */
  virtual void SetZenith(Double_t zenith) {fZenith = zenith;}

  /**
   * gets the azimuth of the cascade
   */
  virtual Double_t GetAzimuth() const {return fAzimuth;}

  /**
   * sets the Azimuth of the cascade
   */
  virtual void SetAzimuth(Double_t azimuth) {fAzimuth = azimuth;}

  /**
   * copies over all the interal data to the destination particle
   * if a dynamic_cast<>() succeeds
   */
  virtual void CopyTo(I3Particle& destination) const
    {
      I3Directional* directional = dynamic_cast<I3Directional*>(&destination);
      if(directional)
	{
	  directional->fZenith = fZenith;
	  directional->fAzimuth = fAzimuth;
	}
    }
 private:
  //ROOT macro
  ClassDef(I3Directional,1);
};

#endif // I3DIRECTIONAL
