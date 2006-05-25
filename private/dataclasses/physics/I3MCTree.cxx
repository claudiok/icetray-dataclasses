#include "dataclasses/physics/I3MCTree.h"

template <class T>
void MCTreeUtils::Split_And_Load(I3FramePtr frame,std::string name,I3Tree<I3MCParticle<T> >& mcTree){

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
void MCTreeUtils::Merge_And_Put(I3FramePtr frame,std::string name,const I3MCTree& i3mcTree,I3Tree<I3MCParticle<T> >& mcTree){
  
  typename I3Tree<I3MCParticle<T> >::iterator head_iter = mcTree.begin();
  typename I3Tree<I3MCParticle<T> >::sibling_iterator siter;
  for(siter = head_iter.begin(); siter != head_iter.end(); ++siter){
    I3MCTree::iterator i; 
    for(i=i3mcTree.begin(); i !=i3mcTree.end(); ++i){
      if(siter->particle.GetID() == i->GetID()){
	//extract i3particle from I3MCParticle<T>
	//and build the rest of the tree
      }
    }
  }
}

template <class T>
T MCTreeUtils::Get(I3Tree<T>& tree, I3Particle&){
  
}

template <class T>
MCTreeUtils::I3Tree<I3MCParticle<T> > Recreate(I3Tree<T>& tree, I3MCTree&){
  
}

#endif 


