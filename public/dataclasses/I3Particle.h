#ifndef I3PARTICLE_H
#define I3PARTICLE_H

#include "TObject.h"
#include "I3Position.h"
#include "StoragePolicy.h"
#include <cmath>

/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Particle.h,v 1.5 2004/04/23 21:10:25 deyoung Exp $
 *
 * @version $Revision: 1.5 $
 * @date $Date: 2004/04/23 21:10:25 $
 * @author pretz
 *
 * @todo implement fatal calls
 * @todo should there be a 'generic muon' and 'generic tau' types?
 */
class I3Particle : public TObject{
 public:
  /**
   * enumerated type of the different paricles.
   * follows the f2k convention for numbering
   */
 enum ParticleType {
    Unknown = -100,
    Null = 0, 
    Gamma = 1,
    EPlus = 2,
    EMinus = 3,
    Nu = 4,
    MuPlus = 5,
    MuMinus = 6,
    Pi0 = 7, 
    PiPlus = 8,
    PiMinus = 9,
    PPlus = 14,
    PMinus = 15,
    TauPlus = 33,
    TauMinus = 34,
    NuE = 201,
    NuMu = 202,
    NuTau = 203,
    NuEBar = 204,
    NuMuBar = 205,
    NuTauBar = 206,
    Brems = 1001,
    DeltaE = 1002,
    PairProd = 1003,
    NuclInt = 1004,
    MuPair = 1005,
    Hadrons = 1006,
    FiberLaser = 2100,
    N2Laser = 2101, 
    YAGLaser = 2201,
    ZPrimary = 3000,
    APrimary = 3500, 
    Elph = 9999
  };

 private:
    ParticleType fType;
    Int_t fID;

public:
    /**
     * indicates that particle has a direction of origin
     */
    virtual Bool_t HasDirection() const =0;
    
    /**
     * gives the type of the particle
     */
    virtual ParticleType Type() const
    {
	return fType;
    }
    
    /**
     * sets the type of the particle
     */
    virtual void Type(ParticleType type)
    {
	fType = type;
    };

    /** 
     * gets the unique ID number of the particle
     */ 
    virtual Ushort_t ParticleNumber() const
    {
	return fID;
    };

      /** 
     * sets the unique ID number of the particle
     */ 
    virtual void ParticleNumber(Int_t ID)
    {
	fID = ID;
    };
  

 /**
  * phi
  */
 virtual Double_t Azimuth() const =0;

 /**
  * theta
  */
 virtual Double_t Zenith() const =0;

 /**
  * copies over data from this particle to the destination particle
  * Only copies that data which the two have in common
  */
 virtual void CopyTo(I3Particle& destination) const
   {
     destination.fType = fType;
     destination.fID = fID;
   }

 /**
  * Copies the data from the source particle into this particle
  * Only copies the data which the two have in commmon
  */
 virtual void CopyFrom(const I3Particle& source) = 0 ; 

  ClassDef(I3Particle,1);
};

typedef PtrPolicy<I3Particle>::ThePolicy I3ParticlePtr;

#endif
