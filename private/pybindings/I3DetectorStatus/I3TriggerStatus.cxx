//
//   Copyright (c) 2004, 2005, 2006, 2007   Troy D. Straszheim  
//   
//   $Id$
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

#include <dataclasses/I3Map.h>
#include <dataclasses/status/I3DetectorStatus.h>
#include <icetray/python/dataclass_suite.hpp>

using namespace boost::python;

I3MapStringStringPtr
get_trigger_settings(I3TriggerStatusPtr ts){
  I3MapStringStringPtr r_map(new I3MapStringString);
  BOOST_FOREACH(I3MapStringString::value_type p, ts->GetTriggerSettings())
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


void register_I3TriggerStatus()
{
  {
    scope outer = 
      class_<I3TriggerStatus, boost::shared_ptr<I3TriggerStatus> >("I3TriggerStatus")
      .add_property("trigger_name", &get_trigger_name)
      .add_property("trigger_settings", &get_trigger_settings)
      .add_property("readout_settings", &get_readout_settings)
      .def(dataclass_suite<I3TriggerStatus>())
      ;

    class_<I3TriggerReadoutConfig, boost::shared_ptr<I3TriggerReadoutConfig> >("I3TriggerReadoutConfig")
      .def_readwrite("readout_time_minus", &I3TriggerReadoutConfig::readoutTimeMinus)
      .def_readwrite("readout_time_plus", &I3TriggerReadoutConfig::readoutTimePlus)
      .def_readwrite("readout_time_offset", &I3TriggerReadoutConfig::readoutTimeOffset)
      .def(dataclass_suite<I3TriggerReadoutConfig>())
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

}
