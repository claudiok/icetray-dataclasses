#include "dataclasses/physics/I3MCTreeUtils.h"
#include "dataclasses/I3TreeUtils.h"
#include "icetray/I3Frame.h"

void I3MCTreeUtils::AddPrimary(I3MCTree& t, I3Particle& p)
{
  p.SetShape(I3Particle::Primary);
  I3TreeUtils::AddTopLevel<I3Particle>(t, p);
}

void I3MCTreeUtils::AddPrimary(I3MCTreePtr t, I3Particle& p)
{
  p.SetShape(I3Particle::Primary);
  I3MCTreeUtils::AddPrimary(*t, p);
}

void I3MCTreeUtils::AddPrimary(I3MCTree& t, const I3MCTree& subt)
{
  I3TreeUtils::AddTopLevel<I3Particle>(t, subt);
}


void I3MCTreeUtils::AppendChild(I3MCTree& t, const I3Particle& parent, const I3Particle& child)
{
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



void I3MCTreeUtils::internal::ConvertComposite(I3MCTree& t, I3MCTree::iterator& i, const std::vector<I3Particle>& cl){
  std::vector<I3Particle>::const_iterator j = cl.begin();
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
I3MCTreeUtils::Get(const I3Frame &frame, const std::string& key){
  I3MCListConstPtr list = frame.Get<I3MCListConstPtr>(key);
  if (list) {
    return I3MCTreeUtils::ListToTree(*list);
  } else {
    return frame.Get<I3MCTreeConstPtr>(key);
  }
}

I3MCTreeConstPtr
I3MCTreeUtils::Get(I3FramePtr frame, const std::string& key){
  return I3MCTreeUtils::Get(*frame,key);
}

I3MCTreeConstPtr
I3MCTreeUtils::Get(const I3Frame &frame, const std::string& key1, const std::string& key2){
  I3MCListConstPtr list1 = frame.Get<I3MCListConstPtr>(key1);
  I3MCListConstPtr list2 = frame.Get<I3MCListConstPtr>(key2);
  if (list1 || list2){
    if (list1) return I3MCTreeUtils::ListToTree(*list1);
    if (list2) return I3MCTreeUtils::ListToTree(*list2);
  } else {
    I3MCTreeConstPtr tree1  = frame.Get<I3MCTreeConstPtr>(key1);
    I3MCTreeConstPtr tree2  = frame.Get<I3MCTreeConstPtr>(key2);
    if (tree1 || tree2){
      if (tree1) return tree1;
      if (tree2) return tree2;
    }
    return I3MCTreeConstPtr();
  }
  return I3MCTreeConstPtr();
}

I3MCTreeConstPtr
I3MCTreeUtils::Get(I3FramePtr frame, const std::string& key1, const std::string& key2){
  return I3MCTreeUtils::Get(*frame,key1,key2);
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

I3MCTree::iterator
I3MCTreeUtils::GetMostEnergeticInIceCascade(const I3MCTree& t)
{
  double maxenergy = 0.;
  I3MCTree::iterator iter, iter_return = t.end();
  for (iter=t.begin(); iter!=t.end(); ++iter) {
    if (iter->GetEnergy()>maxenergy && iter->IsCascade() && 
	iter->GetLocationType() == I3Particle::InIce) {
      maxenergy = iter->GetEnergy();
      iter_return = iter;
    }
  }
  return iter_return;
}

I3MCTree::iterator
I3MCTreeUtils::GetMostEnergeticInIceCascade(I3MCTreeConstPtr t)
{
  return GetMostEnergeticInIceCascade(*t);
}

I3MCTree::iterator
I3MCTreeUtils::GetMostEnergeticMuon(const I3MCTree& t){
  double maxenergy = 0.;
  I3MCTree::iterator iter_return = t.end();
  for (I3MCTree::iterator iter=t.begin(); iter!=t.end(); ++iter) {
    if (iter->GetEnergy()>maxenergy &&
        (iter->GetType()==I3Particle::MuPlus||iter->GetType()==I3Particle::MuMinus))
      {
        maxenergy = iter->GetEnergy();
        iter_return = iter;
      }
  }  
  return iter_return;
}

I3MCTree::iterator
I3MCTreeUtils::GetMostEnergeticMuon(I3MCTreeConstPtr t){
  return I3MCTreeUtils::GetMostEnergeticMuon(*t);
}


I3MCTree::iterator
I3MCTreeUtils::GetMostEnergeticNeutrino(const I3MCTree& t){
  double maxenergy = 0.;
  I3MCTree::iterator iter_return = t.end();
  for (I3MCTree::iterator iter=t.begin(); iter!=t.end(); ++iter) {
    if (iter->GetEnergy()>maxenergy && iter->IsNeutrino()){
      maxenergy = iter->GetEnergy();
      iter_return = iter;
    }
  }
  return iter_return;
}

I3MCTree::iterator
I3MCTreeUtils::GetMostEnergeticNeutrino(I3MCTreeConstPtr t){
  return I3MCTreeUtils::GetMostEnergeticNeutrino(*t);
}


I3MCTree::iterator
I3MCTreeUtils::GetMostEnergeticNucleus(const I3MCTree& t){
  double maxenergy = 0.;
  I3MCTree::iterator iter_return = t.end();
  for (I3MCTree::iterator iter=t.begin(); iter!=t.end(); ++iter) {
    if (iter->GetEnergy()>maxenergy && 
	(iter->GetType()==I3Particle::PPlus || iter->GetType()==I3Particle::PMinus || 
	 (iter->GetType()>=I3Particle::He4Nucleus && 
	  iter->GetType()>=I3Particle::Li7Nucleus && 
	  iter->GetType()>=I3Particle::Be9Nucleus && 
	  iter->GetType()>=I3Particle::B11Nucleus && 
	  iter->GetType()>=I3Particle::C12Nucleus && 
	  iter->GetType()>=I3Particle::N14Nucleus && 
	  iter->GetType()>=I3Particle::O16Nucleus && 
	  iter->GetType()>=I3Particle::F19Nucleus && 
	  iter->GetType()>=I3Particle::Ne20Nucleus && 
	  iter->GetType()>=I3Particle::Na23Nucleus && 
	  iter->GetType()>=I3Particle::Mg24Nucleus && 
	  iter->GetType()>=I3Particle::Al27Nucleus && 
	  iter->GetType()>=I3Particle::Si28Nucleus && 
	  iter->GetType()>=I3Particle::P31Nucleus && 
	  iter->GetType()>=I3Particle::S32Nucleus && 
	  iter->GetType()>=I3Particle::Cl35Nucleus && 
	  iter->GetType()>=I3Particle::Ar40Nucleus && 
	  iter->GetType()>=I3Particle::K39Nucleus && 
	  iter->GetType()>=I3Particle::Ca40Nucleus && 
	  iter->GetType()>=I3Particle::Sc45Nucleus && 
	  iter->GetType()>=I3Particle::Ti48Nucleus && 
	  iter->GetType()>=I3Particle::V51Nucleus && 
	  iter->GetType()>=I3Particle::Cr52Nucleus && 
	  iter->GetType()>=I3Particle::Mn55Nucleus && 
	  iter->GetType()<= I3Particle::Fe56Nucleus))){
      maxenergy = iter->GetEnergy();
      iter_return = iter;
    }
  }
  return iter_return;
}

I3MCTree::iterator
I3MCTreeUtils::GetMostEnergeticNucleus(I3MCTreeConstPtr t){
  return I3MCTreeUtils::GetMostEnergeticNucleus(*t);
}


//------------------------------

const std::vector<I3Particle> 
I3MCTreeUtils::Get(const I3MCTree& t, I3Particle::LocationType l)
{
  std::vector<I3Particle> v;
  I3MCTree::iterator iter;
  for (iter=t.begin(); iter!=t.end(); ++iter) 
    if (iter->GetLocationType()==l) 
      v.push_back(*iter);
  return v;
}

const std::vector<I3Particle> 
I3MCTreeUtils::GetInIce(const I3MCTree& t)
{
  return Get(t,I3Particle::InIce);
}

const std::vector<I3Particle> 
I3MCTreeUtils::GetInIce(I3MCTreeConstPtr t)
{
  return Get(*t,I3Particle::InIce);
}

const std::vector<I3Particle> 
I3MCTreeUtils::GetIceTop(const I3MCTree& t)
{
  return Get(t,I3Particle::IceTop);
}

const std::vector<I3Particle> 
I3MCTreeUtils::GetIceTop(I3MCTreeConstPtr t)
{
  return Get(*t,I3Particle::IceTop);
}

I3MCTree::iterator 
I3MCTreeUtils::GetIterator(I3MCTreePtr t, const I3Particle& p){
  return GetIterator(*t, p);
}

I3MCTree::iterator 
I3MCTreeUtils::GetIterator(I3MCTree& t, const I3Particle& p){
  I3MCTree::iterator i;
  for(i=t.begin() ; i!= t.end(); i++)
    if((i->GetMinorID() == p.GetMinorID()) &&
       (i->GetMajorID() == p.GetMajorID()))
      return i;
  return t.end();
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

I3ParticlePtr
I3MCTreeUtils::GetPrimary(const I3MCTree& t, const I3Particle& p)
{
  I3MCTreePtr t_ptr(new I3MCTree(t));
  const I3MCTree::iterator p_iter = I3MCTreeUtils::GetIterator(t_ptr,p);
  if(t_ptr->depth(p_iter) == 0 )
    return I3ParticlePtr(new I3Particle(p));

  I3MCTree::iterator parent_iter = t_ptr->parent(p_iter);
  while(t_ptr->depth(parent_iter) != 0)
    parent_iter = t_ptr->parent(parent_iter);

  if(parent_iter != t_ptr->end())
    return I3ParticlePtr(new I3Particle(*parent_iter));
  else
    log_error("couldn't find the primary");

  return I3ParticlePtr();
}

I3ParticlePtr
I3MCTreeUtils::GetPrimary(I3MCTreePtr t, const I3Particle& p){
  return GetPrimary(*t,p);
}

I3ParticlePtr
I3MCTreeUtils::GetPrimary(I3MCTreeConstPtr t, const I3Particle& p){
  return GetPrimary(*t,p);
}

