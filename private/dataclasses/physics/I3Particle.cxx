#include <icetray/serialization.h>
#include <dataclasses/physics/I3Particle.h>
#include <boost/functional/hash/hash.hpp>

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
    stringstream s;
    s<<time(0)<<getpid()<<getenv("HOST");
    global_major_id_ = string_hash(s.str());
  }
  major_ID_ = global_major_id_;
}

string I3Particle::GetTypeString() const
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
  case PPlus:      return("PPlus");
  case PMinus:     return("PMinus");
  case TauPlus:    return("TauPlus");
  case TauMinus:   return("TauMinus");
  case Monopole:   return("Monopole");
  case NuE:        return("NuE");
  case NuMu:       return("NuMu");
  case NuTau:      return("NuTau");
  case NuEBar:     return("NuEBar");
  case NuMuBar:    return("NuMuBar");
  case NuTauBar:   return("NuTauBar");
  case Brems:      return("Brems");
  case DeltaE:     return("DeltaE");
  case PairProd:   return("PairProd");
  case NuclInt:    return("NuclInt");
  case MuPair:     return("MuPair");
  case Hadrons:    return("Hadrons");
  default:         return("undefined_particle_type");
  }
}

string I3Particle::GetShapeString() const
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
  default:             return("undefined_particle_shape");
  }
}

string I3Particle::GetFitStatusString() const
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

string I3Particle::GetLocationTypeString() const
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
      type_==Monopole)
    return true;
  else return false;
}

bool I3Particle::IsCascade() const
{
  if (shape_==Cascade ||
      type_ == EPlus    || type_== EMinus   ||
      type_ == Brems    || type_ == DeltaE  ||
      type_ == PairProd || type_ == NuclInt ||
      type_ == Gamma    || type_ == Hadrons ||
      type_ == PiPlus   || type_ == PiMinus ||
      type_ == Pi0      || type_ == MuPair  ||
      type_ == PPlus    || type_ == PMinus )  
    return true;
  else return false;
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
  if (shape_==StartingTrack || shape_==ContainedTrack) return pos_;
  else {
    log_warn("GetStartPos undefined for a particle that is neither starting "
	     "nor contained.");
    I3Position nullpos;
    return nullpos;
  }
}

double I3Particle::GetStartTime() const 
{
  if (shape_==StartingTrack || shape_==ContainedTrack) return time_;
  else{
    log_warn("GetStartTime undefined for a particle that is neither starting "
	     "nor contained.");
    return NAN;
  }
}

I3Position I3Particle::GetStopPos() const 
{
  if (shape_==StoppingTrack) return pos_;
  else if (shape_==ContainedTrack) return ShiftAlongTrack(length_);
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
  else if (shape_==ContainedTrack) { return time_ + length_/speed_; }
  else{
    log_warn("GetStopTime undefined for a particle that is neither stopping "
	     "nor contained.");
    return NAN;
  }
}

I3Particle::ParticleType I3Particle::convert_rdmc(int t){
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

I3_SERIALIZABLE(I3Particle);

I3_SERIALIZABLE(I3ParticleVect);
