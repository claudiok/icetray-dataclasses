/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3TankGeo.h,v 1.19 2005/04/12 18:55:28 dule Exp $
 *
 * @file I3TankGeo.h
 * @version $Revision: 1.19 $
 * @date $Date: 2005/04/12 18:55:28 $
 * @author PN Thu Feb 19 11:48:23 EST 2004
 */
#ifndef __I3TANKGEO_H_
#define __I3TANKGEO_H_

#include <iostream>

#include <TObject.h>

//#include "dataclasses/I3TankMaterial.h"
#include "dataclasses/I3SurfModuleGeo.h"
#include "dataclasses/StoragePolicy.h"
using namespace std;

/**
 * @brief Class which describes the single tank geometry
 * Actually, the tank filling is not needed because it is represented
 * in the selected photon propagation table.
 * @todo comment methods
 * @todo Should this class use something other than I3InIceGeometry?
 */
class I3TankGeo : public I3SurfModuleGeo {

  public:

  /**
   * constructor
   */
  I3TankGeo() {}

  /**
   * virtual destructor
   */
  virtual ~I3TankGeo() {}

  /**
   * The tank radius (outer radius)
   */
  double GetRadius() const { return radius_; }
  void SetRadius(double r) { radius_ = r; }

  /**
   * The tank height (overall height), as simulated in tanktop.
   */
  double  GetHeight() const { return height_; }
  void SetHeight(double h) { height_ = h; }

  /**
   * THe filling height
   */
  double GetFillHeight () const { return fillHeight_; }
  void SetFillHeight (double h) { fillHeight_ = h; }

  /**
   * @todo need more implementation here
   */
  virtual void ToStream(ostream& o) const
    {
      o<<" [ I3TankGeo ]";
    }

  virtual string ToString() const
    {
      ostringstream out;
      ToStream(out);
      return out.str();
    }

 private:

  double radius_; // radius of the tank
  double height_; // height of the tank

  double fillHeight_; // fill height of the tank

  ClassDef(I3TankGeo,2); // increased to 2 Thu Sep  2 16:13:52 EDT 2004
  // because some stuff moved up to I3SurfModuleGeo.
};

inline ostream& operator<<(ostream& o, const I3TankGeo tank)
{
  tank.ToStream(o);
  return o;
}

/**
 * a pointer type to insulate users from memory management
 */
typedef shared_ptr<I3TankGeo>  I3TankGeoPtr;

#endif

