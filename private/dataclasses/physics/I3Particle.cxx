#include <dataclasses/BoostHeaders.h>
#include <dataclasses/physics/I3Particle.h>
#include "dataclasses/I3IDService.h"

I3Particle::~I3Particle() { }

string I3Particle::GetTypeString() const
{
  string str;
  switch (type_) {
  case -100: str = "unknown"; break;
  case    1: str = "Gamma"; break;
  case    2: str = "EPlus"; break;
  case    3: str = "EMinus"; break;
  case    4: str = "Nu"; break;
  case    5: str = "MuPlus"; break;
  case    6: str = "MuMinus"; break;
  case    7: str = "Pi0"; break;
  case    8: str = "PiPlus"; break;
  case    9: str = "PiMinus"; break;
  case   14: str = "PPlus"; break;
  case   15: str = "PMinus"; break;
  case   33: str = "TauPlus"; break;
  case   34: str = "TauMinus"; break;
  case   41: str = "Monopole"; break;
  case  201: str = "NuE"; break;
  case  202: str = "NuMu"; break;
  case  203: str = "NuTau"; break;
  case  204: str = "NuEBar"; break;
  case  205: str = "NuMuBar"; break;
  case  206: str = "NuTauBar"; break;
  case 1001: str = "Brems"; break;
  case 1002: str = "DeltaE"; break;
  case 1003: str = "PairProd"; break;
  case 1004: str = "NuclInt"; break;
  case 1005: str = "MuPair"; break;
  case 1006: str = "Hadrons"; break;
  case 2100: str = "FiberLaser"; break;
  case 2101: str = "N2Laser"; break;
  case 2201: str = "YAGLaser"; break;
  case 3000: str = "ZPrimary"; break;
  case 3500: str = "APrimary"; break;
  case 9999: str = "Elph"; break;
  }
  return str;
}

string I3Particle::GetShapeString() const
{
  string str;
  switch (shape_) {
  case  0: str = "Null"; break;
  case 20: str = "TopShower"; break;
  case 30: str = "Cascade"; break;
  case 40: str = "InfiniteTrack"; break;
  case 50: str = "StartingTrack"; break;
  case 60: str = "StoppingTrack"; break;
  case 70: str = "ContainedTrack"; break;
  }
  return str;
}

string I3Particle::GetFitStatusString() const
{
  string str;
  switch (status_) {
  case -1: str = "NotSet"; break;
  case  0: str = "OK"; break;
  case 10: str = "GeneralFailure"; break;
  case 20: str = "InsufficientHits"; break;
  case 30: str = "FailedToConverge"; break;
  case 40: str = "MissingSeed"; break;
  case 50: str = "InsufficientQuality"; break;
  }
  return str;
}

void I3Particle::SetID(I3IDServicePtr id_serv) { ID_ = id_serv->ServeID(); }

template <class Archive>
  void I3Particle::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3FrameObject", base_object<I3FrameObject>(*this));
    ar & make_nvp("ID",ID_);
    ar & make_nvp("type",type_);
    ar & make_nvp("shape",shape_);
    ar & make_nvp("fitStatus",status_);
    ar & make_nvp("pos",pos_);
    ar & make_nvp("dir",dir_);
    ar & make_nvp("time",time_);
    ar & make_nvp("energy",energy_);
    ar & make_nvp("length",length_);
    ar & make_nvp("speed",speed_);
    ar & make_nvp("compositeType",compositeType_);
  }

I3_SERIALIZABLE(I3Particle);

I3_SERIALIZABLE(I3ParticleVect);
