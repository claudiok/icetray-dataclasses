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
    #define DETECTORSTATUSPROPS (startTime)(endTime)(domStatus)(triggerStatus)
    BOOST_PP_SEQ_FOR_EACH(WRAP_RW_RECASE, I3DetectorStatus, DETECTORSTATUSPROPS )
    #undef DETECTORSTATUSPROPS
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
      #define DOMSTATUSPROPERTIES (pmtHV)(lcMode)(txMode)(lcWindowPre)(lcWindowPost)(lcSpan)(statusATWDa)(statusATWDb)(statusFADC)(pmtHV)(speThreshold)(fePedestal)(dacTriggerBias0)(dacTriggerBias1)(dacFADCRef)(deltaCompress)(domGainType)(cableType)(SLCActive)(mpeThreshold)
      BOOST_PP_SEQ_FOR_EACH(WRAP_RW_RECASE, I3DOMStatus, DOMSTATUSPROPERTIES)
      #undef DOMSTATUSPROPERTIES
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
      .def_readwrite("trigger_name", &I3TriggerStatus::name_)
      .def_readwrite("trigger_settings",&I3TriggerStatus::settings_)
      .def_readwrite("readout_settings",&I3TriggerStatus::readoutconfigs_)
      ;

    class_<I3TriggerReadoutConfig, boost::shared_ptr<I3TriggerReadoutConfig> >("I3TriggerReadoutConfig")
      .def(copy_suite<I3TriggerReadoutConfig>())
      .def_readwrite("readout_time_minus", &I3TriggerReadoutConfig::readoutTimeMinus)
      .def_readwrite("readout_time_plus", &I3TriggerReadoutConfig::readoutTimePlus)
      .def_readwrite("readout_time_offset", &I3TriggerReadoutConfig::readoutTimeOffset)
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
