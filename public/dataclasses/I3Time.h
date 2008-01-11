#ifndef I3TIME_H_INCLUDED
#define I3TIME_H_INCLUDED

#include <string>
#include <time.h>

#include <icetray/I3FrameObject.h>
#include <dataclasses/Utility.h>

/**
 * @brief A class for dealing with global times.  
 *
 * Has methods for setting the time in either the Daq UTC convention or
 * in the Modified Julian convention 
 * 
 * @todo The library I have is using Barycentric Dynamical Time (TDB),
 * which differs from UTC by a number that is a function of year.  UTC has 
 * a leap second every now and then and TDB doesn't Right
 * now they're ~68 seconds different.  May need to account for this.
 * http://jday.sourceforge.net/index.php for reference
 *
 */

//Number of tenths of ns in a year and leap year respectively        
//                         Number of tenths of seconds in a leap year 864000000000000
static const unsigned i3time_version_ = 0;
const std::pair<int64_t,int64_t> MAX_DAQTIME(315569260000000000LL, 316433260000000000LL);

namespace I3TimeUtils
{
  /**
   *Returns true if the year is a leap year
   */
  bool leap_year(const int year);
  
  /**
   *Returns the number of tenths of nanoseconds it the year, depending
   *on whether it's a leap year or not.
   */
  int64_t max_DAQ_time(const int year);
  
  /**
   *Converts a time of type double with I3Units of time (your choice) to
   *the number of tenths of nanoseconds (i.e. "daqtime").  This takes
   *into account rounding.
   */
  int64_t ns_to_daqtime( const double time);
}

class I3Time : public I3FrameObject
{
 public:
  /**
   * @brief enum for the Month
   */
  enum Month
    {
      Jan = 1, 
      Feb = 2, 
      Mar = 3, 
      Apr = 4, 
      May = 5, 
      Jun = 6,
      Jul = 7,
      Aug = 8,
      Sep = 9,
      Oct = 10,
      Nov = 11,
      Dec = 12,
      BadMonth = 999
    };

  /**
   * @brief enum for days of the week
   */
  enum Weekday
    {
      Sunday = 0,
      Monday = 1,
      Tuesday = 2,
      Wednesday = 3,
      Thursday = 4,
      Friday = 5,
      Saturday = 6,
      BadWeekday = 999
    };

  /**
   * @brief default constructor sets the time to year 0, daq UTC time 0.
   * There's no 'nan' for unsigned and long long
   */
  I3Time();

  /**
   * @brief creates the object with the given times as the DAQ time
   */
  I3Time(int32_t year, int64_t daqTime);

  virtual ~I3Time();
	     
  /**
   * @brief Sets the time in the 'daq' style where
   * @param year The year.  Something like 2005.
   * @param daqTime The number of tenths of nanoseconds since the year began
   */  
  void SetDaqTime(int year, int64_t daqTime);
  
  /**
   * @brief Sets the time in the Modified julian convention
   * @param modJulianDay the modified julian day to set
   * @param sec the number of secs after this modified julian day began
   * @param ns the number of ns after this second began.
   */
  void SetModJulianTime(int32_t modJulianDay,
			int32_t sec,
			double ns);

  /**
   * @brief Sets the time in the Unix convention
   * @param unixTime time since the Epoch (00:00:00 UTC, January 1, 1970),
   * measured in seconds
   * @param ns the number of ns after this second began.
   */
  void SetUnixTime(time_t unixTime,double ns=0);

  /**
   * @brief Gets the Modified Julian day
   */
  int32_t GetModJulianDay() const;
  
  /**
   * @brief Gets the number of seconds since this Modified Julian day began
   * @note Modified Julian days begin at midnight
   */
  int32_t GetModJulianSec() const;
  
  /**
   * @brief Gets the number of nanoseconds since this second began
   */
  double GetModJulianNanoSec() const;

  /**
   * @brief Gets the time in Unix convention
   * @returns The number of seconds since the Epoch (00:00:00 UTC, January 1, 1970)
   */
  time_t GetUnixTime() const;

  /**
   * @brief Gets the year in the UTC convention
   */
  int GetUTCYear() const;

  /**
   * @brief Gets the appropriate time for the DAQ.  tenths of nanoseconds
   * since the start of the UTC year.
   */  
  int64_t GetUTCDaqTime() const;

  /**
   * @brief Gets the appropriate UTC Month
   */
  Month GetUTCMonth() const ;

  /**
   * @brief Gets the appropriate day of the week 
   */
  Weekday GetUTCWeekday() const;

  /**
   * @brief Gets the day of the month.  This is calendar day, so
   * there is no '0'
   */
  int32_t GetUTCDayOfMonth() const;

  /**
   * @brief Gets the number of seconds since this UTC year started
   */
  int32_t GetUTCSec() const;
  
  /**
   * @brief Gets the number of nanoseconds since this current second started.
   */
  double GetUTCNanoSec() const;  

  /**
   * equality operator.  
   * @return true if the times are the same
   * @param rhs the I3Time to compare this one to.
   */
  bool operator==(const I3Time& rhs) const;

  /**
   * inequality operator
   * @return false if the times are different
   * @param rhs the I3Time to compare this one to.
   */
  bool operator!=(const I3Time& rhs) const
    {
      if(rhs == *this)
        return false;
      return true;
    }

  /**
   * Dumps a Month to a string for printing
   */
  static std::string MonthToString(Month m);

  /**
   * @brief dumps a Weekday to a string for printing.
   */
  static std::string WeekdayToString(Weekday w);

   /**
   * comparison operator.
   * Compares first the year and then the DAQ time
   * @return true if the lhs should be ordered before the rhs
   */
  bool operator<(const I3Time& rhs) const;

  /**
   * comparison operator.
   * Compares first the year and then the DAQ time
   * @return true if the lhs should be ordered after the rhs
   */
  bool operator>(const I3Time& rhs) const;

  bool operator<=(const I3Time& rhs) const;

  bool operator>=(const I3Time& rhs) const;

  /**
   *Adds a double (please use I3Units of time) to I3Time
   *Takes into account rounding and leap years
   */
  I3Time operator+(const double) const;
  I3Time operator-(const double) const;

 public: 

  static double modjulianday(int year);
  
  static double modjulianday(int year, int64_t daqTime);

  static double julianday(int year);
  
  static double julianday(int year, int64_t daqTime);

  static int32_t yearOf(double modjulianday);

  static int32_t DayOfYear(int64_t daqTime);

  static int32_t DayOfYear(double modjulianday);

 private:

  int32_t year_;
  int64_t daqTime_;

  friend class boost::serialization::access;

  template <class Archive>
  void serialize(Archive& ar, unsigned version);
};

/**
 * Returns the difference between two I3Times in nanoseconds
 */
double operator-(const I3Time t1,const I3Time t2);

I3_POINTER_TYPEDEFS(I3Time);
BOOST_CLASS_VERSION(I3Time, i3time_version_);

#endif //I3TIME_H_INCLUDED
