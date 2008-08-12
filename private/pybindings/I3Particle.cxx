//
//   Copyright (c) 2004, 2005, 2006, 2007   Troy D. Straszheim  
//   
//   $Id: ithon.cxx 25598 2006-11-25 02:52:57Z troy $
//
//   This file is part of IceTray.
//
//   IceTray is free software; you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation; either version 3 of the License, or
//   (at your option) any later version.
//
//   IceTray is distributed in the hope that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//   GNU General Public License for more details.
//
//   You should have received a copy of the GNU General Public License
//   along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#include <vector>

#include <dataclasses/physics/I3Particle.h>

using namespace boost::python;

static double 
get_theta(const I3Particle& self)
{
  return self.GetDir().CalcTheta();
}

static double 
get_phi(const I3Particle& self)
{
  return self.GetDir().CalcPhi();
}

static void 
set_position(I3Particle& self, double x, double y, double z)
{
  self.SetPos(x,y,z);
}

static void 
set_theta_phi(I3Particle& self, double theta, double phi)
{
  self.SetThetaPhi(theta,phi);
}

static void 
set_dir_angles(I3Particle& self, double zen, double azi)
{
  self.SetDir(zen,azi);
}

static void 
set_dir_unitvect(I3Particle& self, double x, double y, double z)
{
  self.SetDir(x,y,z);
}

inline boost::shared_ptr<I3Position> get_pos(I3Particle * particle)
{
  return I3PositionPtr(new I3Position(particle->GetPos()));
}

static std::string 
i3particle_prettyprint(const I3Particle& p)
{
  ostringstream oss;
  oss << "[I3Particle Zenith:" << p.GetZenith() << " Azimuth:" << p.GetAzimuth() << " X:" << p.GetX() << " Y:" << p.GetY() << " Z:" << p.GetZ() 
      << " Energy:" << p.GetEnergy() << " Speed: " << p.GetSpeed() << " Time:" << p.GetTime() << " Weight:" << p.GetWeight() << "]";
  return oss.str();
}

void register_I3Particle()
{
  {
    scope particle_scope = 
      class_<I3Particle, bases<I3FrameObject>, boost::shared_ptr<I3Particle> >("I3Particle")
      .def("GetTime", &I3Particle::GetTime)
      .def("GetX", &I3Particle::GetX)
      .def("GetY", &I3Particle::GetY)
      .def("GetZ", &I3Particle::GetZ)
      .def("GetPos", &get_pos)	
      .def("GetEnergy", &I3Particle::GetEnergy)
      .def("GetSpeed", &I3Particle::GetSpeed)
      .def("GetWeight", &I3Particle::GetWeight)
      .def("GetZenith", &I3Particle::GetZenith)
      .def("GetAzimuth", &I3Particle::GetAzimuth)
      .def("GetType", &I3Particle::GetType)
      .def("GetLength", &I3Particle::GetLength)
      .def("GetFitStatus", &I3Particle::GetFitStatus)
      .def("GetTheta", &get_theta)
      .def("GetPhi", &get_phi)
      .def("GetLocationType", &I3Particle::GetLocationType)
      .def("SetThetaPhi", &set_theta_phi)
      .def("GetShape",&I3Particle::GetShape)
      .def("SetDir", &set_dir_angles)
      .def("SetDir", &set_dir_unitvect)
      .def("SetPos", &set_position)
      .def("SetTime", &I3Particle::SetTime)
      .def("SetEnergy", &I3Particle::SetEnergy)
      .def("SetSpeed", &I3Particle::SetSpeed)
      .def("SetWeight", &I3Particle::SetWeight)
      .def("SetType", &I3Particle::SetType)
      .def("SetLength", &I3Particle::SetLength)
      .def("SetFitStatus", &I3Particle::SetFitStatus)
      .def("SetLocationType", &I3Particle::SetLocationType)
      .def("SetShape",&I3Particle::SetShape)
      .def("__str__", i3particle_prettyprint)
      ;

    enum_<I3Particle::FitStatus>("FitStatus")
      .value("NotSet",I3Particle::NotSet)
      .value("OK",I3Particle::OK)
      .value("GeneralFailure",I3Particle::GeneralFailure)
      .value("InsufficientHits",I3Particle::InsufficientHits)
      .value("FailedToConverge",I3Particle::FailedToConverge)
      .value("MissingSeed",I3Particle::MissingSeed)
      .value("InsufficientQuality",I3Particle::InsufficientQuality)
      ;

    enum_<I3Particle::LocationType>("LocationType")
      .value("Anywhere",I3Particle::Anywhere)
      .value("IceTop",I3Particle::IceTop)
      .value("InIce",I3Particle::InIce)
      ;

    enum_<I3Particle::ParticleType>("ParticleType")
      .value("unknown",I3Particle::unknown)
      .value("Gamma",I3Particle::Gamma)
      .value("EPlus",I3Particle::EPlus)
      .value("EMinus",I3Particle::EMinus)
      .value("MuPlus",I3Particle::MuPlus)
      .value("MuMinus",I3Particle::MuMinus)
      .value("Pi0",I3Particle::Pi0)
      .value("PiPlus",I3Particle::PiPlus)
      .value("PiMinus",I3Particle::PiMinus)
      .value("K0_Long",I3Particle::K0_Long)
      .value("KPlus",I3Particle::KPlus)
      .value("KMinus",I3Particle::KMinus)
      .value("Neutron",I3Particle::Neutron)
      .value("PPlus",I3Particle::PPlus)
      .value("PMinus",I3Particle::PMinus)
      .value("K0_Short",I3Particle::K0_Short)
      .value("NuE",I3Particle::NuE)
      .value("NuEBar",I3Particle::NuEBar)
      .value("NuMu",I3Particle::NuMu)
      .value("NuMuBar",I3Particle::NuMuBar)
      .value("TauPlus",I3Particle::TauPlus)
      .value("TauMinus",I3Particle::TauMinus)
      .value("NuTau",I3Particle::NuTau)
      .value("NuTauBar",I3Particle::NuTauBar)
      .value("He4Nucleus",I3Particle::He4Nucleus)
      .value("Li7Nucleus",I3Particle::Li7Nucleus)
      .value("Be9Nucleus",I3Particle::Be9Nucleus)
      .value("B11Nucleus",I3Particle::B11Nucleus)
      .value("C12Nucleus",I3Particle::C12Nucleus)
      .value("N14Nucleus",I3Particle::N14Nucleus)
      .value("O16Nucleus",I3Particle::O16Nucleus)
      .value("F19Nucleus",I3Particle::F19Nucleus)
      .value("Ne20Nucleus",I3Particle::Ne20Nucleus)
      .value("Na23Nucleus",I3Particle::Na23Nucleus)
      .value("Mg24Nucleus",I3Particle::Mg24Nucleus)
      .value("Al27Nucleus",I3Particle::Al27Nucleus)
      .value("Si28Nucleus",I3Particle::Si28Nucleus)
      .value("P31Nucleus",I3Particle::P31Nucleus)
      .value("S32Nucleus",I3Particle::S32Nucleus)
      .value("Cl35Nucleus",I3Particle::Cl35Nucleus)
      .value("Ar40Nucleus",I3Particle::Ar40Nucleus)
      .value("K39Nucleus",I3Particle::K39Nucleus)
      .value("Ca40Nucleus",I3Particle::Ca40Nucleus)
      .value("Sc45Nucleus",I3Particle::Sc45Nucleus)
      .value("Ti48Nucleus",I3Particle::Ti48Nucleus)
      .value("V51Nucleus",I3Particle::V51Nucleus)
      .value("Cr52Nucleus",I3Particle::Cr52Nucleus)
      .value("Mn55Nucleus",I3Particle::Mn55Nucleus)
      .value("Fe56Nucleus",I3Particle::Fe56Nucleus)
      .value("CherenkovPhoton",I3Particle::CherenkovPhoton)
      .value("Nu",I3Particle::Nu)
      .value("Monopole",I3Particle::Monopole)
      .value("Brems",I3Particle::Brems)
      .value("DeltaE",I3Particle::DeltaE)
      .value("PairProd",I3Particle::PairProd)
      .value("NuclInt",I3Particle::NuclInt)
      .value("MuPair",I3Particle::MuPair)
      .value("Hadrons",I3Particle::Hadrons)
      .value("FiberLaser",I3Particle::FiberLaser)
      .value("N2Laser",I3Particle::N2Laser)
      .value("YAGLaser",I3Particle::YAGLaser)
      .value("STauMinus",I3Particle::STauMinus)
      .value("STauPlus",I3Particle::STauPlus)
      ;

    enum_<I3Particle::ParticleShape>("ParticleShape")
      .value("Null",I3Particle::Null)
      .value("Primary",I3Particle::Primary)
      .value("TopShower",I3Particle::TopShower)
      .value("Cascade",I3Particle::Cascade)
      .value("InfiniteTrack",I3Particle::InfiniteTrack)
      .value("StartingTrack",I3Particle::StartingTrack)
      .value("StoppingTrack",I3Particle::StoppingTrack)
      .value("ContainedTrack",I3Particle::ContainedTrack)
      .value("MCTrack",I3Particle::MCTrack)
      .value("Dark",I3Particle::Dark)
      ;

  }

  class_<std::vector<I3Particle> >("Vector_I3Particle")
    .def(vector_indexing_suite<std::vector<I3Particle> >())
    ;

  register_pointer_conversions<I3Particle>();
}
