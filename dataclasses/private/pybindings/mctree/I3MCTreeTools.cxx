#include "I3MCTreeTools.h"
#include <dataclasses/physics/I3MCTreeUtils.h>
#include <boost/foreach.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/tuple/tuple_comparison.hpp>
#include <sstream>

using boost::algorithm::find_first;
using namespace boost::tuples;
using std::cout;
using std::endl;
using std::stringstream;
 
int I3MCTreeTools::GetNumberOfAtmosphericMuons(const I3MCTree& t)
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

bool I3MCTreeTools::IsCosmicRayParticle(const I3Particle& particle)
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

std::string I3MCTreeTools::internal::DumpChildren(const I3MCTree& t,
					   I3MCTree::iterator i, 
					   const PPPConfig& config){
  stringstream s;
  I3MCTree::sibling_iterator si;
  for(si = t.begin(i); si != t.end(i); si++){
    for(int j=0; j<2*t.depth(si); j++) s<<" ";
    s << ParticlePrettyPrint(*si,config);
    s << DumpChildren(t,si,config);
  }
  return s.str();
}

PPPConfig I3MCTreeTools::internal::ParseConfigString(const std::string& config){
  PPPConfig c;
  if(find_first(config,"+majorID")) c.major_ID = true;
  if(find_first(config,"-majorID")) c.major_ID = false;

  if(find_first(config,"+ID")) c.ID = true;
  if(find_first(config,"-ID")) c.ID = false;

  if(find_first(config,"+type")) c.type = true;
  if(find_first(config,"-type")) c.type = false;

  if(find_first(config,"+pos")) c.pos = true;
  if(find_first(config,"-pos")) c.pos = false;

  if(find_first(config,"+dir")) c.dir = true;
  if(find_first(config,"-dir")) c.dir = false;

  if(find_first(config,"+time")) c.time = true;
  if(find_first(config,"-time")) c.time = false;

  if(find_first(config,"+energy")) c.energy = true;
  if(find_first(config,"-energy")) c.energy = false;

  if(find_first(config,"+length")) c.length = true;
  if(find_first(config,"-length")) c.length = false;

  if(find_first(config,"+speed")) c.speed = true;
  if(find_first(config,"-speed")) c.speed = false;

  if(find_first(config,"+locationType")) c.locationType = true;
  if(find_first(config,"-locationType")) c.locationType = false;

  if(find_first(config,"+shape")) c.shape = true;
  if(find_first(config,"-shape")) c.shape = false;
  return c;
}

std::string I3MCTreeTools::internal::ParticlePrettyPrint(const I3Particle& p, 
						  const PPPConfig& config){
  stringstream s;
  if(config.major_ID) s<<p.GetMajorID();  
  if(config.major_ID && config.ID) s<<":";
  if(config.ID){
    s<<p.GetMinorID()<<" ";
  }else{
    s<<" ";
  }

  if(config.type) s<<p.GetTypeString()<<" ";

  if(config.shape) s<<p.GetShapeString()<<" ";

  if(config.locationType) s<<p.GetLocationTypeString()<<" ";

  if(config.pos){
    s<<"("
	<<p.GetX()/I3Units::m<<"m ,"
	<<p.GetY()/I3Units::m<<"m ,"
	<<p.GetZ()/I3Units::m<<"m) ";
  }

  if(config.dir){
    s<<"("
	<<p.GetZenith()/I3Units::degree<<"deg ,"
	<<p.GetAzimuth()/I3Units::degree<<"deg) ";
  }

  if(config.time) s<<p.GetTime()/I3Units::ns<<"ns ";

  if(config.energy) s<<p.GetEnergy()/I3Units::GeV<<"GeV ";

  if(config.length) s<<p.GetLength()/I3Units::m<<"m ";

  if(config.speed) s<<p.GetSpeed()<<"c ";

  s<<endl;
  return s.str();
}

std::string I3MCTreeTools::Dump(const I3MCTree& t, const std::string& c){
  I3MCTree::sibling_iterator i;
  PPPConfig config = internal::ParseConfigString(c);
  stringstream s;
  s<<"*** TREE DUMP - BEGIN***"<<endl;
  for(i = t.begin(); i != t.end(); i++){
    for(int j=0; j<2*t.depth(i); j++) s<<" ";
    s << internal::ParticlePrettyPrint(*i,config);
    s << internal::DumpChildren(t,i,config);
  }
  s<<"*** TREE DUMP - END***"<<endl;
  return s.str();
}

I3Particle
I3MCTreeTools::Get(const I3MCTree& t, const I3MCHit& mchit)
{
  I3MCTree::iterator iter;
  for (iter=t.begin(); iter!=t.end(); ++iter) 
    if (iter->GetMajorID()== mchit.GetParticleMajorID() && 
	iter->GetMinorID()== mchit.GetParticleMinorID()) 
      return *iter;
  log_error("Could not find I3Particle associated with I3MCHit");
  return I3Particle();
}

NuEventType 
I3MCTreeTools::GetNeutrinoEventType(const I3MCTree& t){

  NuEventType etype(NO_INTERACTION);

  I3MCTreePtr inice_vtx_tree(new I3MCTree);
  I3ParticlePtr nu_cand;
  int max_depth(INT_MIN);
  BOOST_FOREACH(const I3Particle& p, I3MCTreeUtils::GetInIce(t)){
    if(IsNeutrino(p)){
 
      I3MCTree::iterator iter = t.begin();
      for( ; iter != t.end(); iter++){
	if(iter->GetMajorID() == p.GetMajorID() &&
	   iter->GetMinorID() == p.GetMinorID() ) break;
      }
      if(iter == t.end()) return NO_INTERACTION;

      bool inice_daughters(I3MCTreeUtils::GetDaughters(t,p).size());
      BOOST_FOREACH(const I3Particle& d, I3MCTreeUtils::GetDaughters(t,p))
	if(d.GetLocationType() != I3Particle::InIce){
	  inice_daughters = false;
	}
      
      if(t.depth(iter) > max_depth && inice_daughters){
	max_depth = t.depth(iter);
	nu_cand = I3ParticlePtr(new I3Particle(*iter));
      }
    }
  }
  if(nu_cand){
    I3MCTreeUtils::AddPrimary(inice_vtx_tree,*nu_cand);
    BOOST_FOREACH(const I3Particle& d, I3MCTreeUtils::GetDaughters(t,*nu_cand)){
      I3MCTreeUtils::AppendChild(inice_vtx_tree,*nu_cand,d);
    }
  }
  
  if(!inice_vtx_tree->size()) return etype;
  
  if(IsNeutralCurrent(*inice_vtx_tree)) etype = NEUTRAL_CURRENT;
  if(IsChargedCurrent(*inice_vtx_tree)) etype = CHARGED_CURRENT;
  if(IsGlashowResonance(*inice_vtx_tree)) etype = GLASHOW_RESONANCE;
  
  return etype;
}

bool 
I3MCTreeTools::IsNeutrino(const I3Particle& p){
  return (p.GetType() == I3Particle::NuE ||
	  p.GetType() == I3Particle::NuEBar ||
	  p.GetType() == I3Particle::NuMu ||
	  p.GetType() == I3Particle::NuMuBar ||
	  p.GetType() == I3Particle::NuTau ||
	  p.GetType() == I3Particle::NuTauBar);
}

bool 
I3MCTreeTools::IsChargedLepton(const I3Particle& p){
  return (p.GetType() == I3Particle::EMinus ||
	  p.GetType() == I3Particle::EPlus ||
	  p.GetType() == I3Particle::MuMinus ||
	  p.GetType() == I3Particle::MuPlus ||
	  p.GetType() == I3Particle::TauMinus ||
	  p.GetType() == I3Particle::TauPlus);
}

Flavor
I3MCTreeTools::LeptonFlavor(const I3Particle& p){
  if(p.GetType() == I3Particle::EPlus ||
     p.GetType() == I3Particle::EMinus ||
     p.GetType() == I3Particle::NuE ||
     p.GetType() == I3Particle::NuEBar) return Electron;

  if(p.GetType() == I3Particle::MuPlus ||
     p.GetType() == I3Particle::MuMinus ||
     p.GetType() == I3Particle::NuMu ||
     p.GetType() == I3Particle::NuMuBar) return Muon;

  if(p.GetType() == I3Particle::TauPlus ||
     p.GetType() == I3Particle::TauMinus ||
     p.GetType() == I3Particle::NuTau ||
     p.GetType() == I3Particle::NuTauBar) return Tau;

  return Flavorless;
}

lepton_number_t
I3MCTreeTools::LeptonNumber(const I3Particle& p){
  lepton_number_t lep_number(0,0,0);
  if(p.GetType() == I3Particle::EMinus ||
     p.GetType() == I3Particle::NuE) get<0>(lep_number) = 1;

  if(p.GetType() == I3Particle::EPlus ||
     p.GetType() == I3Particle::NuEBar) get<0>(lep_number) = -1;

  if(p.GetType() == I3Particle::MuMinus ||
     p.GetType() == I3Particle::NuMu) get<1>(lep_number) = 1;

  if(p.GetType() == I3Particle::MuPlus ||
     p.GetType() == I3Particle::NuMuBar) get<1>(lep_number) = -1;

  if(p.GetType() == I3Particle::TauMinus ||
     p.GetType() == I3Particle::NuTau) get<2>(lep_number) = 1;

  if(p.GetType() == I3Particle::TauPlus ||
     p.GetType() == I3Particle::NuTauBar) get<2>(lep_number) = -1;

  return lep_number;
}

bool 
I3MCTreeTools::CheckNeutrino(const I3MCTree& t){
  if(I3MCTreeUtils::GetPrimaries(t).size() > 1){
    log_error("Ambiguous event.  Can't handle multiple primaries");
    return false;
  }
  if(I3MCTreeUtils::GetPrimaries(t).size() == 0){
    log_error("This tree is empty.  You don't need me to determine the type");
    return false;
  }

  const I3Particle& primary = I3MCTreeUtils::GetPrimaries(t).front();
  if(!IsNeutrino(primary)){
    log_error("This (%s) is not the neutrino you're looking for.",
	      primary.GetTypeString().c_str());
    log_error("You don't need to see their identification.");
    log_error("Move along...");
    return false;
  }
  return true;
}

bool 
I3MCTreeTools::IsChargedCurrent(const I3MCTree& t){
  if(!CheckNeutrino(t)) return false;
  //CheckNeutrino verifies there's only one primary
  I3Particle nu(I3MCTreeUtils::GetPrimaries(t).front());

  std::vector<I3Particle> daughters = I3MCTreeUtils::GetDaughters(t,nu);

  /**
   * We're looking for hadron + lepton
   */
  if(daughters.size() != 2){
    return false;
  }

  I3ParticlePtr h; //hadron
  I3ParticlePtr l; //lepton

  BOOST_FOREACH(I3Particle& p, daughters){
    if(p.GetType() == I3Particle::Hadrons) 
      h = I3ParticlePtr(new I3Particle(p));
    if(IsChargedLepton(p)) 
      l = I3ParticlePtr(new I3Particle(p));
  }
  if(!h || !l){
    return false;
  }

  //last thing to check is that the flavor
  //and lepton number is the same
  Flavor nu_flavor = LeptonFlavor(nu);
  Flavor l_flavor = LeptonFlavor(*l);

  if(nu_flavor != l_flavor){
    //log_error("neutrino and lepton not the same flavor.");
    return false;
  }

  lepton_number_t l_nu = LeptonNumber(nu);
  lepton_number_t l_lep = LeptonNumber(*l);

  if(l_nu != l_lep){
    //log_error("different lepton numbers");
  }
  return (l_nu == l_lep);
}

bool 
I3MCTreeTools::IsNeutralCurrent(const I3MCTree& t){
  if(!CheckNeutrino(t)) return false;
  //CheckNeutrino verifies there's only one primary
  I3Particle nu(I3MCTreeUtils::GetPrimaries(t).front());
  std::vector<I3Particle> daughters = I3MCTreeUtils::GetDaughters(t,nu);

  /**
   * We're looking for hadron + neutrino
   */
  if(daughters.size() != 2){
    return false;
  }
  I3ParticlePtr h; //hadron
  I3ParticlePtr v; //neutrino

  BOOST_FOREACH(I3Particle& p, daughters){
    if(p.GetType() == I3Particle::Hadrons) 
      h = I3ParticlePtr(new I3Particle(p));
    if(IsNeutrino(p)) 
      v = I3ParticlePtr(new I3Particle(p));
  }
  if(!h || !v) return false;

  return (nu.GetType() == v->GetType());
}

bool 
I3MCTreeTools::IsGlashowResonance(const I3MCTree& t){
  if(!CheckNeutrino(t)) return false;
  //CheckNeutrino verifies there's only one primary
  I3Particle nu(I3MCTreeUtils::GetPrimaries(t).front());
  std::vector <I3Particle> daughters = I3MCTreeUtils::GetDaughters(t,nu);

  /**
   * First we look for a single hadron
   * v + e -> W -> h
   */
  if(daughters.size() == 1){
    if(daughters.front().GetType() == I3Particle::Hadrons)
      return true;
  }

  /**
   * Next we look for hadron + neutrino
   * v + e -> W -> v + l
   */
  if(daughters.size() != 2) return false;
  I3ParticlePtr l; //lepton
  I3ParticlePtr v; //neutrino

  BOOST_FOREACH(I3Particle& p, daughters){
    if(IsChargedLepton(p)) 
      l = I3ParticlePtr(new I3Particle(p));
    if(IsNeutrino(p)) 
      v = I3ParticlePtr(new I3Particle(p));
  }
  if(!l || !v) return false;

  lepton_number_t l_lep = LeptonNumber(*l);
  lepton_number_t l_v = LeptonNumber(*v);

  int delta_l = 
    get<0>(l_lep) + get<0>(l_v) +
    get<1>(l_lep) + get<1>(l_v) +
    get<2>(l_lep) + get<2>(l_v);

  return !delta_l;
}
