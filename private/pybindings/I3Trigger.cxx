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
#include <icetray/I3Units.h>
#include <dataclasses/physics/I3Trigger.h>
#include <dataclasses/physics/I3TriggerHierarchy.h>
#include <icetray/python/stream_to_string.hpp>
#include <dataclasses/ostream_overloads.hpp>

using namespace boost::python;
namespace bp = boost::python;

I3TriggerPtr FindTrigger1(I3TriggerHierarchyPtr t, 
			 int srcID, int typeID, int configID){
  TriggerKey::SourceID s = static_cast<TriggerKey::SourceID>(srcID);
  TriggerKey::TypeID ty = static_cast<TriggerKey::TypeID>(typeID);

  I3TriggerPtr tptr;
  I3Tree<I3Trigger>::iterator t_iter = t->begin();
  for( ; t_iter != t->end(); t_iter++){
    TriggerKey tkey = t_iter->GetTriggerKey();
    if(tkey.GetType() == ty &&
       tkey.GetSource() == s &&
       tkey.CheckConfigID() &&
       tkey.GetConfigID() == configID)
      tptr = I3TriggerPtr(new I3Trigger(*t_iter));
  }
  return tptr;
}

I3TriggerPtr FindTrigger2(I3TriggerHierarchyPtr t, 
			 int srcID, int typeID){
  TriggerKey::SourceID s = static_cast<TriggerKey::SourceID>(srcID);
  TriggerKey::TypeID ty = static_cast<TriggerKey::TypeID>(typeID);

  if(I3TriggerHierarchyUtils::Find(*t,s,ty) != t->end()){
    I3Trigger tr(*(I3TriggerHierarchyUtils::Find(*t,s,ty)));
    return I3TriggerPtr(new I3Trigger(tr));
  }else{
    return I3TriggerPtr();
  }
}

bool IceTop_triggered(I3TriggerHierarchyPtr t){  
  I3TriggerHierarchy::iterator t_iter = t->begin();
  for(; t_iter != t->end(); t_iter++){
    if(t_iter->GetTriggerKey().GetSource() == TriggerKey::ICE_TOP &&
       t_iter->GetTriggerFired())
      return true;
  }
  return false;
}

bool InIce_triggered(I3TriggerHierarchyPtr t){  
  I3TriggerHierarchy::iterator t_iter = t->begin();
  for(; t_iter != t->end(); t_iter++){
    if(t_iter->GetTriggerKey().GetSource() == TriggerKey::IN_ICE &&
       t_iter->GetTriggerFired())
      return true;
  }
  return false;
}

bool InIce_SMT_ONLY(I3TriggerHierarchyPtr t){  
  if(t->size() != 2) return false;

  bool foundGlobal(false);
  bool foundSMT(false);

  I3TriggerHierarchy::iterator t_iter = t->begin();
  for(; t_iter != t->end(); t_iter++){
    if(t_iter->GetTriggerKey().GetSource() == TriggerKey::IN_ICE &&
       t_iter->GetTriggerKey().GetType() == TriggerKey::SIMPLE_MULTIPLICITY &&
       t_iter->GetTriggerFired())
      foundSMT = true;

    if(t_iter->GetTriggerKey().GetSource() == TriggerKey::GLOBAL &&
       t_iter->GetTriggerKey().GetType() == TriggerKey::THROUGHPUT &&
       t_iter->GetTriggerFired())
      foundGlobal = true;
  }
  return foundGlobal && foundSMT;
}

bool AMANDA_triggered(I3TriggerHierarchyPtr t){  
  I3TriggerHierarchy::iterator t_iter = t->begin();
  for(; t_iter != t->end(); t_iter++){
    if(t_iter->GetTriggerKey().GetSource() == TriggerKey::AMANDA_TWR_DAQ &&
       t_iter->GetTriggerFired())
      return true;
  }
  return false;
}

std::vector<double> get_trigger_lengths(I3TriggerHierarchyPtr t, 
				   int srcID, int typeID){
  std::vector<double> tlengths;
  TriggerKey::SourceID s = static_cast<TriggerKey::SourceID>(srcID);
  TriggerKey::TypeID ty = static_cast<TriggerKey::TypeID>(typeID);

  I3TriggerPtr tptr;
  I3Tree<I3Trigger>::iterator t_iter = t->begin();
  for( ; t_iter != t->end(); t_iter++){
    TriggerKey tkey = t_iter->GetTriggerKey();
    if(tkey.GetType() == ty &&
       tkey.GetSource() == s )
      tlengths.push_back(t_iter->GetTriggerLength());
  }
  return tlengths;
}

int length(I3TriggerHierarchyPtr t){
  if(t){
    return  t->size();
  }
  return 0;
}

TriggerKey get_trigkey(const I3Trigger& self)
{
  return self.GetTriggerKey();
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
      .add_property("key", get_trigkey, "Get TriggerKey")
      .def("__str__", &stream_to_string<I3Trigger>)
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
    .add_property("config_id", &TriggerKey::GetConfigID, 
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
    ;
    

  class_<I3TriggerHierarchy, bases<I3FrameObject>, I3TriggerHierarchyPtr>("I3TriggerHierarchy")
    .def("find_trigger", &FindTrigger1)
    .def("find_trigger", &FindTrigger2)   
    .def("in_ice_triggered", &InIce_triggered)
    .def("ice_top_triggered", &IceTop_triggered)
    .def("amanda_triggered", &AMANDA_triggered)
    .def("in_ice_smt_only", &InIce_SMT_ONLY)
    .def("__str__", &stream_to_string<I3TriggerHierarchy>)
    .def("__len__", &length)
    .add_property("trigger_lengths",&get_trigger_lengths)
    .def("__iter__", bp::iterator<I3TriggerHierarchy>())
    ;

  register_pointer_conversions<I3TriggerHierarchy>();
}
