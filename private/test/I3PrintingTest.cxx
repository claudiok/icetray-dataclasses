
#include "test/tut.h"

// MODIFY: replace with include of the header file for the module you
// are testing, or whatever headers are necessary for this test.
#include "dataclasses/I3Event.h"
#include "dataclasses/I3OMGeoIceCube.h"
#include "dataclasses/I3OMResponse.h"
#include "dataclasses/I3DataReadout.h"
#include "dataclasses/I3AMANDAAnalogReadout.h"
#include "dataclasses/I3BasicTrack.h"
#include "dataclasses/I3TriggerData.h"
#include "dataclasses/I3FilterData.h"
#include "dataclasses/I3MCHit.h"
#include "dataclasses/I3Geometry.h"
#include "dataclasses/I3RecoResultRDMCFit.h"

#include "TList.h"
#include "TNamed.h"

#include <iostream>
#include <string>

using namespace std;

namespace tut
{
  struct I3PrintingTest
  {
  };

  typedef test_group<I3PrintingTest> factory;

  typedef factory::object object;
}

namespace
{
  tut::factory t("printing");
}

namespace tut
{
  template<> template<>
  void object::test<1>()
  {
    cout<<"Testing 'printing' an event"<<endl;
    cout<<"****************************"<<endl;
    I3Event event;

    I3OMResponsePtr resp(new I3OMResponse());
    event.GetOMResponseVect().push_back(resp);
    resp = I3OMResponsePtr(new I3OMResponse);
    event.GetOMResponseVect().push_back(resp);

    I3RecoResultRDMCFitPtr fit(new I3RecoResultRDMCFit);
    event.GetRecoResultDict()["f2kFit"]=fit;

    TNamed* n = new TNamed("Foo","");
    TObjectPtr obj(n);
    event.GetBag()["Object"] = obj;
    TList* l = new TList();
    obj = TObjectPtr(l);
    event.GetBag()["List"] = obj;
    cout<<event.GetBag().size()<<endl;

    cout<<event;
  }
  
  template<> template<>
  void object::test<2>() 
  {
    cout<<"Testing 'printing' a geometry"<<endl;
    cout<<"****************************"<<endl;
    I3Geometry geometry;
    I3OMGeoPtr geo(new I3OMGeoIceCube());
    geometry.GetInIceGeometry()[OMKey(1,1)] = geo;
    geo = I3OMGeoPtr(new I3OMGeoIceCube());
    geometry.GetInIceGeometry()[OMKey(1,2)] = geo;
    geo = I3OMGeoPtr((I3OMGeo*)0);
    geometry.GetInIceGeometry()[OMKey(99,99)] = geo;
    cout<<geometry;
  }

  template<> template<>
  void object::test<3>() 
  {
    cout<<"Testing 'printing' some random objects"<<endl;
    cout<<"****************************"<<endl;
    I3AMANDAAnalogReadout a;
    cout<<a;
    I3BasicTrack t;
    cout<<t;
    I3TriggerData trigger;
    cout<<trigger;
    I3FilterData filter;
    cout<<filter;
    I3MCHit mchit;
    mchit.SetTime(3.4);
    cout<<mchit;
  }
}
