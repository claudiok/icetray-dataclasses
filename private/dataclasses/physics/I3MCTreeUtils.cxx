#include "dataclasses/physics/I3MCTreeUtils.h"
#include "icetray/I3Frame.h"


void
I3MCTreeUtils::AddPrimary(I3MCTree& t, const I3Particle& p)
{
  t.insert_after(p);
  I3MCTree::iterator iter(t,p);
  i3_assert( iter != t.end() );
  iter->SetShape(I3Particle::Primary);
}

void
I3MCTreeUtils::AddPrimary(I3MCTreePtr t, const I3Particle& p)
{
  I3MCTreeUtils::AddPrimary(*t,p);
}

void
I3MCTreeUtils::AppendChild(I3MCTree& t, const I3ParticleID& parent, const I3Particle& child)
{
  t.append_child(parent, child);
}

void
I3MCTreeUtils::AppendChild(I3MCTreePtr t, const I3ParticleID& parent, const I3Particle& child)
{
  t->append_child(parent, child);
}

const std::vector<I3Particle>
I3MCTreeUtils::GetPrimaries(const I3MCTree& t)
{
  return t.get_heads();
}

const std::vector<I3Particle>
I3MCTreeUtils::GetPrimaries(I3MCTreeConstPtr t)
{
  return t->get_heads();
}

const std::vector<I3Particle>
I3MCTreeUtils::GetDaughters(const I3MCTree& t, const I3ParticleID& parent)
{
  return t.children(parent);
}

const std::vector<I3Particle>
I3MCTreeUtils::GetDaughters(I3MCTreeConstPtr t, const I3ParticleID& parent)
{
  return t->children(parent);
}

const I3Particle&
I3MCTreeUtils::GetParent(const I3MCTree& t, const I3ParticleID& child)
{
  I3MCTree::nonPtrType parent = t.parent(child);
  if (parent)
    return *parent;
  else
    log_fatal("no parent found");
}

const I3Particle&
I3MCTreeUtils::GetParent(I3MCTreeConstPtr t, const I3ParticleID& child)
{
  return I3MCTreeUtils::GetParent(*t,child);
}

bool
I3MCTreeUtils::HasParent(const I3MCTree& t, const I3ParticleID& child)
{
  I3MCTree::nonPtrType parent = t.parent(child);
  if (parent)
    return true;
  else
    return false;
}

bool
I3MCTreeUtils::HasParent(I3MCTreeConstPtr t, const I3ParticleID& child)
{
  return I3MCTreeUtils::HasParent(*t, child);
}

const I3Particle&
I3MCTreeUtils::GetParticle(const I3MCTree& t, const I3ParticleID& p)
{
  I3MCTree::nonPtrType ret = t.at(p);
  if (ret)
    return *ret;
  else
    log_fatal("particleID not found");
}

const I3Particle&
I3MCTreeUtils::GetParticle(I3MCTreeConstPtr t, const I3ParticleID& p)
{
  return I3MCTreeUtils::GetParticle(*t,p);
}

const I3Particle&
I3MCTreeUtils::GetPrimary(const I3MCTree& t, const I3ParticleID& p)
{
  I3MCTree::nonPtrType child,parent = t.at(p);
  if (!parent)
    log_fatal("particle not found");
  while(parent) {
    child = parent;
    parent = t.parent(*parent);
  }
  return *child;
}

const I3Particle&
I3MCTreeUtils::GetPrimary(I3MCTreeConstPtr t, const I3ParticleID& p)
{
  return I3MCTreeUtils::GetPrimary(*t,p);
}

I3MCTreeConstPtr
I3MCTreeUtils::Get(const I3Frame &frame, const std::string& key)
{
  return frame.Get<I3MCTreeConstPtr>(key);
}

I3MCTreeConstPtr
I3MCTreeUtils::Get(I3FramePtr frame, const std::string& key)
{
  return I3MCTreeUtils::Get(*frame,key);
}


// --------------------- everything below is deprecated --------------------

I3MCTree::const_iterator
I3MCTreeUtils::GetMostEnergeticPrimary(const I3MCTree& t)
{
  double maxenergy = 0.;
  const std::vector<I3Particle> vec = I3MCTreeUtils::GetPrimaries(t);
  I3MCTree::const_iterator iter_return = t.cend();
  for (size_t i=0; i<vec.size();i++) {
    if (vec[i].GetEnergy()>maxenergy) {
      maxenergy = vec[i].GetEnergy();
      iter_return = I3MCTree::const_iterator(t,vec[i]);
    }
  }
  return iter_return;
}

I3MCTree::const_iterator
I3MCTreeUtils::GetMostEnergeticPrimary(I3MCTreeConstPtr t)
{
  return I3MCTreeUtils::GetMostEnergeticPrimary(*t);
}

I3MCTree::const_iterator
I3MCTreeUtils::GetMostEnergeticInIce(const I3MCTree& t)
{
  double maxenergy = 0.;
  I3MCTree::const_iterator iter=t.cbegin(), iter_return = t.cend();
  for (; iter!=t.cend(); ++iter) {
    if (iter->GetEnergy()>maxenergy && 
	iter->GetLocationType()==I3Particle::InIce) {
      maxenergy = iter->GetEnergy();
      iter_return = iter;
    }
  }
  return iter_return;
}

I3MCTree::const_iterator
I3MCTreeUtils::GetMostEnergeticInIce(I3MCTreeConstPtr t)
{
  return I3MCTreeUtils::GetMostEnergeticInIce(*t);
}

I3MCTree::const_iterator
I3MCTreeUtils::GetMostEnergetic(const I3MCTree& t,
				I3Particle::ParticleType type)
{
  double maxenergy = 0.;
  I3MCTree::const_iterator iter=t.cbegin(), iter_return = t.cend();
  for (; iter!=t.cend(); ++iter) {
    if (iter->GetEnergy()>maxenergy && iter->GetType()==type) {
      maxenergy = iter->GetEnergy();
      iter_return = iter;
    }
  }
  return iter_return;
}

I3MCTree::const_iterator
I3MCTreeUtils::GetMostEnergetic(I3MCTreeConstPtr t,
				I3Particle::ParticleType type)
{
  return I3MCTreeUtils::GetMostEnergetic(*t, type);
}

I3MCTree::const_iterator
I3MCTreeUtils::GetMostEnergeticTrack(const I3MCTree& t)
{
  double maxenergy = 0.;
  I3MCTree::const_iterator iter=t.cbegin(), iter_return = t.cend();
  for (; iter!=t.cend(); ++iter) {
    if (iter->GetEnergy()>maxenergy && iter->IsTrack()) {
      maxenergy = iter->GetEnergy();
      iter_return = iter;
    }
  }
  return iter_return;
}

I3MCTree::const_iterator
I3MCTreeUtils::GetMostEnergeticTrack(I3MCTreeConstPtr t)
{
  return I3MCTreeUtils::GetMostEnergeticTrack(*t);
}

I3MCTree::const_iterator
I3MCTreeUtils::GetMostEnergeticCascade(const I3MCTree& t)
{
  double maxenergy = 0.;
  I3MCTree::const_iterator iter=t.cbegin(), iter_return = t.cend();
  for (; iter!=t.cend(); ++iter) {
    if (iter->GetEnergy()>maxenergy && iter->IsCascade()) {
      maxenergy = iter->GetEnergy();
      iter_return = iter;
    }
  }
  return iter_return;
}

I3MCTree::const_iterator
I3MCTreeUtils::GetMostEnergeticCascade(I3MCTreeConstPtr t)
{
  return I3MCTreeUtils::GetMostEnergeticCascade(*t);
}

I3MCTree::const_iterator
I3MCTreeUtils::GetMostEnergeticInIceCascade(const I3MCTree& t)
{
  double maxenergy = 0.;
  I3MCTree::const_iterator iter=t.cbegin(), iter_return = t.cend();
  for (; iter!=t.cend(); ++iter) {
    if (iter->GetEnergy()>maxenergy && iter->IsCascade() && 
	iter->GetLocationType() == I3Particle::InIce) {
      maxenergy = iter->GetEnergy();
      iter_return = iter;
    }
  }
  return iter_return;
}

I3MCTree::const_iterator
I3MCTreeUtils::GetMostEnergeticInIceCascade(I3MCTreeConstPtr t)
{
  return I3MCTreeUtils::GetMostEnergeticInIceCascade(*t);
}

I3MCTree::const_iterator
I3MCTreeUtils::GetMostEnergeticMuon(const I3MCTree& t){
  double maxenergy = 0.;
  I3MCTree::const_iterator iter_return = t.cend();
  for (I3MCTree::const_iterator iter=t.cbegin(); iter!=t.cend(); ++iter) {
    if (iter->GetEnergy()>maxenergy &&
        (iter->GetType()==I3Particle::MuPlus||iter->GetType()==I3Particle::MuMinus))
      {
        maxenergy = iter->GetEnergy();
        iter_return = iter;
      }
  }  
  return iter_return;
}

I3MCTree::const_iterator
I3MCTreeUtils::GetMostEnergeticMuon(I3MCTreeConstPtr t){
  return I3MCTreeUtils::GetMostEnergeticMuon(*t);
}


I3MCTree::const_iterator
I3MCTreeUtils::GetMostEnergeticNeutrino(const I3MCTree& t){
  double maxenergy = 0.;
  I3MCTree::const_iterator iter_return = t.cend();
  for (I3MCTree::const_iterator iter=t.cbegin(); iter!=t.cend(); ++iter) {
    if (iter->GetEnergy()>maxenergy && iter->IsNeutrino()){
      maxenergy = iter->GetEnergy();
      iter_return = iter;
    }
  }
  return iter_return;
}

I3MCTree::const_iterator
I3MCTreeUtils::GetMostEnergeticNeutrino(I3MCTreeConstPtr t){
  return I3MCTreeUtils::GetMostEnergeticNeutrino(*t);
}


I3MCTree::const_iterator
I3MCTreeUtils::GetMostEnergeticNucleus(const I3MCTree& t){
  double maxenergy = 0.;
  I3MCTree::const_iterator iter_return = t.cend();
  for (I3MCTree::const_iterator iter=t.cbegin(); iter!=t.cend(); ++iter) {
    if (iter->GetEnergy()>maxenergy && 
	(iter->GetType()==I3Particle::PPlus || iter->GetType()==I3Particle::PMinus || 
	 (iter->GetType()>=I3Particle::He4Nucleus || 
	  iter->GetType()>=I3Particle::Li7Nucleus || 
	  iter->GetType()>=I3Particle::Be9Nucleus || 
	  iter->GetType()>=I3Particle::B11Nucleus || 
	  iter->GetType()>=I3Particle::C12Nucleus || 
	  iter->GetType()>=I3Particle::N14Nucleus || 
	  iter->GetType()>=I3Particle::O16Nucleus || 
	  iter->GetType()>=I3Particle::F19Nucleus || 
	  iter->GetType()>=I3Particle::Ne20Nucleus || 
	  iter->GetType()>=I3Particle::Na23Nucleus || 
	  iter->GetType()>=I3Particle::Mg24Nucleus || 
	  iter->GetType()>=I3Particle::Al27Nucleus || 
	  iter->GetType()>=I3Particle::Si28Nucleus || 
	  iter->GetType()>=I3Particle::P31Nucleus || 
	  iter->GetType()>=I3Particle::S32Nucleus || 
	  iter->GetType()>=I3Particle::Cl35Nucleus || 
	  iter->GetType()>=I3Particle::Ar40Nucleus || 
	  iter->GetType()>=I3Particle::K39Nucleus || 
	  iter->GetType()>=I3Particle::Ca40Nucleus || 
	  iter->GetType()>=I3Particle::Sc45Nucleus || 
	  iter->GetType()>=I3Particle::Ti48Nucleus || 
	  iter->GetType()>=I3Particle::V51Nucleus || 
	  iter->GetType()>=I3Particle::Cr52Nucleus || 
	  iter->GetType()>=I3Particle::Mn55Nucleus || 
	  iter->GetType()<= I3Particle::Fe56Nucleus))){
      maxenergy = iter->GetEnergy();
      iter_return = iter;
    }
  }
  return iter_return;
}

I3MCTree::const_iterator
I3MCTreeUtils::GetMostEnergeticNucleus(I3MCTreeConstPtr t){
  return I3MCTreeUtils::GetMostEnergeticNucleus(*t);
}


//------------------------------

const std::vector<I3Particle> 
I3MCTreeUtils::Get(const I3MCTree& t, I3Particle::LocationType l)
{
  std::vector<I3Particle> v;
  I3MCTree::const_iterator iter=t.cbegin();
  for (; iter!=t.cend(); ++iter) 
    if (iter->GetLocationType()==l) 
      v.push_back(*iter);
  return v;
}

const std::vector<I3Particle> 
I3MCTreeUtils::GetInIce(const I3MCTree& t)
{
  return I3MCTreeUtils::Get(t,I3Particle::InIce);
}

const std::vector<I3Particle> 
I3MCTreeUtils::GetInIce(I3MCTreeConstPtr t)
{
  return I3MCTreeUtils::Get(*t,I3Particle::InIce);
}

const std::vector<I3Particle> 
I3MCTreeUtils::GetIceTop(const I3MCTree& t)
{
  return I3MCTreeUtils::Get(t,I3Particle::IceTop);
}

const std::vector<I3Particle> 
I3MCTreeUtils::GetIceTop(I3MCTreeConstPtr t)
{
  return I3MCTreeUtils::Get(*t,I3Particle::IceTop);
}

I3MCTree::iterator 
I3MCTreeUtils::GetIterator(I3MCTreePtr t, const I3ParticleID& p){
  return I3MCTreeUtils::GetIterator(*t, p);
}

I3MCTree::iterator 
I3MCTreeUtils::GetIterator(I3MCTree& t, const I3ParticleID& p){
  return I3MCTree::iterator(t,p);
}


