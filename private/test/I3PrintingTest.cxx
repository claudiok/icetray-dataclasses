
#include "TUT/tut.h"

// MODIFY: replace with include of the header file for the module you
// are testing, or whatever headers are necessary for this test.
#include "dataclasses/I3Event.h"
#include "dataclasses/I3OMGeoIceCube.h"
#include "dataclasses/I3OMResponse.h"
#include "dataclasses/I3DataReadout.h"
#include "dataclasses/I3AMANDAAnalogReadout.h"
#include "dataclasses/I3BasicTrack.h"
#include "dataclasses/I3TriggerDict.h"
#include "dataclasses/I3FilterDict.h"
#include "dataclasses/I3MCHit.h"
#include "dataclasses/I3Geometry.h"
#include "dataclasses/I3RecoResultRDMCFit.h"
#include "dataclasses/I3RecoResultAltTracks.h"
#include "dataclasses/I3MCTrack.h"
#include "dataclasses/I3MCCascade.h"
#include "services/I3Logging.h"

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
    event.GetOMResponseMap()[OMKey(1,1)] = resp;
    resp = I3OMResponsePtr(new I3OMResponse);
    event.GetOMResponseMap()[OMKey(1,2)]=resp;

    I3RecoResultRDMCFitPtr fit(new I3RecoResultRDMCFit);
    event.GetRecoResultDict()["f2kFit"]= fit;
    //      roost::static_pointer_cast<I3RecoResult>(fit);

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
    I3TriggerDict trigger;
    cout<<trigger;
    I3FilterDict filter;
    cout<<filter;
    I3MCHit mchit;
    mchit.SetTime(3.4);
    cout<<mchit;
  }


  template<> template<>
  void object::test<4>()
  {
    I3RecoResultAltTracks rrat;
    rrat["foo"] = I3MCTrackPtr(new I3MCTrack());
    rrat["bar"] = I3MCCascadePtr(new I3MCCascade());
    cout<<rrat<<endl;
    log_debug("here it is dumped to logging %s\n",rrat.ToStream().c_str());
  }
}
