/**
 * copyright (C) 2004
 * the icecube collaboration
 * @version $Id$
 * @file I3StationMap.h
 * @date $Date$
 */


#ifndef I3STATIONMAP_H_INCLUDED
#define I3STATIONMAP_H_INCLUDED

#include "dataclasses/I3Map.h"

#include "dataclasses/StationKey.h"
#include "dataclasses/geometry/I3StationGeo.h"
#include "dataclasses/Utility.h"

/**
 * @brief Class which allows looping over stations.
 *
 * This class is meant to allow looping over station, e.g. for trigger
 * considerations
 */
class I3StationMap : public I3Map<StationKey, I3StationGeoPtr> 
{

 public:

  I3StationMap () {}

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

I3_POINTER_TYPEDEFS(I3StationMap);

#endif //I3STATIONMAP_H_INCLUDED
