#include "dataclasses/physics/I3MCTreeUtils.h"
#include "dataclasses/I3TreeUtils.h"
#include "icetray/I3Frame.h"

void I3MCTreeUtils::AddPrimary(I3MCTree& t, const I3Particle& p)
{
  I3TreeUtils::AddTopLevel<I3Particle>(t, p);
}

void I3MCTreeUtils::AddPrimary(I3MCTreePtr t, const I3Particle& p)
{
  I3MCTreeUtils::AddPrimary(*t, p);
}

void I3MCTreeUtils::AddPrimary(I3MCTree& t, const I3MCTree& subt)
{
  //I3MCTree subtt(subt);
  I3TreeUtils::AddTopLevel<I3Particle>(t, subt);
}


void I3MCTreeUtils::AppendChild(I3MCTree& t, const I3Particle& parent, const I3Particle& child)
{
  //Need to find the iterator of the parent
  //do it bonehead-style first
  I3TreeUtils::AppendChild<I3Particle>(t, parent, child);
}

void I3MCTreeUtils::AppendChild(I3MCTreePtr t, const I3Particle& parent, const I3Particle& child)
{
  I3MCTreeUtils::AppendChild(*t, parent, child);
}


const std::vector<I3Particle>
I3MCTreeUtils::GetPrimaries(const I3MCTree& t)
{
  return I3TreeUtils::GetTopLevelList<I3Particle>(t);
}

const std::vector<I3Particle>
I3MCTreeUtils::GetPrimaries(I3MCTreeConstPtr t)
{
  return I3MCTreeUtils::GetPrimaries(*t);
}


const std::vector<I3Particle>
I3MCTreeUtils::GetDaughters(const I3MCTree& t, const I3Particle& parent)
{
  return I3TreeUtils::GetDaughters<I3Particle>(t, parent);
}

const std::vector<I3Particle>
I3MCTreeUtils::GetDaughters(I3MCTreeConstPtr t, const I3Particle& parent)
{
  return I3MCTreeUtils::GetDaughters(*t, parent);
}


const I3Particle&
I3MCTreeUtils::GetParent(const I3MCTree& t, const I3Particle& child)
{
  return I3TreeUtils::GetParent<I3Particle>(t, child);
}

const I3Particle&
I3MCTreeUtils::GetParent(I3MCTreeConstPtr t, const I3Particle& child)
{
  return I3MCTreeUtils::GetParent(*t, child);
}


bool
I3MCTreeUtils::HasParent(const I3MCTree& t, const I3Particle& child)
{
  return I3TreeUtils::HasParent(t, child);
}

bool
I3MCTreeUtils::HasParent(I3MCTreeConstPtr t, const I3Particle& child)
{
  return I3MCTreeUtils::HasParent(*t, child);
}



void I3MCTreeUtils::internal::ConvertComposite(I3MCTree& t, I3MCTree::iterator& i, const vector<I3Particle>& cl){
  vector<I3Particle>::const_iterator j = cl.begin();
  for( ; j!=cl.end(); j++){
    I3Particle p(*j);
    p.GetComposite().clear();
    I3MCTree::iterator k = t.append_child(i,p);
    I3MCTreeUtils::internal::ConvertComposite(t,k,j->GetComposite());
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
    I3MCTreeUtils::internal::ConvertComposite(*t,iter,i->GetComposite());
  }
  return t;
}

I3MCTreePtr I3MCTreeUtils::ListToTree(I3MCListConstPtr list){
  return ListToTree(*list);
}

I3MCTreeConstPtr
I3MCTreeUtils::Get(I3FramePtr frame, const string& key){
  I3MCListConstPtr list  = frame->Get<I3MCListConstPtr>(key);
  if(list){
    return I3MCTreeUtils::ListToTree(*list);
  }else{
    return frame->Get<I3MCTreeConstPtr>(key);
  }
}

I3MCTreeConstPtr
I3MCTreeUtils::Get(I3FramePtr frame, const string& key1, const string& key2){
  I3MCListConstPtr list1  = frame->Get<I3MCListConstPtr>(key1);
  I3MCListConstPtr list2  = frame->Get<I3MCListConstPtr>(key2);
  if(list1 || list2){
    if(list1) return I3MCTreeUtils::ListToTree(*list1);
    if(list2) return I3MCTreeUtils::ListToTree(*list2);
  }else{
    I3MCTreeConstPtr tree1  = frame->Get<I3MCTreeConstPtr>(key1);
    I3MCTreeConstPtr tree2  = frame->Get<I3MCTreeConstPtr>(key2);
    if(tree1 || tree2){
      if(tree1) return tree1;
      if(tree2) return tree2;
    }
    return I3MCTreeConstPtr();
  }
  return I3MCTreeConstPtr();
}

//------------------------------

I3MCTree::iterator
I3MCTreeUtils::GetMostEnergeticPrimary(const I3MCTree& t)
{
  double maxenergy = 0.;
  I3MCTree::sibling_iterator iter, iter_return = t.end();
  for (iter=t.begin(); iter!=t.end(); iter++) {
    if (iter->GetEnergy()>maxenergy) {
      maxenergy = iter->GetEnergy();
      iter_return = iter;
    }
  }
  return iter_return;
}

I3MCTree::iterator
I3MCTreeUtils::GetMostEnergeticPrimary(I3MCTreeConstPtr t)
{
  return GetMostEnergeticPrimary(*t);
}

I3MCTree::iterator
I3MCTreeUtils::GetMostEnergeticInIce(const I3MCTree& t)
{
  double maxenergy = 0.;
  I3MCTree::iterator iter, iter_return = t.end();
  for (iter=t.begin(); iter!=t.end(); ++iter) {
    if (iter->GetEnergy()>maxenergy && 
	iter->GetLocationType()==I3Particle::InIce) {
      maxenergy = iter->GetEnergy();
      iter_return = iter;
    }
  }
  return iter_return;
}

I3MCTree::iterator
I3MCTreeUtils::GetMostEnergeticInIce(I3MCTreeConstPtr t)
{
  return GetMostEnergeticInIce(*t);
}

I3MCTree::iterator
I3MCTreeUtils::GetMostEnergetic(const I3MCTree& t,
				I3Particle::ParticleType type)
{
  double maxenergy = 0.;
  I3MCTree::iterator iter, iter_return = t.end();
  for (iter=t.begin(); iter!=t.end(); ++iter) {
    if (iter->GetEnergy()>maxenergy && iter->GetType()==type) {
      maxenergy = iter->GetEnergy();
      iter_return = iter;
    }
  }
  return iter_return;
}

I3MCTree::iterator
I3MCTreeUtils::GetMostEnergetic(I3MCTreeConstPtr t,
				I3Particle::ParticleType type)
{
  return GetMostEnergetic(*t, type);
}

I3MCTree::iterator
I3MCTreeUtils::GetMostEnergeticTrack(const I3MCTree& t)
{
  double maxenergy = 0.;
  I3MCTree::iterator iter, iter_return = t.end();
  for (iter=t.begin(); iter!=t.end(); ++iter) {
    if (iter->GetEnergy()>maxenergy && iter->IsTrack()) {
      maxenergy = iter->GetEnergy();
      iter_return = iter;
    }
  }
  return iter_return;
}

I3MCTree::iterator
I3MCTreeUtils::GetMostEnergeticTrack(I3MCTreeConstPtr t)
{
  return GetMostEnergeticTrack(*t);
}

I3MCTree::iterator
I3MCTreeUtils::GetMostEnergeticCascade(const I3MCTree& t)
{
  double maxenergy = 0.;
  I3MCTree::iterator iter, iter_return = t.end();
  for (iter=t.begin(); iter!=t.end(); ++iter) {
    if (iter->GetEnergy()>maxenergy && iter->IsCascade()) {
      maxenergy = iter->GetEnergy();
      iter_return = iter;
    }
  }
  return iter_return;
}

I3MCTree::iterator
I3MCTreeUtils::GetMostEnergeticCascade(I3MCTreeConstPtr t)
{
  return GetMostEnergeticCascade(*t);
}

//------------------------------

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

I3MCTree::iterator 
I3MCTreeUtils::GetIterator(I3MCTreePtr t, const I3Particle& p){
  I3MCTree::iterator i;
  for(i=t->begin() ; i!= t->end(); i++)
    if((i->GetMinorID() == p.GetMinorID()) &&
       (i->GetMajorID() == p.GetMajorID()))
      return i;
  return t->end();
}

void I3MCTreeUtils::internal::DumpChildren(const I3MCTree& t,I3MCTree::iterator i){
  I3MCTree::sibling_iterator si;
  for(si = t.begin(i); si != t.end(i); si++){
    for(int j=0; j<5*t.depth(si); j++) cout<<" ";
    cout<<si->GetTypeString()<<" "
	<<si->GetMajorID()<<" "
	<<si->GetMinorID()<<" "
	<<endl;
    DumpChildren(t,si);
  }
}


void I3MCTreeUtils::Dump(const I3MCTree& t){
  I3MCTree::sibling_iterator i;
  cout<<"*** TREE DUMP - BEGIN***"<<endl;
  cout<<"*** "<<t.size()<<" elements"<<endl;
  for(i = t.begin(); i != t.end(); i++){
    for(int j=0; j<5*t.depth(i); j++) cout<<" ";
    cout<<i->GetTypeString()<<" "
	<<i->GetMinorID()<<" "
	<<i->GetMajorID()<<" "
	<<endl;
    internal::DumpChildren(t,i);
  }
  cout<<"*** TREE DUMP - END***"<<endl;
}

void I3MCTreeUtils::Dump(I3MCTreeConstPtr t){
  Dump(*t);
}

void I3MCTreeUtils::Dump(I3MCTreePtr t){
  Dump(*t);
}

I3Particle
I3MCTreeUtils::Get(const I3MCTree& t, const I3MCHit& mchit)
{
  I3MCTree::iterator iter;
  for (iter=t.begin(); iter!=t.end(); ++iter) 
    if (iter->GetMajorID()== mchit.GetParticleMajorID() && 
	iter->GetMinorID()== mchit.GetParticleMinorID()) 
      return *iter;
  log_error("Could not find I3Particle associated with I3MCHit");
  return I3Particle();
}
