/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3TankGeo.h,v 1.14 2004/09/03 23:32:08 niessen Exp $
 *
 * @file I3TankGeo.h
 * @version $Revision: 1.14 $
 * @date $Date: 2004/09/03 23:32:08 $
 * @author PN Thu Feb 19 11:48:23 EST 2004
 */
#ifndef __I3TANKGEO_H_
#define __I3TANKGEO_H_

#include <iostream>

#include <TObject.h>

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
  
  UChar_t fVersion; // some version number.

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
typedef PtrPolicy<I3TankGeo>::ThePolicy I3TankGeoPtr;

#endif

