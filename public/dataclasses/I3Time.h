#ifndef I3TIME_H
#define I3TIME_H

#include <string>
#include "TObject.h"
#include <ostream>

/**
 * @brief A class for dealing with global times.  
 *
 * Has methods for setting the time in either the Daq UTC convention or
 * in the Julian convention 
 * @note a julian day of 0 is Jan 1st 4712 BC 
 * @note Julian days begin at noon
 * 
 * @todo The library I have is using Barycentric Dynamical Time (TDB),
 * which differs from UTC by a number that is a function of year.  UTC has 
 * a leap second every now and then and TDB doesn't Right
 * now they're ~68 seconds different.  May need to account for this.
 * http://jday.sourceforge.net/index.php for reference
 *
 */
class I3Time : public TObject
{
 public:
  /**
   * @brief enum for the Month
   */
  enum Month{Jan = 1, 
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
	     BadMonth = 999};

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
   * @brief Sets the time in the 'daq' style where
   * @param year The year.  Something like 2005.
   * @param daqTime The number of tenths of nanoseconds since the year began
   */  
  void SetDaqTime(int year, long long int daqTime);

  /**
   * @brief Sets the time in the Julian (not modified julian) convention
   * @note Julian days begin at noon.
   * @param julianDay the Julian Day in the standard definition
   * @param sec The number of seconds since the julian day began
   * @param ns The number of ns since the most recent second began
   */
  void SetJulianTime(unsigned int julianDay,
		     unsigned int sec,
		     double ns);

  /**
   * @brief Sets the time in the Modified julian convention
   * @param modJulianDay the modified julian day to set
   * @param sec the number of secs after this modified julian day began
   * @param ns the number of ns after this second began.
   */
  void SetModJulianTime(unsigned int modJulianDay,
			unsigned int sec,
			double ns);

  /**
   * @brief Gets the Julian day
   */
  unsigned int GetJulianDay() const;
  
  /**
   * @brief Gets the number of seconds since this Julian day began
   * @note Julian days begin at noon.
   */
  unsigned int GetJulianSec() const;

  /**
   * @brief Gets the number of nanoseconds since this second began
   */
  double GetJulianNanoSec() const;
  
  /**
   * @brief Gets the Modified Julian day
   */
  unsigned int GetModJulianDay() const;
  
  /**
   * @brief Gets the number of seconds since this Modified Julian day began
   * @note Modified Julian days begin at midnight
   */
  unsigned int GetModJulianSec() const;
  
  /**
   * @brief Gets the number of nanoseconds since this second began
   */
  double GetModJulianNanoSec() const;

  /**
   * @brief Gets the year in the UTC convention
   */
  int GetUTCYear() const;

  /**
   * @brief Gets the appropriate time for the DAQ.  tenths of nanoseconds
   * since the start of the UTC year.
   */  
  long long int GetUTCDaqTime() const;

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
  unsigned int GetUTCDayOfMonth() const;

  /**
   * @brief Gets the number of seconds since this UTC day started
   */
  unsigned int GetUTCSec() const;
  
  /**
   * @brief Gets the number of nanoseconds since this current second started.
   */
  double GetUTCNanoSec() const;  

  /**
   * @brief dumps this class to the given ostream
   */
  void ToStream(ostream& o) const
    {
      o<<"[ I3Time: Year:"<<year_
       <<" DaqTime:"<<daqTime_<<"\n"
       <<"Month: "<<MonthToString(GetUTCMonth())
       <<" Day: "<<GetUTCDayOfMonth()<<"\n"
       <<"ModJulianDay: "<<GetModJulianDay()
       <<" ModJulianSec:"<<GetModJulianSec()<<" ]\n";
    }

  /**
   * Dumps a Month to a string for printing
   */
  static std::string MonthToString(Month m);

  /**
   * @brief dumps a Weekday to a string for printing.
   */
  static std::string WeekdayToString(Weekday w);
 private:
  static double modjulianday(int year);
  
  static double modjulianday(int year, long long int daqTime);

  static double julianday(int year);
  
  static double julianday(int year, long long int daqTime);

  static unsigned int yearOf(double modjulianday);
  
  unsigned int year_;
  long long int daqTime_;

  ClassDef(I3Time,1);
};

inline ostream& operator<<(ostream& o, const I3Time& t)
{
  t.ToStream(o);
  return o;
}

#endif
