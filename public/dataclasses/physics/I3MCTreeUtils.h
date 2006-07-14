/**
    copyright  (C) 2004
    the icecube collaboration
    @file I3MCTreeUtils.h
*/

#ifndef I3MCTREEUTILS_H_INCLUDED
#define I3MCTREEUTILS_H_INCLUDED

#include "dataclasses/physics/I3Particle.h"
#include "dataclasses/physics/I3MCTree.h"
#include "dataclasses/I3Tree.h"
#include "icetray/I3DefaultName.h"

namespace I3MCTreeUtils{

  /**
   *Adds a primary (top-level node) to the tree.
   *The primary has no parent.
   *A tree can have multiple primaries.
   */
  void AddPrimary(I3MCTree&, I3Particle&);

  /**
   *Appends a child to the parent particle
   */
  void AppendChild(I3MCTree&, I3Particle&, I3Particle&);

  /**
   *Gets a list of primaries from the tree
   */
  std::vector<I3Particle> GetPrimaries(I3MCTree&);

  /**
   *Gets a list of daughters of the parent particle.
   */
  std::vector<I3Particle> GetDaughters(I3MCTree&, I3Particle&);

  /**
   *Gets the parent of a particle.  log_fatals if parent does not exist.
   */
  I3Particle& GetParent(I3MCTree&, I3Particle&);

  /**
   *Returns true if the particle has a parent
   */
  bool HasParent(I3MCTree&, I3Particle&);
}

#endif 


