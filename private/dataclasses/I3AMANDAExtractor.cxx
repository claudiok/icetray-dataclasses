#include "dataclasses/I3AMANDAExtractor.h"
#include "dataclasses/I3InIceGeometry.h"
#include "dataclasses/I3OMGeoAMANDA.h"
#include "dataclasses/I3OMGeoIceCube.h"
#include "dataclasses/I3OMGeo.h"

#include <iostream>
using namespace std;

I3AMANDAExtractor::I3AMANDAExtractor(map<OMKey,I3OMGeoAMANDAPtr> &geometry_to_fill) 
  : mygeometry_(geometry_to_fill) { };

void I3AMANDAExtractor::operator() (pair<OMKey,I3OMGeoPtr> the_pair) 
{
  I3OMGeoPtr p = the_pair.second;
  I3OMGeoAMANDAPtr amandap = dynamic_pointer_cast<I3OMGeoAMANDA>(p);
  // you could do whatever other filtering you want here

  if (amandap) 
    mygeometry_[the_pair.first] = amandap;
}



