/**
 *
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Geometry.h,v 1.25 2004/07/19 16:46:01 pretz Exp $
 *
 * @file I3Geometry.h
 * @version $Revision: 1.25 $
 * @date $Date: 2004/07/19 16:46:01 $
 * @author ehrlich
 * @author troy
 * @author pretz
 */
#ifndef I3GEOMETRY_H
#define I3GEOMETRY_H

#include "StoragePolicy.h"
#include "I3InIceGeometry.h"
#include "I3TopGeometry.h"
/**
 * @brief Top-level container of Geometry information
 * 
 * This class stores the information from the Geometry stream.
 * Records for IceCube InIce and AMANDA OMs are in the
 * I3InIceGeometry, and IceTop tanks are stored in the I3TopGeometry.  
 */
class I3Geometry : public TObject 
{
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
  const I3InIceGeometry& GetInIceGeometry() const { return fInIce;}

  /**
   * @return the In-Ice geometry as a non-const object
   */
  I3InIceGeometry& GetInIceGeometry() { return fInIce;}

  /**
   * @return the IceTop geometry as a const object
   */
  const I3TopGeometry& GetIceTopGeometry() const{ return fTop; }

  /**
   * @return the IceTop geometry as a non-const object
   */
  I3TopGeometry& GetIceTopGeometry() { return fTop; }

  virtual void ToStream(ostream& o) const
    {
      o<<"[ I3Geometry\n"
       <<fInIce
	//<<fIceTopGeometry
       <<"]\n";
    }

 private:
  // copy and assignment private
  I3Geometry(const I3Geometry& rhs);
  const I3Geometry& operator=(const I3Geometry& rhs);

  //ROOT macro
  ClassDef(I3Geometry,1);
};

/** 
 * streaming operator
 */
inline ostream& operator<<(ostream& o,const I3Geometry& geo)
{
  geo.ToStream(o);
  return o;
}

/**
 * Pointer typedeffed away to insulate users from the
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3Geometry>::ThePolicy I3GeometryPtr;


#endif // I3GEOMETRY_H
