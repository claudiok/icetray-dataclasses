/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3TimeTest.cxx,v 1.4 2005/03/31 14:15:15 pretz Exp $

    @version $Revision: 1.4 $
    @date $Date: 2005/03/31 14:15:15 $
    @author pretz

    @todo
*/

#include "TUT/tut.h"

#include <string>
using std::string;
using std::cout;
using std::endl;

extern "C"
{
#include "dataclasses/jday.h"
}

#include "dataclasses/I3Time.h"

namespace tut
{
  struct I3TimeTest
  {

  };

  typedef test_group<I3TimeTest> factory;

  typedef factory::object object;
}

namespace
{
  static tut::factory t("I3TimeTest");
}

namespace tut
{
  void object::test<1>() 
  {
    UTinstant i;
    i.j_date=2448988.5; // should be january 1st 1993
    CalDate(&i);
    ensure(i.month == 1);
    ensure(i.year == 1993);
    ensure(i.i_hour == 0);
    ensure(i.i_minute == 0);
    ensure(i.weekday==5);
    ensure(i.day_of_year == 1);
  }
  
  void object::test<2>()
  {
    UTinstant i;
    i.month=1;
    i.year=1993;
    i.day=1;
    i.i_hour=0;
    i.i_minute=0;
    i.second = 0;
    JulDate(&i);
    ensure_distance(i.j_date,2448988.5,0.00000001);
  }

  void object::test<3>()
  {
    UTinstant i;
    i.year=2005;
    
    i.day_of_year=31+28+5;
    JulDate(&i);
    cout<<i.j_date<<endl;
  }

  void object::test<4>()
  {
    UTinstant i;
    i.year = 2005;
    i.month = 1;
    i.day = 1;
    i.i_hour = 0;
    i.i_minute = 0;
    i.second = 0;
    JulDate(&i);
    ensure(i.weekday == 6);
  }

  void object::test<5>()
  {
    I3Time tme;
    tme.SetJulianTime(2453434,(unsigned int)(23.5 / 24. * 3600 * 24),0.);
    cout<<tme.GetUTCYear()<<endl;
    cout<<tme.GetUTCDaqTime()<<endl;
    cout<<tme<<endl;
      
  }

  void object::test<6>()
  {
    cout<<I3Time::WeekdayToString(I3Time::Monday)<<endl;
    ensure(I3Time::WeekdayToString(I3Time::Monday) == "Monday");
    cout<<I3Time::MonthToString(I3Time::Oct)<<endl;
    ensure(I3Time::MonthToString(I3Time::Oct) == "Oct");
  }

  // testing that I can set a daq time and get the days and stuff out
  // as calculated by hand
  void object::test<7>()
  {
    long long int daqTime = 560819884 * (long long)1e8 + 43187970;
    I3Time tme;
    tme.SetDaqTime(2005,daqTime);

    ensure(tme.GetUTCMonth() == I3Time::Mar);

    cout<<"Output day of the month"<<tme.GetUTCDayOfMonth()<<endl;
    ensure("day of month is right",tme.GetUTCDayOfMonth()==6);
    ensure("weekday is right",tme.GetUTCWeekday() == I3Time::Sunday);  
    ensure("secs is right",tme.GetUTCSec()==78598);
    ensure_distance(tme.GetUTCNanoSec(),(double)844318797,0.1);
  }

  void object::test<8>()
  {
    I3Time time;
    time.SetJulianTime(2453460,0,0);

    ensure_equals("checking julian sec",time.GetJulianSec(),0);
  }

  void object::test<9>()
  {
    I3Time time;
    time.SetJulianTime(2453460,0,0);

    ensure_equals("checking julian day",time.GetJulianDay(),2453460);
  }

  void object::test<10>()
  {
    I3Time time;
    time.SetJulianTime(2453460,60*60*12,0);

    ensure_equals("checking julian day",time.GetJulianDay(),2453460);
  }

  void object::test<11>()
  {
    for(int i = 0 ; i < 100 ; i++)
      {
	long long int daqTime = rand() * rand() * rand();
	int year = 1980 + (rand() % 50);
	cout<<" starting daq time and year: "<<daqTime<<" "<<year<<endl;
	I3Time initial_time;
	initial_time.SetDaqTime(year,daqTime);

	I3Time compare_time;
	compare_time.SetJulianTime(initial_time.GetJulianDay(),
				   initial_time.GetJulianSec(),
				   initial_time.GetJulianNanoSec());

	ensure_equals("checking that the year is the same",
		      initial_time.GetUTCYear(),
		      compare_time.GetUTCYear());
	ensure_equals("checking that the UTC time is the same",
		      initial_time.GetUTCDaqTime(),
		      compare_time.GetUTCDaqTime());
	
	
      }
  }

  void object::test<12>()
  {
    I3Time time;
    time.SetDaqTime(2005,560819884 * (long long)1e8 + 43187970);
    ensure_distance(time.GetUTCNanoSec(),844318797.0,0.1);
    ensure_distance(time.GetJulianNanoSec(),844318797.0,0.1);
    ensure_distance(time.GetModJulianNanoSec(),844318797.0,0.1);
  }
}
