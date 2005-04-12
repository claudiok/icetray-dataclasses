/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Particle.h,v 1.20 2005/04/09 03:02:10 olivas Exp $
 *
 * @file I3Particle.h
 * @version $Revision: 1.20 $
 * @date $Date: 2005/04/09 03:02:10 $
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
#include <sstream>

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
    ParticleType type_;
    int        id_;
    int        primaryID_;
    int        parentID_;

  public:
    I3Particle()
    {
      type_=Null;
      id_=0;
      primaryID_=0;
      parentID_=0;
    }

    /**
     * indicates that this track is observable.
     */
    virtual bool IsObservable() const = 0;

    /**
     * indicates that particle has a direction of origin
     */
    virtual bool HasDirection() const =0;

    /**
     * indicates that particle has an energy
     */
    virtual bool HasEnergy() const =0;

    /**
     * indicates that particle is InIce
     */
    virtual bool IsInIce() const =0;

    /**
     * indicates that particle is in IceTop
     */
    virtual bool IsIceTop() const =0;

    /**
     * gives the type of the particle
     */
    virtual ParticleType GetType() const
    {
	return type_;
    }

    /**
     * sets the type of the particle
     */
    virtual void SetType(ParticleType type)
    {
	type_ = type;
    };

    /** 
     * gets the unique ID number of the particle
     */ 
    virtual int GetParticleID() const
    {
	return id_;
    };

    /** 
     * sets the unique ID number of the particle
     */ 
    virtual void SetParticleID(int ID)
    {
	id_ = ID;
    };
    
    /** 
     * gets the ID number of the primary of the particle
     */ 
    virtual int GetPrimaryID() const
    {
	return primaryID_;
    };

    /** 
     * sets the ID number of the primary of the particle
     */ 
    virtual void SetPrimaryID(int PrimaryID)
    {
	primaryID_ = PrimaryID;
    };
  
    /** 
     * gets the ID number of the parent of the particle
     */ 
    virtual int GetParentID() const
    {
	return parentID_;
    };

    /** 
     * sets the ID number of the parent of the particle
     */ 
    virtual void SetParentID(int ParentID)
    {
	parentID_ = ParentID;
    };

 /**
  * copies over data from this particle to the destination particle
  * Only copies that data which the two have in common
  */
 virtual void CopyTo(I3Particle& destination) const
   {
     destination.type_ = type_;
     destination.id_   = id_;
     destination.id_   = primaryID_;
     destination.id_   = parentID_;
   }

 /**
  * Copies the data from the source particle into this particle
  * Only copies the data which the two have in commmon
  */
 virtual void CopyFrom(const I3Particle& source) = 0 ; 

 /**
  * @todo finish implementing this method
  */
 virtual const string ToString() const
   {
     ostringstream out;
     ToStream(out);
     return out.str();
   }

 /**
  * 
  */
 virtual void ToStream(ostream& o) const
   {
     o<<"[ "<<IsA()->GetName()<<" ]\n";
   }
 private:

  friend class boost::serialization::access;

  template <class Archive>
  void serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("Type", type_);
    ar & make_nvp("ID", id_);
    ar & make_nvp("PrimaryID",primaryID_);
    ar & make_nvp("ParentID", parentID_);
  }

 // ROOT macro
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
typedef shared_ptr<I3Particle>  I3ParticlePtr;

#endif
