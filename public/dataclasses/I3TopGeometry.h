/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3TopGeometry.h,v 1.16 2004/09/17 21:12:19 niessen Exp $
 *
 * @file I3TopGeometry.h
 * @version $Revision: 1.16 $
 * @date $Date: 2004/09/17 21:12:19 $
 * @author Peter Niessen Thu Feb 19 12:48:42 EST 2004
 */
#ifndef __I3TOPGEOMETRY_H_
#define __I3TOPGEOMETRY_H_

#include <TObject.h>

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

  /**
   * Just for test
   */
  void Hello () {
    log_info ("Hi, this is the top geometry");
  }

 private:

  I3StationMap fStationMap; //|| the stations
 
  ClassDef (I3TopGeometry,2);  // changed Thu Sep  2 17:08:19 EDT 2004

};

/**
 * pointer type to insulate users from memory management
 */
typedef PtrPolicy<I3TopGeometry>::ThePolicy I3TopGeometryPtr;


#endif
