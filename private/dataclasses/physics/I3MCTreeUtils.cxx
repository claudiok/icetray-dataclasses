#include "dataclasses/physics/I3MCTreeUtils.h"
#include "icetray/I3Frame.h"

void I3MCTreeUtils::add_primary(I3MCTree& t,I3Particle& p){
  I3Tree<I3Particle>::iterator si;
  si = t.end(t.begin());
  t.insert(si,p);
}

void I3MCTreeUtils::append_child(I3MCTree& t, I3Particle& parent, I3Particle& child){
  //Need to find the iterator of the parent
  //do it bonehead-style first
  I3MCTree::iterator i;
  I3MCTree::iterator p_iter;
  for(i=t.begin(); i!=t.end(); ++i){
    if(i->GetID() == parent.GetID()){
      p_iter = i;
      break;
    }
  }
  if(p_iter != t.end()){
    t.append_child(p_iter,child);
  }else{
    log_error("attempt to add a child to a non-existant parent.");
  }
}

std::vector<I3Particle>
I3MCTreeUtils::get_primaries(I3MCTree& t){
  std::vector<I3Particle> primaryList;
  I3MCTree::sibling_iterator i;
  for(i=t.begin(); i!=t.end(); ++i)
    primaryList.push_back(*i);
  return primaryList;
}


