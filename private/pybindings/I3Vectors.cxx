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
#include <vector>

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

void register_I3Vectors()
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
}