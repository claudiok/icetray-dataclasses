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

#define private public
#include <dataclasses/status/I3DetectorStatus.h>
#undef private
#include <dataclasses/I3Map.h>
#include <icetray/python/std_map_indexing_suite.hpp>
#include <icetray/python/copy_suite.hpp>

using namespace boost::python;

I3MapStringIntPtr
get_trigger_settings(I3TriggerStatusPtr ts){
  I3MapStringIntPtr r_map(new I3MapStringInt); 
  BOOST_FOREACH(I3MapStringInt::value_type p, ts->GetTriggerSettings())
    r_map->insert(p);
  return r_map;
}

std::map<I3TriggerStatus::Subdetector, I3TriggerReadoutConfig>
get_readout_settings(I3TriggerStatusPtr ts){
  return ts->GetReadoutSettings();
}


std::string get_trigger_name(I3TriggerStatusPtr ts){
  return ts->GetTriggerName();
}


void register_I3DetectorStatus()
{
  class_<I3DetectorStatus, bases<I3FrameObject>, boost::shared_ptr<I3DetectorStatus> >("I3DetectorStatus")
    .def(copy_suite<I3DetectorStatus>())
    .def_readwrite("StartTime", &I3DetectorStatus::startTime)
    .def_readwrite("EndTime", &I3DetectorStatus::endTime)
    .def_readwrite("DOMStatus", &I3DetectorStatus::domStatus)
    .def_readwrite("TriggerStatus", &I3DetectorStatus::triggerStatus)
    ;

  class_<std::map<OMKey, I3DOMStatus> >("Map_OMKey_I3DOMStatus")
    .def(std_map_indexing_suite<std::map<OMKey, I3DOMStatus> >())
    ;

  class_<std::map<TriggerKey, I3TriggerStatus> >("Map_TriggerKey_I3TriggerStatus")
    .def(std_map_indexing_suite<std::map<TriggerKey, I3TriggerStatus> >())
    ;
    
  //
  // I3DOMStatus
  //
  {
    scope outer = 
      class_<I3DOMStatus, boost::shared_ptr<I3DOMStatus> >("I3DOMStatus")
      .def(copy_suite<I3DOMStatus>())
      .def_readwrite("TrigMode", &I3DOMStatus::trigMode)
      .def_readwrite("LCMode", &I3DOMStatus::lcMode)
      .def_readwrite("LCWindowPre", &I3DOMStatus::lcWindowPre)
      .def_readwrite("LCWindowPost", &I3DOMStatus::lcWindowPost)
      .def_readwrite("LCSpan", &I3DOMStatus::lcSpan)
      .def_readwrite("StatusATWDa", &I3DOMStatus::statusATWDa)
      .def_readwrite("StatusATWDb", &I3DOMStatus::statusATWDb)
      .def_readwrite("StatusFADC", &I3DOMStatus::statusFADC)
      .def_readwrite("PMTHV", &I3DOMStatus::pmtHV)
      .def_readwrite("SpeThreshold", &I3DOMStatus::speThreshold)
      .def_readwrite("FePedestal", &I3DOMStatus::fePedestal)
      .def_readwrite("DacTriggerBias0", &I3DOMStatus::dacTriggerBias0)
      .def_readwrite("DcTriggerBias1", &I3DOMStatus::dacTriggerBias1)
      .def_readwrite("DacFADCRef", &I3DOMStatus::dacFADCRef)
      .def_readwrite("NBinsATWD0", &I3DOMStatus::nBinsATWD0)
      .def_readwrite("NBinsATWD1", &I3DOMStatus::nBinsATWD1)
      .def_readwrite("NBinsATWD2", &I3DOMStatus::nBinsATWD2)
      .def_readwrite("NBinsATWD3", &I3DOMStatus::nBinsATWD3)
      .def_readwrite("NBinsFADC", &I3DOMStatus::nBinsFADC)
      .def_readwrite("DeltaCompress", &I3DOMStatus::deltaCompress)
      .def_readwrite("FBState", &I3DOMStatus::fbState)
      .def_readwrite("FBBrightness", &I3DOMStatus::fbBrightness)
      .def_readwrite("FBLength", &I3DOMStatus::fbLength)
      .def_readwrite("FBDelay", &I3DOMStatus::fbDelay)
      .def_readwrite("FBMask", &I3DOMStatus::fbMask)
      .def_readwrite("FBRate", &I3DOMStatus::fbRate)
      .def_readwrite("DOMGainType", &I3DOMStatus::domGainType)
      .def_readwrite("CableType", &I3DOMStatus::cableType)
      .def_readwrite("SLCActive", &I3DOMStatus::SLCActive)
      ;

    enum_<I3DOMStatus::TrigMode>("TrigMode")
      .value("UnknownTrigMode",I3DOMStatus::UnknownTrigMode)
      .value("TestPattern",I3DOMStatus::TestPattern)
      .value("CPU",I3DOMStatus::CPU)
      .value("SPE",I3DOMStatus::SPE)
      .value("Flasher",I3DOMStatus::Flasher)
      .value("MPE",I3DOMStatus::MPE)
      .export_values()
      ;
    def("identity", identity_<I3DOMStatus::TrigMode>);

    enum_<I3DOMStatus::LCMode>("LCMode")
      .value("UnknownLCMode",I3DOMStatus::UnknownLCMode)
      .value("LCOff",I3DOMStatus::LCOff)
      .value("UpOrDown",I3DOMStatus::UpOrDown)
      .value("Up",I3DOMStatus::Up)
      .value("Down",I3DOMStatus::Down)
      .value("UpAndDown",I3DOMStatus::UpAndDown)
      .value("SoftLC",I3DOMStatus::SoftLC)
      .export_values()
      ;
    def("identity", identity_<I3DOMStatus::LCMode>);

    enum_<I3DOMStatus::OnOff>("OnOff")
      .value("Unknown",I3DOMStatus::Unknown)
      .value("Off",I3DOMStatus::Off)
      .value("On",I3DOMStatus::On)
      .export_values()
      ;
    def("identity", identity_<I3DOMStatus::OnOff>);

    enum_<I3DOMStatus::DOMGain>("DOMGain")
      .value("UnknownGainType",I3DOMStatus::UnknownGainType)
      .value("High",I3DOMStatus::High)
      .value("Low",I3DOMStatus::Low)
      .export_values()
      ;
    def("identity", identity_<I3DOMStatus::DOMGain>);

    enum_<I3DOMStatus::CableType>("CableType")
      .value("UnknownCableType",I3DOMStatus::UnknownCableType)
      .value("Terminated",I3DOMStatus::Terminated)
      .value("Unterminated",I3DOMStatus::Unterminated)
      .export_values()
      ;

    def("identity", identity_<I3DOMStatus::CableType>);

  }

  //
  // I3TriggerStatus
  //
  {
    scope outer = 
      class_<I3TriggerStatus, boost::shared_ptr<I3TriggerStatus> >("I3TriggerStatus")
      .def(copy_suite<I3TriggerStatus>())
      .def_readwrite("TriggerName", &I3TriggerStatus::name_)
      .def_readwrite("TriggerSettings",&I3TriggerStatus::settings_)
      .def_readwrite("ReadoutSettings",&I3TriggerStatus::readoutconfigs_)
      ;

    class_<I3TriggerReadoutConfig, boost::shared_ptr<I3TriggerReadoutConfig> >("I3TriggerReadoutConfig")
      .def(copy_suite<I3TriggerReadoutConfig>())
      .def_readwrite("ReadoutTimeMinus", &I3TriggerReadoutConfig::readoutTimeMinus)
      .def_readwrite("ReadoutTimePlus", &I3TriggerReadoutConfig::readoutTimePlus)
      .def_readwrite("ReadoutTimeOffset", &I3TriggerReadoutConfig::readoutTimeOffset)
      ;

    enum_<I3TriggerStatus::Subdetector>("Subdetector")
      .value("NOT_SPECIFIED",I3TriggerStatus::NOT_SPECIFIED)
      .value("ALL",I3TriggerStatus::ALL)
      .value("ICETOP",I3TriggerStatus::ICETOP)
      .value("INICE",I3TriggerStatus::INICE)
      .export_values()
      ;
    def("identity", identity_<I3TriggerStatus::Subdetector>);

  }

  class_<std::map<I3TriggerStatus::Subdetector, I3TriggerReadoutConfig > >("map_Subdetector_I3TriggerReadoutConfig")
    .def(map_indexing_suite<std::map<I3TriggerStatus::Subdetector, I3TriggerReadoutConfig > >())
    ;
  
  register_pointer_conversions<I3DetectorStatus>();
}
