/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: AmandaExtractor.h,v 1.2 2004/04/27 13:35:23 pretz Exp $
 *
 * @file AmandaExtractor.h
 * @version $Revision: 1.2 $
 * @date $Date: 2004/04/27 13:35:23 $
 * @author Troy
 */
#include "dataclasses/I3InIceGeometry.h"
#include "dataclasses/I3OMGeoAmanda.h"
#include "dataclasses/I3OMGeoIcecube.h"
#include "dataclasses/I3OMGeo.h"

/**
 * @brief An example extractor classes which can get data out of our
 * containers in a type-safe way.
 */
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

