/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3AMANDAExtractor.h,v 1.2 2004/08/01 00:41:01 pretz Exp $
 *
 * @file I3AMANDAExtractor.h
 * @version $Revision: 1.2 $
 * @date $Date: 2004/08/01 00:41:01 $
 * @author Troy
 */

#ifndef I3AMANDAEXTRACTOR_H
#define I3AMANDAEXTRACTOR_H

#include "dataclasses/I3InIceGeometry.h"
#include "dataclasses/I3OMGeoAMANDA.h"
#include "dataclasses/I3OMGeoIceCube.h"
#include "dataclasses/I3OMGeo.h"
#include "dataclasses/OMKey.h"

/**
 * @brief An example extractor classes which can get data out of our
 * containers in a type-safe way.
 */
class I3AMANDAExtractor
{
  //FIXME
  // I could just make this another I3InIceGeometry, but 
  // not until we get our pointainers/smartpointers figured completely out.
  map<OMKey,I3OMGeoAMANDAPtr> &mygeometry_;

  // default constructor private and unimplemented
  I3AMANDAExtractor();

  public:

  /**
   * this is the constructor.  We pass this function object a the
   * other vector that we want it to fill
   * @param geometry_to_fill the map that we will extract the geometry
   * into
   */
  I3AMANDAExtractor(map<OMKey,I3OMGeoAMANDAPtr> &geometry_to_fill); 

  /**
   * the operator that will do the extraction.  When this operator is
   * applied to a particular pair, if the pair contains an I3OMGeoAMANDA,
   * then the OMGeo is appended to the geometry which the extractor is 
   * created with
   */
  void operator()(pair<OMKey,I3OMGeoPtr> the_pair);

};

#endif //I3AMANDAEXTRACTOR_H
