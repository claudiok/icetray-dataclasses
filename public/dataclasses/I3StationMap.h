/**
 * copyright (C) 2004
 * the icecube collaboration
 * $Id: I3StationMap.h,v 1.2 2004/09/17 21:12:19 niessen Exp $
 *
 * @file I3StationMap.h
 * @version $Revision: 1.2 $
 * @date $Date: 2004/09/17 21:12:19 $
 * @author niessen Wed Sep  1 20:28:03 EDT 2004
 */


#ifndef I3STATIONMAP_H
#define I3STATIONMAP_H

#include <TObject.h>

#include "I3DataExecution.h"
#include "dataclasses/StationKey.h"
#include "dataclasses/I3StationGeo.h"
#include "dataclasses/I3TankGeo.h"
#include "dataclasses/StoragePolicy.h"

/**
 * @brief Class which allows looping over stations.
 *
 * This class is meant to allow looping over station, e.g. for trigger
 * considerations
 */
class I3StationMap : public TObject, public MapPolicy<StationKey, I3StationGeoPtr>::ThePolicy {

 public:

  /**
   * constructor
   */
  I3StationMap () {}

  /**
   * virtual destructor
   */
  virtual ~I3StationMap () {}

  /**
   * Just for debugging
   */
  void Hello () {
    log_info ("Hi, this is the station map.");
  }

  /**
   * Go to the first tank
   */
  void GoFirstTank ();

  /**
   * Get the next tank
   */
  I3TankGeo &GetNextTank ();

 private:

  ClassDef (I3StationMap, 1);

};

/**
 * isolate the user from the memory management
 */
typedef PtrPolicy<I3StationMap>::ThePolicy I3StationMapPtr;

#endif
