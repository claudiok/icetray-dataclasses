#include "dataclasses/AmandaExtractor.h"
#include "dataclasses/I3InIceGeometry.h"
#include "dataclasses/I3OMGeoAmanda.h"
#include "dataclasses/I3OMGeoIcecube.h"
#include "dataclasses/I3OMGeo.h"

#include <iostream>
using namespace std;

AmandaExtractor::AmandaExtractor(vector<I3OMGeoAmandaPtr> &geometry_to_fill) 
  : mygeometry_(geometry_to_fill) { };

void AmandaExtractor::operator() (I3OMGeoPtr p) 
{

  I3OMGeoAmandaPtr amandap = boost::dynamic_pointer_cast<I3OMGeoAmanda>(p);
  // you could do whatever other filtering you want here

  if (amandap) 
    mygeometry_.push_back(amandap);
}



