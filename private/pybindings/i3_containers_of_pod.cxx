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

#include <dataclasses/I3Vector.h>
#include <dataclasses/I3Map.h>
#include <vector>
#include <string>

using namespace boost::python;
using std::vector;

static std::string 
string_I3VectorChar(const I3Vector<char> &vc)
{
  return std::string(vc.begin(),vc.end());
}

template <typename T>
void 
register_i3vector_of(const std::string& s)
{
  typedef I3Vector<T> vec_t;
  class_<vec_t, bases<I3FrameObject>, boost::shared_ptr<vec_t> > ((std::string("I3Vector") + s).c_str())
    .def(vector_indexing_suite<vec_t>())
    ;
  register_pointer_conversions<vec_t>();
}

template <typename T, typename U>
void
register_std_pair(const char* s)
{
  typedef std::pair<T, U> type_t;

  class_<type_t>(s)
    .def_readwrite("first", &type_t::first)
    .def_readwrite("second", &type_t::second)
    ;

  def("make_pair", &std::make_pair<T, U>);
}

void register_i3_containers_of_pod()
{
  // 'char' has a special method that converts to string
  class_<I3Vector<char>, bases<I3FrameObject>, boost::shared_ptr<I3Vector<char> > >("I3VectorChar")
    .def(vector_indexing_suite<I3Vector<char> >())
    .def("__str__",string_I3VectorChar)
    ;
  register_pointer_conversions<I3Vector<char> >();

  //
  // others are consistent with each other
  //
  register_i3vector_of<std::string>("String");

  register_i3vector_of<bool>("Bool");

  register_i3vector_of<int16_t>("Short");
  register_i3vector_of<uint16_t>("UShort");

  register_i3vector_of<int32_t>("Int");
  register_i3vector_of<uint32_t>("UInt");

  register_i3vector_of<I3VectorInt64::value_type>("Int64");
  register_i3vector_of<I3VectorUInt64::value_type>("UInt64");

  register_i3vector_of<float>("Float");
  register_i3vector_of<double>("Double");

  register_i3vector_of<std::pair<double, double> >("DoubleDouble");

  register_std_pair<double, double>("pair_double_double");

  class_<I3MapStringDouble, bases<I3FrameObject>, I3MapStringDoublePtr>("I3MapStringDouble")
    .def(map_indexing_suite<I3MapStringDouble >())
    ;
  register_pointer_conversions<I3MapStringDouble>();



  class_<I3MapStringInt, bases<I3FrameObject>, I3MapStringIntPtr>("I3MapStringInt")
    .def(map_indexing_suite<I3MapStringInt >())
    ;
  register_pointer_conversions<I3MapStringInt>();

  class_<I3MapStringBool, bases<I3FrameObject>, I3MapStringBoolPtr>("I3MapStringBool")
    .def(map_indexing_suite<I3MapStringBool >())
    ;
  register_pointer_conversions<I3MapStringBool>();

  class_<I3MapStringStringDouble, bases<I3FrameObject>, I3MapStringStringDoublePtr>("I3MapStringStringDouble")
    .def(map_indexing_suite<I3MapStringStringDouble >())
    ;
  register_pointer_conversions<I3MapStringStringDouble>();

  class_<I3MapUnsignedUnsigned, bases<I3FrameObject>, I3MapUnsignedUnsignedPtr>("I3MapUnsignedUnsigned")
    .def(map_indexing_suite<I3MapUnsignedUnsigned >())
    ;
  register_pointer_conversions<I3MapUnsignedUnsigned>();

  class_<I3MapUShortUShort, bases<I3FrameObject>, I3MapUShortUShortPtr>("I3MapUShortUShort")
    .def(map_indexing_suite<I3MapUShortUShort >())
    ;
  register_pointer_conversions<I3MapUShortUShort>();

  class_<I3MapIntVectorInt, bases<I3FrameObject>, I3MapIntVectorIntPtr>("I3MapIntVectorInt")
    .def(map_indexing_suite<I3MapIntVectorInt >())
    ;
  register_pointer_conversions<I3MapIntVectorInt>();

  class_<I3MapKeyVectorDouble, bases<I3FrameObject>, I3MapKeyVectorDoublePtr>("I3MapKeyVectorDouble")
    .def(map_indexing_suite<I3MapKeyVectorDouble >())
    ;
  register_pointer_conversions<I3MapKeyVectorDouble>();

  class_<I3MapKeyVectorInt, bases<I3FrameObject>, I3MapKeyVectorIntPtr>("I3MapKeyVectorInt")
    .def(map_indexing_suite<I3MapKeyVectorInt >())
    ;
  register_pointer_conversions<I3MapKeyVectorInt>();

  class_<I3MapKeyDouble, bases<I3FrameObject>, I3MapKeyDoublePtr>("I3MapKeyDouble")
    .def(map_indexing_suite<I3MapKeyDouble >())
    ;
  register_pointer_conversions<I3MapKeyDouble>();

}

