/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @version $Revision: 1.5 $
 * @date $Date$
 * @author pretz
 *
 * @todo
 *
 */

#include <I3Test.h>

#include "dataclasses/I3OMGeoIceCube.h"
#include "dataclasses/I3OMResponseMap.h"
#include "dataclasses/I3OMResponse.h"
#include "dataclasses/I3OMSelectionDict.h"
#include "dataclasses/I3OMResponseSelection.h"
//#include "dataclasses/I3OddOMSelection.h"
//#include "dataclasses/I3EvenOMSelection.h"
#include "dataclasses/I3GoodOMSelection.h"
#include "dataclasses/I3BadOMSelection.h"

#include <string>
#include <vector>

using namespace std;

TEST_GROUP(I3OMSelectionTest);

struct OMSelectionTestData  
{
  

  I3OMResponseMap responses;
  I3OMResponsePtr om0_0;
  I3OMResponsePtr om0_1;
  I3OMResponsePtr om0_2;
  I3OMResponsePtr om0_3;
  I3OMResponsePtr om1_0;
  I3OMResponsePtr om1_1;
  I3OMResponsePtr om1_2;
  I3OMResponsePtr om1_3;
  I3OMResponsePtr om7_12;
  I3OMResponsePtr om26_2;
  I3OMResponsePtr om14_39;
  I3OMResponsePtr om80_60;
  I3OMResponsePtr om_5_15;
  
  OMSelectionTestData()
  {
    om0_0 = I3OMResponsePtr(new I3OMResponse);
    om0_1 = I3OMResponsePtr(new I3OMResponse);
    om0_2 = I3OMResponsePtr(new I3OMResponse);
    om0_3 = I3OMResponsePtr(new I3OMResponse);
    om1_0 = I3OMResponsePtr(new I3OMResponse);
    om1_1 = I3OMResponsePtr(new I3OMResponse);
    om1_2 = I3OMResponsePtr(new I3OMResponse);
    om1_3 = I3OMResponsePtr(new I3OMResponse);
    om7_12 = I3OMResponsePtr(new I3OMResponse);
    om26_2 = I3OMResponsePtr(new I3OMResponse);
    om14_39 = I3OMResponsePtr(new I3OMResponse);
    om80_60 = I3OMResponsePtr(new I3OMResponse);
    om_5_15 = I3OMResponsePtr(new I3OMResponse);
    
    responses[OMKey(0,0)] = om0_0;
    responses[OMKey(0,1)] = om0_1;
    responses[OMKey(0,2)] = om0_2;
    responses[OMKey(0,3)] = om0_3;
    
    responses[OMKey(1,0)] = om1_0;
    responses[OMKey(1,1)] = om1_1;
    responses[OMKey(1,2)] = om1_2;
    responses[OMKey(1,3)] = om1_3;
    
    responses[OMKey(7,12)] = om7_12;
    responses[OMKey(26,2)] = om26_2;
    responses[OMKey(14,39)] = om14_39;
    responses[OMKey(80,60)] = om80_60;
    responses[OMKey(-5,15)] = om_5_15;
  }
};


TEST(base_selector)
{
  OMSelectionTestData  data;
  cout<<endl<<"Testing that base selector gets all entries..."<<endl;
  I3OMResponseSelectionPtr omrs(new I3OMResponseSelection);
  I3OMSelectionDict dict;
  dict["foo"] = omrs;
  I3OMSelector iter = dict.GetSelector("foo",data.responses);
  ENSURE(iter->second == data.om_5_15);
  ENSURE(iter->first == OMKey(-5,15));
  iter++;
  ENSURE(iter->second == data.om0_0);
  ENSURE(iter->first == OMKey(0,0));
  iter++;
  ENSURE(iter->second == data.om0_1);
  ENSURE(iter->first == OMKey(0,1));
  iter++;
  ENSURE(iter->second == data.om0_2);
  ENSURE(iter->first == OMKey(0,2));
  iter++;
  ENSURE(iter->second == data.om0_3);
  ENSURE(iter->first == OMKey(0,3));
  iter++;
  ENSURE(iter->second == data.om1_0);
  ENSURE(iter->first == OMKey(1,0));
  iter++;
  ENSURE(iter->second == data.om1_1);
  ENSURE(iter->first == OMKey(1,1));
  iter++;
  ENSURE(iter->second == data.om1_2);
  ENSURE(iter->first == OMKey(1,2));
  iter++;
  ENSURE(iter->second == data.om1_3);
  ENSURE(iter->first == OMKey(1,3));
  iter++;
  ENSURE(iter->second == data.om7_12);
  ENSURE(iter->first == OMKey(7,12));
  iter++;
  ENSURE(iter->second == data.om14_39);
  ENSURE(iter->first == OMKey(14,39));
  iter++;
  ENSURE(iter->second == data.om26_2);
  ENSURE(iter->first == OMKey(26,2));
  iter++;
  ENSURE(iter->second == data.om80_60);
  ENSURE(iter->first == OMKey(80,60));
  iter++;
  ENSURE(iter.base() == iter.end());
}

TEST(backwards_iteration)
{
  OMSelectionTestData  data;
  cout<<"Testing backwards iteration..."<<endl;
  I3OMResponseSelectionPtr omrs(new I3OMResponseSelection);
  I3OMSelectionDict dict;
  dict["foo"] = omrs;
  I3OMSelector iter = dict.GetSelector("foo",data.responses);
  iter++;
  ENSURE(iter->second == data.om0_0);
  iter++;
  ENSURE(iter->second == data.om0_1);
  iter--;
  ENSURE(iter->second == data.om0_0);
  iter++;
  ENSURE(iter->second == data.om0_1);
}

TEST(base_empty_name)
{
  OMSelectionTestData  data;
  cout<<"Testing that OMSelectionDict returns base for empty name..."<<endl;
  I3OMSelectionDict dict;
  I3OMSelector iter = dict.GetSelector("",data.responses);
  ENSURE(iter->second == data.om_5_15);
  ENSURE(iter->first == OMKey(-5,15));
  iter++;
  ENSURE(iter->second == data.om0_0);
  ENSURE(iter->first == OMKey(0,0));
  iter++;
  ENSURE(iter->second == data.om0_1);
  ENSURE(iter->first == OMKey(0,1));
  iter++;
  ENSURE(iter->second == data.om0_2);
  ENSURE(iter->first == OMKey(0,2));
  iter++;
  ENSURE(iter->second == data.om0_3);
  ENSURE(iter->first == OMKey(0,3));
  iter++;
  ENSURE(iter->second == data.om1_0);
  ENSURE(iter->first == OMKey(1,0));
  iter++;
  ENSURE(iter->second == data.om1_1);
  ENSURE(iter->first == OMKey(1,1));
  iter++;
  ENSURE(iter->second == data.om1_2);
  ENSURE(iter->first == OMKey(1,2));
  iter++;
  ENSURE(iter->second == data.om1_3);
  ENSURE(iter->first == OMKey(1,3));
  iter++;
  ENSURE(iter->second == data.om7_12);
  ENSURE(iter->first == OMKey(7,12));
  iter++;
  ENSURE(iter->second == data.om14_39);
  ENSURE(iter->first == OMKey(14,39));
  iter++;
  ENSURE(iter->second == data.om26_2);
  ENSURE(iter->first == OMKey(26,2));
  iter++;
  ENSURE(iter->second == data.om80_60);
  ENSURE(iter->first == OMKey(80,60));
  iter++;
  ENSURE(iter.base() == iter.end());
}

TEST(good_om_sel)
{
  OMSelectionTestData  data;
  cout<<"Testing GoodOMSelection..."<<endl;
  STLVectorStoragePolicy<OMKey> oms;
  oms.push_back(OMKey(-5,15));
  oms.push_back(OMKey(1,2));
  oms.push_back(OMKey(1,3));
  oms.push_back(OMKey(4,13));
  
  I3OMResponseSelectionPtr omrs(new I3GoodOMSelection(oms));
  I3OMSelectionDict dict;
  dict["foo"] = omrs;
  I3OMSelector iter = dict.GetSelector("foo",data.responses);
  ENSURE(iter->second == data.om_5_15);
  iter++;
  ENSURE(iter->second == data.om1_2);
  iter++;
  ENSURE(iter->second == data.om1_3);
  iter++;
  ENSURE(iter.base() == iter.end());
}    

TEST(bad_om_sel)
{
  OMSelectionTestData  data;
  cout<<"Testing BadOMSelection..."<<endl;
  STLVectorStoragePolicy<OMKey> oms;
  oms.push_back(OMKey(-5,15));
  oms.push_back(OMKey(1,2));
  oms.push_back(OMKey(1,3));
  oms.push_back(OMKey(4,13));
  
  I3OMResponseSelectionPtr omrs(new I3BadOMSelection(oms));
  I3OMSelectionDict dict;
  dict["foo"] = omrs;
  I3OMSelector iter = dict.GetSelector("foo",data.responses);
  ENSURE(iter->second == data.om0_0);
  ENSURE(iter->first == OMKey(0,0));
  iter++;
  ENSURE(iter->second == data.om0_1);
  ENSURE(iter->first == OMKey(0,1));
  iter++;
  ENSURE(iter->second == data.om0_2);
  ENSURE(iter->first == OMKey(0,2));
  iter++;
  ENSURE(iter->second == data.om0_3);
  ENSURE(iter->first == OMKey(0,3));
  iter++;
  ENSURE(iter->second == data.om1_0);
  ENSURE(iter->first == OMKey(1,0));
  iter++;
  ENSURE(iter->second == data.om1_1);
  ENSURE(iter->first == OMKey(1,1));
  iter++;
  ENSURE(iter->second == data.om7_12);
  ENSURE(iter->first == OMKey(7,12));
  iter++;
  ENSURE(iter->second == data.om14_39);
  ENSURE(iter->first == OMKey(14,39));
  iter++;
  ENSURE(iter->second == data.om26_2);
  ENSURE(iter->first == OMKey(26,2));
  iter++;
  ENSURE(iter->second == data.om80_60);
  ENSURE(iter->first == OMKey(80,60));
  iter++;
  ENSURE(iter.base() == iter.end());
}    


