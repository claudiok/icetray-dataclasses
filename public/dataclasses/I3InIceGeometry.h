/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3InIceGeometry.h,v 1.11 2004/04/27 02:32:05 pretz Exp $
 *
 * @file I3InIceGeometry.h
 * @version $Revision: 1.11 $
 * @date $Date: 2004/04/27 02:32:05 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 */
#ifndef I3INICEGEOMETRY_H
#define I3INICEGEOMETRY_H

#include <TObject.h>
#include "I3DataExecution.h"
#include "I3OMGeo.h"
#include "StoragePolicy.h"
/**
 * @brief Right now just a containter for IceCube and Amanda OMGeos. 
 *
 * This is the
 * the 'frozen-in-ice' information, as opposed to the stuff that changes.
 * @todo make copy and assignment private.  conflict with something in tests
 * @todo TDS: should contain two vectors, one by geonumber and one
 * with the current indexing scheme, whatever that is.  HasOMGeoNumber
 * and FindOmGeo both do the same thing (linear time search).  Lots of
 * wasted processing here.  Fatal error on "geo not found" makes no
 * sense.
 */

class I3InIceGeometry : public TObject, public VecPointainerPolicy<I3OMGeoPtr>::ThePolicy
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
  // I3InIceGeometry(const I3InIceGeometry& rhs); 
  // const I3InIceGeometry& operator=(const I3InIceGeometry& rhs); 

  // ROOT macro
  ClassDef(I3InIceGeometry,1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3InIceGeometry>::ThePolicy I3InIceGeometryPtr;

#endif //I3INICEGEOMETRY_H
 
