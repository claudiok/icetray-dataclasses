/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3TopGeometry.h,v 1.13 2004/08/02 20:17:10 pretz Exp $
 *
 * @file I3TopGeometry.h
 * @version $Revision: 1.13 $
 * @date $Date: 2004/08/02 20:17:10 $
 * @author Peter Niessen Thu Feb 19 12:48:42 EST 2004
 */
#ifndef __I3TOPGEOMETRY_H_
#define __I3TOPGEOMETRY_H_

#include <TObject.h>

#include "I3DataExecution.h"
#include "dataclasses/I3TopStationGeo.h"
#include "dataclasses/StoragePolicy.h"

/**
 * @brief A station key used to access the IceTop stations.  
 *
 * It's just an integer.
 */
typedef int StationKey;

/**
 * @brief This is an collection of tanks.
 */
class I3TopGeometry : public TObject, public MapPolicy<StationKey,I3TopStationGeoPtr>::ThePolicy
{
 public:

  /**
   * Constructor
   */
  I3TopGeometry () {}

  /**
   * Virtual Destructor
   */
  virtual ~I3TopGeometry(){}

 private:
  ClassDef(I3TopGeometry,1);
};

/**
 * pointer type to insulate users from memory management
 */
typedef PtrPolicy<I3TopGeometry>::ThePolicy I3TopGeometryPtr;


#endif
