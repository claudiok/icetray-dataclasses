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
#include <icetray/python/stream_to_string.hpp>
#include <dataclasses/ostream_overloads.hpp>


using namespace boost::python;

#if PY_VERSION_HEX >= 0x02040000
#define HAVE_PYDATETIME_API
#endif

std::string repr(I3Time t){
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


void set_unix_time_default(I3Time& t, time_t ut){
  t.SetUnixTime(ut);
}

int32_t  (*fx1)(double) = &I3Time::DayOfYear;
int32_t  (*fx2)(int64_t) = &I3Time::DayOfYear;
double   (*fx3)(int) = &I3Time::modjulianday;
double   (*fx4)(int, int64_t) = &I3Time::modjulianday;
double   (*fx5)(int) = &I3Time::julianday;
double   (*fx6)(int, int64_t) = &I3Time::modjulianday;

// MonthToString, WeekdayToString are better done in pythonia

void register_I3Time()
{
#ifdef HAVE_PYDATETIME_API
  PyDateTime_IMPORT;

  def("make_I3Time",&GetI3Time);
#endif
  def("day_of_year",fx1,"I3Time::DayOfYear(double modjulianday)");
  def("day_of_year",fx2,"I3Time::DayOfYear(int64_t daqTime)");
  def("modjulianday", fx3,"I3Time::modjulianday(int year)");
  def("modjulianday", fx4,"I3Time::modjulianday(int year, int64_t daqTime)");
  def("julianday", fx5,"I3Time::julianday(int year)");
  def("julianday", fx6,"I3Time::julianday(int year, int64_t daqTime)");
  def("year_of",&I3Time::yearOf,"I3Time::yearOf(double modjulianday)");

  scope i3time_scope = class_<I3Time, bases<I3FrameObject>, 
    boost::shared_ptr<I3Time> >("I3Time")
    .def(init<int32_t,int64_t>())
    .def(init<const I3Time&>())
    #define DEFS (SetModJulianTime)(SetUTCCalDate)(SetUnixTime)(SetDaqTime)
    BOOST_PP_SEQ_FOR_EACH(WRAP_DEF_RECASE, I3Time, DEFS)
    #undef  DEFS
    .add_property("unix_time", &I3Time::GetUnixTime, set_unix_time_default)
#ifdef HAVE_PYDATETIME_API
    .add_property("date_time", &GetDateTime)
#endif
#define RO_PROPS (ModJulianDay)(ModJulianSec)(ModJulianNanoSec)(ModJulianDayDouble)(UTCYear)(UTCMonth)(UTCDaqTime)(UTCSec)(UTCNanoSec)
    BOOST_PP_SEQ_FOR_EACH(WRAP_PROP_RO, I3Time, RO_PROPS)
    #undef  RO_PROPS
    .def("__str__",&stream_to_string<I3Time>)
    .def("__repr__",&repr)
    .def(self == self)
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
