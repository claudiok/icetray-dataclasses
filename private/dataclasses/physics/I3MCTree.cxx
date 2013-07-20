#include <cassert>

#include <icetray/serialization.h>
#include "dataclasses/physics/I3MCTree.h"


I3MCTree::I3MCTree()
  : TreeBase::Tree<I3Particle,I3ParticleID>()
{ }

I3MCTree::I3MCTree(const I3Particle& p)
  : TreeBase::Tree<I3Particle,I3ParticleID>(p)
{ }

template<class D,class V>
I3MCTree::I3MCTree(const iterator_base<D,V>& other)
  : TreeBase::Tree<I3Particle,I3ParticleID>(other)
{ }

I3MCTree::I3MCTree(const I3MCTree& m)
  : TreeBase::Tree<I3Particle,I3ParticleID>(m)
{ }


void
I3MCTree::AddPrimary(const I3Particle& p)
{
  insert_after(p);
}


I3_SERIALIZABLE(I3MCTree);


