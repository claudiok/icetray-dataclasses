/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Particle.h,v 1.11 2004/07/26 13:53:55 pretz Exp $
 *
 * @file I3Particle.h
 * @version $Revision: 1.11 $
 * @date $Date: 2004/07/26 13:53:55 $
 * @author pretz
 *
 */
#ifndef I3PARTICLE_H
#define I3PARTICLE_H

#include "TObject.h"
#include "I3Position.h"
#include "StoragePolicy.h"
#include "TClass.h"
#include <iostream>
#include <cmath>

using namespace std;

/**
 * @brief The base 'particle' class.  
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
     * indicates that this track is observable.
     */
    virtual Bool_t IsObservable() const = 0;
    
    /**
     * indicates that particle has a direction of origin
     */
    virtual Bool_t HasDirection() const =0;
    
    /**
     * gives the type of the particle
     */
    virtual ParticleType GetType() const
    {
	return fType;
    }
    
    /**
     * sets the type of the particle
     */
    virtual void SetType(ParticleType type)
    {
	fType = type;
    };

    /** 
     * gets the unique ID number of the particle
     */ 
    virtual Int_t GetParticleNumber() const
    {
	return fID;
    };

    /** 
     * sets the unique ID number of the particle
     */ 
    virtual void SetParticleNumber(Int_t ID)
    {
	fID = ID;
    };
  
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

 /**
  * @todo finish implementing this method
  */
 virtual void ToStream(ostream& o) const
   {
     o<<"[ "<<IsA()->GetName()<<" ]\n";
   }

  ClassDef(I3Particle,1);
};

inline ostream& operator<<(ostream& o,const I3Particle& part)
{
  part.ToStream(o);
  return o;
}

typedef PtrPolicy<I3Particle>::ThePolicy I3ParticlePtr;

#endif
