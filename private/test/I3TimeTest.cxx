/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3TimeTest.cxx,v 1.2 2005/03/30 03:51:42 pretz Exp $

    @version $Revision: 1.2 $
    @date $Date: 2005/03/30 03:51:42 $
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
      
  }

  void object::test<6>()
  {
    cout<<I3Time::ToString(I3Time::Monday)<<endl;
    ensure(I3Time::ToString(I3Time::Monday) == "Monday");
    cout<<I3Time::ToString(I3Time::Oct)<<endl;
    ensure(I3Time::ToString(I3Time::Oct) == "Oct");
  }


  void object::test<7>()
  {
    long long int daqTime = 560819884 * (long long)1e8 + 43187970;
    I3Time tme;
    tme.SetDaqTime(2005,daqTime);

    ensure(tme.GetUTCMonth() == I3Time::Mar);

    ensure_equals(tme.GetUTCDayOfMonth(),6);
    ensure(tme.GetUTCWeekday() == I3Time::Sunday);  
    ensure_equals(tme.GetUTCSec(),78598);
    ensure_distance(tme.GetUTCNanoSec(),(double)844318797,0.1);
  }
}
