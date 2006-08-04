#include "dataclasses/physics/I3MCTreeUtils.h"
#include "icetray/I3Frame.h"

void I3MCTreeUtils::AddPrimary(I3MCTree& t, const I3Particle& p)
{
  I3Tree<I3Particle>::iterator si;
  si = t.end(t.begin());
  t.insert(si,p);
}

void I3MCTreeUtils::AddPrimary(I3MCTreePtr t, const I3Particle& p)
{
  I3MCTreeUtils::AddPrimary(*t, p);
}


void I3MCTreeUtils::AppendChild(I3MCTree& t, const I3Particle& parent, const I3Particle& child)
{
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

void I3MCTreeUtils::AppendChild(I3MCTreePtr t, const I3Particle& parent, const I3Particle& child)
{
  I3MCTreeUtils::AppendChild(*t, parent, child);
}


const std::vector<I3Particle>
I3MCTreeUtils::GetPrimaries(const I3MCTree& t)
{
  std::vector<I3Particle> primaryList;
  I3MCTree::sibling_iterator i;
  for(i=t.begin(); i!=t.end(); ++i)
    primaryList.push_back(*i);
  return primaryList;
}

const std::vector<I3Particle>
I3MCTreeUtils::GetPrimaries(I3MCTreeConstPtr t)
{
  return I3MCTreeUtils::GetPrimaries(*t);
}


const std::vector<I3Particle>
I3MCTreeUtils::GetDaughters(const I3MCTree& t, const I3Particle& parent)
{
  std::vector<I3Particle> daughterList;
  I3MCTree::iterator i = t.begin();
  for( ; i != t.end(); i++){
    if(i->GetID() == parent.GetID()){
      I3MCTree::sibling_iterator j(i);
      for(j=t.begin(i); j!=t.end(i); ++j)
	daughterList.push_back(*j);
      return daughterList;
    }
  }
  log_warn("No daughters found for this particle.");
  return daughterList;
}

const std::vector<I3Particle>
I3MCTreeUtils::GetDaughters(I3MCTreeConstPtr t, const I3Particle& parent)
{
  return I3MCTreeUtils::GetDaughters(*t, parent);
}


const I3Particle&
I3MCTreeUtils::GetParent(const I3MCTree& t, const I3Particle& child)
{
  I3MCTree::iterator i = t.begin();
  for( ; i != t.end(); i++){
    if(i->GetID() == child.GetID())
      return *(t.parent(i));
  }
  log_fatal("No parent found for this particle.");
}

const I3Particle&
I3MCTreeUtils::GetParent(I3MCTreeConstPtr t, const I3Particle& child)
{
  return I3MCTreeUtils::GetParent(*t, child);
}


bool
I3MCTreeUtils::HasParent(const I3MCTree& t, const I3Particle& child)
{
  I3MCTree::iterator i = t.begin();
  for( ; i != t.end(); i++)
    if(i->GetID() == child.GetID())
      if(t.parent(i) != t.end()) return true;
  return false;
}

bool
I3MCTreeUtils::HasParent(I3MCTreeConstPtr t, const I3Particle& child)
{
  return I3MCTreeUtils::HasParent(*t, child);
}

void I3MCTreeUtils::ConvertComposite(I3MCTree& t, I3MCTree::iterator& i, const vector<I3Particle>& cl){
  vector<I3Particle>::const_iterator j = cl.begin();
  for( ; j!=cl.end(); j++){
    I3Particle p(*j);
    p.GetComposite().clear();
    I3MCTree::iterator k = t.append_child(i,p);
    I3MCTreeUtils::ConvertComposite(t,k,j->GetComposite());
  }
}

I3MCTreePtr I3MCTreeUtils::ListToTree(const I3MCList& list){
  I3MCTreePtr t(new I3MCTree);
  I3MCList::const_iterator i = list.begin();
  for( ; i!=list.end(); i++){
    I3Tree<I3Particle>::iterator si;
    si = t->end(t->begin());
    I3Particle p(*i);
    p.GetComposite().clear();
    I3MCTree::iterator iter = t->insert(si,p);
    //This is a recursive function
    I3MCTreeUtils::ConvertComposite(*t,iter,i->GetComposite());
  }
  return t;
}

I3MCTreeConstPtr
I3MCTreeUtils::Get(I3FramePtr frame, string key){
  I3MCListConstPtr list  = frame->Get<I3MCListConstPtr>(key);
  if(list){
    return I3MCTreeUtils::ListToTree(*list);
  }else{
    return frame->Get<I3MCTreeConstPtr>(key);
  }
}

/*
const I3Particle& 
I3MCTreeUtils::GetMostEnergeticInIce(const I3MCTree& t)
{
  double maxenergy = 0.;
  I3MCTree::iterator iter, iter_return;
  for (iter=t.begin(); iter!=t.end(); ++iter) {
    if (iter->GetEnergy()>maxenergy && 
	iter->GetLocationType()==I3Particle::InIce) {
      maxenergy = iter->GetEnergy();
      iter_return = iter;
    }
  }
  return *iter_return;
}

const I3Particle& 
I3MCTreeUtils::GetMostEnergeticInIce(I3MCTreeConstPtr t)
{
  return GetMostEnergeticInIce(*t);
}


const vector<I3Particle> 
I3MCTreeUtils::Get(const I3MCTree& t, I3Particle::LocationType l)
{
  vector<I3Particle> v;
  I3MCTree::iterator iter;
  for (iter=t.begin(); iter!=t.end(); ++iter) 
    if (iter->GetLocationType()==l) 
      v.push_back(*iter);
  return v;
}

const vector<I3Particle> 
I3MCTreeUtils::GetInIce(const I3MCTree& t)
{
  return Get(t,I3Particle::InIce);
}

const vector<I3Particle> 
I3MCTreeUtils::GetInIce(I3MCTreeConstPtr t)
{
  return Get(*t,I3Particle::InIce);
}

const vector<I3Particle> 
I3MCTreeUtils::GetIceTop(const I3MCTree& t)
{
  return Get(t,I3Particle::IceTop);
}

const vector<I3Particle> 
I3MCTreeUtils::GetIceTop(I3MCTreeConstPtr t)
{
  return Get(*t,I3Particle::IceTop);
}
*/
