#include "dataclasses/AMANDAExtractor.h"
#include "dataclasses/I3InIceGeometry.h"
#include "dataclasses/I3OMGeoAMANDA.h"
#include "dataclasses/I3OMGeoIceCube.h"
#include "dataclasses/I3OMGeo.h"

#include <iostream>
using namespace std;

AMANDAExtractor::AMANDAExtractor(vector<I3OMGeoAMANDAPtr> &geometry_to_fill) 
  : mygeometry_(geometry_to_fill) { };

void AMANDAExtractor::operator() (I3OMGeoPtr p) 
{

  I3OMGeoAMANDAPtr amandap = boost::dynamic_pointer_cast<I3OMGeoAMANDA>(p);
  // you could do whatever other filtering you want here

  if (amandap) 
    mygeometry_.push_back(amandap);
}



