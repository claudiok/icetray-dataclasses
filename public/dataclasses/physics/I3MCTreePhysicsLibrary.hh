/**
 * copyright  (C) 2013
 * the icecube collaboration
 * @file I3MCTreePhysicsLibrary.h
 */

#ifndef I3MCTREEPHYSLIB_H_INCLUDED
#define I3MCTREEPHYSLIB_H_INCLUDED

#include "dataclasses/physics/I3Particle.h"
#include "dataclasses/physics/I3ParticleID.h"
#include "dataclasses/physics/I3MCTree.h"
#include "dataclasses/physics/I3MCTreeUtils.h"

using I3MCTreeUtils::GetBestFilter;
using I3MCTreeUtils::GetBestFilterPtr;

namespace I3MCTreePhysicsLibrary
{

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
  bool IsActiveVolume(const I3Particle& p){return p.GetLocationType() == I3Particle::InActiveVolume; }

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

  /**
   * Returns the InIce particle with highest energy.
   * This is useful for example in extracting "the muon" from the 
   * atmospheric neutrino data.
   */
  I3MCTree::optional_value GetMostEnergeticPrimary(const I3MCTree& t){
    return GetBestFilter(t, IsPrimary, MoreEnergetic);}

  I3MCTree::optional_value GetMostEnergeticInIce(const I3MCTree& t){
    return GetBestFilter(t,  IsInIce, MoreEnergetic);}

  I3MCTree::optional_value GetMostEnergetic(const I3MCTree& t, I3Particle::ParticleType pt){
    IsParticle is_particle(pt);
    return GetBestFilter(t, is_particle, MoreEnergetic);
  }
    
  I3MCTree::optional_value GetMostEnergeticTrack(const I3MCTree& t){
    return GetBestFilter(t, IsTrack, MoreEnergetic);}

  I3MCTree::optional_value GetMostEnergeticCascade(const I3MCTree& t){
    return GetBestFilter(t, IsCascade, MoreEnergetic);}

  I3MCTree::optional_value GetMostEnergeticInIceCascade(const I3MCTree& t){
    return GetBestFilter(t, IsInIceCascade, MoreEnergetic);}

  I3MCTree::optional_value GetMostEnergeticNeutrino(const I3MCTree& t){
    return GetBestFilter(t, IsNeutrino, MoreEnergetic);}

  I3MCTree::optional_value GetMostEnergeticMuon(const I3MCTree& t){
    return GetBestFilter(t, IsMuon, MoreEnergetic);}

  I3MCTree::optional_value GetMostEnergeticNucleus(const I3MCTree& t){
    return GetBestFilter(t, IsNucleus, MoreEnergetic);}

  /**
   * Returns a std::vector of particles that are InIce.
   *
   * /deprecated Use GetFilter instead
   */
  const std::vector<I3Particle> Get(const I3MCTree&, I3Particle::LocationType) __attribute__ ((deprecated));
  const std::vector<I3Particle> GetInIce(const I3MCTree&) __attribute__ ((deprecated));
  const std::vector<I3Particle> GetInIce(I3MCTreeConstPtr) __attribute__ ((deprecated));

  /**
   * Returns a std::vector of particles that are IceTop.
   *
   * /deprecated Use GetFilter instead
   */
  const std::vector<I3Particle> GetIceTop(const I3MCTree&) __attribute__ ((deprecated));
  const std::vector<I3Particle> GetIceTop(I3MCTreeConstPtr) __attribute__ ((deprecated));

  /**
   * Returns an iterator
   *
   * /deprecated Use I3MCTree::iterator iter(tree,particleID);
   */
  I3MCTree::iterator GetIterator(I3MCTreePtr, const I3ParticleID&) __attribute__ ((deprecated));
  I3MCTree::iterator GetIterator(I3MCTree&, const I3ParticleID&) __attribute__ ((deprecated));

}

#endif 


