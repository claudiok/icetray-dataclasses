/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Cascade.h,v 1.11 2004/08/31 13:30:55 pretz Exp $
 *
 * @file I3Cascade.h
 * @version $Revision: 1.11 $
 * @date $Date: 2004/08/31 13:30:55 $
 * @author pretz
 */
#ifndef I3CASCADE_H
#define I3CASCADE_H

#include "Rtypes.h"
#include "I3InIceParticle.h"

/**
 * @brief The cascade interface.  
 *
 * If 'IsLocalized' is true, then you should
 * be able to get X,Y,Z and T out.  If HasEnergy is true, then you should
 * expect to be able to get an Energy out. 
 *
 *
 */
class I3Cascade : public I3InIceParticle{
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
   * the time of the cascade
   */
  virtual Double_t GetT() const =0;

  /**
   * the position of the cascade as an I3Position object
   */
  virtual I3Position GetPos() const =0;

 /**
  * Copies the data from the source particle into this particle
  * Only copies the data which the two have in commmon
  */
  virtual void CopyTo(I3Particle& destination) const
    {
      I3Particle::CopyTo(destination);
    }

  virtual void ToStream(ostream& o) const
    {
      I3Particle::ToStream(o);
    }

 private:
  //ROOT macro
  ClassDef(I3Cascade,1);
};

/** 
 * pointer type to insulate users from memory management issues
 */
typedef PtrPolicy<I3Cascade>::ThePolicy I3CascadePtr;

#endif
