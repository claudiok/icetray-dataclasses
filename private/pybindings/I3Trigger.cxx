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

#include <vector>
#include <icetray/I3Units.h>
#include <dataclasses/physics/I3Trigger.h>
#include <dataclasses/physics/I3TriggerHierarchy.h>
#include <dataclasses/I3Vector.h>
#include <icetray/python/dataclass_suite.hpp>
#include <dataclasses/ostream_overloads.hpp>

using namespace boost::python;
namespace bp = boost::python;


int length(I3TriggerHierarchyPtr t){
  if(t){
    return  t->size();
  }
  return 0;
}

using boost::python::object;
object
get_config_id_optional( const TriggerKey& tk){
  if( tk.GetConfigIDOptional() )
    return object(tk.GetConfigIDOptional().get() );
  else return object();
}

TriggerKey get_trigkey(const I3Trigger& self)
{
  return self.GetTriggerKey();
}

void set_trigkey(I3Trigger& self, const TriggerKey& tk)
{
  self.GetTriggerKey() = tk;
}

static I3TriggerHierarchyPtr
from_frame(I3Frame &frame, const std::string &name)
{
	I3TriggerHierarchyConstPtr ptr =
	    frame.Get<I3TriggerHierarchyConstPtr>(name);
	return boost::const_pointer_cast<I3TriggerHierarchy>(ptr);
}

void register_I3Trigger()
{
  {
    scope trigscope = 
      class_<I3Trigger, I3TriggerPtr>("I3Trigger")
      PROPERTY(I3Trigger, time, TriggerTime)
      PROPERTY(I3Trigger, length, TriggerLength)
      PROPERTY(I3Trigger, fired, TriggerFired)
      // force copy of trigkey via standalone fn
      .add_property("key", get_trigkey, set_trigkey,"Get TriggerKey")
      .def( self == self )
      .def( self != self )
      .def(dataclass_suite<I3Trigger>())
      .def( freeze() )
      ;

    enum_<TriggerKey::SourceID>("SourceID")
      .value("IN_ICE",TriggerKey::IN_ICE)
      .value("ICE_TOP",TriggerKey::ICE_TOP)
      .value("AMANDA_TWR_DAQ",TriggerKey::AMANDA_TWR_DAQ)
      .value("EXTERNAL",TriggerKey::EXTERNAL)
      .value("GLOBAL",TriggerKey::GLOBAL)
      .value("AMANDA_MUON_DAQ",TriggerKey::AMANDA_MUON_DAQ)
      .value("SPASE",TriggerKey::SPASE)
      .value("UNKNOWN_SOURCE",TriggerKey::UNKNOWN_SOURCE)
      .export_values()
      ;
    def("identity", identity_<TriggerKey::SourceID>);


    enum_<TriggerKey::TypeID>("TypeID")
      .value("SIMPLE_MULTIPLICITY",TriggerKey::SIMPLE_MULTIPLICITY)
      .value("CALIBRATION",TriggerKey::CALIBRATION)
      .value("MIN_BIAS",TriggerKey::MIN_BIAS)
      .value("THROUGHPUT",TriggerKey::THROUGHPUT)
      .value("TWO_COINCIDENCE",TriggerKey::TWO_COINCIDENCE)
      .value("THREE_COINCIDENCE",TriggerKey::THREE_COINCIDENCE)
      .value("MERGED",TriggerKey::MERGED)
      .value("SLOW_PARTICLE",TriggerKey::SLOW_PARTICLE)
      .value("FRAGMENT_MULTIPLICITY",TriggerKey::FRAGMENT_MULTIPLICITY)
      .value("STRING",TriggerKey::STRING)
      .value("VOLUME",TriggerKey::VOLUME)
      .value("SPHERE",TriggerKey::SPHERE)
      .value("UNBIASED",TriggerKey::UNBIASED)
      .value("SPASE_2",TriggerKey::SPASE_2)
      .value("UNKNOWN_TYPE",TriggerKey::UNKNOWN_TYPE)
      .export_values()
      ;
    def("identity", identity_<TriggerKey::TypeID>);

  }

  class_<TriggerKey>("TriggerKey")
    .def(init<TriggerKey::SourceID, TriggerKey::TypeID>() )
    .def(init<TriggerKey::SourceID, TriggerKey::TypeID, int>() )
    #define PROPERTIES (Source)(Type)(Subtype)
    BOOST_PP_SEQ_FOR_EACH(WRAP_PROP, TriggerKey, PROPERTIES)
    #undef  PROPERTIES
    .add_property("config_id", get_config_id_optional, 
		  (void (TriggerKey::*)(int)) &TriggerKey::SetConfigID)
    .def("check_config_id", &TriggerKey::CheckConfigID)
    .def("reset_config_id", (void (TriggerKey::*)()) &TriggerKey::SetConfigID)
    .def("__str__", &stream_to_string<TriggerKey>)
    .def(self < self)
    .def(self >= self)
    .def(self > self)
    .def(self <= self)
    .def(self == self)
    .def(self != self)
    .def(dataclass_suite<TriggerKey>())
    ;
    
  class_<I3TriggerHierarchy, bases<I3FrameObject>, I3TriggerHierarchyPtr>("I3TriggerHierarchy")
    .def("__len__", &length)
    .def("__iter__", bp::iterator<I3TriggerHierarchy>())
    .def("insert",&I3TriggerHierarchyUtils::Insert)
    .def("from_frame", &from_frame)
    .staticmethod("from_frame")
    .def(dataclass_suite<I3TriggerHierarchy>())
    ;

  class_<I3VectorI3Trigger, bases<I3FrameObject>, shared_ptr<I3VectorI3Trigger > >("I3VectorI3Trigger")
    .def(dataclass_suite<I3VectorI3Trigger >())
    ;

  register_pointer_conversions<I3VectorI3Trigger>();
  register_pointer_conversions<I3TriggerHierarchy>();
}
