/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3TopGeometryTest.cxx,v 1.4 2004/09/03 23:20:09 niessen Exp $

    @version $Revision: 1.4 $
    @date $Date: 2004/09/03 23:20:09 $
    @author pretz

    @todo
*/

#include "TUT/tut.h"

#include <string>

#include <TFile.h>

#include "dataclasses/I3TopGeometry.h"
#include "dataclasses/I3OMGeoIceTop.h"
#include "dataclasses/I3TankGeo.h"
#include "dataclasses/I3SurfModuleGeo.h"


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
  tut::factory t("I3TopGeometryTest");
}

namespace tut
{
  template<> template<>
  void object::test<1>() 
  {
    I3TopGeometry geo;

    // create the setup, from inside to outside
    I3OMGeoIceTopPtr om00 (new I3OMGeoIceTop);
    I3OMGeoIceTopPtr om01 (new I3OMGeoIceTop);
    I3OMGeoIceTopPtr om10 (new I3OMGeoIceTop);
    I3OMGeoIceTopPtr om11 (new I3OMGeoIceTop);

    I3OMGeoIceTop &om00_p = *om00; // create pointers for reference
    I3OMGeoIceTop &om01_p = *om01;
    I3OMGeoIceTop &om10_p = *om10;
    I3OMGeoIceTop &om11_p = *om11;

    I3Position p_om00 (I3Position (-.5, 0., 0.));
    I3Position p_om01 (I3Position (+.5, 0., 0.));
    I3Position p_om10 (I3Position (-.5, 0., 0.));
    I3Position p_om11 (I3Position (+.5, 0., 0.));

    om00->SetPos (p_om00);
    om01->SetPos (p_om01);
    om10->SetPos (p_om10);
    om11->SetPos (p_om11);

    I3TankGeoPtr tank0 (new I3TankGeo);
    tank0->SetHeight (45.0);
    //tank0->push_back (om00_p);
    //tank0->push_back (om01_p);
    I3TankGeoPtr tank1 (new I3TankGeo);
    tank1->SetHeight (90.0);
    //tank1->push_back (om10_p);
    //tank1->push_back (om11_p);

    I3TankGeo &tank0_p = *tank0;
    I3TankGeo &tank1_p = *tank1;

    I3StationGeoPtr station (new I3StationGeo);
    //station->push_back (tank0_p); // point to the 
    //station->push_back (tank1_p);

    // create the lists/maps in the geometry

    // the station
    geo.GetStationMap ()[StationKey (0)] = station;

    // the tanks
    geo.GetSurfModuleVector ().push_back (tank0);
    geo.GetSurfModuleVector ().push_back (tank1);

    // the oms
    geo.GetOMTopMap ()[OMKey (1, 61)] = om00;
    geo.GetOMTopMap ()[OMKey (1, 62)] = om01;
    geo.GetOMTopMap ()[OMKey (1, 63)] = om10;
    geo.GetOMTopMap ()[OMKey (1, 64)] = om11;

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
    
#if 0
    I3TankGeo &tank_0
      = dynamic_cast<I3TankGeo &>(geo_in->GetSurfModuleVector ()[0]);
    I3TankGeo &tank_1
      = dynamic_cast<I3TankGeo &>(geo_in->GetSurfModuleVector ()[1]);
    ensure("tank 0 height is right", tank_0.GetHeight () == 45.0);
    ensure("tank 1 height is right", tank_1.GetHeight () == 90.0);
    ensure("size of surfdet list is right",geo_in
	   ->GetSurfModuleVector ().size () == 2);
#endif
	   
  }

}
