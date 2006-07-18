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


const I3Particle& 
I3MCTreeUtils::GetDefaultSecondary(const I3MCTree& t)
{
  const I3Particle& primary = I3MCTreeUtils::GetPrimaries(t)[0];
  const I3Particle& track = I3MCTreeUtils::GetDaughters(t, primary)[0];
  return track;
}

const I3Particle& 
I3MCTreeUtils::GetDefaultSecondary(I3MCTreeConstPtr t)
{
  return I3MCTreeUtils::GetDefaultSecondary(*t);
}
