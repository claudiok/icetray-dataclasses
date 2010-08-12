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

// this pragma has to go before any functions or whatever are defined.
#pragma GCC diagnostic ignored "-Wwrite-strings"

#include <vector>

#include <dataclasses/I3Time.h>
#include <Python.h>
#include <datetime.h>

using namespace boost::python;

#if PY_VERSION_HEX >= 0x02040000
#define HAVE_PYDATETIME_API
#endif

string dump(I3Time t){
  double ns=t.GetModJulianNanoSec();
  stringstream s;
  s << t.GetUTCString("%Y-%m-%d %H:%M:%S.");
  s << setw(3) << setfill('0') << int(ns/1e6) << ',';
  s << setw(3) << setfill('0') << int(ns/1e3)%1000 << ',';
  s << setw(3) << setfill('0') << int(ns)%1000 << ',';
  s << uint64_t(ns*10)%10 << " UTC";
  return s.str();
}

string repr(I3Time t){
  std::stringstream out;
  out <<  "I3Time(" << t.GetUTCYear() << "," << t.GetUTCDaqTime() << ")";
  return out.str();
}

#ifdef HAVE_PYDATETIME_API
boost::python::object GetDateTime(const I3Time& t)
{
  PyObject* obj = PyDateTime_FromDateAndTime(t.GetUTCYear(), 
					     t.GetUTCMonth(), 
					     t.GetUTCDayOfMonth(),
					     t.GetModJulianSec()/3600,
					     t.GetModJulianSec()%3600/60,
					     t.GetModJulianSec()%60,
					     int(t.GetModJulianNanoSec()/1000+0.5)//round to nearest microsecond
					     );
  handle<> h(obj);
  boost::python::object o(h);
  return o;
}

I3Time GetI3Time(const boost::python::object& datetime_obj)
{
  I3Time t;
  PyObject* datetime = datetime_obj.ptr();

  //datetime is a subclass of date so check for that before date
  if (PyDateTime_Check(datetime))
    {
      t.SetUTCCalDate(PyDateTime_GET_YEAR(datetime),
		      PyDateTime_GET_MONTH(datetime),
		      PyDateTime_GET_DAY(datetime),
		      PyDateTime_DATE_GET_HOUR(datetime),
		      PyDateTime_DATE_GET_MINUTE(datetime),
		      PyDateTime_DATE_GET_SECOND(datetime),
		      PyDateTime_DATE_GET_MICROSECOND(datetime)*1e3
		      );
    }
  else if (PyDate_Check(datetime))
    {
      t.SetUTCCalDate(PyDateTime_GET_YEAR(datetime),
		      PyDateTime_GET_MONTH(datetime),
		      PyDateTime_GET_DAY(datetime),
		      0,0,0,0);
    }
  else
    {
      PyErr_SetString(PyExc_TypeError, "Argument for GetI3Time must be of type datetime.datetime or datetime.date");
      throw_error_already_set();
    }
  return t;
}
#endif


void register_I3Time()
{
#ifdef HAVE_PYDATETIME_API
  PyDateTime_IMPORT;

  def("make_I3Time",&GetI3Time);
#endif

  scope i3time_scope = class_<I3Time, bases<I3FrameObject>, 
    boost::shared_ptr<I3Time> >("I3Time")
    .def(init<int32_t,int64_t>())
    .def(init<const I3Time&>())
    .def("GetModJulianDay", &I3Time::GetModJulianDay)
    .def("GetModJulianSec", &I3Time::GetModJulianSec)
    .def("GetModJulianNanoSec", &I3Time::GetModJulianNanoSec)
    .def("GetModJulianDayDouble", &I3Time::GetModJulianDayDouble)
    .def("SetModJulianTime", &I3Time::SetModJulianTime)
    .def("SetUTCCalDate",&I3Time::SetUTCCalDate)
    .def("GetUTCYear", &I3Time::GetUTCYear)
    .def("GetUTCMonth", &I3Time::GetUTCMonth)
    .def("GetUTCDaqTime", &I3Time::GetUTCDaqTime)
    .def("GetUTCString", &I3Time::GetUTCString)
    .def("GetUTCString",&dump)
    .def("GetUnixTime", &I3Time::GetUnixTime)
    .def("SetUnixTime", &I3Time::SetUnixTime)
    .def("SetDaqTime", &I3Time::SetDaqTime)
#ifdef HAVE_PYDATETIME_API
    .def("GetDateTime", &GetDateTime)
#endif
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
    .export_values()
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
    .export_values()
    ;
}
