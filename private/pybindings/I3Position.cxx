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

#include <dataclasses/I3Position.h>

using namespace boost::python;

string dump(I3Position p){
  ostringstream s;
  s << "I3Position(" << p.GetX() << "," <<p.GetY() << "," << p.GetZ() << ")";
  return s.str();
}

void register_I3Position()
{

  class_<I3Position, bases<I3FrameObject>, boost::shared_ptr<I3Position> >("I3Position")
    //.def(init<double,double,double,int>())
    .def(init<double,double,double>())
    PROPERTY(I3Position, X, X)
    PROPERTY(I3Position, Y, Y)
    PROPERTY(I3Position, Z, Z)
    .def("GetR", &I3Position::GetR)
    .def("GetTheta", &I3Position::GetTheta)
    .def("GetPhi", &I3Position::GetPhi)
    .def("GetRho", &I3Position::GetRho)
    .def("ShiftCoordSystem", &I3Position::ShiftCoordSystem)
    .def("RotateX", &I3Position::RotateX)
    .def("RotateY", &I3Position::RotateY)
    .def("RotateZ", &I3Position::RotateZ)
    .def("CalcDistance", &I3Position::CalcDistance)
    .def("__str__",dump)
    ;
  
}
