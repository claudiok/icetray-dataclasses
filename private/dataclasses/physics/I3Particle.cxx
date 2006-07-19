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
