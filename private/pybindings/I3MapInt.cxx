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
#include <dataclasses/ostream_overloads.hpp>
#include <icetray/python/boost_serializable_pickle_suite.hpp>

using namespace boost::python;

void register_I3MapInt()
{
  class_<I3MapUnsignedUnsigned, bases<I3FrameObject>, I3MapUnsignedUnsignedPtr>("I3MapUnsignedUnsigned")
    .def(std_map_indexing_suite<I3MapUnsignedUnsigned >())
    .def("__str__", &stream_to_string<I3MapUnsignedUnsigned>)
    .def_pickle(boost_serializable_pickle_suite<I3MapUnsignedUnsigned>())
    ;
  register_pointer_conversions<I3MapUnsignedUnsigned>();
  
  class_<I3MapUShortUShort, bases<I3FrameObject>, I3MapUShortUShortPtr>("I3MapUShortUShort")
    .def(std_map_indexing_suite<I3MapUShortUShort >())
    .def("__str__", &stream_to_string<I3MapUShortUShort>)
    .def_pickle(boost_serializable_pickle_suite<I3MapUShortUShort>())
    ;
  register_pointer_conversions<I3MapUShortUShort>();
  
  class_<I3MapIntVectorInt, bases<I3FrameObject>, I3MapIntVectorIntPtr>("I3MapIntVectorInt")
    .def(std_map_indexing_suite<I3MapIntVectorInt >())
    .def("__str__", &stream_to_string<I3MapIntVectorInt>)
    .def_pickle(boost_serializable_pickle_suite<I3MapIntVectorInt>())
    ;
  register_pointer_conversions<I3MapIntVectorInt>();
  
}

