/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3TopGeometry.h,v 1.12 2004/08/02 19:31:11 pretz Exp $
 *
 * @file I3TopGeometry.h
 * @version $Revision: 1.12 $
 * @date $Date: 2004/08/02 19:31:11 $
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

#endif
