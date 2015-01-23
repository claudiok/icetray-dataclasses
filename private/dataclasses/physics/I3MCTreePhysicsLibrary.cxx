#include <dataclasses/physics/I3MCTreePhysicsLibrary.hh>

#include "dataclasses/physics/I3ParticleID.h"
#include "dataclasses/physics/I3MCTreeUtils.h"

using I3MCTreeUtils::GetBestFilter;
using I3MCTreeUtils::GetBestFilterPtr;

namespace{
  bool MoreEnergetic(const I3Particle& a, const I3Particle& b){
    if (a.GetEnergy() > b.GetEnergy()) return true;
    else return false;
  }

  bool IsPrimary(const I3Particle& p){ return p.IsPrimary(); }
  bool IsCascade(const I3Particle& p){ return p.IsCascade(); }
  bool IsTopShower(const I3Particle& p){ return p.IsTopShower(); }
  bool IsNeutrino(const I3Particle& p){ return p.IsNeutrino(); }
  bool IsNucleus(const I3Particle& p){ return p.IsNucleus(); }
  bool IsTrack(const I3Particle& p){ return p.IsTrack(); }

  bool IsInIceCascade(const I3Particle& p){
      return p.GetLocationType() == I3Particle::InIce && p.IsCascade(); }
  bool IsInIce(const I3Particle& p){return p.GetLocationType() == I3Particle::InIce; }
  bool IsIceTop(const I3Particle& p){return p.GetLocationType() == I3Particle::IceTop; }
  bool IsActiveVolume(const I3Particle& p){
    return p.GetLocationType() == I3Particle::InActiveVolume;
  }

  bool IsElectron(const I3Particle& p){
    return p.GetType() == I3Particle::EPlus 
      || p.GetType() == I3Particle::EMinus; 
  }

  bool IsMuon(const I3Particle& p){
    return p.GetType() == I3Particle::MuPlus 
      || p.GetType() == I3Particle::MuMinus; 
  }

  bool IsTau(const I3Particle& p){
    return p.GetType() == I3Particle::TauPlus 
      || p.GetType() == I3Particle::TauMinus; 
  }

  struct IsParticle{
    I3Particle::ParticleType type;
    IsParticle(const I3Particle::ParticleType t):type(t){};
    bool operator()(const I3Particle& p){ return p.GetType() == type;}    
  };
}

I3MCTree::optional_value 
I3MCTreePhysicsLibrary::GetMostEnergeticPrimary(const I3MCTree& t){
  return GetBestFilter(t, IsPrimary, MoreEnergetic);
}
I3MCTree::optional_value 
I3MCTreePhysicsLibrary::GetMostEnergeticPrimary(I3MCTreeConstPtr t){
  return GetMostEnergeticPrimary(*t);
}

I3MCTree::optional_value 
I3MCTreePhysicsLibrary::GetMostEnergeticInIce(const I3MCTree& t){
    return GetBestFilter(t,  IsInIce, MoreEnergetic);
}
I3MCTree::optional_value 
I3MCTreePhysicsLibrary::GetMostEnergeticInIce(I3MCTreeConstPtr t){
  return GetMostEnergeticInIce(*t);
}

I3MCTree::optional_value 
I3MCTreePhysicsLibrary::GetMostEnergetic(const I3MCTree& t, I3Particle::ParticleType pt){
  IsParticle is_particle(pt);
  return GetBestFilter(t, is_particle, MoreEnergetic);
}
I3MCTree::optional_value 
I3MCTreePhysicsLibrary::GetMostEnergetic(I3MCTreeConstPtr t, I3Particle::ParticleType pt){
  return GetMostEnergetic(*t, pt);
}

I3MCTree::optional_value 
I3MCTreePhysicsLibrary::GetMostEnergeticTrack(const I3MCTree& t){
  return GetBestFilter(t, IsTrack, MoreEnergetic);
}

I3MCTree::optional_value 
I3MCTreePhysicsLibrary::GetMostEnergeticTrack(I3MCTreeConstPtr t){
  return GetMostEnergeticTrack(*t);
}

I3MCTree::optional_value 
I3MCTreePhysicsLibrary::GetMostEnergeticCascade(const I3MCTree& t){
  return GetBestFilter(t, IsCascade, MoreEnergetic);
}
I3MCTree::optional_value 
I3MCTreePhysicsLibrary::GetMostEnergeticCascade(I3MCTreeConstPtr t){
  return GetMostEnergeticCascade(*t);
}

I3MCTree::optional_value 
I3MCTreePhysicsLibrary::GetMostEnergeticInIceCascade(const I3MCTree& t){
  return GetBestFilter(t, IsInIceCascade, MoreEnergetic); 
}

I3MCTree::optional_value 
I3MCTreePhysicsLibrary::GetMostEnergeticInIceCascade(I3MCTreeConstPtr t){
  return GetMostEnergeticInIceCascade(*t);
}

I3MCTree::optional_value 
I3MCTreePhysicsLibrary::GetMostEnergeticNeutrino(const I3MCTree& t){
  return GetBestFilter(t, IsNeutrino, MoreEnergetic);
}

I3MCTree::optional_value 
I3MCTreePhysicsLibrary::GetMostEnergeticNeutrino(I3MCTreeConstPtr t){
  return GetMostEnergeticNeutrino(*t);
}

I3MCTree::optional_value 
I3MCTreePhysicsLibrary::GetMostEnergeticMuon(const I3MCTree& t){
  return GetBestFilter(t, IsMuon, MoreEnergetic);
}
I3MCTree::optional_value 
I3MCTreePhysicsLibrary::GetMostEnergeticMuon(I3MCTreeConstPtr t){
  return GetMostEnergeticMuon(*t);
}

I3MCTree::optional_value 
I3MCTreePhysicsLibrary::GetMostEnergeticNucleus(const I3MCTree& t){
  return GetBestFilter(t, IsNucleus, MoreEnergetic);
}
I3MCTree::optional_value 
I3MCTreePhysicsLibrary::GetMostEnergeticNucleus(I3MCTreeConstPtr t){
  return GetMostEnergeticNucleus(*t);
}

