#include "dataclasses/I3Time.h"

#include <iostream>

using std::cout;
using std::endl;

I3Time::I3Time(int year,
	       long long int daqTime)
{
 long long h_day, h_sec, h_ns;

 // This is from Dima.  Thanks.
 h_day=daqTime/(24*3600*(long long)1.e10);
 daqTime%=(24*3600*(long long)1.e10);
 h_sec=daqTime/((long long)1.e10);
 daqTime%=((long long)1.e10);
 h_ns=daqTime/((long long)10);
 daqTime%=((long long)10);

 UTinstant startOfYear;
 startOfYear.year = year;
 startOfYear.month=1;
 startOfYear.day=1;
 startOfYear.i_hour=0;
 startOfYear.i_minute=0;
 startOfYear.second=0;
 
 double julianStartOfYear = JulDate(&startOfYear);
 // printf("Julian day for the start of year %d %0.8f\n",year,julianStartOfYear);
 // printf("num days since start of year: %d\n",(int)h_day);
 // printf("Fractional part of the day: %f\n",(double) h_sec/(60. * 60. * 24.));

 instant_.j_date = 
   julianStartOfYear + (double)h_day + (double) h_sec/(60. *60. * 24.);
 // printf("calculated julian date for this time: %0.8f\n",instant_.j_date);
 CalDate(&instant_);

 julianDay_ = (unsigned int)instant_.j_date;

 assert(h_sec <= 60 * 60 * 24);

 // adjusting for the fact that Julian days start at noon
 if(h_sec < 60 * 60 * 12)
   h_sec += 60 * 60 * 12;
 else
   h_sec -= 60 * 60 * 12;

 /** wrong */
 sec_ = h_sec;
 ns_ = h_ns;

}

I3Time::I3Time(unsigned int julianDay,
	       unsigned int sec,
	       double ns) : 
  julianDay_(julianDay),
  sec_(sec),
  ns_(ns)
{
  double d_julianday = (double)julianDay_ + (double)sec_/(60. * 60. * 24);
  instant_.j_date = d_julianday;
  CalDate(&instant_);
}

int I3Time::GetUTCYear()
{
  return instant_.year;
}

long long int I3Time::GetUTCDaqTime()
{
  long long int to_return =  (long long int)ns_ * 10;
  
  to_return += (long long int)1e10 * sec_;

  to_return += 
    (long long int) 3600 * 
    (long long int)24 * 
    (long long)1e10 * 
    (long long)instant_.day_of_year;
  
  return to_return;
}

unsigned int I3Time::GetJulianDay()
{
  return julianDay_;
}

unsigned int I3Time::GetJulianSec()
{
  return sec_;
}

double I3Time::GetJulianNanoSec()
{
  return ns_;
}

I3Time::Month I3Time::GetUTCMonth()
{
  switch(instant_.month)
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

I3Time::Weekday I3Time::GetUTCWeekday()
{
  switch(instant_.weekday)
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

unsigned int I3Time::GetUTCDayOfMonth()
{
  return instant_.day;
}

unsigned int I3Time::GetUTCSec()
{
  if(sec_ < 60 * 60 * 12)
    return sec_ + 60 * 60 * 12;
  else
    return sec_ - 60 * 60 * 12;
}

double I3Time::GetUTCNanoSec()
{
  return ns_;
}

std::string I3Time::ToString(Month m)
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

std::string I3Time::ToString(Weekday w)
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
