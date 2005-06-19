/**
    copyright  (C) 2004
    the icecube collaboration
    $Id$

    @version $Revision: 1.10 $
    @date $Date$
    @author pretz

    @todo
*/

#include <I3Test.h>

#include <string>
using std::string;
using std::cout;
using std::endl;

extern "C"
{
#include "dataclasses/jday.h"
}

#include "dataclasses/I3Time.h"

TEST_GROUP(I3TimeTest);


TEST(UTinstant_jul_to_date)
{
  UTinstant i;
  i.j_date=2448988.5; // should be january 1st 1993
  CalDate(&i);
  ENSURE(i.month == 1);
  ENSURE(i.year == 1993);
  ENSURE(i.i_hour == 0);
  ENSURE(i.i_minute == 0);
  ENSURE(i.weekday==5);
  ENSURE(i.day_of_year == 1);
}
  
TEST(UTinstant_date_to_jul)
{
  UTinstant i;
  i.month=1;
  i.year=1993;
  i.day=1;
  i.i_hour=0;
  i.i_minute=0;
  i.second = 0;
  JulDate(&i);
  ENSURE_DISTANCE(i.j_date,2448988.5,0.00000001);
}

TEST(UT_instant_weekday)
{
  UTinstant i;
  i.year = 2005;
  i.month = 1;
  i.day = 1;
  i.i_hour = 0;
  i.i_minute = 0;
  i.second = 0;
  JulDate(&i);
  ENSURE(i.weekday == 6);
}

TEST(I3Time_weekday_month)
{
  cout<<I3Time::WeekdayToString(I3Time::Monday)<<endl;
  ENSURE(I3Time::WeekdayToString(I3Time::Monday) == "Monday");
  cout<<I3Time::MonthToString(I3Time::Oct)<<endl;
  ENSURE(I3Time::MonthToString(I3Time::Oct) == "Oct");
}

  // testing that I can set a daq time and get the days and stuff out
  // as calculated by hand
TEST(test7)
{
  long long int daqTime = 560819884 * (long long)1e8 + 43187970;
  I3Time tme;
  tme.SetDaqTime(2005,daqTime);
  
  ENSURE(tme.GetUTCMonth() == I3Time::Mar);
  
  cout<<"Output day of the month"<<tme.GetUTCDayOfMonth()<<endl;
  ENSURE(tme.GetUTCDayOfMonth()==6,"day of month is right");
  ENSURE(tme.GetUTCWeekday() == I3Time::Sunday,"weekday is right");  
  ENSURE(tme.GetUTCSec()==5608198,"secs is right");
  ENSURE_DISTANCE(tme.GetUTCNanoSec(),(double)844318797,0.1);
}

TEST(test8)
{
  I3Time time;
  time.SetModJulianTime(53460,0,0);
  
  ENSURE(time.GetModJulianSec()==0,"checking modjulian sec");
}

TEST(test9)
{
  I3Time time;
  time.SetModJulianTime(53460,0,0);
  
  ENSURE(time.GetModJulianDay()==53460,"checking modjulian day");
}

TEST(test10)
{
  I3Time time;
  time.SetModJulianTime(53460,60*60*12,0);
  
  ENSURE(time.GetModJulianDay()==53460,"checking modjulian day");
}

TEST(test11)
{
  for(int i = 0 ; i < 100 ; i++)
    {
      rand();
      long long int daqTime = ((long long)rand()) 
	* ((long long)rand()) 
	* ((long long)rand()) %
	((long long)24 * 365 * 3600 * ((long long)1e10) ) ;
      if(daqTime < 0)
	daqTime = -daqTime;
      int year = 1995 + (rand() % 20);
      I3Time initial_time;
      initial_time.SetDaqTime(year,daqTime);
      
      I3Time compare_time;
      compare_time.SetModJulianTime(initial_time.GetModJulianDay(),
				    initial_time.GetModJulianSec(),
				    initial_time.GetModJulianNanoSec());
      
      ENSURE(initial_time.GetUTCYear()==
	     compare_time.GetUTCYear(),
	     "checking that the year is the same");
      ENSURE(std::llabs(initial_time.GetUTCDaqTime() 
			- compare_time.GetUTCDaqTime()) < 10,
	     "checking that the UTC time is the same to ns");
      
      
    }
}

TEST(test12)
{
  I3Time time;
  time.SetDaqTime(2005,560819884 * (long long)1e8 + 43187970);
  ENSURE_DISTANCE(time.GetUTCNanoSec(),844318797.0,0.1);
  ENSURE_DISTANCE(time.GetModJulianNanoSec(),844318797.0,0.1);
}

TEST(test13)
{
  ENSURE_DISTANCE(I3Time::julianday(2005),2453371.500000,0.00001);
  ENSURE_DISTANCE(I3Time::modjulianday(2005),53371.00000,0.000001);
}

TEST(test14)
{
  I3Time lowest;
  lowest.SetDaqTime(2004,235918301);
  
  I3Time lower;
  lower.SetDaqTime(2004,235918402);
  
  I3Time higher;
  higher.SetDaqTime(2008,283294782);
  
  I3Time highest;
  highest.SetDaqTime(2009,283294782);
  
  ENSURE(lowest<lower);
  ENSURE(lowest<higher);
  ENSURE(lowest<highest);
  ENSURE(lower<higher);
  ENSURE(lower<highest);
  ENSURE(higher<highest);
  
  ENSURE(!(lower<lowest));
  ENSURE(!(higher<lowest));
  ENSURE(!(highest<lowest));
  ENSURE(!(higher<lower));
  ENSURE(!(highest<lower));
  ENSURE(!(highest<higher));
  
  ENSURE(highest!=higher);
  ENSURE(lower!=higher);
  ENSURE(lowest!=lower);
  
  ENSURE(lower>lowest);
  ENSURE(higher>lowest);
  ENSURE(highest>lowest);
  ENSURE(higher>lower);
  ENSURE(highest>lower);
  ENSURE(highest>higher);

  ENSURE(lower>=lowest);
  ENSURE(higher>=lowest);
  ENSURE(highest>=lowest);
  ENSURE(higher>=lower);
  ENSURE(highest>=lower);
  ENSURE(highest>=higher);
  
  ENSURE(lowest<=lower);
  ENSURE(lowest<=higher);
  ENSURE(lowest<=highest);
  ENSURE(lower<=higher);
  ENSURE(lower<=highest);
  ENSURE(higher<=highest);
  
  I3Time same;
  same.SetDaqTime(2004,235918301);
  
  ENSURE(lowest == same);
  ENSURE(lowest <= same);
  ENSURE(lowest >= same);
}

