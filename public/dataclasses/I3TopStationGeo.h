/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3TopStationGeo.h,v 1.5 2004/08/05 13:00:21 troy Exp $
 *
 * @file I3TopStationGeo.h
 * @version $Revision: 1.5 $
 * @date $Date: 2004/08/05 13:00:21 $
 * @author PN/RU Tue Jun 22 10:30:16 EDT 2004
 */
#ifndef __I3TopStationGEO_H_
#define __I3TopStationGEO_H_

#include <iostream>

#include <TObject.h>

#include "dataclasses/I3TankMaterial.h"
#include "dataclasses/I3TopGeometry.h"
#include "dataclasses/StoragePolicy.h"
#include "dataclasses/I3TankGeo.h"

using namespace std;
/**
 * @brief Class which describes a icetop station
 * @todo needs the i3tankgeo a z coordinate
 */
class I3TopStationGeo : public TObject, public VectorPolicy<I3TankGeoPtr>::ThePolicy
{

 public:
  I3TopStationGeo () {}
  virtual ~I3TopStationGeo() {;}  
  
  private:
  //ROOT macro

  ClassDef(I3TopStationGeo,1);
};

/**
 * pointer type to insulate users from memory management
 */
typedef PtrPolicy<I3TopStationGeo>::ThePolicy I3TopStationGeoPtr;

#endif

