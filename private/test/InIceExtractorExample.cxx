/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: InIceExtractorExample.cxx,v 1.2 2004/06/30 17:20:26 pretz Exp $

    @version $Revision: 1.2 $
    @date $Date: 2004/06/30 17:20:26 $
    @author Troy D. Straszheim

    @todo

    Example of how to extract stuff from a polymorphic vector
*/

#include "test/tut.h"

#include "dataclasses/I3InIceGeometry.h"
#include "dataclasses/I3OMGeoAmanda.h"
#include "dataclasses/I3OMGeoIcecube.h"
#include "dataclasses/I3OMGeo.h"
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
  // here's simple function that takes a pointet an I3OMGeo and sets
  // its fields to random values
  void SetOMRandomValues (I3OMGeoPtr p) 
  {
    p->SetOMNumber(rand()%1024);
    p->SetX(rand()/0.002);
    p->SetY(rand()/0.002);
    p->SetZ(rand()/0.002);
  }

  // this prints an OM
  void PrintOM (I3OMGeoPtr p) 
  {
    cout << "[" << p->iam() 
	 << " #" << p->GetOMNumber() 
	 << " X:" << p->GetX() 
	 << " Y:" << p->GetY() 
	 << " Z:" << p->GetZ() 
	 << "]" << endl; 
  }

  struct AmandaExtractor
  {
    // I could just make this another I3InIceGeometry, but 
    // not until we get our pointainers/smartpointers figured completely out.
    vector<I3OMGeoAmandaPtr> &mygeometry_;

    // this is the constructor.  We pass this function object a the
    // other vector that we want it to fill
    AmandaExtractor(vector<I3OMGeoAmandaPtr> &geometry_to_fill) 
      : mygeometry_(geometry_to_fill) { };

    void operator()(I3OMGeoPtr p) {
      I3OMGeoAmandaPtr amandap = dynamic_cast<I3OMGeoAmandaPtr>(p);
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
    // OMGeo/OMGeoAmanda/OMGeoIcecube
    for (int i=0; i<6; i++) {
      geometry.push_back(new I3OMGeoAmanda);
      geometry.push_back(new I3OMGeoIcecube);
      geometry.push_back(new I3OMGeo);
    }

    // loop through this geometry (from begin() to end()) and print
    // each element print the geometry.  see function PrintOM() above
    cout << "INITIAL PRINTOUT OF I3Geometry" << endl;
    for_each(geometry.begin(), geometry.end(), PrintOM);

    // Let's loop through the geometry and call SetOMRandomValues on
    // each member. this "for_each" technique is quicker and safer
    // than using loops, and it works on maps, lists, deques, sets,
    // all of that.  Some of our OM's may have duplicate OMNumber
    // values, that is OK for the purposes of this Example.
    for_each(geometry.begin(), geometry.end(), SetOMRandomValues);
      
    // "random_shuffle" is an STL algorithm.  It does what you think.
    random_shuffle(geometry.begin(), geometry.end());  

    // Now let's see it again
    cout << "SHUFFLED, RANDOMIZED I3Geometry" << endl;
    for_each(geometry.begin(), geometry.end(), PrintOM);

    // Let's get the GeoAmandas out, we want our own vector of
    // pointers to them to play with.  We use the "AmandaExtractor"
    // function object, above.
    vector<I3OMGeoAmandaPtr> amanda_geometry;
    // we could just use another I3InIceGeometry, but the pointainer
    // thing makes this difficult as we get double deletes at the end.

    // create an extractor object, pass the amanda_geometry to the
    // constructor
    AmandaExtractor the_extractor(amanda_geometry);

    // now for_each will call the "parenthesis operator", or
    // "operator()" of the_extractor, which puts the ones it likes
    // into amanda_geometry
    for_each(geometry.begin(), geometry.end(), the_extractor);

    // let's see what's in our new array, should be just omgeoamandas
    cout << "AMANDAS ONLY, UNSORTED" << endl;
    for_each(amanda_geometry.begin(), amanda_geometry.end(), PrintOM);

    // now let's sort 'em by OM Number and see 'em again
    cout << "AMANDAS ONLY SORTED BY OMNUMBER" << endl;
    sort(amanda_geometry.begin(), amanda_geometry.end(), OMNumber_lessthan);
    for_each(amanda_geometry.begin(), amanda_geometry.end(), PrintOM);
  }
}

