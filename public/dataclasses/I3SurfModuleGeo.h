/**
 * copyright (C) 2004
 * the icecube collaboration
 * $Id: I3SurfModuleGeo.h,v 1.2 2004/09/14 17:10:05 niessen Exp $
 *
 * @file I3SurfModuleGeo.h
 * @version $Revision: 1.2 $
 * @date $Date: 2004/09/14 17:10:05 $
 * @author niessen Thu Sep  2 12:02:04 EDT 2004
 */

#ifndef I3SURFDETGEO_H
#define I3SURFDETGEO_H

#include <TObject.h>

#include "dataclasses/I3Constants.h"
//#include "dataclasses/I3InIceGeometry.h"
#include "dataclasses/OMKey.h"
#include "dataclasses/I3OMGeo.h"
#include "dataclasses/StoragePolicy.h"

/**
 * @brief Class describing the commons of surface detectors
 *
 * To be able to aggregate stations from both SPASE modules as well as
 * IceTop tanks, we need something common, just like it is the case
 * which the I3OMGeoAMANDA and I3OMGeoIceCube. Because the IceTop tank
 * has OMs inserted into it, it stores OM references/pointers. This
 * this list is empty for SPASE. The orientantion gives the position
 * away from grid north (in radians).
 */
class I3SurfModuleGeo : public TObject, public MapPolicy<OMKey, I3OMGeoPtr>::ThePolicy {

 public:

  /**
   * constructor
   */
  I3SurfModuleGeo () {}

  /**
   * virtual destructor
   */
  virtual ~I3SurfModuleGeo () {}

#if 0
  /**
   * Get the position of the tank
   */
  I3Position GetSurfModulePos() const {
    return fSurfModulePos;
  }

  /**
   * Set the position of the tank, in x, y and z
   */
  void SetSurfModulePos(I3Position pos) {
    fSurfModulePos.SetPosition(pos);
  }

  /**
   * Set the position of the tank, z is set to I3Constants::zIceTop
   */
  void SetSurfModulePos(Double_t x, Double_t y) {
    fSurfModulePos.SetPosition(x,y,I3Constants::zIceTop);
  }

  /**
   * Get the orientation 
   */
  Float_t GetOrientation () const {
    return fOrientation;
  }

  /**
   * Set the orientation
   */
  void SetOrientation (Float_t orientation) {
    fOrientation = orientation;
  }

  /**
   * Get the version (whatever this is.)
   */
  UChar_t GetVersion() const {
    return fVersion;
  }

  /**
   * Set the version (whatever it is.)
   */
  void SetVersion(UChar_t version) {
    fVersion = version;
  }

 private:

  I3Position fSurfModulePos; // position of the surface detector

  Float_t fOrientation; // rotation angle around the z-axis. (radians)

  UChar_t fVersion; // some version number
#endif

  ClassDef (I3SurfModuleGeo, 1);

};

/**
 * hide the memory management from the user
 */
typedef PtrPolicy<I3SurfModuleGeo>::ThePolicy I3SurfModuleGeoPtr;

#endif
