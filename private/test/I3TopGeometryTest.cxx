/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3TopGeometryTest.cxx,v 1.7 2004/10/11 07:06:10 troy Exp $

    @version $Revision: 1.7 $
    @date $Date: 2004/10/11 07:06:10 $
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

    TFile file_out("test.out.root","RECREATE");

    geo.Write();
    file_out.Close();
  }
  
  template<> template<>
  void object::test<2>()
  {
    TFile file_in("test.out.root");
    I3TopGeometryPtr geo_in((I3TopGeometry*)file_in.FindObjectAny("I3TopGeometry"));

    ensure("pointer is non-zero",geo_in!=0);

    I3StationMap &array = geo_in->GetStationMap ();
    
    I3StationGeo &station
      = *(array[StationKey (1)]);

    I3TankGeoPtr tank (roost::dynamic_pointer_cast<I3TankGeo>(station[0]));

    I3OMGeoIceTopPtr om (roost::dynamic_pointer_cast<I3OMGeoIceTop>((*tank)[OMKey (1, 61)]));

    ensure ("om is displaced", om->GetPos ().GetX () == -.5);

  }

}
