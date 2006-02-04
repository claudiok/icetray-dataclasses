#include <dataclasses/BoostHeaders.h>
#include <dataclasses/physics/I3MCTruth.h>

I3MCTruth::~I3MCTruth() {}

template <class Archive>
  void I3MCTruth::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("TObject", base_object<TObject>(*this));
    ar & make_nvp("mcID",mcID_);
    ar & make_nvp("mcLength",mcLength_);
  }
  

std::string I3MCTruth::Stringize(I3MCTruth::MCID type)
{
  if(type ==I3MCTruth::Null)
    return "Null";
  else if(type == I3MCTruth::Unknown)
    return "Unknown";
  else if(type == I3MCTruth::Gamma)
    return "Gamma";
  else if(type == I3MCTruth::EPlus)
    return "Positron";
  else if(type == I3MCTruth::EMinus)
    return "Electron";
  else if(type == I3MCTruth::Nu)
    return "Neutrino";
  else if(type == I3MCTruth::MuPlus)
    return "MuPlus";
  else if(type == I3MCTruth::MuMinus)
    return "MuMinus";
  else if(type == I3MCTruth::Pi0)
    return "Pi0";
  else if(type == I3MCTruth::PiPlus)
    return "PiPlus";
  else if(type == I3MCTruth::PiMinus)
    return "PiMinus";
  else if(type == I3MCTruth::PPlus)
    return "Proton";
  else if(type == I3MCTruth::PMinus)
    return "AntiProton";
  else if(type == I3MCTruth::TauPlus)
    return "TauPlus";
  else if(type == I3MCTruth::TauMinus)
    return "TauMinus";
  else if(type == I3MCTruth::NuE)
    return "NuE";
  else if(type == I3MCTruth::NuMu)
    return "NuMu";
  else if(type == I3MCTruth::NuTau)
    return "NuTau";
  else if(type == I3MCTruth::NuEBar)
    return "NuEBar";
  else if(type == I3MCTruth::NuMuBar)
    return "NuMuBar";
  else if(type == I3MCTruth::Brems)
    return "Brems";
  else if(type == I3MCTruth::DeltaE)
    return "DeltaE";
  else if(type == I3MCTruth::PairProd)
    return "PairProd";
  else if(type == I3MCTruth::NuclInt)
    return "NuclInt";
  else if(type == I3MCTruth::MuPair)
    return "MuPair";
  else if(type == I3MCTruth::Hadrons)
    return "Hadrons";
  else if(type == I3MCTruth::FiberLaser)
    return "FiberLaser";
  else if(type == I3MCTruth::N2Laser)
    return "N2Laser";
  else if(type == I3MCTruth::YAGLaser)
    return "YAGLaser";
  else if(type >= I3MCTruth::ZPrimary && type <=I3MCTruth::ZPrimary+400)
    {
      char output[255];
      sprintf(output,"ZPrimary_%d",type-I3MCTruth::ZPrimary);
      std::string to_return(output);
      return to_return;
    }
  else if(type >= I3MCTruth::APrimary && type <= I3MCTruth::APrimary+400)
    {
      char output[255];
      sprintf(output,"APrimary_%d",type-I3MCTruth::APrimary);
      std::string to_return(output);
      return to_return;
    }
  else if(type == I3MCTruth::Elph)
    return "Elephantino";

  return "Unknown";
}


I3_SERIALIZABLE(I3MCTruth);
