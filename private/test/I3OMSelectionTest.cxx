/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3OMSelectionTest.cxx,v 1.1 2005/02/08 22:03:38 pretz Exp $
 *
 * @version $Revision: 1.1 $
 * @date $Date: 2005/02/08 22:03:38 $
 * @author pretz
 *
 * @todo
 *
 */

#include "TUT/tut.h"

#include "dataclasses/I3RecoHitTimeWindowSelector.h"
#include "dataclasses/I3OMGeoIceCube.h"
#include "dataclasses/I3OMResponseMap.h"
#include "dataclasses/I3OMResponse.h"
#include "dataclasses/I3OMSelectionDict.h"
#include "dataclasses/I3OMResponseSelection.h"
#include "dataclasses/I3OddOMSelection.h"
#include "dataclasses/I3EvenOMSelection.h"
#include "dataclasses/I3GoodOMSelection.h"
#include "dataclasses/I3BadOMSelection.h"

#include <string>
#include <vector>

using namespace std;

namespace tut
{
  struct I3OMSelectionTest 
  {
    I3OMResponseMap responses;
    I3OMResponsePtr om00;
    I3OMResponsePtr om01;
    I3OMResponsePtr om02;
    I3OMResponsePtr om03;
    I3OMResponsePtr om10;
    I3OMResponsePtr om11;
    I3OMResponsePtr om12;
    I3OMResponsePtr om13;

    I3OMSelectionTest()
    {
      om00 = I3OMResponsePtr(new I3OMResponse);
      om01 = I3OMResponsePtr(new I3OMResponse);
      om02 = I3OMResponsePtr(new I3OMResponse);
      om03 = I3OMResponsePtr(new I3OMResponse);
      om10 = I3OMResponsePtr(new I3OMResponse);
      om11 = I3OMResponsePtr(new I3OMResponse);
      om12 = I3OMResponsePtr(new I3OMResponse);
      om13 = I3OMResponsePtr(new I3OMResponse);
      
      responses[OMKey(0,0)] = om00;
      responses[OMKey(0,1)] = om01;
      responses[OMKey(0,2)] = om02;
      responses[OMKey(0,3)] = om03;

      responses[OMKey(1,0)] = om10;
      responses[OMKey(1,1)] = om11;
      responses[OMKey(1,2)] = om12;
      responses[OMKey(1,3)] = om13;



    }
  };



  typedef test_group<I3OMSelectionTest> factory;

  typedef factory::object object;
}

namespace
{
  static tut::factory t("I3OMSelectionTest");
}

namespace tut
{
  template<> template<>
  void object::test<1>() 
  {
    I3OMResponseSelectionPtr omrs(new I3OMResponseSelection);
    I3OMSelectionDict dict;
    dict["foo"] = omrs;
    I3OMSelector iter = dict.GetSelector("foo",responses);
    ensure(iter->second == om00);
    ensure(iter->first == OMKey(0,0));
    iter++;
    ensure(iter->second == om01);
    ensure(iter->first == OMKey(0,1));
    iter++;
    ensure(iter->second == om02);
    ensure(iter->first == OMKey(0,2));
    iter++;
    ensure(iter->second == om03);
    ensure(iter->first == OMKey(0,3));
    iter++;
    ensure(iter->second == om10);
    ensure(iter->first == OMKey(1,0));
    iter++;
    ensure(iter->second == om11);
    ensure(iter->first == OMKey(1,1));
    iter++;
    ensure(iter->second == om12);
    ensure(iter->first == OMKey(1,2));
    iter++;
    ensure(iter->second == om13);
    ensure(iter->first == OMKey(1,3));
    iter++;
    ensure(iter.base() == iter.end());
  }

  template<> template<>
  void object::test<2>()
  {
    I3OMResponseSelectionPtr omrs(new I3OddOMSelection);
    I3OMSelectionDict dict;
    dict["foo"] = omrs;
    I3OMSelector iter = dict.GetSelector("foo",responses);
    ensure(iter->second == om01);
    iter++;
    ensure(iter->second == om03);
    iter++;
    ensure(iter->second == om11);
    iter++;
    ensure(iter->second == om13);
    iter++;
    ensure(iter.base() == iter.end());
  }

  template<> template<>
  void object::test<3>() 
  {
    I3OMResponseSelectionPtr omrs(new I3EvenOMSelection);
    I3OMSelectionDict dict;
    dict["foo"] = omrs;
    I3OMSelector iter = dict.GetSelector("foo",responses);
    ensure(iter->second == om00);
    iter++;
    ensure(iter->second == om02);
    iter++;
    ensure(iter->second == om10);
    iter++;
    ensure(iter->second == om12);
    iter++;
    ensure(iter.base() == iter.end());
  }

  template<> template<>
  void object::test<4>() 
  {
    I3OMResponseSelectionPtr omrs(new I3OMResponseSelection);
    I3OMSelectionDict dict;
    dict["foo"] = omrs;
    I3OMSelector iter = dict.GetSelector("foo",responses);
    ensure(iter->second == om00);
    iter++;
    ensure(iter->second == om01);
    iter--;
    ensure(iter->second == om00);
    iter++;
    ensure(iter->second == om01);
  }
  
  template<> template<>
  void object::test<5>() 
  {
    I3OMSelectionDict dict;
    I3OMSelector iter = dict.GetSelector("",responses);
    ensure(iter->second == om00);
    ensure(iter->first == OMKey(0,0));
    iter++;
    ensure(iter->second == om01);
    ensure(iter->first == OMKey(0,1));
    iter++;
    ensure(iter->second == om02);
    ensure(iter->first == OMKey(0,2));
    iter++;
    ensure(iter->second == om03);
    ensure(iter->first == OMKey(0,3));
    iter++;
    ensure(iter->second == om10);
    ensure(iter->first == OMKey(1,0));
    iter++;
    ensure(iter->second == om11);
    ensure(iter->first == OMKey(1,1));
    iter++;
    ensure(iter->second == om12);
    ensure(iter->first == OMKey(1,2));
    iter++;
    ensure(iter->second == om13);
    ensure(iter->first == OMKey(1,3));
    iter++;
    ensure(iter.base() == iter.end());
  }

  template<> template<>
  void object::test<6>()
  {
    VectorPolicy<OMKey>::ThePolicy oms;
    oms.push_back(OMKey(1,2));
    oms.push_back(OMKey(1,3));

    I3OMResponseSelectionPtr omrs(new I3GoodOMSelection(oms));
    I3OMSelectionDict dict;
    dict["foo"] = omrs;
    I3OMSelector iter = dict.GetSelector("foo",responses);
    ensure(iter->second == om12);
    iter++;
    ensure(iter->second == om13);
    iter++;
    ensure(iter.base() == iter.end());
  }    

  template<> template<>
  void object::test<7>()
  {
    #warning This test will compile but not link
//     VectorPolicy<OMKey>::ThePolicy oms;
//     oms.push_back(OMKey(1,2));
//     oms.push_back(OMKey(1,3));

//     I3OMResponseSelectionPtr omrs(new I3BadOMSelection(oms));
//     I3OMSelectionDict dict;
//     dict["foo"] = omrs;
//     I3OMSelector iter = dict.GetSelector("foo",responses);
//     ensure(iter->second == om01);
//     iter++;
//     ensure(iter->second == om02);
//     iter++;
//     ensure(iter->second == om03);
//     iter++;
//     ensure(iter->second == om10);
//     iter++;
//     ensure(iter->second == om11);
//     iter++;
//     ensure(iter->second == om12);
//     iter++;
//     ensure(iter.base() == iter.end());
  }    



    
}

