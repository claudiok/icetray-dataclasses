/**
 * copyright (C) 2004
 * $Id: I3StationGeo.h,v 1.5 2005/04/08 20:59:00 olivas Exp $
 *
 * @file I3StationGeo.h
 * @version $Revision: 1.5 $
 * @date $Date: 2005/04/08 20:59:00 $
 * @author niessen Wed Sep  1 20:55:17 EDT 2004
 */

#ifndef __I3STATIONGEO_H_
#define __I3STATIONGEO_H_

#include <TObject.h>

#include "dataclasses/I3SurfModuleGeo.h"
#include "dataclasses/StoragePolicy.h"

/**
 * @brief "Geometry" of the station
 *
 * This actually is not a geometry. It's more, like a string, an
 * entity to organise the tanks into stations. From an organisational
 * point of view, this is on a level with I3TankGeo.
 */
class I3StationGeo : public TObject, public STLVectorStoragePolicy<I3SurfModuleGeoPtr> {

 public:

  /**
   * constructor
   */
  I3StationGeo () {}

  /**
   * virtual destructor
   */
  virtual ~I3StationGeo () {}

  /**
   * Say hello
   */
  void Hello () {
    log_info ("Hi, I'm a station");
  }


 private:

  ClassDef (I3StationGeo, 1);

};

typedef PtrPolicy<I3StationGeo>::ThePolicy I3StationGeoPtr;

#endif
 
