#ifndef I3TIME_H
#define I3TIME_H

#include <string>

extern "C"
{
#include "dataclasses/jday.h"
}

class I3Time
{
 public:
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

	     
  I3Time(int year, 
	 long long int daqTime);
  I3Time(unsigned int julianDay,
	 unsigned int sec, 
	 double ns);
  
  unsigned int GetJulianDay();
  
  unsigned int GetJulianSec();
  
  double GetJulianNanoSec();

  int GetUTCYear();
  
  long long int GetUTCDaqTime();

  Month GetUTCMonth();

  Weekday GetUTCWeekday();

  unsigned int GetUTCDayOfMonth();

  unsigned int GetUTCSec();
  
  double GetUTCNanoSec();  

  static std::string ToString(Month m);

  static std::string ToString(Weekday w);
 private:
  unsigned int julianDay_;
  unsigned int sec_;
  double ns_;
  UTinstant instant_;
};

#endif
