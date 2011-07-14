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
std::string TriggerPrettyPrint(const I3Trigger& t){
  std::stringstream s;
  s<<t.GetTriggerKey().GetSourceString()<<" "
   <<t.GetTriggerKey().GetTypeString()<<" "
   <<t.GetTriggerKey().GetSubtype()<<" ";
  if(t.GetTriggerKey().CheckConfigID())
    s<<t.GetTriggerKey().GetConfigID()<<" ";
  else
    s<<"configID not set ";
  t.GetTriggerFired() ? s<<"FIRED":s<<"NOT_FIRED";
  s<<" ";
  s<<" length = "<<t.GetTriggerLength()/I3Units::microsecond<<" mus";
  s<<" time = "<<t.GetTriggerTime()/I3Units::microsecond<<" mus";
  return s.str();
}

std::string DumpChildren(I3TriggerHierarchyPtr t,
		    I3TriggerHierarchy::iterator i){
  std::stringstream s;
  I3TriggerHierarchy::sibling_iterator si;
  for(si = t->begin(i); si != t->end(i); si++){
    for(int j=0; j<2*t->depth(si); j++) s<<" ";
    s<<TriggerPrettyPrint(*si) << std::endl;
    s<<DumpChildren(t,si);
  }
  return s.str();
}

std::string print(I3TriggerHierarchyPtr t){
  std::stringstream s;

  I3TriggerHierarchy::sibling_iterator i;
  s<<"*** TRIGGER DUMP - BEGIN***"<<std::endl;
  for(i = t->begin(); i != t->end(); i++){
    for(int j=0; j<2*t->depth(i); j++) s<<" ";
    s<<TriggerPrettyPrint(*i) << std::endl;
    s<<DumpChildren(t,i);
  }
  s<<"*** TRIGGER DUMP - END***"<<std::endl;

  return s.str();
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

std::string PrettyPrintTriggerKey(const TriggerKey& k){
  std::stringstream s;
  s << "[";
  s << k.GetSourceString() << ":"
    << k.GetTypeString();
  if(k.CheckConfigID())
    s << ":"<<k.GetConfigID() ;
  s << "]" ;
  return s.str();
}

void register_I3Trigger()
{
  {
    scope trigscope = 
      class_<I3Trigger, I3TriggerPtr>("I3Trigger")
      PROPERTY(I3Trigger, Time, TriggerTime)
      PROPERTY(I3Trigger, Length, TriggerLength)
      PROPERTY(I3Trigger, Fired, TriggerFired)
      // force copy of trigkey via standalone fn
      .add_property("Key", get_trigkey, "Get TriggerKey")
      .def("__str__", TriggerPrettyPrint)
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
    .add_property("Source", &TriggerKey::GetSource, &TriggerKey::SetSource)
    .add_property("Type", &TriggerKey::GetType, &TriggerKey::SetType)
    .add_property("Subtype", &TriggerKey::GetSubtype, &TriggerKey::SetSubtype)
    .add_property("ConfigID", &TriggerKey::GetConfigID, 
		  (void (TriggerKey::*)(int)) &TriggerKey::SetConfigID)
    .def("CheckConfigID", &TriggerKey::CheckConfigID)
    .def("ResetConfigID", (void (TriggerKey::*)()) &TriggerKey::SetConfigID)
    .def("__str__", &PrettyPrintTriggerKey)
    .def(self < self)
    .def(self >= self)
    .def(self > self)
    .def(self <= self)
    .def(self == self)
    .def(self != self)
    ;
    

  class_<I3TriggerHierarchy, bases<I3FrameObject>, I3TriggerHierarchyPtr>("I3TriggerHierarchy")
    .def("FindTrigger", &FindTrigger1)
    .def("FindTrigger", &FindTrigger2)   
    .def("InIce_triggered", &InIce_triggered)
    .def("IceTop_triggered", &IceTop_triggered)
    .def("AMANDA_triggered", &AMANDA_triggered)
    .def("InIce_SMT_ONLY", &InIce_SMT_ONLY)
    .def("__str__", &print)
    .def("__len__", &length)
    .add_property("TriggerLengths",&get_trigger_lengths)
    .def("__iter__", bp::iterator<I3TriggerHierarchy>())
    ;

  register_pointer_conversions<I3TriggerHierarchy>();
}
