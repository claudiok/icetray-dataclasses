#include "dataclasses/I3InIceGeometry.h"
#include "dataclasses/I3OMGeoAmanda.h"
#include "dataclasses/I3OMGeoIcecube.h"
#include "dataclasses/I3OMGeo.h"

class AmandaExtractor
{
  // I could just make this another I3InIceGeometry, but 
  // not until we get our pointainers/smartpointers figured completely out.
  vector<I3OMGeoAmandaPtr> &mygeometry_;

  AmandaExtractor();

  public:

  // this is the constructor.  We pass this function object a the
  // other vector that we want it to fill
  AmandaExtractor(vector<I3OMGeoAmandaPtr> &geometry_to_fill); 

  void operator()(I3OMGeoPtr p);

};

