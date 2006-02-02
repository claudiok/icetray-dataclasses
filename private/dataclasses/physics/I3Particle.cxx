#include <dataclasses/BoostHeaders.h>
#include <dataclasses/physics/I3Particle.h>

I3Particle::~I3Particle() {}

template <class Archive>
  void I3Particle::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("TObject", base_object<TObject>(*this));
    ar & make_nvp("type",type_);
    ar & make_nvp("mcID",mcID_);
    ar & make_nvp("parentID",parentID_);
    ar & make_nvp("primaryID",primaryID_);
    ar & make_nvp("myID",myID_);
    ar & make_nvp("recoName",recoName_);
  }

std::string I3Particle::Stringize(I3Particle::MCID type)
{
  if(type ==I3Particle::Null)
    return "Null";
  else if(type == I3Particle::Unknown)
    return "Unknown";
  else if(type == I3Particle::Gamma)
    return "Gamma";
  else if(type == I3Particle::EPlus)
    return "Positron";
  else if(type == I3Particle::EMinus)
    return "Electron";
  else if(type == I3Particle::Nu)
    return "Neutrino";
  else if(type == I3Particle::MuPlus)
    return "MuPlus";
  else if(type == I3Particle::MuMinus)
    return "MuMinus";
  else if(type == I3Particle::Pi0)
    return "Pi0";
  else if(type == I3Particle::PiPlus)
    return "PiPlus";
  else if(type == I3Particle::PiMinus)
    return "PiMinus";
  else if(type == I3Particle::PPlus)
    return "Proton";
  else if(type == I3Particle::PMinus)
    return "AntiProton";
  else if(type == I3Particle::TauPlus)
    return "TauPlus";
  else if(type == I3Particle::TauMinus)
    return "TauMinus";
  else if(type == I3Particle::NuE)
    return "NuE";
  else if(type == I3Particle::NuMu)
    return "NuMu";
  else if(type == I3Particle::NuTau)
    return "NuTau";
  else if(type == I3Particle::NuEBar)
    return "NuEBar";
  else if(type == I3Particle::NuMuBar)
    return "NuMuBar";
  else if(type == I3Particle::Brems)
    return "Brems";
  else if(type == I3Particle::DeltaE)
    return "DeltaE";
  else if(type == I3Particle::PairProd)
    return "PairProd";
  else if(type == I3Particle::NuclInt)
    return "NuclInt";
  else if(type == I3Particle::MuPair)
    return "MuPair";
  else if(type == I3Particle::Hadrons)
    return "Hadrons";
  else if(type == I3Particle::FiberLaser)
    return "FiberLaser";
  else if(type == I3Particle::N2Laser)
    return "N2Laser";
  else if(type == I3Particle::YAGLaser)
    return "YAGLaser";
  else if(type >= I3Particle::ZPrimary && type <=I3Particle::ZPrimary+400)
    {
      char output[255];
      sprintf(output,"ZPrimary_%d",type-I3Particle::ZPrimary);
      std::string to_return(output);
      return to_return;
    }
  else if(type >= I3Particle::APrimary && type <= I3Particle::APrimary+400)
    {
      char output[255];
      sprintf(output,"APrimary_%d",type-I3Particle::APrimary);
      std::string to_return(output);
      return to_return;
    }
  else if(type == I3Particle::Elph)
    return "Elephantino";

  return "Unknown";
}


I3_SERIALIZABLE(I3Particle);
