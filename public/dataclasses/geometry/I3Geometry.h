/**
 *
 * copyright  (C) 2004
 * the icecube collaboration
 * @version n$Id$
 * @file I3Geometry.h
 * @date $Date$
 */

#ifndef I3GEOMETRY_H_INCLUDED
#define I3GEOMETRY_H_INCLUDED

#include "dataclasses/Utility.h"
#include "dataclasses/geometry/I3InIceGeometry.h"
#include "dataclasses/geometry/I3TopGeometry.h"
#include "dataclasses/I3Time.h"
#include <icetray/I3FrameTraits.h>

/**
 * @brief Top-level container of Geometry information
 * 
 * This class stores the information from the Geometry stream.
 * Records for IceCube InIce and AMANDA OMs are in the
 * I3InIceGeometry, and IceTop tanks are stored in the I3TopGeometry.  
 */
class I3Geometry : public TObject 
{
  I3InIceGeometry inIce_; 
  I3TopGeometry top_; 
  I3Time startTime_;
  I3Time endTime_;
 public:

  I3Geometry(){};

  virtual ~I3Geometry();

  /**
   * Gets the start Time for this header
   */
  I3Time GetStartTime() const { return startTime_;}

  /**
   * Sets the start Time for this header
   */
  void SetStartTime(const I3Time& t) { startTime_ = t;}

  /**
   * Sets the ending time for this header
   */
  void SetEndTime(const I3Time& t){endTime_ = t;}

  /**
   * Gets the ending time for this header
   */
  I3Time GetEndTime() const { return endTime_;}

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

  I3Geometry(const I3Geometry& geometry);
  const I3Geometry& operator=(const I3Geometry& geometry);

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

template<>
struct I3FrameTraits<I3Geometry>
{
  static const char* defaultName;
};

template<>
struct I3FrameTraits<const I3Geometry>
{
  static const char* defaultName;
};

I3_POINTER_TYPEDEFS(I3Geometry);

#endif // I3GEOMETRY_H_INCLUDED

