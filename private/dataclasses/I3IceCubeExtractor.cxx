#include "dataclasses/I3IceCubeExtractor.h"
#include "dataclasses/I3InIceGeometry.h"
#include "dataclasses/I3OMGeoAMANDA.h"
#include "dataclasses/I3OMGeoIceCube.h"
#include "dataclasses/I3OMGeo.h"

#include <iostream>
using namespace std;

I3IceCubeExtractor::I3IceCubeExtractor(map<OMKey,I3OMGeoIceCubePtr> &geometry_to_fill) 
  : mygeometry_(geometry_to_fill) { };

void I3IceCubeExtractor::operator() (pair<OMKey,I3OMGeoPtr> the_pair) 
{
  I3OMGeoPtr p = the_pair.second;
  I3OMGeoIceCubePtr amandap = boost::dynamic_pointer_cast<I3OMGeoIceCube>(p);
  // you could do whatever other filtering you want here

  if (amandap) 
    mygeometry_[the_pair.first] = amandap;
}



