/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3TopGeometryTest.cxx,v 1.1 2004/08/02 20:17:10 pretz Exp $

    @version $Revision: 1.1 $
    @date $Date: 2004/08/02 20:17:10 $
    @author pretz

    @todo
*/

#include "test/tut.h"

#include "dataclasses/I3TopGeometry.h"
#include "TFile.h"
#include <string>


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
  void object::test<1>() 
  {
    I3TopGeometry geo;
    
    I3TopStationGeoPtr station = new I3TopStationGeo();
    I3TankGeoPtr tank = new I3TankGeo();
    tank->SetTankHeight(45.0);
    geo[0] = station;
    station->push_back(tank);

    TFile file_out("test.out.root","RECREATE");
    

    geo.Write();
    file_out.Close();
    
    TFile file_in("test.out.root");
    I3TopGeometryPtr geo_in = 
      (I3TopGeometryPtr) file_in.FindObjectAny("I3TopGeometry");

    ensure("pointer is non-zero",geo_in!=0);
    
    ensure("size read-in is right",geo_in->size()==1);
    ensure("size of station geo is right",(*geo_in)[0]->size()==1);
    ensure("tank height is right",(*(*geo_in)[0])[0]->GetTankHeight() == 45.0);
  }

  void object::test<2>()
  {
  }

}
