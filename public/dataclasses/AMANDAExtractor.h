/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: AMANDAExtractor.h,v 1.1 2004/07/06 14:15:31 pretz Exp $
 *
 * @file AMANDAExtractor.h
 * @version $Revision: 1.1 $
 * @date $Date: 2004/07/06 14:15:31 $
 * @author Troy
 */
#include "dataclasses/I3InIceGeometry.h"
#include "dataclasses/I3OMGeoAMANDA.h"
#include "dataclasses/I3OMGeoIceCube.h"
#include "dataclasses/I3OMGeo.h"

/**
 * @brief An example extractor classes which can get data out of our
 * containers in a type-safe way.
 */
class AMANDAExtractor
{
  //FIXME
  // I could just make this another I3InIceGeometry, but 
  // not until we get our pointainers/smartpointers figured completely out.
  vector<I3OMGeoAMANDAPtr> &mygeometry_;

  AMANDAExtractor();

  public:

  // this is the constructor.  We pass this function object a the
  // other vector that we want it to fill
  AMANDAExtractor(vector<I3OMGeoAMANDAPtr> &geometry_to_fill); 

  void operator()(I3OMGeoPtr p);

};

