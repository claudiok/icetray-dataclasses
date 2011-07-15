//
//   Copyright (c) 2004, 2005, 2006, 2007, 2008   Troy D. Straszheim  
//   
//   $Id: pybindings/I3DOMLaunch.cxx 46254 2008-06-14 02:50:30Z troy $
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
#include <icetray/python/std_vector_indexing_suite.hpp>

using namespace boost::python;

void register_I3DOMLaunch()
{

  {
    scope outer = 
    class_<I3DOMLaunch, boost::shared_ptr<I3DOMLaunch> >("I3DOMLaunch")
      .add_property("StartTime", &I3DOMLaunch::GetStartTime, &I3DOMLaunch::SetStartTime)
      .add_property("LCBit", &I3DOMLaunch::GetLCBit, &I3DOMLaunch::SetLCBit)
      .add_property("TriggerType", &I3DOMLaunch::GetTriggerType, &I3DOMLaunch::SetTriggerType)
      .add_property("TriggerMode", &I3DOMLaunch::GetTriggerMode, &I3DOMLaunch::SetTriggerMode)
      .add_property("WhichATWD", &I3DOMLaunch::GetWhichATWD, &I3DOMLaunch::SetWhichATWD)
      .add_property("IsPedestalSub", &I3DOMLaunch::GetIsPedestalSub, &I3DOMLaunch::SetIsPedestalSub)
      .add_property("ChargeStampHighestSample", &I3DOMLaunch::GetChargeStampHighestSample, &I3DOMLaunch::SetChargeStampHighestSample)
      .add_property("RawFADC", make_function((std::vector<int>& (I3DOMLaunch::*)()) &I3DOMLaunch::GetRawFADC,
                                             return_internal_reference<1>()),
		    make_function((std::vector<int>& (I3DOMLaunch::*)()) &I3DOMLaunch::GetRawFADC, return_internal_reference<1>()))				  
      .add_property("RawATWDs", make_function((std::vector<std::vector<int> >& (I3DOMLaunch::*)(void)) &I3DOMLaunch::GetRawATWDs,
					      return_internal_reference<1>()),
		    make_function((std::vector<std::vector<int> >& (I3DOMLaunch::*)(void)) &I3DOMLaunch::GetRawATWDs,
				  return_internal_reference<1>()))
      .def("GetRawATWD", (std::vector<int>& (I3DOMLaunch::*)(unsigned)) &I3DOMLaunch::GetRawATWD, return_internal_reference<1>())	   
      .add_property("RawChargeStamp", make_function((std::vector<int>& (I3DOMLaunch::*)()) &I3DOMLaunch::GetRawChargeStamp,
                                                    return_internal_reference<1>()),
		    make_function((std::vector<int>& (I3DOMLaunch::*)()) &I3DOMLaunch::GetRawChargeStamp,
				  return_internal_reference<1>()))
      .add_property("WhichATWDChargeStamp", &I3DOMLaunch::GetWhichATWDChargeStamp, &I3DOMLaunch::SetWhichATWDChargeStamp)
      .def(self == self)
    ;

    enum_<I3DOMLaunch::TriggerType>("TriggerType")
      .value("TEST_PATTERN",I3DOMLaunch::TEST_PATTERN)
      .value("CPU_REQUESTED",I3DOMLaunch::CPU_REQUESTED)
      .value("SPE_DISCRIMINATOR_TRIGGER",I3DOMLaunch::SPE_DISCRIMINATOR_TRIGGER)
      .value("FLASHER_BOARD_TRIGGER",I3DOMLaunch::FLASHER_BOARD_TRIGGER)
      .value("MPE_DISCRIMINATOR_TRIGGER",I3DOMLaunch::MPE_DISCRIMINATOR_TRIGGER)
      .value("ONBOARD_LED",I3DOMLaunch::ONBOARD_LED)
      .export_values()
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
      .value("MIN_BIAS", I3DOMLaunch::MIN_BIAS)
      .value("LAST_TRIGGER_SITUATION", I3DOMLaunch::LAST_TRIGGER_SITUATION)
      .export_values()
      ;
  
    def("Identity", identity_<I3DOMLaunch::TriggerMode>);

    enum_<I3DOMLaunch::ATWDselect>("ATWDselect")
      .value("ATWDa", I3DOMLaunch::ATWDa)
      .value("ATWDb", I3DOMLaunch::ATWDb)
      .export_values()
      ;
    def("Identity", identity_<I3DOMLaunch::ATWDselect>);
  }

  class_<std::vector<I3DOMLaunch> >("I3DOMLaunchSeries")
    .def(std_vector_indexing_suite<std::vector<I3DOMLaunch> >())
    ;
    
  class_<I3DOMLaunchSeriesMap, bases<I3FrameObject>, I3DOMLaunchSeriesMapPtr>("I3DOMLaunchSeriesMap")
    .def(std_map_indexing_suite<I3DOMLaunchSeriesMap>())
    ;
    
  register_pointer_conversions<I3DOMLaunchSeriesMap>();
}
