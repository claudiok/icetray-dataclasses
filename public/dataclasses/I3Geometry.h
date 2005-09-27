/**
 *
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file I3Geometry.h
 * @version $Revision: 1.31 $
 * @date $Date$
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
  I3InIceGeometry inIce_; //||;
  I3TopGeometry top_; //||
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
  const I3InIceGeometry& GetInIceGeometry() const { return inIce_;}

  /**
   * @return the In-Ice geometry as a non-const object
   */
  I3InIceGeometry& GetInIceGeometry() { return inIce_;}

  /**
   * @return the IceTop geometry as a const object
   */
  const I3TopGeometry& GetIceTopGeometry() const{ return top_; }

  /**
   * @return the IceTop geometry as a non-const object
   */
  I3TopGeometry& GetIceTopGeometry() { return top_; }

  /**
   * streams the geometry to the given ostream
   */
  virtual void ToStream(ostream& o) const
    {
      o<<"[ I3Geometry\n"
       <<inIce_
			//<<top_
       <<"]\n";
    }

 private:

  //ROOT macro
  ClassDef(I3Geometry,1);

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
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
typedef shared_ptr<I3Geometry>  I3GeometryPtr;


#endif // I3GEOMETRY_H

