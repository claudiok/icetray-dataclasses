/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3TimeTest.cxx,v 1.9 2005/04/01 20:23:24 pretz Exp $

    @version $Revision: 1.9 $
    @date $Date: 2005/04/01 20:23:24 $
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
    ensure("secs is right",tme.GetUTCSec()==5608198);
    ensure_distance(tme.GetUTCNanoSec(),(double)844318797,0.1);
  }

  void object::test<8>()
  {
    I3Time time;
    time.SetModJulianTime(53460,0,0);

    ensure("checking modjulian sec",time.GetModJulianSec()==0);
  }

  void object::test<9>()
  {
    I3Time time;
    time.SetModJulianTime(53460,0,0);

    ensure("checking modjulian day",time.GetModJulianDay()==53460);
  }

  void object::test<10>()
  {
    I3Time time;
    time.SetModJulianTime(53460,60*60*12,0);

    ensure("checking modjulian day",time.GetModJulianDay()==53460);
  }

  void object::test<11>()
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

	ensure_equals("checking that the year is the same",
		      initial_time.GetUTCYear(),
		      compare_time.GetUTCYear());
	ensure("checking that the UTC time is the same to ns",
	       abs(initial_time.GetUTCDaqTime() 
		   - compare_time.GetUTCDaqTime()) < 10);
	
	
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

  void object::test<13>()
  {
    ensure_distance(I3Time::julianday(2005),2453371.500000,0.00001);
    ensure_distance(I3Time::modjulianday(2005),53371.00000,0.000001);
  }

  void object::test<14>()
  {
    I3Time lowest;
    lowest.SetDaqTime(2004,235918301);
    
    I3Time lower;
    lower.SetDaqTime(2004,235918402);

    I3Time higher;
    higher.SetDaqTime(2008,283294782);

    I3Time highest;
    highest.SetDaqTime(2009,283294782);
    
    ensure("1",lowest<lower);
    ensure("2",lowest<higher);
    ensure("3",lowest<highest);
    ensure("4",lower<higher);
    ensure("5",lower<highest);
    ensure("6",higher<highest);

    ensure("7",!(lower<lowest));
    ensure("8",!(higher<lowest));
    ensure("9",!(highest<lowest));
    ensure("10",!(higher<lower));
    ensure("11",!(highest<lower));
    ensure("12",!(highest<higher));

    ensure("13",highest!=higher);
    ensure("14",lower!=higher);
    ensure("15",lowest!=lower);

    I3Time same;
    same.SetDaqTime(2004,235918301);

    ensure("16",lowest == same);
  }
}
