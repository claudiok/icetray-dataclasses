/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3InIceGeometry.h,v 1.14 2004/07/07 19:05:57 pretz Exp $
 *
 * @file I3InIceGeometry.h
 * @version $Revision: 1.14 $
 * @date $Date: 2004/07/07 19:05:57 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 */
#ifndef I3INICEGEOMETRY_H
#define I3INICEGEOMETRY_H

#include <TObject.h>
#include <map>
#include "I3DataExecution.h"
#include "I3OMGeo.h"
#include "OMKey.h"
#include "StoragePolicy.h"
/**
 * @brief Right now just a containter for IceCube and AMANDA OMGeos. 
 *
 * This is the
 * the 'frozen-in-ice' information, as opposed to the stuff that changes.
 * @todo make copy and assignment private.  conflict with something in tests
 * @todo should the 'mapness' be incorporated in the same kind of
 * 'Storage Policy' we have for other classes?
 */

class I3InIceGeometry : public TObject, public map<OMKey,I3OMGeoPtr>
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
 
