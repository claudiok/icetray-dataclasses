#include "dataclasses/physics/I3MCTree.h"
#include "icetray/I3Frame.h"

void I3MCTree::AddPrimary(I3Particle& p){
  this->insert(this->begin(),p);
}

void I3MCTree::AppendChild(I3Particle& parent, I3Particle& child){
  //Need to find the iterator of the parent
  //do it bonehead-style first
  I3MCTree::iterator i;
  I3MCTree::iterator p_iter;
  for(i=this->begin(); i!=this->end(); ++i){
    if(i->GetID() == parent.GetID()){
      p_iter = i;
      break;
    }
  }
  if(p_iter != this->end()){
    this->append_child(p_iter,child);
  }else{
    log_error("attempt to add a child to a non-existant parent.");
  }
}

std::vector<I3Composite> 
I3MCTree::GetComposites()
{
  std::vector<I3Composite> c_list;
  I3MCTree::iterator i;
  for(i=this->begin(); i!=this->end(); ++i){
    if(i->GetCompositeType() == I3Particle::Head){
      I3Composite c;
      c.particle = *i;
      //fill the vector composite
      I3Particle constituent;
      constituent.SetCompositeType(I3Particle::Child);//just for illustrative purposes
      if(constituent.GetCompositeType() == I3Particle::Child)
	c.composite.push_back(constituent);
      c_list.push_back(c);
    }
  }
  return c_list;
}

std::vector<I3Particle>
I3MCTree::GetPrimaries(){
  std::vector<I3Particle> primaryList;
  I3MCTree::sibling_iterator i;
  for(i=this->begin(); i!=this->end(); ++i)
    primaryList.push_back(*i);
  return primaryList;
}

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
  
  typename I3Tree<I3MCParticle<T> >::iterator head_iter = propTree.begin();
  typename I3Tree<I3MCParticle<T> >::sibling_iterator prop_iter;
  for(prop_iter = head_iter.begin(); prop_iter != head_iter.end(); ++prop_iter){
    I3MCTree::iterator gen_iter; 
    I3Tree<I3MCParticle<T> > prop_subtree = 
      propTree.subtree(begin(prop_iter),end(prop_iter));

    std::pair<I3MCTreePtr, shared_ptr<I3Tree<T> > > split_trees = 
      I3MCTreeUtils::split(prop_subtree);

    I3MCTreePtr prop_particlesubtree = split_trees->first; 
    shared_ptr<I3Tree<T> > prop_mcsubtree = split_trees->second; 


    for(gen_iter=genTree.begin();gen_iter !=genTree.end(); ++gen_iter){
      if(prop_iter->particle.GetID() == gen_iter->GetID()){
	//extract i3particle from I3MCParticle<T>
	//and build the rest of the tree

	typename I3Tree<I3MCParticle<T> >::sibling_iterator siter;
	for(siter=prop_iter.begin(); siter!= prop_iter.end(); ++siter){
	  i3particleTree->append_child(j,i->particle);
	  payloadTree->append_child(k,i->mc);
	}

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


