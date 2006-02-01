/**
 * copyright (C) 2004
 * @version $Id$
 * @file I3StationGeo.h
 * @date $Date$
 */

#ifndef I3STATIONGEO_H_INCLUDED
#define I3STATIONGEO_H_INCLUDED

#include "dataclasses/I3Vector.h"

#include "dataclasses/geometry/I3SurfModuleGeo.h"
#include "dataclasses/StoragePolicy.h"
#include "dataclasses/geometry/I3OMGeo.h"
#include "dataclasses/OMKey.h"

/**
 * @brief "Geometry" of the station
 *
 * This actually is not a geometry. It's more, like a string, an
 * entity to organise the tanks into stations. From an organisational
 * point of view, this is on a level with I3TankGeo.
 */
class I3StationGeo : public I3Vector<I3SurfModuleGeoPtr> 
{

 public:

  I3StationGeo ();

  virtual ~I3StationGeo ();

  /**
   * Get the OM Geo of the OM with this key
   */
  I3OMGeoPtr GetOMGeoPtr (const OMKey &om_key);

 private:

  friend class boost::serialization::access;

  template <class Archive>
  void serialize(Archive& ar, unsigned version);

};

typedef shared_ptr<I3StationGeo>  I3StationGeoPtr;

#endif //I3STATIONGEO_H_INCLUDED
 
