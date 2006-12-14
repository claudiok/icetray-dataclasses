#include <dataclasses/BoostHeaders.h>
#include <dataclasses/physics/I3Particle.h>

int I3Particle::global_id_ = 0;

I3Particle::~I3Particle() { }

string I3Particle::GetTypeString() const
{
  switch (type_) {
  case unknown:    return("unknown");
  case Gamma:      return("Gamma");
  case EPlus:      return("EPlus");
  case EMinus:     return("EMinus");
  case Nu:         return("Nu");
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
  case FiberLaser: return("FiberLaser");
  case N2Laser:    return("N2Laser");
  case YAGLaser:   return("YAGLaser");
  case ZPrimary:   return("ZPrimary");
  case APrimary:   return("APrimary");
  case CRProton:   return("CRProton");
  case CRHelium:   return("CRHelium");
  case CROxygen:   return("CROxygen");
  case CRSilicon:  return("CRSilicon");
  case CRIron:     return("CRIron");
  case Elph:       return("Elph");
  default:         return("undefined particle type");
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
  default:             return("undefined particle shape");
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
  default:                  return("undefined fit status");
  }
}

string I3Particle::GetLocationTypeString() const
{
  switch (locationType_) {
  case Anywhere: return("Anywhere");
  case IceTop:   return("IceTop");
  case InIce:    return("InIce");
  default:       return("undefined location type");
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
      type_ == EPlus || type_== EMinus ||
      type_ == Brems || type_ == DeltaE ||
      type_ == PairProd || type_ == NuclInt ||
      type_ == Gamma || type_==Hadrons ||
      type_== PiPlus || type_ == PiMinus) 
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


template <class Archive>
  void I3Particle::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3FrameObject", base_object<I3FrameObject>(*this));
    ar & make_nvp("ID",ID_);
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

I3_SERIALIZABLE(I3Particle);

I3_SERIALIZABLE(I3ParticleVect);
