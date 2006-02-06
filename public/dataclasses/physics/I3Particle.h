/**
 * copyright  (C) 2004
 * the icecube collaboration
 * @version $Id$
 * @file I3Particle.h
 * @date $Date$
 */

#ifndef I3PARTICLE_H_INCLUDED
#define I3PARTICLE_H_INCLUDED

#include "TObject.h"
#include "dataclasses/Utility.h"
#include <string>

class I3Particle : public TObject
{
 public:

  virtual ~I3Particle();

  I3Particle():
    type_(InIce),
    parentID_(INT_MAX),
    primaryID_(INT_MAX),
    myID_(INT_MAX),
    recoName_("Default")
    {};

  enum MCTruthID {
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
    Monopole = 41,
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

  enum ParticleType{InIce, IceTop, Primary};
 
  I3Particle::ParticleType GetType() const { return type_;}
 
  void SetType(I3Particle::ParticleType type){type_ = type;}

  I3Particle::MCTruthID GetMCTruth() const { return mcTruthID_;}
 
  void SetMCTruthID(I3Particle::MCTruthID mcTruthID){mcTruthID_ = mcTruthID;}

  I3Particle::MCTruthID GetMCTruthID() const { return mcTruthID_;}

  unsigned GetParentID() const { return parentID_;}
 
  void SetParentID(unsigned parentID){parentID_ = parentID;}

  unsigned GetPrimaryID() const { return primaryID_;}
 
  void SetPrimaryID(unsigned primaryID){primaryID_ = primaryID;}

  unsigned GetMyID() const { return myID_;}
 
  void SetMyID(unsigned myID){myID_ = myID;}

  const std::string& GetRecoName() const { return recoName_;}
 
  void SetRecoName(std::string& recoName){recoName_ = recoName;}

 private:

  ParticleType type_;
  unsigned parentID_;
  unsigned primaryID_;
  unsigned myID_;
  std::string recoName_;
  MCTruthID mcTruthID_;

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
  
  ClassDef(I3Particle,1);
};

I3_POINTER_TYPEDEFS(I3Particle);

#endif //I3PARTICLE_H_INCLUDED
