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

void I3Time::SetDaqTime(int year, 
			long long int daqTime)
{
  year_ = year;
  daqTime_ = daqTime;
}

void I3Time::SetJulianTime(unsigned int julianDay,
			   unsigned int sec,
			   double ns)
{
  SetModJulianTime(julianDay  - 240000, sec - 12*3600,ns);
}

void I3Time::SetModJulianTime(unsigned int modJulianDay,
			      unsigned int sec,
			      double ns)
{
  double modjulian = ((double)modJulianDay) + (((double)sec)/(3600. * 24));
  year_ = yearOf(modjulian);
  double daysafteryear = modjulian - modjulianday(year_);
  double secsafteryear = daysafteryear * 3600. * 24.;
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

unsigned int I3Time::GetJulianDay() const
{
  return (unsigned int)julianday(year_,daqTime_);
}

unsigned int I3Time::GetJulianSec() const
{
  double jul = julianday(year_,daqTime_);
  double fract_of_day = jul - ((unsigned int)jul);
  return (unsigned int)(fract_of_day * 3600. * 24.);
}

double I3Time::GetJulianNanoSec() const
{
  long long daqtenthsns = daqTime_ %((long long)1e10);
  return 0.1 * daqtenthsns;
}

unsigned int I3Time::GetModJulianDay() const
{
  return (unsigned int)modjulianday(year_,daqTime_);
}

unsigned int I3Time::GetModJulianSec() const
{
  double modjul = modjulianday(year_,daqTime_);
  double fract_of_day = modjul - ((unsigned int)modjul);
  return (unsigned int)(fract_of_day * 3600. * 24.);
}

double I3Time::GetModJulianNanoSec() const
{
  long long daqtenthsns = daqTime_ %((long long)1e10);
  return 0.1 * daqtenthsns;
}

I3Time::Month I3Time::GetUTCMonth() const
{
  return BadMonth;
}

I3Time::Weekday I3Time::GetUTCWeekday() const
{
  return BadWeekday;
}

unsigned int I3Time::GetUTCDayOfMonth() const
{
  return 0;
}

unsigned int I3Time::GetUTCSec() const
{
  return 0;
}

double I3Time::GetUTCNanoSec() const
{
  long long daqtenthsns = daqTime_ %((long long)1e10);
  return 0.1 * daqtenthsns;
}

std::string I3Time::MonthToString(Month m)
{
  return "";
}

std::string I3Time::WeekdayToString(Weekday w)
{
  return "";
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
  return JulDate(&i) - 240000.5;
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
  double julianDay = modjulianday + 240000.5;
  UTinstant i;
  i.j_date = julianDay;
  CalDate(&i);
  return i.year;
}
