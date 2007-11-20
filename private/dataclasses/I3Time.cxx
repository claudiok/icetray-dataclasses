#include <dataclasses/jday.h>

#include <icetray/serialization.h>
#include <dataclasses/I3Time.h>
#include <dataclasses/I3Units.h>

/**
 *Returns true if year is a leap year.
 *Meaning if is divisible by 4 and is NOT a century
 *year and in that case must be divisible by 400
 */
bool I3TimeUtils::leap_year(const int year){
  return ((!(year%4)&&(year%100)) || //divisible by four and not a century year
	   (!(year%400)&&!(year%100))); //a century year and divisible by four hundred
}

int64_t I3TimeUtils::max_DAQ_time(const int year){
  if(I3TimeUtils::leap_year(year)){
    return MAX_DAQTIME.first; 
  }else{
    return MAX_DAQTIME.second;
  }
}

int64_t I3TimeUtils::ns_to_daqtime( const double time){
  //the addition of 0.5 effectively rounds
  return static_cast<int64_t>((10.*time/I3Units::ns)+ 0.5); 
}

I3Time::I3Time()
{
  year_ = 0;
  daqTime_ = 0;
}

I3Time::~I3Time() {}

I3Time::I3Time(int32_t year, int64_t daqTime) : year_(year),daqTime_(daqTime) {}

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
  double modjulian = ((double)modJulianDay) + (((double)sec)/(3600. * 24.));
  year_ = yearOf(modjulian);
  int32_t daysafteryear = (int32_t)(modjulian - modjulianday(year_));
  int32_t secsafteryear = daysafteryear * 3600 * 24 + sec;
  daqTime_ =
    ((int64_t)secsafteryear * ((int64_t)(1e10)))
    + ((int64_t)(ns * 10.));
}

void I3Time::SetUnixTime(time_t unixTime)
{
  if(unixTime < 0) log_fatal("invalid Unix time");
  SetModJulianTime(unixTime / 86400 + 40587, unixTime % 86400, 0);
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
  //new_years should always be one or zero
  bool new_years_eve = (I3TimeUtils::ns_to_daqtime(second_term) + daqTime_) > I3TimeUtils::max_DAQ_time(year_);
  int32_t year = year_ + static_cast<int>(new_years_eve);

  int64_t daqTime;
  if(new_years_eve){
    //just the remainder
    daqTime = daqTime_ + I3TimeUtils::ns_to_daqtime(second_term) - I3TimeUtils::max_DAQ_time(year_);
  }else{
    //just add 'em
    daqTime = daqTime_ + I3TimeUtils::ns_to_daqtime(second_term);
  }

  return I3Time(year,daqTime);
}

I3Time I3Time::operator-(const double second_term) const
{
  //new_years_eve should always be one or zero
  bool new_years_eve = I3TimeUtils::ns_to_daqtime(second_term) > daqTime_; 
  int32_t year = year_ - static_cast<int>(new_years_eve);

  int64_t daqTime;
  if(new_years_eve){
    //just the remainder
    //What I care about in subtraction is whether *last* year was a leap year
    daqTime = daqTime_ - I3TimeUtils::ns_to_daqtime(second_term) + I3TimeUtils::max_DAQ_time(year);
  }else{
    //just subtract 'em
    daqTime = daqTime_ - I3TimeUtils::ns_to_daqtime(second_term);
  }

  return I3Time(year,daqTime);
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
