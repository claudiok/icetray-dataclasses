extern "C"
{
#include "dataclasses/jday.h"
}

#include "dataclasses/I3Time.h"

#include <iostream>
#include <cassert>

using std::cout;
using std::endl;

UTinstant UTinstantiate(unsigned int julian,unsigned int sec)
{
  UTinstant to_return;
  to_return.j_date = 
    (double)julian + 
    (double)sec / (3600. * 24.);
  CalDate(&to_return);
  return to_return;
}

UTinstant UTinstantiate(const I3Time& time)
{
  UTinstant to_return;
  to_return.j_date = 
    (double)time.GetJulianDay() + 
    (double)time.GetJulianSec() / (3600. * 24.);
  CalDate(&to_return);
  return to_return;
}

I3Time::I3Time()
{
  year_ = 0;
  daqTime_ = 0;
}

// I3Time::I3Time(int year,
// 	       long long int daqTime)
// {
//   SetDaqTime(year,daqTime);


// }

// I3Time::I3Time(unsigned int julianDay,
// 	       unsigned int sec,
// 	       double ns) : 
//   julianDay_(julianDay),
//   sec_(sec),
//   ns_(ns)
// {
// }

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
  JulianTime jul;
  jul.day = julianDay;
  jul.sec = sec;
  jul.ns = ns;
  DaqTime daq = Julian2Daq(jul);
  year_ = daq.year;
  daqTime_ = daq.time;
}

void I3Time::SetModJulianTime(unsigned int modJulianDay,
			      unsigned int sec,
			      double ns)
{
#warning "Yet to be implemented"
  //   if(sec < 60 * 60 * 12)
  //     {
  //       julianDay_ = modJulianDay + 2400000;
  //       sec_ = sec + 60 * 60 * 12;
  //     }
  //   else
  //     {
  //       julianDay_ = modJulianDay + 2400000;
  //       sec_ = sec - 60 * 60 * 12;
  //     }
  //   ns_ = ns;
  
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
  DaqTime t;
  t.time = daqTime_;
  t.year = year_;
  JulianTime jul = Daq2Julian(t);
  return jul.day;
}

unsigned int I3Time::GetJulianSec() const
{
  DaqTime t;
  t.time = daqTime_;
  t.year = year_;
  JulianTime jul = Daq2Julian(t);
  return jul.sec;
}

double I3Time::GetJulianNanoSec() const
{
  DaqTime t;
  t.time = daqTime_;
  t.year = year_;
  JulianTime jul = Daq2Julian(t);
  return jul.ns;
}

unsigned int I3Time::GetModJulianDay() const
{
#warning "Yet to be implemented"
  //   if(sec_ > 60 * 60 * 12)
  //     return julianDay_ - 2400000;
  //   else
  //     return julianDay_ - 2400001;
}

unsigned int I3Time::GetModJulianSec() const
{
#warning "Yet to be implemented"
  //   if(sec_ < 60 * 60 * 12)
  //     return sec_ + 60 * 60 * 12;
  //   else
  //     return sec_ - 60 * 60 * 12;
}

double I3Time::GetModJulianNanoSec() const
{
#warning "Yet to be implemented"
  //   return ns_;
}

I3Time::Month I3Time::GetUTCMonth() const
{
  UTinstant thisInstant = UTinstantiate(*this);
  switch(thisInstant.month)
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
  UTinstant thisInstant = UTinstantiate(*this);
  switch(thisInstant.weekday)
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
  UTinstant thisInstant = UTinstantiate(*this);
  return thisInstant.day;
}

unsigned int I3Time::GetUTCSec() const
{
  long long thetime = daqTime_;
  thetime%=(24*3600*(long long)1.e10);
  return thetime/((long long)1.e10);
}

double I3Time::GetUTCNanoSec() const
{
  long long thetime = daqTime_;
  thetime%=(24*3600*(long long)1.e10);
  thetime%=((long long)1.e10);
  return thetime/((long long)10);
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

I3Time::JulianTime I3Time::Daq2Julian(DaqTime t)
{
  JulianTime to_return;

  // This is from Dima.  Thanks.
  long long h_day, h_sec, h_ns;
  
  h_day=t.time/(24*3600*(long long)1.e10);
  t.time%=(24*3600*(long long)1.e10);
  h_sec=t.time/((long long)1.e10);
  t.time%=((long long)1.e10);
  h_ns=t.time/((long long)10);
  t.time%=((long long)10);
  
  UTinstant startOfYear;
  startOfYear.year = t.year;
  startOfYear.month=1;
  startOfYear.day=1;
  startOfYear.i_hour=0;
  startOfYear.i_minute=0;
  startOfYear.second=0;
  
  double julianStartOfYear = JulDate(&startOfYear);
  
  UTinstant thisInstant;
  thisInstant.j_date = 
    julianStartOfYear + (double)h_day + (double) h_sec/(60. *60. * 24.);
  // printf("calculated julian date for this time: %0.8f\n",instant_.j_date);
  //  CalDate(&instant_);
  
  to_return.day = (unsigned int)thisInstant.j_date;
  
  assert(h_sec <= 60 * 60 * 24);
  
  // adjusting for the fact that Julian days start at noon
  if(h_sec < 60 * 60 * 12)
    h_sec += 60 * 60 * 12;
  else
    h_sec -= 60 * 60 * 12;
  
  to_return.sec = h_sec;
  to_return.ns = h_ns;  

  return to_return;
}

I3Time::DaqTime I3Time::Julian2Daq(JulianTime t)
{
  UTinstant thisInstant = UTinstantiate(t.day,t.sec);

  long long int daqTime =  (long long int)t.ns * 10;
  daqTime += (long long int)1e10 * t.sec;
  daqTime += 
    (long long int) 3600 * 
    (long long int)24 * 
    (long long)1e10 * 
    (long long)thisInstant.day_of_year;
  unsigned int year = thisInstant.year;

  DaqTime to_return;
  to_return.year = year;
  to_return.time = daqTime;
  
  return to_return;  
}
