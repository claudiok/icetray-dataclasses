/**
 * copyright (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file I3StationMap.h
 * @version $Revision: 1.6 $
 * @date $Date$
 * @author niessen Wed Sep  1 20:28:03 EDT 2004
 */


#ifndef I3STATIONMAP_H
#define I3STATIONMAP_H

#include <TObject.h>

#include "dataclasses/StationKey.h"
#include "dataclasses/I3StationGeo.h"
//#include "dataclasses/I3TankGeo.h"
#include "dataclasses/StoragePolicy.h"

/**
 * @brief Class which allows looping over stations.
 *
 * This class is meant to allow looping over station, e.g. for trigger
 * considerations
 */
class I3StationMap : public TObject, public map<StationKey, I3StationGeoPtr> {

 public:

  /**
   * constructor
   */
  I3StationMap () {}

  /**
   * virtual destructor
   */
  virtual ~I3StationMap();

  /**
   * Go to the first tank
   */
  void GoFirstTank ();

  /**
   * Get the next tank
   */
  //I3TankGeo &GetNextTank ();
  // commented out to remove compile-time warning

 private:

  friend class boost::serialization::access;

  template <class Archive>
  void serialize(Archive& ar, unsigned version);

};

/**
 * isolate the user from the memory management
 */
typedef shared_ptr<I3StationMap>  I3StationMapPtr;

#endif
