/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3GeometryTest.cxx,v 1.2 2004/07/06 14:15:27 pretz Exp $

    @version $Revision: 1.2 $
    @date $Date: 2004/07/06 14:15:27 $
    @author pretz

    @todo

*/
 
#include "test/tut.h"

#include "dataclasses/I3Geometry.h"
#include "dataclasses/I3OMGeoIceCube.h"
#include "dataclasses/I3OMGeoAMANDA.h"
#include "TFile.h"
#include "TTree.h"
#include "TClass.h"
#include <string>
using std::string;
using std::cout;
using std::endl;

namespace tut
{
  struct I3GeometryTest
  {
  };
    
  typedef test_group<I3GeometryTest> factory;

  typedef factory::object object;
}

namespace
{
  tut::factory t("I3GeometryTest");
}

namespace tut
{
  template<> template<>
  void object::test<1>()
  {
  I3Geometry *geometry = new I3Geometry(); 
  I3OMGeoIceCubePtr om_icecube( new I3OMGeoIceCube());
  om_icecube->SetX(10.5);

  geometry->GetInIceGeometry().push_back(om_icecube);      
  TTree *t = new TTree("mytree","tree");
  cout<<geometry->GetInIceGeometry().size()<<endl;
      
  t->Branch("branch","I3Geometry",&geometry);
  
  t->Fill();
  
  I3Geometry *geo_out = new I3Geometry;
  t->SetBranchAddress("branch",&geo_out);
  ensure("checking array sizes",
	 geometry->GetInIceGeometry().size() 
	 == geo_out->GetInIceGeometry().size());

  t->GetEvent(0);
  }

  // branch empty 
  //   template<> template<>
  //   void object::test<2>() 
  //   {
  //     I3Geometry geometry;
  //     I3Geometry* geometry_ptr;
  
  //     TTree *t = new TTree("mytree","tree");
  
  //     t->Branch("branch","I3Geometry",&geometry_ptr);
  
  //     t->Fill();
  
  //     I3Geometry *geo_out = new I3Geometry;
  
  //     t->SetBranchAddress("branch",&geo_out);
  
  //     t->GetEvent(0);
  
  //     I3GeometryPtr geo_out_ptr(geo_out);
  //    delete geometry;
  //delete geo_out;
  //  }
  
  //testing filling an event with tracks into a tree
  //   template<> template<>
  //   void object::test<3>() // dont need to start with 1
  //  {
  //     I3Geometry *geometry = new I3Geometry(); 
  //     I3OMGeoIceCubePtr om_icecube( new I3OMGeoIceCube());
  
  //     TTree *t = new TTree("mytree","tree");
  
  //     t->Branch("branch","I3Geometry",&geometry);
  
  //     t->Fill();
  
  //     I3Geometry *geo_out = new I3Geometry;
  //     t->SetBranchAddress("branch",&geo_out);
  
  //     t->GetEvent(0);
  
  //delete geometry;
  //delete geo_out;
  //  }
}
