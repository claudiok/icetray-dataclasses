//
//   Copyright (c) 2004, 2005, 2006, 2007   Troy D. Straszheim  
//   
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

#include <dataclasses/I3Direction.h>
#include <icetray/python/stream_to_string.hpp>
#include <icetray/python/boost_serializable_pickle_suite.hpp>
#include <dataclasses/ostream_overloads.hpp>

using namespace boost::python;

void register_I3Direction()
{

  void (I3Direction::* oneary)(const I3Direction&) = &I3Direction::SetDirection;
  void (I3Direction::* twoary)(float, float) = &I3Direction::SetDirection;
  void (I3Direction::* threeary)(double, double, double) = &I3Direction::SetDirection;

  class_<I3Direction, bases<I3FrameObject>, boost::shared_ptr<I3Direction> >("I3Direction")
    .def(init<float,float>())
    .def(init<double,double,double>())
    .def("set_direction", oneary)
    .def("set_direction", twoary)
    .def("set_direction", threeary)
     #define MEMBERS (SetThetaPhi)(ResetDirection)(NullDirection)(RotateX)(RotateY)(RotateZ)
    BOOST_PP_SEQ_FOR_EACH(WRAP_DEF_RECASE, I3Direction, MEMBERS)
    #undef  MEMBERS
    #define RO_PROPERTIES (Zenith)(Azimuth)(X)(Y)(Z)
    BOOST_PP_SEQ_FOR_EACH(WRAP_PROP_RO, I3Direction, RO_PROPERTIES)
    #undef  RO_PROPERTIES
    .add_property("theta", &I3Direction::CalcTheta)
    .add_property("phi", &I3Direction::CalcPhi)
    .def("__str__", &stream_to_string<I3Direction>)
    .def(self == self)
    .def_pickle(boost_serializable_pickle_suite<I3Direction>())
    .def( freeze() )
    ;
  register_pointer_conversions<I3Direction>();
}
