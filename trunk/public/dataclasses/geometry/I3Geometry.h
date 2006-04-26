/**
 *
 * copyright  (C) 2004
 * the icecube collaboration
 * @version n$Id$
 * @file I3Geometry.h
 * @date $Date$
 */

#ifndef I3GEOMETRY_H_INCLUDED
#define I3GEOMETRY_H_INCLUDED

#include "dataclasses/Utility.h"
#include "dataclasses/geometry/I3TankGeo.h"
#include "dataclasses/geometry/I3OMGeo.h"
#include "dataclasses/I3Time.h"
#include <icetray/I3DefaultName.h>
#include "icetray/I3FrameObject.h"
#include "dataclasses/I3Map.h"
/*
  The following is a flattened version of the Geometry Class for dcv2
  The 8 classes of old are now 3 structs.  

  (1) I3Geometry contains the 'master' data, namely the map of OMKey to OM 
  (for inice, icetop, and amanda), as well as the map of the stations.

  (2) I3OMGeo contains all the necessary information for a single OM, including
  an enum to specify what type of OM it is.

  (3) I3TankGeo which represents the 2 tanks within an icetop station.

  The major change is that there are no longer InIce and IceTop objects that
  can be called from the geometry class.  Instead, one should call the
  I3OMGeoMap object directly and use this.  Hence, a change would look like:
  old: I3InIceGeometry inice = Geometry.GetInIceGeometry();
  new: I3OMGeoMap geomap = Geometry.omgeo;

  The other changes were minor (simply eliminating the Get/Set functions in
  favor of direct setting) 

  -bchristy
*/


//Typedefs to avoid having to write the same thing over and over again.
typedef vector<I3TankGeo> I3StationGeo;
I3_POINTER_TYPEDEFS(I3StationGeo)

typedef map<OMKey, I3OMGeo> I3OMGeoMap;
I3_POINTER_TYPEDEFS(I3OMGeoMap)

typedef map<int, I3StationGeo> I3StationGeoMap;
I3_POINTER_TYPEDEFS(I3StationGeoMap)

     struct I3Geometry : public I3FrameObject
{
  I3Geometry(){};
  virtual ~I3Geometry();

  //Map of all OMs based on their OMKey
  I3OMGeoMap omgeo;

  //Map of all the stations. 
  //Each int specifies a StationGeo object, which is a vector of 2 TankGeo's.
  I3StationGeoMap stationgeo;

  I3Time startTime;
  I3Time endTime;

  const I3Geometry& operator=(const I3Geometry& geometry);

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
};

I3_DEFAULT_NAME(I3Geometry);
I3_POINTER_TYPEDEFS(I3Geometry);

#endif // I3GEOMETRY_H_INCLUDED
