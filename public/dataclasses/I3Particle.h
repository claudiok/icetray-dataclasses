/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Particle.h,v 1.14 2004/08/02 19:59:58 blaufuss Exp $
 *
 * @file I3Particle.h
 * @version $Revision: 1.14 $
 * @date $Date: 2004/08/02 19:59:58 $
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
    Int_t        fID;
    Int_t        fPrimaryID;
    Int_t        fParentID;

  public:
    I3Particle() 
    {
      fType=Null;
      fID=0;
      fPrimaryID=0;
      fParentID=0;
    }

    /**
     * indicates that this track is observable.
     */
    virtual Bool_t IsObservable() const = 0;
    
    /**
     * indicates that particle has a direction of origin
     */
    virtual Bool_t HasDirection() const =0;

    /**
     * indicates that particle is InIce
     */
    virtual Bool_t IsInIce() const =0;

    /**
     * indicates that particle is in IceTop
     */
    virtual Bool_t IsIceTop() const =0;
    
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
    virtual Int_t GetParticleID() const
    {
	return fID;
    };

    /** 
     * sets the unique ID number of the particle
     */ 
    virtual void SetParticleID(Int_t ID)
    {
	fID = ID;
    };
    
    /** 
     * gets the ID number of the primary of the particle
     */ 
    virtual Int_t GetPrimaryID() const
    {
	return fPrimaryID;
    };

    /** 
     * sets the ID number of the primary of the particle
     */ 
    virtual void SetPrimaryID(Int_t PrimaryID)
    {
	fPrimaryID = PrimaryID;
    };
  
    /** 
     * gets the ID number of the parent of the particle
     */ 
    virtual Int_t GetParentID() const
    {
	return fParentID;
    };

    /** 
     * sets the ID number of the parent of the particle
     */ 
    virtual void SetParentID(Int_t ParentID)
    {
	fParentID = ParentID;
    };

 /**
  * copies over data from this particle to the destination particle
  * Only copies that data which the two have in common
  */
 virtual void CopyTo(I3Particle& destination) const
   {
     destination.fType = fType;
     destination.fID   = fID;
     destination.fID   = fPrimaryID;
     destination.fID   = fParentID;
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

/**
 * streams an I3Particle to an arbitrary ostream
 */
inline ostream& operator<<(ostream& o,const I3Particle& part)
{
  part.ToStream(o);
  return o;
}

/**
 * pointer type to insulate users from memory management
 */
typedef PtrPolicy<I3Particle>::ThePolicy I3ParticlePtr;

#endif
