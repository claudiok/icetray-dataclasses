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

using namespace boost::python;

void register_I3Direction()
{

  void (I3Direction::* oneary)(const I3Direction&) = &I3Direction::SetDirection;
  void (I3Direction::* twoary)(double, double) = &I3Direction::SetDirection;
  void (I3Direction::* threeary)(double, double, double) = &I3Direction::SetDirection;

  class_<I3Direction, bases<I3FrameObject>, boost::shared_ptr<I3Direction> >("I3Direction")
    .def(init<double,double>())
    .def("SetDirection", oneary)
    .def("SetDirection", twoary)
    .def("SetDirection", threeary)
    .def("SetThetaPhi", &I3Direction::SetThetaPhi)
    .def("ResetDirection", &I3Direction::ResetDirection)
    .def("NullDirection", &I3Direction::NullDirection)
    .def("RotateX", &I3Direction::RotateX)
    .def("RotateY", &I3Direction::RotateY)
    .def("RotateZ", &I3Direction::RotateZ)
    .add_property("Zenith", &I3Direction::GetZenith)
    .add_property("Azimuth", &I3Direction::GetAzimuth)
    .add_property("X", &I3Direction::GetX)
    .add_property("Y", &I3Direction::GetY)
    .add_property("Z", &I3Direction::GetZ)
    .add_property("Theta", &I3Direction::CalcTheta)
    .add_property("Phi", &I3Direction::CalcPhi)
    ;
  register_pointer_conversions<I3Direction>();
}
