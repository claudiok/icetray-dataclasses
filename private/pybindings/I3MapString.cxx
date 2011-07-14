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

using namespace boost::python;

void register_I3MapString()
{
  class_<I3MapStringDouble, bases<I3FrameObject>, I3MapStringDoublePtr>("I3MapStringDouble")
    .def(std_map_indexing_suite<I3MapStringDouble >())
    ;
  register_pointer_conversions<I3MapStringDouble>();

  class_<I3MapStringInt, bases<I3FrameObject>, I3MapStringIntPtr>("I3MapStringInt")
    .def(std_map_indexing_suite<I3MapStringInt >())
    ;
  register_pointer_conversions<I3MapStringInt>();
  
  class_<I3MapStringBool, bases<I3FrameObject>, I3MapStringBoolPtr>("I3MapStringBool")
    .def(std_map_indexing_suite<I3MapStringBool >())
    ;
  register_pointer_conversions<I3MapStringBool>();
  
  class_<I3MapStringVectorDouble, bases<I3FrameObject>, I3MapStringVectorDoublePtr>("I3MapStringVectorDouble")
    .def(std_map_indexing_suite<I3MapStringVectorDouble >())
    ;
  register_pointer_conversions<I3MapStringVectorDouble>();



  class_<I3MapStringStringDouble, bases<I3FrameObject>, I3MapStringStringDoublePtr>("I3MapStringStringDouble")
    .def(std_map_indexing_suite<I3MapStringStringDouble >())
    ;
  register_pointer_conversions<I3MapStringStringDouble>();

  class_<std::map<std::string,std::string > >("TestMapStringString",no_init)
    .def(std_map_indexing_suite<std::map<std::string,std::string > >())
    ;

  class_<std::map<std::string,int > >("std_map_string_int",no_init)
    .def(std_map_indexing_suite<std::map<std::string,int > >())
    ;
}
