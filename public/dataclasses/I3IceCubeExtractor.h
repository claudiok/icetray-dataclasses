/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3IceCubeExtractor.h,v 1.1 2004/07/30 02:47:56 pretz Exp $
 *
 * @file I3IceCubeExtractor.h
 * @version $Revision: 1.1 $
 * @date $Date: 2004/07/30 02:47:56 $
 * @author pretz
 */

#ifndef I3ICECUBEEXTRACTOR_H
#define I3ICECUBEEXTRACTOR_H

#include "dataclasses/I3InIceGeometry.h"
#include "dataclasses/I3OMGeoIceCube.h"
#include "dataclasses/I3OMGeoIceCube.h"
#include "dataclasses/I3OMGeo.h"
#include "dataclasses/OMKey.h"

/**
 * @brief An example extractor classes which can get data out of our
 * containers in a type-safe way.
 */
class I3IceCubeExtractor
{
  //FIXME
  // I could just make this another I3InIceGeometry, but 
  // not until we get our pointainers/smartpointers figured completely out.
  map<OMKey,I3OMGeoIceCubePtr> &mygeometry_;

  I3IceCubeExtractor();

  public:

  // this is the constructor.  We pass this function object a the
  // other vector that we want it to fill
  I3IceCubeExtractor(map<OMKey,I3OMGeoIceCubePtr> &geometry_to_fill); 

  void operator()(pair<OMKey,I3OMGeoPtr> the_pair);

};

#endif //I3ICECUBEEXTRACTOR_H
