/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Cascade.h,v 1.4 2004/04/27 02:32:05 pretz Exp $
 *
 * @file I3Cascade.h
 * @version $Revision: 1.4 $
 * @date $Date: 2004/04/27 02:32:05 $
 * @author pretz
 */
#ifndef I3CASCADE_H
#define I3CASCADE_H

#include "Rtypes.h"
#include "I3ObservableParticle.h"

/**
 * @brief The cascade interface.  
 *
 * If 'IsLocalized' is true, then you should
 * be able to get X,Y,Z and T out.  If HasEnergy is true, then you should
 * expect to be able to get an Energy out. 
 *
 * @todo implement fatal calls
 *
 */
class I3Cascade : public I3ObservableParticle{
 public:
  /**
   * indicates that this is not a track
   */
  virtual Bool_t IsTrack() {return kFALSE;}

  /**
   * indicates that this particle is a Cascade.
   */
  virtual Bool_t IsCascade() {return kTRUE;}

  /**
   * indicates whether the cascade has a direction, and whether Zenith()and 
   * Azimuth() are legimitate to call.
   */
  virtual Bool_t HasDirection() const =0;

  /**
   * indicates whether the cascade has an energy, and whether the Energy() 
   * method  will work
   */ 
  virtual Bool_t HasEnergy() const =0;

  /**
   * the X position of the cascade
   */
  virtual Double_t X() const =0;

  /**
   * the Y position of the cascade
   */
  virtual Double_t Y() const =0;

  /**
   * the Z position of the cascade
   */
  virtual Double_t Z() const =0;

  /**
   * the time of the cascade
   */
  virtual Double_t T() const =0;

  /**
   * the position of the cascade as an I3Position object
   */
  virtual I3Position Pos() const =0;

  /**
   * the energy of the cascade
   */
  virtual Double_t Energy() const = 0;

 /**
  * Copies the data from the source particle into this particle
  * Only copies the data which the two have in commmon
  */
  virtual void CopyTo(I3Particle& destination) const
    {
      I3Particle::CopyTo(destination);
    }

  ClassDef(I3Cascade,1);
};


#endif
