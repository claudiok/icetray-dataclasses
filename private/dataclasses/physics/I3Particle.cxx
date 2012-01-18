#include <icetray/serialization.h>
#include <dataclasses/physics/I3Particle.h>
#include <boost/functional/hash/hash.hpp>
#include <dataclasses/I3Constants.h>

#include <limits>
#include <boost/assign/list_of.hpp>

int I3Particle::global_minor_id_ = 0;
uint64_t I3Particle::global_major_id_ = 0;

I3Particle::~I3Particle() { }
I3Particle::I3Particle(ParticleShape shape, ParticleType type) : 
  parentID_(-1),
  primaryID_(-1),
  pdgEncoding_(ConvertToPdgEncoding(type)),
  shape_(shape),
  status_(NotSet),
  pos_(),
  dir_(),
  time_(NAN),
  energy_(NAN),
  length_(NAN),
  speed_(I3Constants::c),
  locationType_(Anywhere)
{
  ID_ = global_minor_id_++;
  if(global_major_id_ ==0){
    boost::hash<std::string> string_hash;
    std::stringstream s;
    s<<time(0)<<getpid()<<getenv("HOST");
    global_major_id_ = string_hash(s.str());
  }
  major_ID_ = global_major_id_;
  log_trace("Calling I3Particle::I3Particle(ParticleShape %i, ParticleType %i).", static_cast<int>(shape), static_cast<int>(type));
}

std::string I3Particle::GetTypeString() const
{
  const ParticleType type = ConvertFromPdgEncoding(pdgEncoding_);
    
  switch (type) {
  case UnknownWithPdgEncoding:    return("UnknownWithPdgEncoding");
  case unknown:    return("unknown");
  case Gamma:      return("Gamma");
  case EPlus:      return("EPlus");
  case EMinus:     return("EMinus");
  case MuPlus:     return("MuPlus");
  case MuMinus:    return("MuMinus");
  case Pi0:        return("Pi0");
  case PiPlus:     return("PiPlus");
  case PiMinus:    return("PiMinus");
  case K0_Long:    return("K0_Long");
  case KPlus:      return("KPlus");
  case KMinus:     return("KMinus");
  case Neutron:    return("Neutron");
  case PPlus:      return("PPlus");
  case PMinus:     return("PMinus");
  case K0_Short:   return("K0_Short");
  case Eta:            return("Eta");
  case Lambda:         return("Lambda");
  case SigmaPlus:      return("SigmaPlus");
  case Sigma0:         return("Sigma0");
  case SigmaMinus:     return("SigmaMinus");
  case Xi0:            return("Xi0");
  case XiMinus:        return("XiMinus");
  case OmegaMinus:     return("OmegaMinus");
  case NeutronBar:     return("NeutronBar");
  case LambdaBar:      return("LambdaBar");
  case SigmaMinusBar:  return("SigmaMinusBar");
  case Sigma0Bar:      return("Sigma0Bar");
  case SigmaPlusBar:   return("SigmaPlusBar");
  case Xi0Bar:         return("Xi0Bar");
  case XiPlusBar:      return("XiPlusBar");
  case OmegaPlusBar:   return("OmegaPlusBar");
  case DPlus:          return("DPlus");
  case DMinus:         return("DMinus");
  case D0:             return("D0");
  case D0Bar:          return("D0Bar");
  case DsPlus:         return("DsPlus");
  case DsMinusBar:     return("DsMinusBar");
  case LambdacPlus:    return("LambdacPlus");
  case WPlus:          return("WPlus");
  case WMinus:         return("WMinus");
  case Z0:             return("Z0");
  case NuE:            return("NuE");
  case NuEBar:         return("NuEBar");
  case NuMu:           return("NuMu");
  case NuMuBar:        return("NuMuBar");
  case TauPlus:        return("TauPlus");
  case TauMinus:       return("TauMinus");
  case NuTau:          return("NuTau");
  case NuTauBar:       return("NuTauBar");
  case He4Nucleus:     return("He4Nucleus");
  case Li7Nucleus:     return("Li7Nucleus");
  case Be9Nucleus:     return("Be9Nucleus");
  case B11Nucleus:     return("B11Nucleus");
  case C12Nucleus:     return("C12Nucleus");
  case N14Nucleus:     return("N14Nucleus");
  case O16Nucleus:     return("O16Nucleus");
  case F19Nucleus:     return("F19Nucleus");
  case Ne20Nucleus:    return("Ne20Nucleus");
  case Na23Nucleus:    return("Na23Nucleus");
  case Mg24Nucleus:    return("Mg24Nucleus");
  case Al27Nucleus:    return("Al27Nucleus");
  case Si28Nucleus:    return("Si28Nucleus");
  case P31Nucleus:     return("P31Nucleus");
  case S32Nucleus:     return("S32Nucleus");
  case Cl35Nucleus:    return("Cl35Nucleus");
  case Ar40Nucleus:    return("Ar40Nucleus");
  case K39Nucleus:     return("K39Nucleus");
  case Ca40Nucleus:    return("Ca40Nucleus");
  case Sc45Nucleus:    return("Sc45Nucleus");
  case Ti48Nucleus:    return("Ti48Nucleus");
  case V51Nucleus:     return("V51Nucleus");
  case Cr52Nucleus:    return("Cr52Nucleus");
  case Mn55Nucleus:    return("Mn55Nucleus");
  case Fe56Nucleus:    return("Fe56Nucleus");
  case CherenkovPhoton:return("CherenkovPhoton");
  case Nu:         return("Nu");
  case Monopole:   return("Monopole");
  case Brems:      return("Brems");
  case DeltaE:     return("DeltaE");
  case PairProd:   return("PairProd");
  case NuclInt:    return("NuclInt");
  case MuPair:     return("MuPair");
  case Hadrons:    return("Hadrons");
  case FiberLaser: return("FiberLaser");
  case N2Laser:    return("N2Laser");
  case YAGLaser:   return("YAGLaser");
  case STauPlus:   return("STauPlus");
  case STauMinus:  return("STauMinus");
  default:         return("undefined_particle_type");
  }
}

std::string I3Particle::GetShapeString() const
{
  switch (shape_) {
  case Null:           return("Null");
  case Primary:        return("Primary");
  case TopShower:      return("TopShower");
  case Cascade:        return("Cascade");
  case InfiniteTrack:  return("InfiniteTrack");
  case StartingTrack:  return("StartingTrack");
  case StoppingTrack:  return("StoppingTrack");
  case ContainedTrack: return("ContainedTrack");
  case MCTrack:        return("MCTrack");
  case Dark:           return("Dark");
  default:             return("undefined_particle_shape");
  }
}

std::string I3Particle::GetFitStatusString() const
{
  switch (status_) {
  case NotSet:              return("NotSet");
  case OK:                  return("OK");
  case GeneralFailure:      return("GeneralFailure");
  case InsufficientHits:    return("InsufficientHits");
  case FailedToConverge:    return("FailedToConverge");
  case MissingSeed:         return("MissingSeed");
  case InsufficientQuality: return("InsufficientQuality");
  default:                  return("undefined_fit_status");
  }
}

std::string I3Particle::GetLocationTypeString() const
{
  switch (locationType_) {
  case Anywhere: return("Anywhere");
  case IceTop:   return("IceTop");
  case InIce:    return("InIce");
  default:       return("undefined_location_type");
  }
}

bool I3Particle::IsTrack() const 
{
  const ParticleType type = ConvertFromPdgEncoding(pdgEncoding_);

  if (shape_==InfiniteTrack || shape_==StartingTrack ||
      shape_==StoppingTrack || shape_==ContainedTrack ||
      type==MuPlus || type==MuMinus ||
      type==TauPlus || type==TauMinus ||
      type==STauPlus || type==STauMinus ||
      type==Monopole ||
      (shape_ == Primary && 
       ( type == PPlus       ||
	 type == PMinus      ||
	 type == He4Nucleus  ||
	 type == Li7Nucleus  ||
	 type == Be9Nucleus  ||
	 type == B11Nucleus  ||
	 type == C12Nucleus  ||
	 type == N14Nucleus  ||
	 type == O16Nucleus  ||
	 type == F19Nucleus  ||
	 type == Ne20Nucleus ||
	 type == Na23Nucleus ||
	 type == Mg24Nucleus ||
	 type == Al27Nucleus ||
	 type == Si28Nucleus ||
	 type == P31Nucleus  ||
	 type == S32Nucleus  ||
	 type == Cl35Nucleus ||
	 type == Ar40Nucleus ||
	 type == K39Nucleus  ||
	 type == Ca40Nucleus ||
	 type == Sc45Nucleus ||
	 type == Ti48Nucleus ||
	 type == V51Nucleus  ||
	 type == Cr52Nucleus ||
	 type == Mn55Nucleus ||
	 type == Fe56Nucleus ||
	 type == Gamma )
       )
      ) return true;    
  else return false;
}

bool I3Particle::IsCascade() const
{
  const ParticleType type = ConvertFromPdgEncoding(pdgEncoding_);

  if (shape_ == Cascade ||
      type == EPlus    || type == EMinus   ||
      type == Brems    || type == DeltaE  ||
      type == PairProd || type == NuclInt ||
      type == Hadrons  || type == Pi0     ||
      type == PiPlus   || type == PiMinus ||      
      (shape_ != Primary && 
       ( type == PPlus       ||
	 type == PMinus      ||
	 type == He4Nucleus  ||
	 type == Li7Nucleus  ||
	 type == Be9Nucleus  ||
	 type == B11Nucleus  ||
	 type == C12Nucleus  ||
	 type == N14Nucleus  ||
	 type == O16Nucleus  ||
	 type == F19Nucleus  ||
	 type == Ne20Nucleus ||
	 type == Na23Nucleus ||
	 type == Mg24Nucleus ||
	 type == Al27Nucleus ||
	 type == Si28Nucleus ||
	 type == P31Nucleus  ||
	 type == S32Nucleus  ||
	 type == Cl35Nucleus ||
	 type == Ar40Nucleus ||
	 type == K39Nucleus  ||
	 type == Ca40Nucleus ||
	 type == Sc45Nucleus ||
	 type == Ti48Nucleus ||
	 type == V51Nucleus  ||
	 type == Cr52Nucleus ||
	 type == Mn55Nucleus ||
	 type == Fe56Nucleus ||
	 type == Gamma )
       )
      ) return true;    
  else return false;
}

bool I3Particle::IsNeutrino() const
{
  const ParticleType type = ConvertFromPdgEncoding(pdgEncoding_);
    
  if( type==NuE ||
      type==NuEBar ||
      type==NuMu ||
      type==NuMuBar ||
      type==NuTau||
      type==NuTauBar||
      type==Nu )
    return true;
  else
    return false;
}

bool I3Particle::HasPosition() const
{
  if ( isnan(GetX()) || isnan(GetY()) || isnan(GetZ()) ) return false;
  else return true;
}

bool I3Particle::HasDirection() const
{
  if (isnan(GetZenith()) || isnan(GetAzimuth()) ) return false;
  else return true;
}

bool I3Particle::HasEnergy() const
{ 
  if (isnan(energy_)) return false; 
  else return true; 
}

bool I3Particle::IsPrimary() const 
{
  if (shape_==Primary) return true;
  else return false;
}

bool I3Particle::IsTopShower() const
{
  if (shape_==TopShower) return true;
  else return false;
}

I3Position I3Particle::ShiftAlongTrack(double dist) const 
{
  if (IsTrack()) {
    double x = GetX() - dist * sin(GetZenith()) * cos(GetAzimuth());
    double y = GetY() - dist * sin(GetZenith()) * sin(GetAzimuth());
    double z = GetZ() - dist * cos(GetZenith());
    I3Position p(x,y,z,I3Position::car);
    return p;
  }
  else {
    log_warn("ShiftAlongTrack undefined for a particle that is not a track.");
    I3Position nullpos;
    return nullpos;
  }
}

I3Position I3Particle::GetStartPos() const 
{ 
  if (shape_ == StartingTrack || 
      shape_ == ContainedTrack || 
      shape_ == MCTrack) return pos_;
  else {
    log_warn("GetStartPos undefined for a particle that is neither starting "
	     "nor contained.");
    I3Position nullpos;
    return nullpos;
  }
}

double I3Particle::GetStartTime() const 
{
  if (shape_ == StartingTrack || 
      shape_ == ContainedTrack ||
      shape_ == MCTrack ) return time_;
  else{
    log_warn("GetStartTime undefined for a particle that is neither starting "
	     "nor contained.");
    return NAN;
  }
}

I3Position I3Particle::GetStopPos() const 
{
  if (shape_==StoppingTrack) return pos_;
  else if (shape_ == ContainedTrack || shape_ == MCTrack){
    return ShiftAlongTrack(length_);
  }
  else {
    log_warn("GetStopPos undefined for a particle that is neither stopping "
	     "nor contained.");
    I3Position nullpos;
    return nullpos;
  }
}

double I3Particle::GetStopTime() const 
{ 
  if (shape_==StoppingTrack) return time_;
  else if (shape_ == ContainedTrack || shape_ == MCTrack){ 
    return time_ + length_/speed_; 
  }else{  
    log_warn("GetStopTime undefined for a particle that is neither stopping "
	     "nor contained.");
    return NAN;
  }
}

I3Particle::ParticleType I3Particle::convert_rdmc(int t) const{
  switch(t){
  case RDMCParticleTypes::unknown:
    return I3Particle::unknown; break;
  case RDMCParticleTypes::Gamma:
    return I3Particle::Gamma; break;
  case RDMCParticleTypes::EPlus:
    return I3Particle::EPlus; break;
  case RDMCParticleTypes::EMinus:
    return I3Particle::EMinus; break;
  case RDMCParticleTypes::Nu:
    return I3Particle::Nu; break;
  case RDMCParticleTypes::MuPlus:
    return I3Particle::MuPlus; break;
  case RDMCParticleTypes::MuMinus:
    return I3Particle::MuMinus; break;
  case RDMCParticleTypes::Pi0:
    return I3Particle::Pi0; break;
  case RDMCParticleTypes::PiPlus:
    return I3Particle::PiPlus; break;
  case RDMCParticleTypes::PiMinus:
    return I3Particle::PiMinus; break;
  case RDMCParticleTypes::PPlus:
    return I3Particle::PPlus; break;
  case RDMCParticleTypes::PMinus:
    return I3Particle::PMinus; break;
  case RDMCParticleTypes::TauPlus:
    return I3Particle::TauPlus; break;
  case RDMCParticleTypes::TauMinus:
    return I3Particle::TauMinus; break;
  case RDMCParticleTypes::Monopole:
    return I3Particle::Monopole; break;
  case RDMCParticleTypes::NuE:
    return I3Particle::NuE; break;
  case RDMCParticleTypes::NuMu:
    return I3Particle::NuMu; break;
  case RDMCParticleTypes::NuTau:
    return I3Particle::NuTau; break;
  case RDMCParticleTypes::NuEBar:
    return I3Particle::NuEBar; break;
  case RDMCParticleTypes::NuMuBar:
    return I3Particle::NuMuBar; break;
  case RDMCParticleTypes::NuTauBar:
    return I3Particle::NuTauBar; break;
  case RDMCParticleTypes::Brems:
    return I3Particle::Brems; break;
  case RDMCParticleTypes::DeltaE:
    return I3Particle::DeltaE; break;
  case RDMCParticleTypes::PairProd:
    return I3Particle::PairProd; break;
  case RDMCParticleTypes::NuclInt:
    return I3Particle::NuclInt; break;
  case RDMCParticleTypes::MuPair:
    return I3Particle::MuPair; break;
  case RDMCParticleTypes::Hadrons:
    return I3Particle::Hadrons; break;
  case RDMCParticleTypes::FiberLaser:
    return I3Particle::FiberLaser; break;
  case RDMCParticleTypes::N2Laser:
    return I3Particle::N2Laser; break;
  case RDMCParticleTypes::YAGLaser:
    return I3Particle::YAGLaser; break;
  case RDMCParticleTypes::ZPrimary:
    return I3Particle::unknown; break;
  case RDMCParticleTypes::APrimary:
    return I3Particle::unknown; break;
  case RDMCParticleTypes::CRProton:
    return I3Particle::PPlus; break;
  case RDMCParticleTypes::CRHelium:
    return I3Particle::He4Nucleus; break;
  case RDMCParticleTypes::CROxygen:
    return I3Particle::O16Nucleus; break;
  case RDMCParticleTypes::CRSilicon:
    return I3Particle::Si28Nucleus; break;
  case RDMCParticleTypes::CRIron:
    return I3Particle::Fe56Nucleus; break;
  case RDMCParticleTypes::Elph:
    return I3Particle::unknown; break;
  case 3001:
    return I3Particle::PPlus; break;
  case 3002:
    return I3Particle::He4Nucleus; break;
  case 3003:
    return I3Particle::Li7Nucleus; break;
  case 3004:
    return I3Particle::Be9Nucleus; break;
  case 3005:
    return I3Particle::B11Nucleus; break;
  case 3006:
    return I3Particle::C12Nucleus; break;
  case 3007:
    return I3Particle::N14Nucleus; break;
  case 3008:
    return I3Particle::O16Nucleus; break;
  case 3009:
    return I3Particle::F19Nucleus; break;
  case 3010:
    return I3Particle::Ne20Nucleus; break;
  case 3011:
    return I3Particle::Na23Nucleus; break;
  case 3012:
    return I3Particle::Mg24Nucleus; break;
  case 3013:
    return I3Particle::Al27Nucleus; break;
  case 3014:
    return I3Particle::Si28Nucleus; break;
  case 3015:
    return I3Particle::P31Nucleus; break;
  case 3016:
    return I3Particle::S32Nucleus; break;
  case 3017:
    return I3Particle::Cl35Nucleus; break;
  case 3018:
    return I3Particle::Ar40Nucleus; break;
  case 3019:
    return I3Particle::K39Nucleus; break;
  case 3020:
    return I3Particle::Ca40Nucleus; break;
  case 3021:
    return I3Particle::Sc45Nucleus; break;
  case 3022:
    return I3Particle::Ti48Nucleus; break;
  case 3023:
    return I3Particle::V51Nucleus; break;
  case 3024:
    return I3Particle::Cr52Nucleus; break;
  case 3025:
    return I3Particle::Mn55Nucleus; break;
  case 3026:
    return I3Particle::Fe56Nucleus; break;
    
  }
  return I3Particle::unknown;
}

I3Particle::ParticleType I3Particle::GetType() const
{
    return ConvertFromPdgEncoding(pdgEncoding_);
}

void I3Particle::SetType(I3Particle::ParticleType type)
{
    if (type == I3Particle::UnknownWithPdgEncoding)
        log_fatal("You cannot set the ParticleType to \"UnknownWithPdgEncoding\" using SetType().");
    
    pdgEncoding_ = ConvertToPdgEncoding(type);
}

void I3Particle::SetRDMCType(int type)
{
    pdgEncoding_ = ConvertToPdgEncoding(convert_rdmc(type));
}


// numbering scheme from http://pdg.lbl.gov/2011/reviews/rpp2011-rev-monte-carlo-numbering.pdf
const I3Particle::toPdgEncodingConversionTable_t
I3Particle::toPdgEncodingConversionTable_ =
boost::assign::list_of<I3Particle::toPdgEncodingConversionTable_t::relation>
(I3Particle::UnknownWithPdgEncoding, std::numeric_limits<int32_t>::max()) // should not have a pdg encoding equivalent..
(I3Particle::unknown,          0)
(I3Particle::Gamma,            22)
(I3Particle::EPlus,           -11)
(I3Particle::EMinus,           11)
(I3Particle::MuPlus,          -13)
(I3Particle::MuMinus,          13)
(I3Particle::Pi0,              111)
(I3Particle::PiPlus,           211)
(I3Particle::PiMinus,         -211)
(I3Particle::K0_Long,          130)
(I3Particle::KPlus,            321)
(I3Particle::KMinus,          -321)
(I3Particle::Neutron,          2112)
(I3Particle::PPlus,            2212)
(I3Particle::PMinus,          -2212)
(I3Particle::K0_Short,         310)
(I3Particle::Eta,              221)
(I3Particle::Lambda,           3122)
(I3Particle::SigmaPlus,        3222)
(I3Particle::Sigma0,           3212)
(I3Particle::SigmaMinus,       3112)
(I3Particle::Xi0,              3322)
(I3Particle::XiMinus,          3312)
(I3Particle::OmegaMinus,       3334)
(I3Particle::NeutronBar,      -2112)
(I3Particle::LambdaBar,       -3122)
(I3Particle::SigmaMinusBar,   -3222)
(I3Particle::Sigma0Bar,       -3212)
(I3Particle::SigmaPlusBar,    -3112)
(I3Particle::Xi0Bar,          -3322)
(I3Particle::XiPlusBar,       -3312)
(I3Particle::OmegaPlusBar,    -3334)
(I3Particle::DPlus,            411)
(I3Particle::DMinus,          -411)
(I3Particle::D0,               421)
(I3Particle::D0Bar,           -421)
(I3Particle::DsPlus,           431)
(I3Particle::DsMinusBar,      -431)
(I3Particle::LambdacPlus,      4122)
(I3Particle::WPlus,            24)
(I3Particle::WMinus,          -24)
(I3Particle::Z0,               23)
(I3Particle::NuE,              12)
(I3Particle::NuEBar,          -12)
(I3Particle::NuMu,             14)
(I3Particle::NuMuBar,         -14)
(I3Particle::TauPlus,         -15)
(I3Particle::TauMinus,         15)
(I3Particle::NuTau,            16)
(I3Particle::NuTauBar,        -16)
// nuclei
(I3Particle::He4Nucleus,       1000020040)
(I3Particle::Li7Nucleus,       1000030070)
(I3Particle::Be9Nucleus,       1000040090)
(I3Particle::B11Nucleus,       1000050110)
(I3Particle::C12Nucleus,       1000060120)
(I3Particle::N14Nucleus,       1000070140)
(I3Particle::O16Nucleus,       1000080160)
(I3Particle::F19Nucleus,       1000090190)
(I3Particle::Ne20Nucleus,      1000100200)
(I3Particle::Na23Nucleus,      1000110230)
(I3Particle::Mg24Nucleus,      1000120240)
(I3Particle::Al27Nucleus,      1000130270)
(I3Particle::Si28Nucleus,      1000140280)
(I3Particle::P31Nucleus,       1000150310)
(I3Particle::S32Nucleus,       1000160320)
(I3Particle::Cl35Nucleus,      1000170350)
(I3Particle::Ar40Nucleus,      1000180400)
(I3Particle::K39Nucleus,       1000190390)
(I3Particle::Ca40Nucleus,      1000200400)
(I3Particle::Sc45Nucleus,      1000210450)
(I3Particle::Ti48Nucleus,      1000220480)
(I3Particle::V51Nucleus,       1000230510)
(I3Particle::Cr52Nucleus,      1000240520)
(I3Particle::Mn55Nucleus,      1000250550)
(I3Particle::Fe56Nucleus,      1000260560)
// types without valid pdg encodings, use codes >=2000000000 or <=-2000000000
(I3Particle::CherenkovPhoton,  2000009900)
(I3Particle::Nu,              -2000000004)
(I3Particle::Monopole,        -2000000041)
(I3Particle::Brems,           -2000001001)
(I3Particle::DeltaE,          -2000001002)
(I3Particle::PairProd,        -2000001003)
(I3Particle::NuclInt,         -2000001004)
(I3Particle::MuPair,          -2000001005)
(I3Particle::Hadrons,         -2000001006)
(I3Particle::FiberLaser,      -2000002100)
(I3Particle::N2Laser,         -2000002101)
(I3Particle::YAGLaser,        -2000002201)
(I3Particle::STauPlus,        -2000009131)
(I3Particle::STauMinus,       -2000009132);


I3Particle::ParticleType I3Particle::ConvertFromPdgEncoding(int32_t pdg_encoding)
{
    toPdgEncodingConversionTable_t::right_const_iterator it =
    toPdgEncodingConversionTable_.right.find(pdg_encoding);
    
    if (it != toPdgEncodingConversionTable_.right.end()) {
        log_trace("PDG code \"%i\", returning I3Particle::ParticleType \"%i\".", static_cast<int>(pdg_encoding),static_cast<int>(it->second));
        return it->second;
    }
    
    // let the caller know that there is no equivalent ParticleType
    log_warn("unknown PDG code \"%i\" cannot be converted to a I3Particle::ParticleType. It will appear as \"UnknownWithPdgEncoding\".", static_cast<int>(pdg_encoding));
    return I3Particle::UnknownWithPdgEncoding;  
}

int32_t I3Particle::ConvertToPdgEncoding(I3Particle::ParticleType type)
{
    if (type==UnknownWithPdgEncoding)
        log_fatal("ConvertToPdgEncoding must not be called with type \"UnknownWithPdgEncoding\".");

    toPdgEncodingConversionTable_t::left_const_iterator it =
    toPdgEncodingConversionTable_.left.find(type);
    
    if (it != toPdgEncodingConversionTable_.left.end()) {
        log_trace("I3Particle::ParticleType \"%i\", returning PDG code \"%i\".", static_cast<int>(type),static_cast<int>(it->second));
        return it->second;
    }

    // in case this error is shown, especially when reading I3 files, data loss will occur
    // (i.e. the ParticleType will be reported as "unknown" instead of the number it used
    // to be). This will only happen for types that have numbers not listed in the
    // ParticleType enum. So they shouldn't occur anyway. In case they do, the correct solution
    // is to add them to the enum.
    log_error("unknown I3Particle::ParticleType \"%i\" cannot be converted to a PDG encoding.", static_cast<int>(type));
    return 0;
}

template <class Archive>
  void I3Particle::save(Archive& ar, unsigned version) const
  {
    ar & make_nvp("I3FrameObject", base_object<I3FrameObject>(*this));
    ar & make_nvp("ID",ID_);
    ar & make_nvp("MajorID",major_ID_);
    ar & make_nvp("pdgEncoding",pdgEncoding_);
    ar & make_nvp("shape",shape_);
    ar & make_nvp("fitStatus",status_);
    ar & make_nvp("pos",pos_);
    ar & make_nvp("dir",dir_);
    ar & make_nvp("time",time_);
    ar & make_nvp("energy",energy_);
    ar & make_nvp("length",length_);
    ar & make_nvp("speed",speed_);
    ar & make_nvp("LocationType",locationType_);
  }

template <class Archive>
  void I3Particle::load(Archive& ar, unsigned version)
  {
  if (version>i3particle_version_)
    log_fatal("Attempting to read version %u from file but running version %u of I3Particle class.",version,i3particle_version_);

    ar & make_nvp("I3FrameObject", base_object<I3FrameObject>(*this));
    ar & make_nvp("ID",ID_);
    if(version>1){
      ar & make_nvp("MajorID",major_ID_);
    }
    if(version == 0){
      ar & make_nvp("parentID",parentID_);
      ar & make_nvp("primaryID",primaryID_);
    }
    if(version <= 2){
      I3Particle::ParticleType t;
      ar & make_nvp("type",t);
      pdgEncoding_ = ConvertToPdgEncoding(convert_rdmc(t));
    }else if(version <= 4){
      I3Particle::ParticleType t;
      ar & make_nvp("type",t);
      pdgEncoding_ = ConvertToPdgEncoding(t);
    }else{ // version >= 5
      ar & make_nvp("pdgEncoding",pdgEncoding_);
    }
    ar & make_nvp("shape",shape_);
    ar & make_nvp("fitStatus",status_);
    ar & make_nvp("pos",pos_);
    ar & make_nvp("dir",dir_);
    ar & make_nvp("time",time_);
    ar & make_nvp("energy",energy_);
    ar & make_nvp("length",length_);
    ar & make_nvp("speed",speed_);
    if(version == 0)
      ar & make_nvp("composite",composite_);
    if(version>0)
      ar & make_nvp("LocationType",locationType_);
    if(version == 4){
        // obscure version in use by Antares, contains bjorken x and y.
        // Those should never have been in I3Particle. Load them and
        // forget them.
        double bjorkenx, bjorkeny;
        ar & make_nvp("bjorkenx",bjorkenx);
        ar & make_nvp("bjorkeny",bjorkeny);
    }
  }

bool operator==(const I3Particle& lhs, const I3Particle& rhs){
  return ( lhs.GetMinorID() == rhs.GetMinorID() &&
	   lhs.GetMajorID() == rhs.GetMajorID() &&
	   lhs.GetParentID() == rhs.GetParentID() &&
	   lhs.GetPrimaryID() == rhs.GetPrimaryID() &&
	   lhs.GetPdgEncoding() == rhs.GetPdgEncoding() &&
	   lhs.GetShape() == rhs.GetShape() &&
	   lhs.GetFitStatus() == rhs.GetFitStatus() &&
	   lhs.GetLocationType() == rhs.GetLocationType() &&
	   lhs.GetPos() == rhs.GetPos() &&
	   lhs.GetDir() == rhs.GetDir() &&
	   lhs.GetTime() == rhs.GetTime() &&
	   lhs.GetLength() == rhs.GetLength() &&
	   lhs.GetEnergy() == rhs.GetEnergy() &&
	   lhs.GetSpeed() == rhs.GetSpeed() &&
	   lhs.GetComposite()==rhs.GetComposite()
	   );
}

std::ostream& operator<<(std::ostream& oss, const I3Particle& p){
  oss << "[ I3Particle MajorID : " << p.GetMajorID() << std::endl
      << "             MinorID : " << p.GetMinorID() << std::endl
      << "              Zenith : " << p.GetZenith()  << std::endl
      << "             Azimuth : " << p.GetAzimuth()  << std::endl
      << "                   X : " << p.GetX() << std::endl
      << "                   Y : " << p.GetY() << std::endl
      << "                   Z : " << p.GetZ() << std::endl
      << "                Time : " << p.GetTime() << std::endl
      << "              Energy : " << p.GetEnergy() << std::endl
      << "               Speed : " << p.GetSpeed() <<  std::endl
      << "              Length : " << p.GetLength() << std::endl
      << "                Type : " << p.GetTypeString() << std::endl
      << "        PDG encoding : " << p.GetPdgEncoding() << std::endl
      << "               Shape : " << p.GetShapeString() << std::endl
      << "              Status : " << p.GetFitStatusString() <<  std::endl
      << "            Location : " << p.GetLocationTypeString() << std::endl 
      << "]" ;
  return oss;
}


I3_SERIALIZABLE(I3Particle);

I3_SERIALIZABLE(I3ParticleVect);
