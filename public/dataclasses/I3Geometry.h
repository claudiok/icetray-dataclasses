#ifndef I3GEOMETRY_H
#define I3GEOMETRY_H

#include "StoragePolicy.h"
#include "I3InIceGeometry.h"
#include "I3TopGeometry.h"
/**
 *
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Geometry.h,v 1.15 2004/02/26 18:17:01 pretz Exp $
 *
 * The Geometry information for the IceCube detector.  There's the InIce
 * portion and the IceTop portion.  It is expected that AMANDA tubes
 * will be incorporated as additional kinds of InIce tubes.
 *
 * @version $Revision: 1.15 $
 * @date $Date: 2004/02/26 18:17:01 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 * @todo should the copy and assignment be private?
 * @todo Move the header-like data into the GeometryHeader
*/
class I3Geometry : public TObject{
  I3InIceGeometry fInIce; //||;
  I3TopGeometry fTop; //||
 public:
  /**
   * constructor
   */
  I3Geometry(){};

  /**
   * destructor
   */
  virtual ~I3Geometry(){};

  /**
   * @return the In-Ice geometry as a constant object
   */
  const I3InIceGeometry& InIceGeometry() const { return fInIce;}

  /**
   * @return the In-Ice geometry as a non-const object
   */
  I3InIceGeometry& InIceGeometry() { return fInIce;}

  /**
   * @return the IceTop geometry as a const object
   */
  const I3TopGeometry& IceTopGeometry() const{ return fTop; }

  /**
   * @return the IceTop geometry as a non-const object
   */
  I3TopGeometry& IceTopGeometry() { return fTop; }

 private:
  // copy and assignment private
  I3Geometry(const I3Geometry& rhs);
  const I3Geometry& operator=(const I3Geometry& rhs);

  //ROOT macro
  ClassDef(I3Geometry,1);
};

/**
 * Pointer typedeffed away to insulate users from the
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3Geometry>::ThePolicy I3GeometryPtr;


#endif // I3GEOMETRY_H
