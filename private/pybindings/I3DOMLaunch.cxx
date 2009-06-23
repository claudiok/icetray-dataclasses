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

#include <dataclasses/physics/I3DOMLaunch.h>
#include <icetray/python/std_map_indexing_suite.hpp>

using namespace boost::python;

void register_I3DOMLaunch()
{
  //  I3Vector<int>& (I3DOMLaunch::*)() = &I3DOMLaunch::GetRawFADC;

  {
    scope outer = 
    class_<I3DOMLaunch, boost::shared_ptr<I3DOMLaunch> >("I3DOMLaunch")
      .def("GetStartTime", &I3DOMLaunch::GetStartTime)
      .def("GetLCBit", &I3DOMLaunch::GetLCBit)
      .def("GetTriggerType", &I3DOMLaunch::GetTriggerType)
      .def("GetTriggerMode", &I3DOMLaunch::GetTriggerMode)
      .def("GetWhichATWD", &I3DOMLaunch::GetWhichATWD)
      .def("GetIsPedestalSub", &I3DOMLaunch::GetIsPedestalSub)
      .def("GetChargeStampHighestSample", &I3DOMLaunch::GetChargeStampHighestSample)
      .def("GetRawFADC", (I3Vector<int>& (I3DOMLaunch::*)()) &I3DOMLaunch::GetRawFADC,
	   return_internal_reference<1>())
      .def("GetRawATWD", (I3Vector<int>& (I3DOMLaunch::*)(unsigned)) &I3DOMLaunch::GetRawATWD,
	   return_internal_reference<1>())
      .def("GetRawChargeStamp", (I3Vector<int>& (I3DOMLaunch::*)()) &I3DOMLaunch::GetRawChargeStamp,
	   return_internal_reference<1>())
      .def("SetStartTime",&I3DOMLaunch::SetStartTime)
      .def("SetTriggerType", &I3DOMLaunch::SetTriggerType)
      .def("SetTriggerMode", &I3DOMLaunch::SetTriggerMode)
      .def("SetWhichATWD", &I3DOMLaunch::SetWhichATWD)
      .def("SetLCBit", &I3DOMLaunch::SetLCBit)
      .def("SetIsPedestalSub", &I3DOMLaunch::SetIsPedestalSub)
      .def("SetChargeStampHighestSample", &I3DOMLaunch::SetChargeStampHighestSample)

    ;

    enum_<I3DOMLaunch::TriggerType>("TriggerType")
      .value("TEST_PATTERN",I3DOMLaunch::TEST_PATTERN)
      .value("CPU_REQUESTED",I3DOMLaunch::CPU_REQUESTED)
      .value("SPE_DISCRIMINATOR_TRIGGER",I3DOMLaunch::SPE_DISCRIMINATOR_TRIGGER)
      .value("FLASHER_BOARD_TRIGGER",I3DOMLaunch::FLASHER_BOARD_TRIGGER)
      .value("MPE_DISCRIMINATOR_TRIGGER",I3DOMLaunch::MPE_DISCRIMINATOR_TRIGGER)
      .value("ONBOARD_LED",I3DOMLaunch::ONBOARD_LED)
      ;
    def("identity", identity_<I3DOMLaunch::TriggerType>);
  
    enum_<I3DOMLaunch::TriggerMode>("TriggerMode")
      .value("UNDEFINED", I3DOMLaunch::UNDEFINED)
      .value("REQUIRE_BOTH", I3DOMLaunch::REQUIRE_BOTH)
      .value("FR_RUN", I3DOMLaunch::FR_RUN)
      .value("LC_LOWER", I3DOMLaunch::LC_LOWER)
      .value("LC_UPPER", I3DOMLaunch::LC_UPPER)
      .value("UNKNOWN_MODE", I3DOMLaunch::UNKNOWN_MODE)
      .value("SLC_READOUT", I3DOMLaunch::SLC_READOUT)
      .value("LAST_TRIGGER_SITUATION", I3DOMLaunch::LAST_TRIGGER_SITUATION);
  
    def("identity", identity_<I3DOMLaunch::TriggerMode>);
  }

  class_<std::vector<I3DOMLaunch> >("I3DOMLaunchSseries")
    .def(vector_indexing_suite<std::vector<I3DOMLaunch> >())
    ;
    
  class_<I3DOMLaunchSeriesMap, bases<I3FrameObject>, I3DOMLaunchSeriesMapPtr>("I3DOMLaunchSeriesMap")
    .def(std_map_indexing_suite<I3DOMLaunchSeriesMap>())
    ;
    
  register_pointer_conversions<I3DOMLaunchSeriesMap>();
}
