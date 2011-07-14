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

std::string dump(const I3Position &p){
  std::ostringstream s;
  s << "I3Position(" << p.GetX() << "," <<p.GetY() << "," << p.GetZ() << ")";
  return s.str();
}

tuple i3position_to_tuple(const I3Position& p)
{
  return make_tuple(p.GetX(), p.GetY(), p.GetZ());
}

unsigned i3position_len(const I3Position&) { return 3; }

double i3position_getitem(const I3Position& self, unsigned index) 
{ 
  switch(index)
    {
    case 0:
      return self.GetX();
    case 1:
      return self.GetY();
    case 2:
      return self.GetZ();
    default:
      throw std::out_of_range("index out of range");
    }
}

void i3position_setitem(I3Position& self, unsigned index, double value) 
{ 
  switch(index)
    {
    case 0:
      self.SetX(value);
    case 1:
      self.SetY(value);
    case 2:
      self.SetZ(value);
    default:
      throw std::out_of_range("index out of range");
    }
}

void register_I3Position()
{

  def("i3position_to_tuple", i3position_to_tuple);

  scope position_scope = 
    class_<I3Position, bases<I3FrameObject>, boost::shared_ptr<I3Position> >
    ("I3Position",
     "I3Position objects can subscripted like 5-element arrays (x, y, z, theta, phi) and converted to tuples and lists")
    .def(init<double,double,double>())
    .def(init<double,double,double,I3Position::RefFrame>())
    PROPERTY(I3Position, X, X)
    PROPERTY(I3Position, Y, Y)
    PROPERTY(I3Position, Z, Z)
    .add_property("R", &I3Position::GetR)
    .add_property("Theta", &I3Position::GetTheta)
    .add_property("Phi", &I3Position::GetPhi)
    .add_property("Rho", &I3Position::GetRho)
    .def("ShiftCoordSystem", &I3Position::ShiftCoordSystem)
    .def("RotateX", &I3Position::RotateX)
    .def("RotateY", &I3Position::RotateY)
    .def("RotateZ", &I3Position::RotateZ)
    .def("CalcDistance", &I3Position::CalcDistance)
    .def("__str__", dump)
    .def("__len__", i3position_len)
    .def("__getitem__", i3position_getitem)
    .def("__setitem__", i3position_setitem)
    ;

  enum_<I3Position::RefFrame>("RefFrame")
    .value("car",I3Position::car)
    .value("sph",I3Position::sph)
    .value("cyl",I3Position::cyl)
    .export_values()
    ;

  register_pointer_conversions<I3Position>();

  implicitly_convertible<I3Position, tuple>();
  
}
