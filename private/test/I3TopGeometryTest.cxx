/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3TopGeometryTest.cxx,v 1.7.2.1 2005/01/25 23:33:44 troy Exp $

    @version $Revision: 1.7.2.1 $
    @date $Date: 2005/01/25 23:33:44 $
    @author pretz

    @todo
*/

#include "TUT/tut.h"

#include <string>

#include <TFile.h>

#include "dataclasses/I3TopGeometry.h"
#include "dataclasses/I3StationMap.h"
#include "dataclasses/I3StationGeo.h"
#include "dataclasses/I3SurfModuleGeo.h"
#include "dataclasses/I3TankGeo.h"
#include "dataclasses/I3OMGeoIceTop.h"


namespace tut
{
  struct I3TopGeometryTest
  {
  };

  typedef test_group<I3TopGeometryTest> factory;

  typedef factory::object object;
}

namespace
{
  static tut::factory t("I3TopGeometryTest");
}

namespace tut
{
  template<> template<>
  void object::test<1>() 
  {
    I3TopGeometry geo;

    // get the station map:
    I3StationMap &array = geo.GetStationMap ();

    // create the setup, from inside to outside
    I3OMGeoIceTopPtr om (new I3OMGeoIceTop);
    I3TankGeoPtr tank (new I3TankGeo);
    I3StationGeoPtr station (new I3StationGeo);

    // positions
    I3Position p_om (I3Position (-.5, 0., 0.));
    I3Position p_tank (I3Position (1., 2., 3.));
    
    om->SetPos (p_om);
    tank->SetPos (p_tank);
    
    // insert the om into the tank
    (*tank)[OMKey (1, 61)] = om;

    // insert the tank into the station
    station->push_back (tank);

    // insert the station into the array
    array[StationKey (1)] = station;
  }
}
