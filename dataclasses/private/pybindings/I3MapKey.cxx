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
#include <icetray/python/dataclass_suite.hpp>
#include <dataclasses/ostream_overloads.hpp>

using namespace boost::python;

void register_I3MapKey()
{
  class_<I3MapKeyVectorDouble, bases<I3FrameObject>, I3MapKeyVectorDoublePtr>("I3MapKeyVectorDouble")
    .def(dataclass_suite<I3MapKeyVectorDouble >())
    ;
  register_pointer_conversions<I3MapKeyVectorDouble>();
  
  class_<I3MapKeyVectorInt, bases<I3FrameObject>, I3MapKeyVectorIntPtr>("I3MapKeyVectorInt")
    .def(dataclass_suite<I3MapKeyVectorInt >())
    ;
  register_pointer_conversions<I3MapKeyVectorInt>();
  
  class_<I3MapKeyDouble, bases<I3FrameObject>, I3MapKeyDoublePtr>("I3MapKeyDouble")
    .def(dataclass_suite<I3MapKeyDouble >())
    ;
  register_pointer_conversions<I3MapKeyDouble>();

}

