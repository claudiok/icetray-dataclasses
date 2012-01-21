//
//   Copyright (c) 2004, 2005, 2006, 2007, 2008   Troy D. Straszheim  
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

#include <dataclasses/I3Map.h>
#include <icetray/python/std_map_indexing_suite.hpp>
#include <icetray/python/stream_to_string.hpp>
#include <icetray/python/boost_serializable_pickle_suite.hpp>
#include <dataclasses/ostream_overloads.hpp>

using namespace boost::python;

void register_I3MapString()
{
  class_<I3MapStringDouble, bases<I3FrameObject>, I3MapStringDoublePtr>("I3MapStringDouble")
    .def(std_map_indexing_suite<I3MapStringDouble >())
    .def("__str__", &stream_to_string<I3MapStringDouble>)
    .def_pickle(boost_serializable_pickle_suite<I3MapStringDouble>())
    ;
  register_pointer_conversions<I3MapStringDouble>();

  class_<I3MapStringInt, bases<I3FrameObject>, I3MapStringIntPtr>("I3MapStringInt")
    .def(std_map_indexing_suite<I3MapStringInt >())
    .def("__str__", &stream_to_string<I3MapStringInt>)
    .def_pickle(boost_serializable_pickle_suite<I3MapStringInt>())
    ;
  register_pointer_conversions<I3MapStringInt>();
  
  class_<I3MapStringBool, bases<I3FrameObject>, I3MapStringBoolPtr>("I3MapStringBool")
    .def(std_map_indexing_suite<I3MapStringBool >())
    .def("__str__", &stream_to_string<I3MapStringBool>)
    .def_pickle(boost_serializable_pickle_suite<I3MapStringBool>())
    ;
  register_pointer_conversions<I3MapStringBool>();
  
  class_<I3MapStringVectorDouble, bases<I3FrameObject>, I3MapStringVectorDoublePtr>("I3MapStringVectorDouble")
    .def(std_map_indexing_suite<I3MapStringVectorDouble >())
    .def("__str__", &stream_to_string<I3MapStringVectorDouble>)
    .def_pickle(boost_serializable_pickle_suite<I3MapStringVectorDouble>())
    ;
  register_pointer_conversions<I3MapStringVectorDouble>();



  class_<I3MapStringStringDouble, bases<I3FrameObject>, I3MapStringStringDoublePtr>("I3MapStringStringDouble")
    .def(std_map_indexing_suite<I3MapStringStringDouble >())
    .def("__str__", &stream_to_string<I3MapStringStringDouble>)
    .def_pickle(boost_serializable_pickle_suite<I3MapStringStringDouble>())
    ;
  register_pointer_conversions<I3MapStringStringDouble>();

  class_<std::map<std::string,std::string > >("TestMapStringString",no_init)
    .def(std_map_indexing_suite<std::map<std::string,std::string > >())
    .def_pickle(boost_serializable_pickle_suite<std::map<std::string,std::string > >())
    ;

  //
  //  TDS: big problems here.  the duplicate registration of pair<string,int>
  //  with the boost.python conversion registry is a warn when compiled 'release',
  //  and triggers an ugly assert in registry.cpp when compiled 'debug',
  //  due to the fact that we link against different versions of libboost_python[-d].so
  //
  //  AO (1/19/12) : This was "fixed" several years ago (2009-11-20).  When building the
  //  tools a patch is applied which manually comments out this specific assert.
  //  This could be a problem again when/if we switch to system build and/or
  //  giving people the option to build against whatever boost they want.
  //  In the meantime, people simply need to rebuild their tools.
  

  class_<std::map<std::string,int > >("std_map_string_int",no_init)
    .def(std_map_indexing_suite<std::map<std::string,int > >())
    .def_pickle(boost_serializable_pickle_suite<std::map<std::string,int > >())
    ;
}
