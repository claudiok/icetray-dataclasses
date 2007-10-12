/**
    copyright  (C) 2004
    the icecube collaboration
    $Id$

    @version $Revision: 1.10 $
    @date $Date$
    @author pretz
*/
#include <I3Test.h>

#include <iostream>
#include <string>
#include <vector>

#include <boost/random.hpp>

#include <dataclasses/jday.h>
#include <dataclasses/I3Time.h>
#include <dataclasses/I3Units.h>


using namespace std;


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

TEST(leap_year)
{
  vector<int> leap_years;
  leap_years.resize(4);
  leap_years[0] = 2000;
  leap_years[1] = 2004;
  leap_years[2] = 2008;
  leap_years[3] = 2012;
  vector<int>::iterator i;
  for(i=leap_years.begin(); i != leap_years.end(); ++i){
    cout<<*i<<endl;
    ENSURE(I3TimeUtils::leap_year(*i),"This is, in fact, a leap year!");
  }

  vector<int> not_leap_years;
  not_leap_years.resize(4);
  not_leap_years[0] = 1999;
  not_leap_years[1] = 2003;
  not_leap_years[2] = 2007;
  not_leap_years[3] = 2010;

  for(i=not_leap_years.begin(); i != not_leap_years.end(); ++i)
    ENSURE(!(I3TimeUtils::leap_year(*i)),"This is, in fact, NOT a leap year!");
}

TEST(ns_to_daqtime_rounding)
{
  vector<double> times_to_test;
  times_to_test.resize(7);
  times_to_test[0] = 0.01;//round down
  times_to_test[1] = 0.11;//round down
  times_to_test[2] = 0.08;//round up
  times_to_test[3] = 0.23;//round down
  times_to_test[4] = 0.25;//round up
  times_to_test[5] = 0.54;//round down
  times_to_test[6] = 0.79;//round up
  vector<int64_t> result_times;
  result_times.resize(7);
  result_times[0] = 0;
  result_times[1] = 1;
  result_times[2] = 1;
  result_times[3] = 2;
  result_times[4] = 3;
  result_times[5] = 5;
  result_times[6] = 8;

  vector<double>::iterator i;
  vector<int64_t>::iterator j;
  for(i=times_to_test.begin(), j=result_times.begin(); 
      i != times_to_test.end(); 
      ++i,++j)
    ENSURE(I3TimeUtils::ns_to_daqtime(*i * I3Units::ns) == *j);
}

TEST(plus_double)
{
  int year(2005);
  int64_t delta(10);
  double t(1.);
  int64_t daqTime = I3TimeUtils::max_DAQ_time(year) - delta/2;
  I3Time t0(year,daqTime);
  I3Time t1(year+1,delta/2); //should go over by half a delta
  I3Time t1_prime = t0 + t;

  cout<<"Year: "<<t1_prime.GetUTCYear()<<endl;
  cout<<"DAQTime: "<<t1_prime.GetUTCDaqTime()<<endl;

  ENSURE(t1_prime == t1,"Someone doesn't know how to add");
}

TEST(plus_double_leap_year)
{
  int year(2000);
  int64_t delta(10);
  double t(1.);
  int64_t daqTime = I3TimeUtils::max_DAQ_time(year) - delta/2;
  I3Time t0(year,daqTime);
  I3Time t1(year+1,delta/2); //should go over by half a delta
  I3Time t1_prime = t0 + t;

  cout<<"Year: "<<t1_prime.GetUTCYear()<<endl;
  cout<<"DAQTime: "<<t1_prime.GetUTCDaqTime()<<endl;

  ENSURE(t1_prime == t1,"Someone doesn't know how to add");
}

TEST(minus_double)
{
  int year(2006);
  int64_t delta(10);
  double t(1.);
  int64_t daqTime = delta/2;
  I3Time t0(year,daqTime);
  I3Time t1(year-1,I3TimeUtils::max_DAQ_time(year) - delta/2); //should go over by half a delta
  I3Time t1_prime = t0 - t;

  cout<<"Year: "<<t1_prime.GetUTCYear()<<endl;
  cout<<"DAQTime: "<<t1_prime.GetUTCDaqTime()<<endl;

  ENSURE(t1_prime == t1,"Someone doesn't know how to subtract");
}

TEST(add_subtract_double)
{
//  boost::rand48 rng(static_cast<int>(time(0)));
//  boost::uniform_smallint<int> string_rng(1990,2020);
//
//  boost::uniform_smallint<int64_t> om_rng(0,);
//  boost::uniform_smallint<double> delta(0,10e7);

  int year(2006);
  double t(3.14);
  int64_t daqTime = 1209820980;

  I3Time t0(year,daqTime);
  I3Time t1_prime = t0 - t;
  I3Time t0_prime = t1_prime + t;

  cout<<"t0 Year: "<<t0.GetUTCYear()<<endl;
  cout<<"t0 DAQTime: "<<t0.GetUTCDaqTime()<<endl;

  cout<<"t1' Year: "<<t1_prime.GetUTCYear()<<endl;
  cout<<"t1' DAQTime: "<<t1_prime.GetUTCDaqTime()<<endl;

  cout<<"t0' Year: "<<t0_prime.GetUTCYear()<<endl;
  cout<<"t0' DAQTime: "<<t0_prime.GetUTCDaqTime()<<endl;

  ENSURE(t0 == t0_prime,"+/- are not inverses of each other");
}

TEST(test_unix_time)
{
  I3Time tm;
  tm.SetUnixTime(1163203200);
  ENSURE_EQUAL(tm.GetUTCYear(), 2006);
  ENSURE_EQUAL(tm.GetUTCMonth(), I3Time::Nov);
  ENSURE_EQUAL(tm.GetUTCDayOfMonth(), 11);

  tm.SetUnixTime(1704071648);
  ENSURE_EQUAL(tm.GetUTCYear(), 2024);
  ENSURE_EQUAL(tm.GetUTCMonth(), I3Time::Jan);
  ENSURE_EQUAL(tm.GetUTCDayOfMonth(), 1);
  ENSURE_EQUAL(tm.GetUTCSec(), 4448);

  tm.SetUnixTime(1900800);
  ENSURE_EQUAL(tm.GetModJulianDay(), 40609);

  tm.SetUnixTime(1308787200);
  ENSURE_EQUAL(tm.GetModJulianDay(), 55735);

  tm.SetUnixTime(1192228335);
  ENSURE_DISTANCE(I3Time::modjulianday(tm.GetUTCYear(),tm.GetUTCDaqTime()),
                  54385.9390625, 0.0000001);
}


