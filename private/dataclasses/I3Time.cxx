extern "C"
{
#include "dataclasses/jday.h"
}

#include "dataclasses/I3Time.h"

#include <iostream>
#include <cassert>

using std::cout;
using std::endl;

I3Time::I3Time()
{
  year_ = 0;
  daqTime_ = 0;
}

I3Time::I3Time(unsigned int year, long long daqTime) : year_(year),daqTime_(daqTime)
{
}

void I3Time::SetDaqTime(int year, 
			long long int daqTime)
{
  year_ = year;
  daqTime_ = daqTime;
}

void I3Time::SetModJulianTime(unsigned int modJulianDay,
			      unsigned int sec,
			      double ns)
{
  double modjulian = ((double)modJulianDay) + (((double)sec)/(3600. * 24.));
  year_ = yearOf(modjulian);
  unsigned int daysafteryear = (unsigned int)(modjulian - modjulianday(year_));
  unsigned int secsafteryear = daysafteryear * 3600 * 24 + sec;
  daqTime_ =
    ((long long int)secsafteryear * ((long long int)(1e10)))
    + ((long long int)ns * ((long long int)10));
}


int I3Time::GetUTCYear() const
{
  return year_;
}

long long int I3Time::GetUTCDaqTime() const
{
  return daqTime_;
}

unsigned int I3Time::GetModJulianDay() const
{
  return (unsigned int)modjulianday(year_,daqTime_);
}

unsigned int I3Time::GetModJulianSec() const
{
  unsigned int daysafteryear = 
    (unsigned int)(modjulianday(year_,daqTime_) - modjulianday(year_));
  unsigned int secsafteryear = 
    (daqTime_ - daqTime_%((long long)(1e10)))/((long long)1e10);
  return secsafteryear - daysafteryear * 3600 * 24 ;
}

double I3Time::GetModJulianNanoSec() const
{
  long long daqtenthsns = daqTime_ %((long long)1e10);
  return 0.1 * daqtenthsns;
}

I3Time::Month I3Time::GetUTCMonth() const
{
  double julday = julianday(year_,daqTime_);
  UTinstant i;
  i.j_date = julday;
  CalDate(&i);
  switch(i.month)
    {
    case 1:
      return Jan;
    case 2:
      return Feb;
    case 3:
      return Mar;
    case 4:
      return Apr;
    case 5:
      return May;
    case 6:
      return Jun;
    case 7:
      return Jul;
    case 8:
      return Aug;
    case 9:
      return Sep;
    case 10:
      return Oct;
    case 11:
      return Nov;
    case 12:
      return Dec;
    default:
      return BadMonth;
    }
}

I3Time::Weekday I3Time::GetUTCWeekday() const
{
  double julday = julianday(year_,daqTime_);
  UTinstant i;
  i.j_date = julday;
  CalDate(&i);
  switch(i.weekday)
    {
    case 0:
      return Sunday;
    case 1:
      return Monday;
    case 2:
      return Tuesday;
    case 3:
      return Wednesday;
    case 4:
      return Thursday;
    case 5:
      return Friday;
    case 6:
      return Saturday;
    default:
      return BadWeekday;
    }

}

unsigned int I3Time::GetUTCDayOfMonth() const
{
  double julday = julianday(year_,daqTime_);
  UTinstant i;
  i.j_date = julday;
  CalDate(&i);
  return i.day;
}

unsigned int I3Time::GetUTCSec() const
{
  long long int tenthsOfNs = daqTime_ %((long long)1e10);
  unsigned int daqSecs = (daqTime_ - tenthsOfNs)/((long long)1e10);
  return daqSecs;
}

double I3Time::GetUTCNanoSec() const
{
  long long daqtenthsns = daqTime_ %((long long)1e10);
  return 0.1 * daqtenthsns;
}

bool I3Time::operator<(const I3Time& rhs) const
{
      if(year_ < rhs.year_)
	return true;
      if(year_ > rhs.year_)
	return false;
      if(daqTime_ < rhs.daqTime_)
	return true;
      return false;
}

bool I3Time::operator>(const I3Time& rhs) const
{
      if(year_ > rhs.year_)
	return true;
      if(year_ < rhs.year_)
	return false;
      if(daqTime_ > rhs.daqTime_)
	return true;
      return false;
}

bool I3Time::operator==(const I3Time& rhs) const
{
  if(year_ == rhs.year_ && daqTime_ == rhs.daqTime_)
    return true;
  return false;
}

bool I3Time::operator<=(const I3Time& rhs) const
{
  if(*this < rhs || *this == rhs)
    return true;
  return false;
}

bool I3Time::operator>=(const I3Time& rhs) const
{
  if(*this > rhs || *this == rhs)
    return true;
  return false;
}

std::string I3Time::MonthToString(Month m)
{
  switch(m)
    {
    case Jan:
      return "Jan";
    case Feb:
      return "Feb";
    case Mar:
      return "Mar";
    case Apr:
      return "Apr";
    case May:
      return "May";
    case Jun:
      return "Jun";
    case Jul:
      return "Jul";
    case Aug:
      return "Aug";
    case Sep:
      return "Sep";
    case Oct:
      return "Oct";
    case Nov:
      return "Nov";
    case Dec:
      return "Dec";
    default:
      return "BadMonth";
    }
}

std::string I3Time::WeekdayToString(Weekday w)
{
  switch(w)
    {
    case Sunday:
      return "Sunday";
    case Monday:
      return "Monday";
    case Tuesday:
      return "Tuesday";
    case Wednesday:
      return "Wednesday";
    case Thursday:
      return "Thursday";
    case Friday:
      return "Friday";
    case Saturday:
      return "Saturday";
    default:
      return "BadWeekday";
    }

}

double I3Time::modjulianday(int year)
{
  UTinstant i;
  i.year = year;
  i.month = 1;
  i.day = 1;
  i.i_hour = 0;
  i.i_minute = 0;
  i.second = 0;
  return JulDate(&i) - 2400000.5;
}

double I3Time::modjulianday(int year, long long int daqTime)
{
  long long int tenthsOfNs = daqTime %((long long)1e10);
  long long int daqSecs = (daqTime - tenthsOfNs)/((long long)1e10);
  double daqDaysSinceYear = ((double)(daqSecs))/(3600. * 24.);
  double modjulian_of_year = modjulianday(year);
  return modjulian_of_year + daqDaysSinceYear;
  
}

double I3Time::julianday(int year)
{
 UTinstant i;
  i.year = year;
  i.month = 1;
  i.day = 1;
  i.i_hour = 0;
  i.i_minute = 0;
  i.second = 0;
  return JulDate(&i);
}

double I3Time::julianday(int year, long long int daqTime)
{
  long long int tenthsOfNs = daqTime %((long long)1e10);
  long long int daqSecs = (daqTime - tenthsOfNs)/((long long)1e10);
  double daqDaysSinceYear = ((double)(daqSecs))/(3600. * 24.);
  double julian_of_year = julianday(year);
  return julian_of_year + daqDaysSinceYear;
  
}

unsigned int I3Time::yearOf(double modjulianday)
{
  double julianDay = modjulianday + 2400000.5;
  UTinstant i;
  i.j_date = julianDay;
  CalDate(&i);
  return i.year;
}
