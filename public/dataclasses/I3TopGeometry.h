/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3TopGeometry.h,v 1.16.2.2 2005/02/04 21:51:03 troy Exp $
 *
 * @file I3TopGeometry.h
 * @version $Revision: 1.16.2.2 $
 * @date $Date: 2005/02/04 21:51:03 $
 * @author Peter Niessen Thu Feb 19 12:48:42 EST 2004
 */
#ifndef __I3TOPGEOMETRY_H_
#define __I3TOPGEOMETRY_H_

#include "I3DataExecution.h"
#include "dataclasses/I3StationMap.h"
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

  /**
   * Constructor
   */
  I3TopGeometry () {}

  /**
   * Virtual Destructor
   */
  virtual ~I3TopGeometry(){}

  /**
   * return the Station map as a const object
   */
  const I3StationMap &GetStationMap () const {
    return fStationMap;
  }

  /**
   * return the Station map as a non-const object
   */
  I3StationMap &GetStationMap () {
    return fStationMap;
  }

 private:

  I3StationMap fStationMap; //|| the stations
 


};

/**
 * pointer type to insulate users from memory management
 */
typedef PtrPolicy<I3TopGeometry>::ThePolicy I3TopGeometryPtr;


#endif
