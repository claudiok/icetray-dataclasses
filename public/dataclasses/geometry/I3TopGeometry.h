/**
 * copyright  (C) 2004
 * the icecube collaboration
 * @version $Id$
 * @file I3TopGeometry.h
 * @date $Date$
 */

#ifndef I3TOPGEOMETRY_H_INCLUDED
#define I3TOPGEOMETRY_H_INCLUDED

#include <TObject.h>

#include "dataclasses/geometry/I3StationMap.h"
#include "dataclasses/StationKey.h"
#include "dataclasses/StoragePolicy.h"

/**
 * @brief This is the surface (top) geometry. We have stations,
 * modules (tank/SPASE modules) and OMs in the modules. Stations,
 * modules and OMs are stored in separated objects for ease of looping
 * over them, but they carry pointers to establish relationships
 * (e.g. which station does a tank belong to).
 */
class I3TopGeometry : public TObject {

 public:

  I3TopGeometry () {}

  virtual ~I3TopGeometry();

  /**
   * return the Station map as a const object
   */
  const I3StationMap &GetStationMap () const {
    return stationMap_;
  }

  /**
   * return the Station map as a non-const object
   */
  I3StationMap &GetStationMap () {
    return stationMap_;
  }

  /**
   * Get the geometry of a certain module
   */
  I3OMGeoPtr GetOMGeoPtr (OMKey &om_key);

 private:

  I3StationMap stationMap_; // the stations

  friend class boost::serialization::access;

  template <class Archive>
  void serialize(Archive& ar, unsigned version);

};

/**
 * pointer type to insulate users from memory management
 */
typedef shared_ptr<I3TopGeometry>  I3TopGeometryPtr;


#endif //I3TOPGEOMETRY_H_INCLUDED
