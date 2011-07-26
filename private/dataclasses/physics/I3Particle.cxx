#include <icetray/serialization.h>
#include <dataclasses/physics/I3Particle.h>
#include <boost/functional/hash/hash.hpp>
#include <dataclasses/I3Constants.h>

int I3Particle::global_minor_id_ = 0;
uint64_t I3Particle::global_major_id_ = 0;

I3Particle::~I3Particle() { }
I3Particle::I3Particle(ParticleShape shape, ParticleType type) : 
  parentID_(-1),
  primaryID_(-1),
  type_(type),
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
}

std::string I3Particle::GetTypeString() const
{
  switch (type_) {
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
  case TauPlus:    return("TauPlus");
  case TauMinus:   return("TauMinus");
  case Monopole:   return("Monopole");
  case NuE:        return("NuE");
  case NuMu:       return("NuMu");
  case NuTau:      return("NuTau");
  case NuEBar:     return("NuEBar");
  case NuMuBar:    return("NuMuBar");
  case NuTauBar:   return("NuTauBar");
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
  case CherenkovPhoton:    return("CherenkovPhoton");
  case Nu:         return("Nu");
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
  if (shape_==InfiniteTrack || shape_==StartingTrack ||
      shape_==StoppingTrack || shape_==ContainedTrack ||
      type_==MuPlus || type_==MuMinus ||
      type_==TauPlus || type_==TauMinus ||
      type_==STauPlus || type_==STauMinus ||
      type_==Monopole ||
      (shape_ == Primary && 
       ( type_ == PPlus       ||
	 type_ == PMinus      ||
	 type_ == He4Nucleus  ||
	 type_ == Li7Nucleus  ||
	 type_ == Be9Nucleus  ||
	 type_ == B11Nucleus  ||
	 type_ == C12Nucleus  ||
	 type_ == N14Nucleus  ||
	 type_ == O16Nucleus  ||
	 type_ == F19Nucleus  ||
	 type_ == Ne20Nucleus ||
	 type_ == Na23Nucleus ||
	 type_ == Mg24Nucleus ||
	 type_ == Al27Nucleus ||
	 type_ == Si28Nucleus ||
	 type_ == P31Nucleus  ||
	 type_ == S32Nucleus  ||
	 type_ == Cl35Nucleus ||
	 type_ == Ar40Nucleus ||
	 type_ == K39Nucleus  ||
	 type_ == Ca40Nucleus ||
	 type_ == Sc45Nucleus ||
	 type_ == Ti48Nucleus ||
	 type_ == V51Nucleus  ||
	 type_ == Cr52Nucleus ||
	 type_ == Mn55Nucleus ||
	 type_ == Fe56Nucleus ||
	 type_ == Gamma )
       )
      ) return true;    
  else return false;
}

bool I3Particle::IsCascade() const
{
  if (shape_ == Cascade ||
      type_ == EPlus    || type_== EMinus   ||
      type_ == Brems    || type_ == DeltaE  ||
      type_ == PairProd || type_ == NuclInt ||
      type_ == Hadrons  || type_ == Pi0     ||
      type_ == PiPlus   || type_ == PiMinus ||      
      (shape_ != Primary && 
       ( type_ == PPlus       ||
	 type_ == PMinus      ||
	 type_ == He4Nucleus  ||
	 type_ == Li7Nucleus  ||
	 type_ == Be9Nucleus  ||
	 type_ == B11Nucleus  ||
	 type_ == C12Nucleus  ||
	 type_ == N14Nucleus  ||
	 type_ == O16Nucleus  ||
	 type_ == F19Nucleus  ||
	 type_ == Ne20Nucleus ||
	 type_ == Na23Nucleus ||
	 type_ == Mg24Nucleus ||
	 type_ == Al27Nucleus ||
	 type_ == Si28Nucleus ||
	 type_ == P31Nucleus  ||
	 type_ == S32Nucleus  ||
	 type_ == Cl35Nucleus ||
	 type_ == Ar40Nucleus ||
	 type_ == K39Nucleus  ||
	 type_ == Ca40Nucleus ||
	 type_ == Sc45Nucleus ||
	 type_ == Ti48Nucleus ||
	 type_ == V51Nucleus  ||
	 type_ == Cr52Nucleus ||
	 type_ == Mn55Nucleus ||
	 type_ == Fe56Nucleus ||
	 type_ == Gamma )
       )
      ) return true;    
  else return false;
}

bool I3Particle::IsNeutrino() const
{
  if( type_==NuE ||
      type_==NuEBar ||
      type_==NuMu ||
      type_==NuMuBar ||
      type_==NuTau||
      type_==NuTauBar||
      type_==Nu )
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

template <class Archive>
  void I3Particle::save(Archive& ar, unsigned version) const
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
    ar & make_nvp("type",type_);
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
    if(version > 2){
      ar & make_nvp("type",type_);
    }else{
      I3Particle::ParticleType t;
      ar & make_nvp("type",t);
      type_ = convert_rdmc(t);
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
  }

bool operator==(const I3Particle& lhs, const I3Particle& rhs){
  return ( lhs.GetMinorID() == rhs.GetMinorID() &&
	   lhs.GetMajorID() == rhs.GetMajorID() &&
	   lhs.GetParentID() == rhs.GetParentID() &&
	   lhs.GetPrimaryID() == rhs.GetPrimaryID() &&
	   lhs.GetType() == rhs.GetType() &&
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

std::ostream& operator<<(std::ostream& oss, const I3Particle& d){
  return oss;
}


I3_SERIALIZABLE(I3Particle);

I3_SERIALIZABLE(I3ParticleVect);
