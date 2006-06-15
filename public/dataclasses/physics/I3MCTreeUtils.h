/**
    copyright  (C) 2004
    the icecube collaboration
    @file I3MCTreeUtils.h
*/

#ifndef I3MCTREEUTILS_H_INCLUDED
#define I3MCTREEUTILS_H_INCLUDED

#include "dataclasses/physics/I3Particle.h"
#include "dataclasses/physics/I3Composite.h"
#include "dataclasses/physics/I3MCParticle.h"
#include "dataclasses/physics/I3MCTree.h"
#include "dataclasses/I3Tree.h"
#include "icetray/I3DefaultName.h"

namespace I3MCTreeUtils{
  /**
   *Splits the tree into two seperate trees and puts them in the frame.
   *It puts an I3MCTree in the frame with the default name
   *and the 'extra' tree with frame with the name 'name'
   *This is meant mostly for propagators.
   */
  template <class T>
    void split_and_load(I3FramePtr frame,
			std::string name,
			I3Tree<I3MCParticle<T> >& mcTree);

  /**
   *Splits the tree into two seperate trees.
   */
  template <class T>
    std::pair< I3MCTreePtr, shared_ptr<I3Tree<T> > >
    split(I3Tree<I3MCParticle<T> >& mcTree);

  /**
   *Extracts the I3Particle from mcTree and adds it to i3mcTree and puts the result tree
   *into the frame with the default name.  The 'extra' tree is put into the frame under
   *the name 'name'
   */
  template <class T>
    void merge_and_put(I3FramePtr frame,
		       std::string name,
		       const I3MCTree& i3mcTree,
		       I3Tree<I3MCParticle<T> >& mcTree);

  /**
   *Returns the 'extra' info from a tree corresponding to a given particle.
   */
  template <class T>
    T GetMCInfo(I3Tree<T>& tree, I3Particle&);

  /**
   *Recreates the tree with the particle and all of the extras
   */
  template <class T>
    I3Tree<I3MCParticle<T> > Recreate(I3Tree<T>& tree, I3MCTree&);
}

#endif 


