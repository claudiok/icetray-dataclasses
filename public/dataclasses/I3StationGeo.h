/**
 * copyright (C) 2004
 * $Id: I3StationGeo.h,v 1.2 2004/09/14 17:10:05 niessen Exp $
 *
 * @file I3StationGeo.h
 * @version $Revision: 1.2 $
 * @date $Date: 2004/09/14 17:10:05 $
 * @author niessen Wed Sep  1 20:55:17 EDT 2004
 */

#ifndef __I3STATIONGEO_H_
#define __I3STATIONGEO_H_

#include <TObject.h>

//#include "I3DataExecution.h"
//#include "dataclasses/I3TankGeo.h"
#include "dataclasses/I3SurfModuleGeo.h"
#include "dataclasses/StoragePolicy.h"

/**
 * @brief "Geometry" of the station
 *
 * This actually is not a geometry. It's more, like a string, an
 * entity to organise the tanks into stations. From an organisational
 * point of view, this is on a level with I3TankGeo.
 */
class I3StationGeo : public TObject, public VectorPolicy<I3SurfModuleGeoPtr>::ThePolicy {

 public:

  /**
   * constructor
   */
  I3StationGeo () {}

  /**
   * virtual destructor
   */
  virtual ~I3StationGeo () {}

 private:

  ClassDef (I3StationGeo, 1);

};

typedef PtrPolicy<I3StationGeo>::ThePolicy I3StationGeoPtr;

#endif
 
