#include <string>
#include <dataclasses/jday.h>

#include <icetray/serialization.h>
#include <dataclasses/I3Time.h>
#include <icetray/I3Units.h>

/**
 *Returns true if year is a leap year.
 *Meaning if is divisible by 4 and is NOT a century
 *year and in that case must be divisible by 400
 */
bool I3TimeUtils::leap_year(const int year){
  return ((!(year%4)&&(year%100)) || //divisible by four and not a century year
	   (!(year%400)&&!(year%100))); //a century year and divisible by four hundred
}

//Figure out the right length of a year.  Is it a leap year?
//  MAX_DAQTIME pair has run lengths:
//    first: normal year
//    second:  leap year
int64_t I3TimeUtils::max_DAQ_time(const int year){
  if(I3TimeUtils::leap_year(year)){
    return MAX_DAQTIME.second; 
  }else{  //NOT leap year
    return MAX_DAQTIME.first;
  }
}

int64_t I3TimeUtils::ns_to_daqtime( const double time){
  //the addition of 0.5 effectively rounds
  return static_cast<int64_t>((10.*time/I3Units::ns)+ 0.5); 
}

const char* I3Time::DRIVING_TIME = "DrivingTime";

I3Time::I3Time()
{
  year_ = 0;
  daqTime_ = 0;
}

I3Time::~I3Time() {}

I3Time::I3Time(int32_t year, int64_t daqTime) : year_(year),daqTime_(daqTime) {}

I3Time::I3Time(double mjd) {
  if (isnan(mjd)) {
    log_error("Constructing with NAN not possible; will use std constructor");
    year_=0;
    daqTime_=0;
  }
  int32_t modJulianDay = (int32_t)mjd;
  int32_t sec = (int32_t)((mjd-modJulianDay)*86400);
  double ns = (double)((((mjd-modJulianDay)*86400)-sec)*1e9);
  SetModJulianTime(modJulianDay, sec, ns);
}

void I3Time::SetDaqTime(int year, 
                        int64_t daqTime)
{
  year_ = year;
  daqTime_ = daqTime;
}

void I3Time::SetModJulianTime(int32_t modJulianDay,
                              int32_t sec,
                              double ns)
{
  // Add a check, and log_warn about secs more than year length...
  //double modjulian = ((double)modJulianDay) + (((double)sec)/(3600. * 24.));
  year_ = yearOf(modJulianDay);
  //int32_t daysafteryear = (int32_t)(modjulian - modjulianday(year_));
  int32_t daysafteryear = modJulianDay - (int32_t)modjulianday(year_);
  int32_t secsafteryear = daysafteryear * 3600 * 24 + sec;
  daqTime_ =
    ((int64_t)secsafteryear * ((int64_t)(1e10)))
    + ((int64_t)(ns * 10.));
}

void I3Time::SetModJulianTimeDouble(double mjd) {
  if (isnan(mjd)) {
    log_error("Calling with NAN not possible; will do nothing");
    return;
  }
  int32_t modJulianDay = (int32_t)mjd;
  int32_t sec = (int32_t)((mjd-modJulianDay)*86400);
  double ns = (double)((((mjd-modJulianDay)*86400)-sec)*1e9);
  SetModJulianTime(modJulianDay, sec, ns);
}

void I3Time::SetUTCCalDate(int year, int month, int day, int hour, int minute, int sec, double ns)
{
    int daysOfMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31}; 
    if(I3TimeUtils::leap_year(year)) daysOfMonth[1] = 29;
    
    if(month<1 || month>12)
    {
        log_error("Invalid month!");
        return;
    }

    if(day<1 || day>daysOfMonth[month-1])
    {
        log_error("Invalid day!");
        return;
    }
    
    if(hour<0 || hour>23)
    {
        log_error("Invalid hour!");
        return;
    }

    if(minute<0 || minute>59)
    {
        log_error("Invalid minute!");
        return;
    }

    if(sec<0 || sec>59)
    {
        log_error("Invalid second!");
        return;
    }
    
    if(ns<0 || ns>=1e9)
    {
        log_error("Invalid nanosecond!");
        return;
    }
    
    UTinstant i;
    i.year     = year;
    i.month    = month;
    i.day      = day;
    i.i_hour   = 0;
    i.i_minute = 0;
    i.second   = 0;
    
    int32_t modJulDay = (int32_t)(JulDate(&i) - 2400000.5);
    int32_t second = (int32_t)(hour*3600 + minute*60 + sec);
    
    SetModJulianTime(modJulDay, second, ns);
}

void I3Time::SetUnixTime(time_t unixTime,double ns)
{
  if(unixTime < 0) log_fatal("invalid Unix time");
  SetModJulianTime(unixTime / 86400 + 40587, unixTime % 86400, ns);
}

time_t I3Time::GetUnixTime() const
{
  return (GetModJulianDay()-40587)*86400+GetModJulianSec();
}

int I3Time::GetUTCYear() const
{
  return year_;
}

int64_t I3Time::GetUTCDaqTime() const
{
  return daqTime_;
}

int32_t I3Time::GetModJulianDay() const
{
  return (int32_t)modjulianday(year_,daqTime_);
}

int32_t I3Time::GetModJulianSec() const
{
  int32_t daysafteryear = 
    (int32_t)(modjulianday(year_,daqTime_) - modjulianday(year_));
  int32_t secsafteryear = 
    (daqTime_ - daqTime_%((int64_t)(1e10)))/((int64_t)1e10);
  return secsafteryear - daysafteryear * 3600 * 24 ;
}

double I3Time::GetModJulianNanoSec() const
{
  int64_t daqtenthsns = daqTime_ %((int64_t)1e10);
  return 0.1 * daqtenthsns;
}

double I3Time::GetModJulianDayDouble() const
{
  return GetModJulianDay() + GetModJulianSec()/86400. + GetModJulianNanoSec()/8.64e13;
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

int32_t I3Time::GetUTCDayOfMonth() const
{
  double julday = julianday(year_,daqTime_);
  UTinstant i;
  i.j_date = julday;
  CalDate(&i);
  return i.day;
}

int32_t I3Time::GetUTCSec() const
{
  int64_t tenthsOfNs = daqTime_ %((int64_t)1e10);
  int32_t daqSecs = (daqTime_ - tenthsOfNs)/((int64_t)1e10);
  return daqSecs;
}

double I3Time::GetUTCNanoSec() const
{
  int64_t daqtenthsns = daqTime_ %((int64_t)1e10);
  return 0.1 * daqtenthsns;
}

std::string I3Time::GetUTCString(std::string format)const
{
  time_t t=GetUnixTime();
  struct tm *tm=gmtime(&t);
  char datestring[256];
  strftime (datestring, sizeof(datestring), format.c_str(), tm);
  return datestring;
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

I3Time I3Time::operator+(const double second_term) const
{

  int64_t daqTime;
  int32_t year;
  if((I3TimeUtils::ns_to_daqtime(second_term) + daqTime_) > I3TimeUtils::max_DAQ_time(year_) ){
    year = year_ + 1;
    //just the remainder
    daqTime = daqTime_ + I3TimeUtils::ns_to_daqtime(second_term) - I3TimeUtils::max_DAQ_time(year_);
  }
  else{
    year = year_;
    daqTime = daqTime_ + I3TimeUtils::ns_to_daqtime(second_term);
  }

  return I3Time(year,daqTime);
}


I3Time I3Time::operator-(const double second_term) const
{
  int64_t daqTime;
  int32_t year;
  if(I3TimeUtils::ns_to_daqtime(second_term) > daqTime_){
    year = year_ - 1;
    //just the remainder
    //What I care about in subtraction is whether *last* year was a leap year
    daqTime = daqTime_ - I3TimeUtils::ns_to_daqtime(second_term) + I3TimeUtils::max_DAQ_time(year);
  }
  else{
    year = year_;
    //just subtract 'em
    daqTime = daqTime_ - I3TimeUtils::ns_to_daqtime(second_term);
  }

  return I3Time(year,daqTime);
}

double operator-(const I3Time t1,const I3Time t2) 
{
  return 
    ( t1.GetModJulianNanoSec() - t2.GetModJulianNanoSec() ) * I3Units::nanosecond +
    ( t1.GetModJulianSec()     - t2.GetModJulianSec()     ) * I3Units::second +
    ( t1.GetModJulianDay()     - t2.GetModJulianDay()     ) * I3Units::day;
}

std::ostream& operator<<(std::ostream& oss, const I3Time& t){
  double ns=t.GetModJulianNanoSec();
  oss << t.GetUTCString("%Y-%m-%d %H:%M:%S.");
  oss << std::setw(3) << std::setfill('0') << int(ns/1e6) << ',';
  oss << std::setw(3) << std::setfill('0') << int(ns/1e3)%1000 << ',';
  oss << std::setw(3) << std::setfill('0') << int(ns)%1000 << ',';
  oss << uint64_t(ns*10)%10 << " UTC";

  return oss;
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

double I3Time::modjulianday(int year, int64_t daqTime)
{
  int64_t tenthsOfNs = daqTime %((int64_t)1e10);
  int64_t daqSecs = (daqTime - tenthsOfNs)/((int64_t)1e10);
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

double I3Time::julianday(int year, int64_t daqTime)
{
  int64_t tenthsOfNs = daqTime %((int64_t)1e10);
  int64_t daqSecs = (daqTime - tenthsOfNs)/((int64_t)1e10);
  double daqDaysSinceYear = ((double)(daqSecs))/(3600. * 24.);
  double julian_of_year = julianday(year);
  return julian_of_year + daqDaysSinceYear;
  
}

int32_t I3Time::yearOf(double modjulianday)
{
  double julianDay = modjulianday + 2400000.5;
  UTinstant i;
  i.j_date = julianDay;
  CalDate(&i);
  return i.year;
}

int32_t I3Time::DayOfYear(double modjulianday)
{
  UTinstant i;
  double julianDay = modjulianday + 2400000.5;
  i.j_date = julianDay;
  CalDate(&i);
  
  return i.day_of_year;
}

int32_t I3Time::DayOfYear(int64_t daqTime)
{
  int64_t tenthsOfNs = daqTime %((int64_t)1e10);
  int64_t daqSecs = (daqTime - tenthsOfNs)/((int64_t)1e10);
  int64_t daqSecsSinceDay = daqSecs % ((int64_t)(3600 * 24));
  int32_t day_of_year = (daqSecs - daqSecsSinceDay)/(3600 * 24) + 1;
  
  return day_of_year; 
}

template <class Archive>
void 
I3Time::serialize(Archive& ar, unsigned version)
{
  if (version>i3time_version_)
    log_fatal("Attempting to read version %u from file but running version %u of I3Time class.",version,i3time_version_);

  ar & make_nvp("I3FrameObject", base_object<I3FrameObject>(*this));
  ar & make_nvp("Year", year_);
  ar & make_nvp("DaqTime", daqTime_);
}

I3_SERIALIZABLE(I3Time);
