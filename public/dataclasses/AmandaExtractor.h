/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: AmandaExtractor.h,v 1.3 2004/07/03 18:40:57 troy Exp $
 *
 * @file AmandaExtractor.h
 * @version $Revision: 1.3 $
 * @date $Date: 2004/07/03 18:40:57 $
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
  //FIXME
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

