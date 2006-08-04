/**
    copyright  (C) 2004
    the icecube collaboration
    @file I3MCTreeUtils.h
*/

#ifndef I3MCTREEUTILS_H_INCLUDED
#define I3MCTREEUTILS_H_INCLUDED

#include "dataclasses/physics/I3Particle.h"
#include "dataclasses/physics/I3MCTree.h"
#include "dataclasses/physics/I3MCList.h"
#include "dataclasses/I3Tree.h"
#include "icetray/I3DefaultName.h"

namespace I3MCTreeUtils
{
  /**
   *Adds a primary (top-level node) to the tree.
   *The primary has no parent.
   *A tree can have multiple primaries.
   */
  void AddPrimary(I3MCTree&, const I3Particle&);
  void AddPrimary(I3MCTreePtr,  const I3Particle&);

  /**
   *Appends a child to the parent particle
   */
  void AppendChild(I3MCTree&,  const I3Particle&,  const I3Particle&);
  void AppendChild(I3MCTreePtr,  const I3Particle&,  const I3Particle&);

  /**
   *Gets a list of primaries from the tree
   */
  const std::vector<I3Particle> GetPrimaries(const I3MCTree&);
  const std::vector<I3Particle> GetPrimaries(I3MCTreeConstPtr);

  /**
   *Gets a list of daughters of the parent particle.
   */
  const std::vector<I3Particle> GetDaughters(const I3MCTree&, const I3Particle&);
  const std::vector<I3Particle> GetDaughters(I3MCTreeConstPtr, const I3Particle&);

  /**
   *Gets the parent of a particle.  log_fatals if parent does not exist.
   */
  const I3Particle& GetParent(const I3MCTree&, const I3Particle&);
  const I3Particle& GetParent(I3MCTreeConstPtr, const I3Particle&);

  /**
   *Returns true if the particle has a parent
   */
  bool HasParent(const I3MCTree&, const I3Particle&);
  bool HasParent(I3MCTreeConstPtr, const I3Particle&);


  I3MCTreePtr ListToTree(const I3MCList&);
  I3MCTreeConstPtr Get(I3FramePtr, std::string);
  void ConvertComposite(I3MCTree&, I3MCTree::iterator&);

  /**
   *Returns the InIce particle with highest energy.
   *This is useful for example in extracting "the muon" from the 
   *atmospheric neutrino data.
   */
  //const I3Particle& GetMostEnergeticInIce(const I3MCTree&);
  //const I3Particle& GetMostEnergeticInIce(I3MCTreeConstPtr);

  /**
   *Returns a vector of particles that are InIce.
   */
  //const vector<I3Particle> Get(const I3MCTree&, I3Particle::LocationType);

  //const vector<I3Particle> GetInIce(const I3MCTree&);
  //const vector<I3Particle> GetInIce(I3MCTreeConstPtr);

  /**
   *Returns a vector of particles that are IceTop.
   */
  //const vector<I3Particle> GetIceTop(const I3MCTree&);
  //const vector<I3Particle> GetIceTop(I3MCTreeConstPtr);
}

#endif 


