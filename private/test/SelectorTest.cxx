/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: SelectorTest.cxx,v 1.1 2004/07/30 04:27:48 pretz Exp $
 *
 * @version $Revision: 1.1 $
 * @date $Date: 2004/07/30 04:27:48 $
 * @author pretz
 *
 * @todo
 *
 */

#include "test/tut.h"

#include "dataclasses/I3RecoHitTimeWindowSelector.h"
#include "dataclasses/I3OMGeoListedSelector.h"
#include "dataclasses/I3RecoHitSeries.h"
#include "dataclasses/I3InIceGeometry.h"
#include "dataclasses/I3OMGeoIceCube.h"

#include <string>
#include <vector>

using namespace std;

namespace tut
{
  struct I3SelectorTest 
  {
  };

  typedef test_group<I3SelectorTest> factory;

  typedef factory::object object;
}

namespace
{
  tut::factory t("SelectorTest");
}

namespace tut
{
  template<> template<>
  void object::test<1>() 
  {
    I3RecoHitSeries series;
    series.resize(5);
    for(int i=0;i<5;i++)
      {
	series[i]=new I3RecoHit();
      }
    series[0]->SetTime(3.4);
    series[1]->SetTime(5.1);
    series[2]->SetTime(7.8);
    series[3]->SetTime(9.9);
    series[4]->SetTime(10.3);
    
    vector<I3RecoHitPtr> selected_hits;
    I3RecoHitTimeWindowSelector select(selected_hits,5.0,8.0);
    for_each(series.begin(),series.end(),select);
    ensure("extracted hit series is the right size",selected_hits.size() == 2);
    ensure("extracted hit series has the right first member",
	   selected_hits[0]->GetTime()==5.1);
    ensure("extracted hit series has the right second member",
	   selected_hits[1]->GetTime()==7.8);
      
  }

  template<> template<>
  void object::test<2>()
  {
    I3InIceGeometry geo;
    vector<OMKey> bad_tubes;
    for(int string = 1;string<=5;string++)
      for(int tube=1;tube<=5;tube++)
	geo[OMKey(string,tube)] = new I3OMGeoIceCube();
    bad_tubes.push_back(OMKey(3,5));
    bad_tubes.push_back(OMKey(1,2));
    bad_tubes.push_back(OMKey(1,4));
    
    map<OMKey,I3OMGeoPtr> good_tubes;

    I3OMGeoListedSelector selection(good_tubes,bad_tubes);
    for_each(geo.begin(),geo.end(),selection);

    for(int string=1;string<=5;string++)
      for(int tube=1;tube<=5;tube++)
	{
	  if(string==3 && tube ==5)
	    ensure("bad tube doesn't appear",
		   good_tubes.find(OMKey(3,5)) == good_tubes.end());
	  else if(string==1 && tube ==2)
	    ensure("bad tube doesn't appear",
		   good_tubes.find(OMKey(1,2)) == good_tubes.end());
	  else if(string==1 && tube==4)
	    ensure("bad tube doesn't appear",
		   good_tubes.find(OMKey(1,4)) == good_tubes.end());
	  else
	    ensure("good tube appears",
		   good_tubes.find(OMKey(string,tube)) != good_tubes.end());
	}

  }
  

}

