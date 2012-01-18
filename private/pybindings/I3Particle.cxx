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
#include <boost/preprocessor/seq.hpp>
#include <icetray/python/std_vector_indexing_suite.hpp>
#include <icetray/python/stream_to_string.hpp>
#include <dataclasses/ostream_overloads.hpp>

using namespace boost::python;
 
void register_I3Particle()
{

  {
    scope particle_scope = 
      class_<I3Particle, bases<I3FrameObject>, boost::shared_ptr<I3Particle> >("I3Particle")
      #define RO_PROPERTIES (MajorID)(MinorID)
      #define PROPERTIES (Time)(Energy)(Shape)(Type)(PdgEncoding)(Length)(Speed)(FitStatus)(LocationType)
      #define CONVENIENCE_BOOLS (IsTrack)(IsCascade)(IsPrimary)(IsTopShower)(IsNeutrino)
      BOOST_PP_SEQ_FOR_EACH(WRAP_PROP_RO, I3Particle, RO_PROPERTIES)
      BOOST_PP_SEQ_FOR_EACH(WRAP_PROP, I3Particle, PROPERTIES)
      BOOST_PP_SEQ_FOR_EACH(WRAP_PROP_BOOL, I3Particle, CONVENIENCE_BOOLS)
      #undef RO_PROPERTIES
      #undef PROPERTIES
      #undef CONVENIENCE_BOOLS
      .add_property("pos", make_function( (const I3Position& (I3Particle::*)()) &I3Particle::GetPos, return_internal_reference<1>() ),
					  (void (I3Particle::*)(const I3Position&)) &I3Particle::SetPos ) 
      .add_property("dir", make_function( (const I3Direction& (I3Particle::*)()) &I3Particle::GetDir, return_internal_reference<1>() ),
					  (void (I3Particle::*)(const I3Direction&)) &I3Particle::SetDir ) 
      .def("shift_along_track", &I3Particle::ShiftAlongTrack)
      .def( freeze() )
      .def("__str__", &stream_to_string<I3Particle>)
      ;

    enum_<I3Particle::FitStatus>("FitStatus")
      .value("NotSet",I3Particle::NotSet)
      .value("OK",I3Particle::OK)
      .value("GeneralFailure",I3Particle::GeneralFailure)
      .value("InsufficientHits",I3Particle::InsufficientHits)
      .value("FailedToConverge",I3Particle::FailedToConverge)
      .value("MissingSeed",I3Particle::MissingSeed)
      .value("InsufficientQuality",I3Particle::InsufficientQuality)
      .export_values()
      ;

    enum_<I3Particle::LocationType>("LocationType")
      .value("Anywhere",I3Particle::Anywhere)
      .value("IceTop",I3Particle::IceTop)
      .value("InIce",I3Particle::InIce)
      .export_values()
      ;

    enum_<I3Particle::ParticleType>("ParticleType")
      .value("UnknownWithPdgEncoding",I3Particle::UnknownWithPdgEncoding)
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
      .value("Eta",I3Particle::Eta)
      .value("Lambda",I3Particle::Lambda)
      .value("SigmaPlus",I3Particle::SigmaPlus)
      .value("Sigma0",I3Particle::Sigma0)
      .value("SigmaMinus",I3Particle::SigmaMinus)
      .value("Xi0",I3Particle::Xi0)
      .value("XiMinus",I3Particle::XiMinus)
      .value("OmegaMinus",I3Particle::OmegaMinus)
      .value("NeutronBar",I3Particle::NeutronBar)
      .value("LambdaBar",I3Particle::LambdaBar)
      .value("SigmaMinusBar",I3Particle::SigmaMinusBar)
      .value("Sigma0Bar",I3Particle::Sigma0Bar)
      .value("SigmaPlusBar",I3Particle::SigmaPlusBar)
      .value("Xi0Bar",I3Particle::Xi0Bar)
      .value("XiPlusBar",I3Particle::XiPlusBar)
      .value("OmegaPlusBar",I3Particle::OmegaPlusBar)
      .value("DPlus",I3Particle::DPlus)
      .value("DMinus",I3Particle::DMinus)
      .value("D0",I3Particle::D0)
      .value("D0Bar",I3Particle::D0Bar)
      .value("DsPlus",I3Particle::DsPlus)
      .value("DsMinusBar",I3Particle::DsMinusBar)
      .value("LambdacPlus",I3Particle::LambdacPlus)
      .value("WPlus",I3Particle::WPlus)
      .value("WMinus",I3Particle::WMinus)
      .value("Z0",I3Particle::Z0)
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
      .export_values()
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
      .export_values()
      ;

  }

  class_<std::vector<I3Particle> >("I3ParticleVect")
    .def(std_vector_indexing_suite<std::vector<I3Particle> >())
    .def("__str__", &stream_to_string<std::vector<I3Particle> >)
    ;

  register_pointer_conversions<I3Particle>();
}
