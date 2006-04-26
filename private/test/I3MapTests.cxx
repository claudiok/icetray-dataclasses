/**
    copyright  (C) 2004
    the icecube collaboration
    $Id:  $

    @version $Revision:  $
    @author blaufuss

*/

#include <I3Test.h>

#include "dataclasses/geometry/I3Geometry.h"
#include "dataclasses/Utility.h"

TEST_GROUP(I3MapStuff);

/**
 * Check getting an item out.
 */

TEST(GetOMGeoX)
{
  I3Geometry geo;
  const I3Geometry& georef = geo;
  I3OMGeo omone;
  I3OMGeo omtwo;
  I3Position posone(100.0,200.0,300.0);
  I3Position postwo(110.0,210.0,310.0);
  OMKey keyone(21,22);
  OMKey keytwo(31,32);


  omone.position = posone;
  omtwo.position = postwo;

  // Const cast to fake getting a const object from frame.
  const_cast<I3Geometry&>(georef).omgeo[keyone] = omone;
  const_cast<I3Geometry&>(georef).omgeo[keytwo] = omtwo;

  //Now. lets' try to access....using at
  
  double hitx = georef.omgeo.at(keyone).position.GetX(); 
  ENSURE_DISTANCE(hitx,posone.GetX(),0.01,"Bad X value from map");

  //Look for something not there.
  OMKey fives(5,5);
  try{
    georef.omgeo.at(fives).position.GetX();
    FAIL("That at() call should not work");
  } catch (const std::exception&e) { }

}


TEST(stlmapwithI3Get)
{
  map<string,int> m;
  m["hello"] = 5;
  cout<<I3::Get("hello",m)<<endl;
  ENSURE_EQUAL(I3::Get("hello",m),5,"non-const map");

  const map<string,int>& cm = m;
  cout<<I3::Get("hello",cm)<<endl;
  ENSURE_EQUAL(I3::Get("hello",cm),5,"non-const map");

  try 
    {
      cout<<I3::Get("foo",m)<<endl;
      ENSURE(0,"Should have thrown");
    }
  catch(const exception& e)
    {

    }

  try 
    {
      cout<<I3::Get("foo",cm)<<endl;
      ENSURE(0,"Should have thrown");
    }
  catch(const exception& e)
    {

    }

}


TEST(I3MapwithI3Get)
{
  I3Map<string,int> m;
  m["hello"] = 5;
  cout<<I3::Get("hello",m)<<endl;
  ENSURE_EQUAL(I3::Get("hello",m),5,"non-const map");

  const I3Map<string,int>& cm = m;
  cout<<I3::Get("hello",cm)<<endl;
  ENSURE_EQUAL(I3::Get("hello",cm),5,"non-const map");

  try 
    {
      cout<<I3::Get("foo",m)<<endl;
      ENSURE(0,"Should have thrown");
    }
  catch(const exception& e)
    {

    }

  try 
    {
      cout<<I3::Get("foo",cm)<<endl;
      ENSURE(0,"Should have thrown");
    }
  catch(const exception& e)
    {

    }

}


TEST(I3MapwithI3GetandOMKeys)
{
  I3Map<OMKey,int> m;
  m[OMKey(4,5)] = 5;
  cout<<I3::Get(OMKey(4,5),m)<<endl;
  ENSURE_EQUAL(I3::Get(OMKey(4,5),m),5,"non-const map");

  const I3Map<OMKey,int>& cm = m;
  cout<<I3::Get(OMKey(4,5),cm)<<endl;
  ENSURE_EQUAL(I3::Get(OMKey(4,5),cm),5,"non-const map");

  try 
    {
      cout<<I3::Get(OMKey(4,4),m)<<endl;
      ENSURE(0,"Should have thrown");
    }
  catch(const exception& e)
    {

    }

  try 
    {
      cout<<I3::Get(OMKey(4,4),cm)<<endl;
      ENSURE(0,"Should have thrown");
    }
  catch(const exception& e)
    {

    }

}
