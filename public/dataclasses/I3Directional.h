/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Directional.h,v 1.3 2004/04/23 21:31:29 deyoung Exp $
 *
 * @file 
 * @version $Revision: 1.3 $
 * @date $Date: 2004/04/23 21:31:29 $
 * @author 
 *
 * @todo
 *
 */
#ifndef I3DIRECTIONAL_H
#define I3DIRECTIONAL_H

#include "Rtypes.h"

/**
 * A class which implements the 'directional' aspect of an I3Cascade.
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
  virtual Double_t Zenith() const {return fZenith;}

  /**
   * sets the zenith of the cascade
   */
  virtual void Zenith(Double_t zenith) {fZenith = zenith;}

  /**
   * gets the azimuth of the cascade
   */
  virtual Double_t Azimuth() const {return fAzimuth;}

  /**
   * sets the Azimuth of the cascade
   */
  virtual void Azimuth(Double_t azimuth) {fAzimuth = azimuth;}

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
