#include <cassert>

#include <icetray/serialization.h>
#include "dataclasses/physics/I3MCTree.h"



I3_SERIALIZABLE(TreeBase::TreeNode<I3Particle>);



const uint64_t I3MCTree::HIDDEN_ROOT_ = 0;

I3MCTree::I3MCTree()
  : TreeBase::Tree<I3Particle,I3ParticleID>(HIDDEN_ROOT_)
{ }

I3MCTree::I3MCTree(const I3Particle& p)
  : TreeBase::Tree<I3Particle,I3ParticleID>(HIDDEN_ROOT_)
{ AddPrimary(p); }

template<class D,class V>
I3MCTree::I3MCTree(const iterator_base<D,V>& other)
  : TreeBase::Tree<I3Particle,I3ParticleID>(other)
{ }

I3MCTree::I3MCTree(const I3MCTree& m)
  : TreeBase::Tree<I3Particle,I3ParticleID>(m)
{ }


void
I3MCTree::set_head(const I3Particle& p)
{
  i3_assert( valueToHash_(p) == HIDDEN_ROOT_ );
}


void
I3MCTree::AddPrimary(const I3Particle& p)
{
  append_child_(HIDDEN_ROOT_,p);
}



I3_SERIALIZABLE(I3MCTree);


