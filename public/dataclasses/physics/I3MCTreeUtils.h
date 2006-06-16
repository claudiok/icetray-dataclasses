/**
    copyright  (C) 2004
    the icecube collaboration
    @file I3MCTreeUtils.h
*/

#ifndef I3MCTREEUTILS_H_INCLUDED
#define I3MCTREEUTILS_H_INCLUDED

#include "dataclasses/physics/I3Particle.h"
#include "dataclasses/physics/I3Composite.h"
#include "dataclasses/physics/I3MCTree.h"
#include "dataclasses/I3Tree.h"
#include "icetray/I3DefaultName.h"

namespace I3MCTreeUtils{

  void add_primary(I3MCTree&, I3Particle&);

  void append_child(I3MCTree&, I3Particle&, I3Particle&);

  std::vector<I3Composite> get_composites(I3MCTree&);

  std::vector<I3Particle> get_primaries(I3MCTree&);

}

#endif 


