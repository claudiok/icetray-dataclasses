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

#include <dataclasses/I3String.h>
#include <icetray/python/stream_to_string.hpp>
#include <icetray/python/boost_serializable_pickle_suite.hpp>
#include <dataclasses/ostream_overloads.hpp>

using namespace boost::python;

size_t 
i3string_get_length(const I3String& s)
{
  return s.value.size();
}

void register_I3String()
{
  class_<I3String, bases<I3FrameObject>, boost::shared_ptr<I3String> >("I3String")
    .def(init<>())
    .def(init<const std::string&>())
    .def(init<const I3String&>())
    .def_readwrite("value", &I3String::value)
    .def("__repr__",&stream_to_string<I3String>)
    .def("__str__",&stream_to_string<I3String>)
    .def("__len__",i3string_get_length)
    .def_pickle(boost_serializable_pickle_suite<I3String>())
    .def( freeze() )
    ;

  register_pointer_conversions<I3String>();
}
