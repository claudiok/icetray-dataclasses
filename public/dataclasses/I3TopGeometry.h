/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3TopGeometry.h,v 1.14 2004/09/03 23:32:08 niessen Exp $
 *
 * @file I3TopGeometry.h
 * @version $Revision: 1.14 $
 * @date $Date: 2004/09/03 23:32:08 $
 * @author Peter Niessen Thu Feb 19 12:48:42 EST 2004
 */
#ifndef __I3TOPGEOMETRY_H_
#define __I3TOPGEOMETRY_H_

#include <TObject.h>

#include "I3DataExecution.h"
#include "dataclasses/I3OMTopMap.h"
#include "dataclasses/I3SurfModuleVector.h"
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
   * return the om map as a constant object
   */
  const I3OMTopMap &GetOMTopMap () const {
    return fOMMap;
  }

  /**
   * return the om map as a non-const object
   */
  I3OMTopMap &GetOMTopMap () {
    return fOMMap;
  }

  /**
   * return the tank vector as constant object
   */
  const I3SurfModuleVector &GetSurfModuleVector () const {
    return fSurfModuleVector;
  }

  /**
   * return the tank vector as a non-const object
   */
  I3SurfModuleVector &GetSurfModuleVector () {
    return fSurfModuleVector;
  }

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

  I3OMTopMap fOMMap; //||  the oms inside the tanks (/modules)
  
  I3SurfModuleVector fSurfModuleVector; //|| the tanks of a station

  I3StationMap fStationMap; //|| the stations
 
  ClassDef (I3TopGeometry,2);  // changed Thu Sep  2 17:08:19 EDT 2004

};

/**
 * pointer type to insulate users from memory management
 */
typedef PtrPolicy<I3TopGeometry>::ThePolicy I3TopGeometryPtr;


#endif
