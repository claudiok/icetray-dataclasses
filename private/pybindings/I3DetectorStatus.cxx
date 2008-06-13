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

#include <dataclasses/status/I3DetectorStatus.h>

using namespace boost::python;

void register_I3DetectorStatus()
{
  class_<I3DetectorStatus, bases<I3FrameObject>, boost::shared_ptr<I3DetectorStatus> >("I3DetectorStatus")
    .def_readwrite("startTime", &I3DetectorStatus::startTime)
    .def_readwrite("endTime", &I3DetectorStatus::endTime)
    .def_readwrite("domStatus", &I3DetectorStatus::domStatus)
    .def_readwrite("aomStatus", &I3DetectorStatus::aomStatus)
    .def_readwrite("triggerStatus", &I3DetectorStatus::triggerStatus)
    .def_readwrite("amandaTriggerStatus", &I3DetectorStatus::amandaTriggerStatus)
    ;

  class_<std::map<OMKey, I3DOMStatus> >("Map_OMKey_I3DOMStatus")
    .def(map_indexing_suite<std::map<OMKey, I3DOMStatus> >())
    ;
    
  //
  // I3DOMStatus
  //
  {
    scope outer = 
      class_<I3DOMStatus, boost::shared_ptr<I3DOMStatus> >("I3DOMStatus")
      .def_readwrite("trigMode", &I3DOMStatus::trigMode)
      .def_readwrite("lcMode", &I3DOMStatus::lcMode)
      .def_readwrite("lcWindowPre", &I3DOMStatus::lcWindowPre)
      .def_readwrite("lcWindowPost", &I3DOMStatus::lcWindowPost)
      .def_readwrite("lcSpan", &I3DOMStatus::lcSpan)
      .def_readwrite("statusATWDa", &I3DOMStatus::statusATWDa)
      .def_readwrite("statusATWDb", &I3DOMStatus::statusATWDb)
      .def_readwrite("statusFADC", &I3DOMStatus::statusFADC)
      .def_readwrite("pmtHV", &I3DOMStatus::pmtHV)
      .def_readwrite("speThreshold", &I3DOMStatus::speThreshold)
      .def_readwrite("fePedestal", &I3DOMStatus::fePedestal)
      .def_readwrite("dacTriggerBias0", &I3DOMStatus::dacTriggerBias0)
      .def_readwrite("dacTriggerBias1", &I3DOMStatus::dacTriggerBias1)
      .def_readwrite("dacFADCRef", &I3DOMStatus::dacFADCRef)
      .def_readwrite("nBinsATWD0", &I3DOMStatus::nBinsATWD0)
      .def_readwrite("nBinsATWD1", &I3DOMStatus::nBinsATWD1)
      .def_readwrite("nBinsATWD2", &I3DOMStatus::nBinsATWD2)
      .def_readwrite("nBinsATWD3", &I3DOMStatus::nBinsATWD3)
      .def_readwrite("nBinsFADC", &I3DOMStatus::nBinsFADC)
      .def_readwrite("deltaCompress", &I3DOMStatus::deltaCompress)
      .def_readwrite("fbState", &I3DOMStatus::fbState)
      .def_readwrite("fbBrightness", &I3DOMStatus::fbBrightness)
      .def_readwrite("fbLength", &I3DOMStatus::fbLength)
      .def_readwrite("fbDelay", &I3DOMStatus::fbDelay)
      .def_readwrite("fbMask", &I3DOMStatus::fbMask)
      .def_readwrite("fbRate", &I3DOMStatus::fbRate)
      .def_readwrite("domGainType", &I3DOMStatus::domGainType)
      .def_readwrite("cableType", &I3DOMStatus::cableType)
      .def_readwrite("SLCActive", &I3DOMStatus::SLCActive)
      ;

    enum_<I3DOMStatus::TrigMode>("TrigMode")
      .value("UnknownTrigMode",I3DOMStatus::UnknownTrigMode)
      .value("TestPattern",I3DOMStatus::TestPattern)
      .value("CPU",I3DOMStatus::CPU)
      .value("SPE",I3DOMStatus::SPE)
      .value("Flasher",I3DOMStatus::Flasher)
      .value("MPE",I3DOMStatus::MPE)
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
      ;
    def("identity", identity_<I3DOMStatus::LCMode>);

    enum_<I3DOMStatus::OnOff>("OnOff")
      .value("Unknown",I3DOMStatus::Unknown)
      .value("Off",I3DOMStatus::Off)
      .value("On",I3DOMStatus::On)
      ;
    def("identity", identity_<I3DOMStatus::OnOff>);

    enum_<I3DOMStatus::DOMGain>("DOMGain")
      .value("UnknownGainType",I3DOMStatus::UnknownGainType)
      .value("High",I3DOMStatus::High)
      .value("Low",I3DOMStatus::Low)
      ;
    def("identity", identity_<I3DOMStatus::DOMGain>);

    enum_<I3DOMStatus::CableType>("CableType")
      .value("UnknownCableType",I3DOMStatus::UnknownCableType)
      .value("Terminated",I3DOMStatus::Terminated)
      .value("Unterminated",I3DOMStatus::Unterminated)
      ;
    def("identity", identity_<I3DOMStatus::CableType>);

  }

  register_pointer_conversions<I3DetectorStatus>();
}
