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

#include <dataclasses/I3Time.h>

using namespace boost::python;

string dump(I3Time t){
  return t.GetUTCString();
}

string repr(I3Time t){
  std::stringstream out;
  out <<  "I3Time(" << t.GetUTCYear() << "," << t.GetUTCDaqTime() << ")";
  return out.str();
}


void register_I3Time()
{

  scope i3time_scope = class_<I3Time, bases<I3FrameObject>, boost::shared_ptr<I3Time> >("I3Time")
    .def(init<int32_t,int64_t>())
    .def("GetModJulianDay", &I3Time::GetModJulianDay)
    .def("GetModJulianSec", &I3Time::GetModJulianSec)
    .def("GetModJulianNanoSec", &I3Time::GetModJulianNanoSec)
    .def("SetModJulianTime", &I3Time::SetModJulianTime)
    .def("SetUTCCalDate",&I3Time::SetUTCCalDate)
    .def("GetUTCYear", &I3Time::GetUTCYear)
    .def("GetUTCMonth", &I3Time::GetUTCMonth)
    .def("GetUTCMonth", &I3Time::GetUTCMonth)
    .def("GetUTCDaqTime", &I3Time::GetUTCDaqTime)
    .def("GetUTCString", &I3Time::GetUTCString)
    .def("GetUTCString",&dump)
    .def("GetUnixTime", &I3Time::GetUnixTime)
    .def("SetUnixTime", &I3Time::SetUnixTime)
    .def("SetDaqTime", &I3Time::SetDaqTime)
    .def("__str__",&dump)
    .def("__repr__",&repr)
    .def(self-self)
    .def(self-double())
    .def(self+double())
    .def(self<self)
    .def(self>self)
    .def(self<=self)
    .def(self>=self)
    ;

  register_pointer_conversions<I3Time>();
  
  enum_<I3Time::Month>("Month")
    .value("Jan", I3Time::Jan)
    .value("Feb", I3Time::Feb)
    .value("Mar", I3Time::Mar)
    .value("Apr", I3Time::Apr)
    .value("May", I3Time::May)
    .value("Jun", I3Time::Jun)
    .value("Jul", I3Time::Jul)
    .value("Aug", I3Time::Aug)
    .value("Sep", I3Time::Sep)
    .value("Oct", I3Time::Oct)
    .value("Nov", I3Time::Nov)
    .value("Dec", I3Time::Dec)
    .value("BadMonth", I3Time::BadMonth)
    ;

  enum_<I3Time::Weekday>("Weekday")
    .value("Sunday", I3Time::Sunday)
    .value("Monday", I3Time::Monday)
    .value("Tuesday", I3Time::Tuesday)
    .value("Wednesday", I3Time::Wednesday)
    .value("Thursday", I3Time::Thursday)
    .value("Friday", I3Time::Friday)
    .value("Saturday", I3Time::Saturday)
    .value("BadWeekday", I3Time::BadWeekday)
    ;
}
