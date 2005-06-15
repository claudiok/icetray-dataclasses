/**
 * copyright (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file I3SurfModuleGeo.h
 * @version $Revision: 1.7 $
 * @date $Date$
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
class I3SurfModuleGeo : public TObject, public STLMapStoragePolicy<OMKey, I3OMGeoPtr> {

 public:

  /**
   * constructor
   */
  I3SurfModuleGeo () {}

  /**
   * virtual destructor
   */
  virtual ~I3SurfModuleGeo () {}

  /**
   * Get the position of the tank
   */
  I3Position GetPos() const {
    return surfModulePos_;
  }

  /**
   * Set the position of the tank, in x, y and z
   */
  void SetPos (I3Position pos) {
    surfModulePos_.SetPosition(pos);
  }

  /**
   * Set the position of the tank, z is set to I3Constants::zIceTop
   */
  void SetPos (double x, double y) {
    surfModulePos_.SetPosition(x,y,I3Constants::zIceTop);
  }

  /**
   * Get the orientation 
   */
  float GetOrientation () const {
    return orientation_;
  }

  /**
   * Set the orientation
   */
  void SetOrientation (float orientation) {
    orientation_ = orientation;
  }

 private:

  I3Position surfModulePos_; // position of the surface detector

  float orientation_; // rotation angle around the z-axis. (radians)

  ClassDef (I3SurfModuleGeo, 1);

  friend class boost::serialization::access;

  template <class Archive>
  void serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3SurfModuleGeo",
		  base_object< STLMapStoragePolicy<OMKey, I3OMGeoPtr> >(*this));
    ar & make_nvp("surfModulePos",surfModulePos_);
    ar & make_nvp("orientation",orientation_);
  }

};

/**
 * hide the memory management from the user
 */
typedef shared_ptr<I3SurfModuleGeo>  I3SurfModuleGeoPtr;

#endif
