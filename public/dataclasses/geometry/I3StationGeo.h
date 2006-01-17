/**
 * copyright (C) 2004
 * $Id$
 *
 * @file I3StationGeo.h
 * @version $Revision: 1.6 $
 * @date $Date$
 * @author niessen Wed Sep  1 20:55:17 EDT 2004
 */

#ifndef __I3STATIONGEO_H_
#define __I3STATIONGEO_H_

#include <TObject.h>

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
class I3StationGeo : public TObject, public vector<I3SurfModuleGeoPtr> {

 public:

  /**
   * constructor
   */
  I3StationGeo ();

  /**
   * virtual destructor
   */
  virtual ~I3StationGeo ();

  /**
   * Get the OM Geo of the OM with this key
   */
  I3OMGeoPtr GetOMGeoPtr (OMKey &om_key);

 private:

  friend class boost::serialization::access;

  template <class Archive>
  void serialize(Archive& ar, unsigned version);

};

typedef shared_ptr<I3StationGeo>  I3StationGeoPtr;

#endif
 