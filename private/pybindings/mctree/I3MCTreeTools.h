/**
    copyright  (C) 2004
    the icecube collaboration
    @file I3MCTreeTools.h
*/
/*
#ifndef I3MCTREETOOLS_H_INCLUDED
#define I3MCTREETOOLS_H_INCLUDED

#include "dataclasses/physics/I3Particle.h"
#include "dataclasses/physics/I3MCTree.h"
#include "dataclasses/physics/I3MCHit.h"
#include <boost/tuple/tuple.hpp>

struct PPPConfig{
  bool ID;
  bool major_ID;
  bool type;
  bool shape;
  bool pos;
  bool dir;
  bool time;
  bool energy;
  bool length;
  bool speed;
  bool locationType;

  PPPConfig(){
    ID = true;
    major_ID = false;
    type = true;
    shape = false;
    pos = true;
    dir = true;
    time = true;
    energy = true;
    length = true;
    speed = false;
    locationType = false;
  }
};

enum NuEventType{
  CHARGED_CURRENT = 1,
  NEUTRAL_CURRENT = 2,
  GLASHOW_RESONANCE = 3,
  NO_INTERACTION = 0
};

enum Flavor{
  Flavorless = 0,
  Electron = 1,
  Muon = 2,
  Tau = 3
};

typedef boost::tuples::tuple<int,int,int> lepton_number_t;;
namespace I3MCTreeTools
{

  /**
   * Used internally by ListToTree and called recursively.
   * The general population probably won't find this useful.
   * To use it properly, you need to...
   * 1) Copy the particle you want to add
   * 2) Clear the composite list of the copy
   * 3) Append the copy (with the empty composite list) to the tree with insert.
   * 4) Pass to ConvertComposite the tree, the iterator (return value from insert call),
        and the composite list of the original particle.
   *  Again probably not for general consumption.
   */ /*
  namespace internal{
    std::string DumpChildren(const I3MCTree&,I3MCTree::iterator, const PPPConfig&);
    std::string ParticlePrettyPrint(const I3Particle&, const PPPConfig&);
    PPPConfig ParseConfigString(const std::string&);
  }

  int GetNumberOfAtmosphericMuons(const I3MCTree&);
  bool IsCosmicRayParticle(const I3Particle&);

  /**
   * This gets the particle that created the hit;
   */ /*
  I3Particle Get(const I3MCTree&, const I3MCHit&);

  /**
   * This gets the primary that created the particle;
   */ /*
  I3ParticlePtr GetPrimary(const I3MCTree&, const I3Particle&);
  
  std::string Dump(const I3MCTree&, const std::string& config = "");

  NuEventType GetNeutrinoEventType(const I3MCTree&);

  bool IsNeutralCurrent(const I3MCTree&);
  bool IsChargedCurrent(const I3MCTree&);
  bool IsGlashowResonance(const I3MCTree&);

  bool IsNeutrino(const I3Particle&);
  bool IsChargedLepton(const I3Particle&);
  Flavor LeptonFlavor(const I3Particle&);

  lepton_number_t LeptonNumber(const I3Particle&);

  bool CheckNeutrino(const I3MCTree&);
}

#endif 
*/

