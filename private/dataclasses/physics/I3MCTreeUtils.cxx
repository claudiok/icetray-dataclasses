#include "dataclasses/physics/I3MCTreeUtils.h"
#include "icetray/I3Frame.h"

template <class T>
std::pair< I3MCTreePtr, shared_ptr<I3Tree<T> > >
I3MCTreeUtils::split(I3Tree<I3MCParticle<T> >& mcTree){
  I3MCTreePtr mctree;
  shared_ptr<I3Tree<T> > ptree;
  
  mctree->set_head(mcTree.begin()->particle);
  ptree->set_head(mcTree.begin()->mc);
  
  I3MCTree::iterator j;
  typename I3Tree<T>::iterator k;
  
  typename I3Tree<I3MCParticle<T> >::iterator i;
  for(i=mcTree.begin(), j=mctree->begin(), k=ptree->begin();
      i != mcTree.end(); 
      ++i,++j,++k){
    //just keep appending children
    //iterate over children
    typename I3Tree<I3MCParticle<T> >::sibling_iterator siter;
    for(siter=i.begin(); siter!= i.end(); ++siter){
      mctree->append_child(j,i->particle);
      ptree->append_child(k,i->mc);
      }
  }
  return std::pair<I3MCTreePtr, shared_ptr<I3MCParticle<T> > >(mctree,ptree);
}

template <class T>
void I3MCTreeUtils::split_and_load(I3FramePtr frame,std::string name,I3Tree<I3MCParticle<T> >& mcTree){

  I3MCTreePtr i3particleTree;
  shared_ptr<I3Tree<T> > payloadTree;
  
  i3particleTree->set_head(mcTree.begin()->particle);
  payloadTree->set_head(mcTree.begin()->mc);
  
  I3MCTree::iterator j;
  typename I3Tree<T>::iterator k;
  
  typename I3Tree<I3MCParticle<T> >::iterator i;
  for(i=mcTree.begin(), j=i3particleTree->begin(), k=payloadTree->begin();
      i != mcTree.end(); 
      ++i,++j,++k){
    //just keep appending children
    //iterate over children
    typename I3Tree<I3MCParticle<T> >::sibling_iterator siter;
    for(siter=i.begin(); siter!= i.end(); ++siter){
      i3particleTree->append_child(j,i->particle);
      payloadTree->append_child(k,i->mc);
      }
  }
  frame->Put(i3particleTree);
  frame->Put(name,payloadTree);
}

template <class T>
void I3MCTreeUtils::merge_and_put(I3FramePtr frame,std::string name,
				  const I3MCTree& genTree,I3Tree<I3MCParticle<T> >& propTree){

  I3MCTreePtr newGenTree(new I3MCTree(genTree));//This is going into the frame

  I3MCTreePtr finalMCTree;//this is what will go into the frame
  shared_ptr<I3Tree<T> > finalMCInfoTree;//this is what will go into the frame
  
  typename I3Tree<I3MCParticle<T> >::iterator head_iter = propTree.begin();
  typename I3Tree<I3MCParticle<T> >::sibling_iterator prop_iter;
  for(prop_iter = head_iter.begin(); prop_iter != head_iter.end(); ++prop_iter){
    I3MCTree::iterator gen_iter; 
    I3Tree<I3MCParticle<T> > prop_subtree = 
      propTree.subtree(begin(prop_iter),end(prop_iter));

    std::pair<I3MCTreePtr, shared_ptr<I3Tree<T> > > split_trees = 
      I3MCTreeUtils::split(prop_subtree);

    //second things first...let's put the separated propagator
    //tree together so we don't have to worry about it anymore
    finalMCInfoTree->insert_subtree(finalMCInfoTree->begin(),split_trees->second->begin()); 
    //glad that's over with...

    //now back to the first thing
    I3MCTreePtr prop_particlesubtree = split_trees->first; 

    for(gen_iter=newGenTree->begin();gen_iter !=newGenTree->end(); ++gen_iter){
      if(prop_iter->particle.GetID() == gen_iter->GetID()){
	newGenTree->replace(gen_iter,split_trees->first->begin());
      }
    }
  }
}

template <class T>
T I3MCTreeUtils::GetMCInfo(I3Tree<T>& tree, I3Particle&){
  
}

template <class T>
I3Tree<I3MCParticle<T> > 
I3MCTreeUtils::Recreate(I3Tree<T>& tree, I3MCTree&){
  
}


