/**
 *
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3InIceGeometry.h,v 1.2 2004/02/26 19:58:26 pretz Exp $
 *
 * Right now just a containter for IceCube and Amanda OMGeos. This is the
 * the 'frozen-in-ice' information, as opposed to the stuff that changes.
 *
 * @version $Revision: 1.2 $
 * @date $Date: 2004/02/26 19:58:26 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 * @todo should the copy and assignment be private?
 * @todo Move the header-like data into the GeometryHeader
*/


#ifndef I3INICEGEOMETRY_H
#define I3INICEGEOMETRY_H

#include <TObject.h>
#include "I3OMGeo.h"
#include "StoragePolicy.h"

class I3InIceGeometry : public TObject, public VectorPolicy<I3OMGeoPtr>::ThePolicy
{
 public:
  /** 
   * constructor
   */
  I3InIceGeometry(){};

  /**
   * default destructor
   */
  virtual ~I3InIceGeometry(){};

 private:
/*   // copy and assignment are private */
/*   I3InIceGeometry(const I3InIceGeometry& rhs); */
/*   const I3InIceGeometry& operator=(const I3InIceGeometry& rhs); */

  // ROOT macro
  ClassDef(I3InIceGeometry,1);
};

typedef PtrPolicy<I3InIceGeometry>::ThePolicy I3InIceGeometryPtr;

#endif //I3INICEGEOMETRY_H
 
