/**
 * copyright  (C) 2004
 * the icecube collaboration
 * @version $Id$
 * @file I3TankGeo.h
 * @date $Date$
 */

#ifndef I3TANKGEO_H_INCLUDED
#define I3TANKGEO_H_INCLUDED

#include <iostream>

#include <TObject.h>
#include "dataclasses/I3Position.h"
#include "dataclasses/Utility.h"
using namespace std;

/*Simple struct that contains all the pertinent Tank info.
  Note that there is no OM information for this struct. 
  This is what led me to comment out the cryptic switch statement in
  I3TextFileGeometryService and I3FileGeoOrigin (in phys-services) since
  it appeared to be assigning OMGeoPtr info to a TankGeo object.
  (in the old version, TankGeo inherited from I3SurfModuleGeo, hence it
  had OMGeo info associated with it)
  See I3Geometry.h for more info
*/


struct I3TankGeo : public TObject
{
  I3TankGeo() {}
  virtual ~I3TankGeo();

  

  I3Position position; //tank x,y,z position
  double orientation; //relative angular rotation of tank
  double tankradius; //tank radius (I3Units!)
  double tankheight; //tank height (I3Units!)
  double fillheight; //water/ice level height (I3Units!)

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);

};


I3_POINTER_TYPEDEFS(I3TankGeo);

#endif //I3TANKGEO_H_INCLUDED
