/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3TankGeo.h,v 1.15.4.2 2005/02/04 21:51:03 troy Exp $
 *
 * @file I3TankGeo.h
 * @version $Revision: 1.15.4.2 $
 * @date $Date: 2005/02/04 21:51:03 $
 * @author PN Thu Feb 19 11:48:23 EST 2004
 */
#ifndef __I3TANKGEO_H_
#define __I3TANKGEO_H_

#include <iostream>

#include "dataclasses/I3TankMaterial.h"
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
  Double_t GetRadius() const { return fRadius; }
  void SetRadius(Double_t r) { fRadius = r; }

  /**
   * The tank height (overall height), as simulated in tanktop.
   */
  Double_t  GetHeight() const { return fHeight; }
  void SetHeight(Double_t h) { fHeight = h; }

  /**
   * THe filling height
   */
  Double_t GetFillHeight () const { return fFillHeight; }
  void SetFillHeight (Double_t h) { fFillHeight = h; }

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

  Double_t fRadius; // radius of the tank
  Double_t fHeight; // height of the tank

  Double_t fFillHeight; // fill height of the tank


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
typedef PtrPolicy<I3TankGeo>::ThePolicy I3TankGeoPtr;

#endif

