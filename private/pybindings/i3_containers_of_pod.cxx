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

using namespace boost::python;
using std::vector;

void register_i3_containers_of_pod()
{
  class_<I3Vector<int>, bases<I3FrameObject>, boost::shared_ptr<I3Vector<int> > >("I3Vector_int")
    .def(vector_indexing_suite<I3Vector<int> >())
    .def("__str__", &vector_str<I3Vector<int> >);

  class_<I3MapStringDouble, bases<I3FrameObject>, I3MapStringDoublePtr>("I3MapStringDouble")
    .def(map_indexing_suite<I3MapStringDouble >())
    ;
}

