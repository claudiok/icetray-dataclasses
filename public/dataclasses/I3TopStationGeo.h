/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3TopStationGeo.h,v 1.3 2004/08/02 22:09:05 blaufuss Exp $
 *
 * @file I3TopStationGeo.h
 * @version $Revision: 1.3 $
 * @date $Date: 2004/08/02 22:09:05 $
 * @author PN/RU Tue Jun 22 10:30:16 EDT 2004
 */
#ifndef __I3TankStationGEO_H_
#define __I3TankStationGEO_H_

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
  ClassDef(I3TopStationGeo,1);
};

typedef PtrPolicy<I3TopStationGeo>::ThePolicy I3TopStationGeoPtr;

#endif

