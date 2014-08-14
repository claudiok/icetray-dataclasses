//
//   Copyright (c) 2004, 2005, 2006, 2007, 2008   Troy D. Straszheim  
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

#ifndef I3VECTORS_H_PYBINDINGS
#define I3VECTORS_H_PYBINDINGS 

#include <icetray/ostream_pair.hpp>
#include <dataclasses/I3Vector.h>
#include <dataclasses/ostream_overloads.hpp>
#include <dataclasses/physics/I3Particle.h>
#include <dataclasses/I3Position.h>
#include <icetray/python/dataclass_suite.hpp>
#include <vector>
#include <sstream>

using namespace boost::python;

using std::vector;

template <typename T>
void 
register_i3vector_of(const std::string& s)
{
  typedef I3Vector<T> vec_t;
  class_<vec_t, bases<I3FrameObject>, boost::shared_ptr<vec_t> > ((std::string("I3Vector") + s).c_str())
    .def(dataclass_suite<vec_t>())
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
    .def(dataclass_suite<type_t>())
    ;
#if __cplusplus < 201103L
  //In newer c++ the signature of make_pair has become intractable
  //for existing versions of boost::python
  def("make_pair", &std::make_pair<T, U>);
#endif
}

#endif //I3VECTORS_H_PYBINDINGS
