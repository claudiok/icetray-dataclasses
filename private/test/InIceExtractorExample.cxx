/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: InIceExtractorExample.cxx,v 1.10 2004/07/29 16:02:51 pretz Exp $

    @version $Revision: 1.10 $
    @date $Date: 2004/07/29 16:02:51 $
    @author Troy D. Straszheim

    @todo

    Example of how to extract stuff from a polymorphic vector
*/

#include "test/tut.h"

#include "dataclasses/I3InIceGeometry.h"
#include "dataclasses/I3OMGeoAMANDA.h"
#include "dataclasses/I3OMGeoIceCube.h"
#include "dataclasses/I3OMGeo.h"
#include "dataclasses/I3Geometry.h"
#include <string>
#include <vector>

using std::string;
using std::cout;
using std::endl;

namespace tut
{
  struct InIceExtractorExample
  {
    I3InIceGeometry geometry;
  };

  typedef test_group<InIceExtractorExample> factory;
  typedef factory::object object;
}

namespace
{
  tut::factory t("InIceExtractorExample");
}

namespace tut
{
  //TDS: FIXME

  // here's simple function that takes a pointet an I3OMGeo and sets
  // its fields to random values
  void SetOMRandomValues (pair<OMKey,I3OMGeoPtr> the_pair) 
  {
    I3OMGeoPtr p = the_pair.second;
    ensure(p!=0);
    p->SetOMNumber(rand()%1024);
    p->SetX(rand()/0.002);
    p->SetY(rand()/0.002);
    p->SetZ(rand()/0.002);
  }

  // this prints an OM
  void PrintOMPtr(I3OMGeoPtr p)
  {
    ensure(p!=0);
    I3OMGeo::EOMType type = p->GetOMType();
    string the_type;
    if(type == I3OMGeo::AMANDA)
      the_type = "AMANDA";
    else if(type == I3OMGeo::IceCube)
      the_type == "IceCube";
    cout << "[" << the_type
	 << " #" << p->GetOMNumber() 
	 << " X:" << p->GetX() 
	 << " Y:" << p->GetY() 
	 << " Z:" << p->GetZ() 
	 << "]" << endl; 
  }

  void PrintOM (pair<OMKey,I3OMGeoPtr> the_pair) 
  {
    cout<<the_pair.first<<" ";
    I3OMGeoPtr p = the_pair.second;
    PrintOMPtr(p);
  }

  struct AMANDAExtractor
  {
    // I could just make this another I3InIceGeometry, but 
    // not until we get our pointainers/smartpointers figured completely out.
    vector<I3OMGeoAMANDAPtr> &mygeometry_;

    // this is the constructor.  We pass this function object a the
    // other vector that we want it to fill
    AMANDAExtractor(vector<I3OMGeoAMANDAPtr> &geometry_to_fill) 
      : mygeometry_(geometry_to_fill) { };

    void operator()(pair<OMKey,I3OMGeoPtr> the_pair) {
      I3OMGeoPtr p = the_pair.second;
      I3OMGeoAMANDAPtr amandap = boost::dynamic_pointer_cast<I3OMGeoAMANDA>(p);
      if (amandap) mygeometry_.push_back(amandap);
    }
  };

  // for sorting by OMNumber
  bool OMNumber_lessthan(I3OMGeoPtr l, I3OMGeoPtr r) {
    return (l->GetOMNumber() < r->GetOMNumber());
  }

  //
  //  Here's the main test routine.  You should (I will make a demo
  //  and figure out the kinks) be able to do everything inside the
  //  function below inside a root session, interactively.  The
  //  dynamic_casts<> wont work if fed directly to root, but if they
  //  are in little precompiled functions it should be OK.  Again I'm
  //  looking at this next.
  //
  //  Now let's exercise the geometry a bit with generic programming
  //  techniques:
  //
  //  Again, this would be a little clearer in real life, the testing
  //  framework adds a little bit of distraction here
  template<> template<>
  void object::test<1>()
  {
    // Make a 30 entry-long I3Geometry with 10 each of
    // OMGeo/OMGeoAMANDA/OMGeoIceCube
    for (int i=0; i<6; i++) {
      geometry[OMKey(1,i)] = new I3OMGeoAMANDA;
      geometry[OMKey(2,i)] = new I3OMGeoIceCube;
    }
  
      // loop through this geometry (from begin() to end()) and print
    // each element print the geometry.  see function PrintOM() above
    cout << "INITIAL PRINTOUT OF I3Geometry" << endl;

    for_each(geometry.begin(),geometry.end(),PrintOM);
  
    // Let's loop through the geometry and call SetOMRandomValues on
    // each member. this "for_each" technique is quicker and safer
    // than using loops, and it works on maps, lists, deques, sets,
    // all of that.  Some of our OM's may have duplicate OMNumber
    // values, that is OK for the purposes of this Example.
    for_each(geometry.begin(), geometry.end(), SetOMRandomValues);
    
    // not used anymore.  The map preserves the order.  -pretz
    //     // "random_shuffle" is an STL algorithm.  It does what you think.
    //     random_shuffle(geometry.begin(), geometry.end());  
    //     // Now let's see it again
    cout << "RANDOMIZED I3Geometry" << endl;
    for_each(geometry.begin(), geometry.end(), PrintOM);

//     // Let's get the GeoAMANDAs out, we want our own vector of
//     // pointers to them to play with.  We use the "AMANDAExtractor"
//     // function object, above.
    vector<I3OMGeoAMANDAPtr> amanda_geometry;

//     // we could just use another I3InIceGeometry, but the pointainer
//     // thing makes this difficult as we get double deletes at the end.

//     // create an extractor object, pass the amanda_geometry to the
//     // constructor
    AMANDAExtractor the_extractor(amanda_geometry);

//     // now for_each will call the "parenthesis operator", or
//     // "operator()" of the_extractor, which puts the ones it likes
//     // into amanda_geometry
    for_each(geometry.begin(), geometry.end(), the_extractor);

//     // let's see what's in our new array, should be just omgeoamandas
    cout << "AMANDAS ONLY" << endl;
    for_each(amanda_geometry.begin(), amanda_geometry.end(), PrintOMPtr);

//     Not needed since now it's already sorted, being a map
//     // now let's sort 'em by OM Number and see 'em again
//     cout << "AMANDAS ONLY SORTED BY OMNUMBER" << endl;
//     sort(amanda_geometry.begin(), amanda_geometry.end(), OMNumber_lessthan);
//     for_each(amanda_geometry.begin(), amanda_geometry.end(), PrintOM);
  
      }

  // An example using the new OMKey access to the InIceGeometry
  template<> template<>
  void object::test<2>()
  {
    I3Geometry geometry;
    int str;
    unsigned int om;
    for(str=-3;str<=5;str++)
      for(om=1;om<=3;om++)
	{
	  if(str<0)
	    {
	      I3OMGeoAMANDAPtr omamanda(new I3OMGeoAMANDA());
	      omamanda->SetX(rand() %1000);
	      omamanda->SetY(rand() %1000);
	      omamanda->SetZ(rand() %1000);
	      geometry.GetInIceGeometry()[OMKey(str,om)] = omamanda;
	    }
	  if(str>0)
	    {
	      I3OMGeoIceCubePtr omicecube(new I3OMGeoIceCube());
	      omicecube->SetX(rand() %1000);
	      omicecube->SetY(rand() %1000);
	      omicecube->SetZ(rand() %1000);
	      geometry.GetInIceGeometry()[OMKey(str,om)] = omicecube;
	    }
	  
	}
    I3InIceGeometry::iterator iter;
    cout<<"\n";
    for(iter=geometry.GetInIceGeometry().begin();
	iter!=geometry.GetInIceGeometry().end();
	iter++)
      {
	cout<<iter->first.GetString()<<" "<<iter->first.GetOM()<<"\n";
      }
    cout<<endl;
    
  }
  
}

