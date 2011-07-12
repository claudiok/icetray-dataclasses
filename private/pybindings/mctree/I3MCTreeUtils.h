//
//   Copyright (c) 2004, 2005, 2006, 2007   Troy D. Straszheim  
//   
//   $Id: ithon.cxx 25598 2006-11-25 02:52:57Z troy $
//
//   This file is part of IceTray.
//
//   IceTray is free software; you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation; either version 3 of the License, or
//   (at your option) any later version.
//
//   IceTray is distributed in the hope that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//   GNU General Public License for more details.
//
//   You should have received a copy of the GNU General Public License
//   along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#include <vector>

#include <dataclasses/physics/I3MCTreeUtils.h>
#include <dataclasses/physics/I3MCTree.h>
#include <dataclasses/I3Constants.h>

inline boost::shared_ptr<I3Particle> GetMostEnergeticPrimary(I3MCTree* tree)
{
  I3MCTree::iterator itr=I3MCTreeUtils::GetMostEnergeticPrimary(*tree);
  if (itr==tree->end())
    {
      return I3ParticlePtr();
    }
  else
    {
      return I3ParticlePtr(new I3Particle(*itr));
    }
}

inline boost::shared_ptr<I3Particle> GetMostEnergeticInIce(I3MCTree* tree)
{
  I3MCTree::iterator itr=I3MCTreeUtils::GetMostEnergeticInIce(*tree);
  if (itr==tree->end())
    {
      return I3ParticlePtr();
    }
  else
    {
      return I3ParticlePtr(new I3Particle(*itr));
    }
}

inline boost::shared_ptr<I3Particle> GetMostEnergetic(I3MCTree* tree,I3Particle::ParticleType type)
{
  I3MCTree::iterator itr=I3MCTreeUtils::GetMostEnergetic(*tree,type);
  if (itr==tree->end())
    {
      return I3ParticlePtr();
    }
  else
    {
      return I3ParticlePtr(new I3Particle(*itr));
    }
}
inline boost::shared_ptr<I3Particle> GetMostEnergeticTrack(I3MCTree* tree)
{
  I3MCTree::iterator itr=I3MCTreeUtils::GetMostEnergeticTrack(*tree);
  if (itr==tree->end())
    {
      return I3ParticlePtr();
    }
  else
    {
      return I3ParticlePtr(new I3Particle(*itr));
    }
}
inline boost::shared_ptr<I3Particle> GetMostEnergeticCascade(I3MCTree* tree)
{
  I3MCTree::iterator itr=I3MCTreeUtils::GetMostEnergeticCascade(*tree);
  if (itr==tree->end())
    {
      return I3ParticlePtr();
    }
  else
    {
      return I3ParticlePtr(new I3Particle(*itr));
    }
}

std::vector<I3Particle> GetInIce(I3MCTreePtr t){
  return I3MCTreeUtils::GetInIce(t);
}

void AddPrimary(I3MCTreePtr t, I3ParticlePtr p){
  return I3MCTreeUtils::AddPrimary(*t,*p);
}

void AppendChild(I3MCTreePtr t, I3ParticlePtr p, I3ParticlePtr d){
  return I3MCTreeUtils::AppendChild(*t,*p, *d);
}

int NCascades(I3MCTreePtr t){
  int n_cascades(0);
  I3MCTree::iterator t_iter = t->begin();
  for( ; t_iter != t->end(); t_iter++){
    if(t_iter->IsCascade()) n_cascades++;
  }
  return n_cascades;
}

std::vector<I3Particle> GetPrimaries(I3MCTreePtr t){
  return I3MCTreeUtils::GetPrimaries(t);
}

void Merge(I3MCTreePtr t, I3MCTreePtr t2){
  I3MCTree::sibling_iterator si;
  for(si = t2->begin(); si != t2->end(); si++){      
    t->insert_subtree(t->begin(),si);
  }
}

std::vector<I3Particle> 
GetDaughters(I3MCTreePtr t, I3ParticlePtr p){
  return I3MCTreeUtils::GetDaughters(*t,*p);
}

bool HasParent(I3MCTreePtr t, I3ParticlePtr c){
  return I3MCTreeUtils::HasParent(*t,*c);
}

inline I3ParticlePtr Get(const I3MCTree& tree, const I3MCHit& hit)
{
  return I3ParticlePtr(new I3Particle(I3MCTreeUtils::Get(tree,hit)));
}

inline I3ParticlePtr GetPrimary(const I3MCTree& tree, const I3Particle& particle)
{
  return I3ParticlePtr(new I3Particle(*I3MCTreeUtils::GetPrimary(tree,particle)));
}

I3ParticlePtr
GetMostEnergeticStochastic(const I3MCTree& t)
{
  double maxenergy = 0.;
  I3MCTree::iterator iter, iter_return = t.end();
  for (iter=t.begin(); iter!=t.end(); ++iter) {
    if (iter->GetEnergy()>maxenergy && 
	(iter->GetType()==I3Particle::Brems ||
        iter->GetType()==I3Particle::PairProd ||
        iter->GetType()==I3Particle::DeltaE ||
        iter->GetType()==I3Particle::NuclInt) ) {
      maxenergy = iter->GetEnergy();
      iter_return = iter;
    }
  }
  if(iter_return != t.end())
    return I3ParticlePtr( new I3Particle(*iter_return));
  else return I3ParticlePtr();
}

int GetNumberOfStochastics(const I3MCTree& t, double thresholdEnergy)
{
  int numberOfStochastics = 0;
  I3MCTree::iterator iter;
  for (iter=t.begin(); iter!=t.end(); ++iter) {
    if (iter->GetEnergy()>thresholdEnergy && 
	(iter->GetType()==I3Particle::Brems ||
        iter->GetType()==I3Particle::PairProd ||
        iter->GetType()==I3Particle::DeltaE ||
        iter->GetType()==I3Particle::NuclInt) ) {
      numberOfStochastics++;
    }
  }
  return numberOfStochastics;
}

bool IsCosmicRayParticle(const I3Particle& particle)
{
  bool isCosmicRayParticle = false;
  if (particle.GetType() ==  I3Particle::PPlus ||
      particle.GetType() ==  I3Particle::PMinus ||
      particle.GetType() ==  I3Particle::He4Nucleus ||
      particle.GetType() ==  I3Particle::Li7Nucleus ||
      particle.GetType() ==  I3Particle::Be9Nucleus ||
      particle.GetType() ==  I3Particle::B11Nucleus ||
      particle.GetType() ==  I3Particle::C12Nucleus ||
      particle.GetType() ==  I3Particle::N14Nucleus ||
      particle.GetType() ==  I3Particle::O16Nucleus ||
      particle.GetType() ==  I3Particle::F19Nucleus ||
      particle.GetType() ==  I3Particle::Ne20Nucleus ||
      particle.GetType() ==  I3Particle::Na23Nucleus ||
      particle.GetType() ==  I3Particle::Mg24Nucleus ||
      particle.GetType() ==  I3Particle::Al27Nucleus ||
      particle.GetType() ==  I3Particle::Si28Nucleus ||
      particle.GetType() ==  I3Particle::P31Nucleus ||
      particle.GetType() ==  I3Particle::S32Nucleus ||
      particle.GetType() ==  I3Particle::Cl35Nucleus ||
      particle.GetType() ==  I3Particle::Ar40Nucleus ||
      particle.GetType() ==  I3Particle::K39Nucleus ||
      particle.GetType() ==  I3Particle::Ca40Nucleus ||
      particle.GetType() ==  I3Particle::Sc45Nucleus ||
      particle.GetType() ==  I3Particle::Ti48Nucleus ||
      particle.GetType() ==  I3Particle::V51Nucleus ||
      particle.GetType() ==  I3Particle::Cr52Nucleus ||
      particle.GetType() ==  I3Particle::Mn55Nucleus ||
      particle.GetType() ==  I3Particle::Fe56Nucleus){

    isCosmicRayParticle = true;
  }
  return isCosmicRayParticle; 
}


int GetNumberOfAtmosphericMuons(const I3MCTree& t)
{
  int numberOfAtmosphericMuons = 0;

  //--check for primary particle type
  BOOST_FOREACH(const I3Particle& primary, I3MCTreeUtils::GetPrimaries(t)){
    if (IsCosmicRayParticle(primary)){ 
      BOOST_FOREACH(const I3Particle& particle, I3MCTreeUtils::GetDaughters(t, primary)){
	if(particle.GetType()==I3Particle::MuPlus ||
	   particle.GetType()==I3Particle::MuMinus){
	  numberOfAtmosphericMuons++;
	}
      }//BOOST_FOREACH daughter
      
    }//BOOST_FOREACH primary
  }
  return numberOfAtmosphericMuons;
}


