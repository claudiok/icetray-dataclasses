/**
    copyright  (C) 2004
    the icecube collaboration
    $Id:  $

    @version $Revision:  $
    @author blaufuss

*/

#include <I3Test.h>

#include "dataclasses/geometry/I3Geometry.h"


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

  //Now. lets' try to access....
  
  double hitx = georef.omgeo.at(keyone).position.GetX(); 

}
