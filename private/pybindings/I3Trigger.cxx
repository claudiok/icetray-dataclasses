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

vector<double> get_trigger_lengths(I3TriggerHierarchyPtr t, 
				   int srcID, int typeID){
  vector<double> tlengths;
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
string TriggerPrettyPrint(const I3Trigger& t){
  stringstream s;
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
  s<<endl;
  return s.str();
}

string DumpChildren(I3TriggerHierarchyPtr t,
		    I3TriggerHierarchy::iterator i){
  stringstream s;
  I3TriggerHierarchy::sibling_iterator si;
  for(si = t->begin(i); si != t->end(i); si++){
    for(int j=0; j<2*t->depth(si); j++) s<<" ";
    s<<TriggerPrettyPrint(*si);
    s<<DumpChildren(t,si);
  }
  return s.str();
}

string print(I3TriggerHierarchyPtr t){
  stringstream s;

  I3TriggerHierarchy::sibling_iterator i;
  s<<"*** TRIGGER DUMP - BEGIN***"<<endl;
  for(i = t->begin(); i != t->end(); i++){
    for(int j=0; j<2*t->depth(i); j++) s<<" ";
    s<<TriggerPrettyPrint(*i);
    s<<DumpChildren(t,i);
  }
  s<<"*** TRIGGER DUMP - END***"<<endl;

  return s.str();
}

int length(I3TriggerHierarchyPtr t){
  if(t){
    return  t->size();
  }
  return 0;
}

void register_I3Trigger()
{
  {
    scope trigscope = 
      class_<I3Trigger, I3TriggerPtr>("I3Trigger")
      PROPERTY(I3Trigger, TriggerTime, TriggerTime)
      PROPERTY(I3Trigger, TriggerLength, TriggerLength)
      PROPERTY(I3Trigger, TriggerFired, TriggerFired)
      ;

    enum_<TriggerKey::TypeID>("TypeID")
      .value("SIMPLE_MULTIPLICITY",TriggerKey::SIMPLE_MULTIPLICITY)
      ;
    def("identity", identity_<TriggerKey::TypeID>);

    enum_<TriggerKey::SourceID>("SourceID")
      .value("IN_ICE",TriggerKey::IN_ICE)
      ;
    def("identity", identity_<TriggerKey::SourceID>);
  }

  class_<I3TriggerHierarchy, bases<I3FrameObject>, I3TriggerHierarchyPtr>("I3TriggerHierarchy")
    .def("FindTrigger", &FindTrigger1)
    .def("FindTrigger", &FindTrigger2)
    .def("IceTop_triggered", &IceTop_triggered)
    .def("AMANDA_triggered", &AMANDA_triggered)
    .def("InIce_SMT_ONLY", &InIce_SMT_ONLY)
    .def("__str__", &print)
    .def("__len__", &length)
    .def("GetTriggerLengths",&get_trigger_lengths)
    ;

}