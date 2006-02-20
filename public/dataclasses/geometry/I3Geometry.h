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
#include <icetray/I3FrameTraits.h>
/*
  The following is a flattened version of the Geometry Class for dcv2
  Instead of the 8 classes before, geometry has been reduced to 3.  
  (1) I3Geometry contains the 'master' data, namely the map of OMKey to OM 
  (for inice, icetop, and amanda), as well as the map of the stations.
  (2) I3OMGeo contains all the necessary information for a single OM, including
  an enum to specify what type of OM it is.
  (3) I3TankGeo which represents the 2 tanks within an icetop station.

  The major change is that there are no longer InIce and IceTop objects that
  can be called from the geometry class.  When one needs to loop over the OMs,
  simply use the map<OMKey, I3OMGeoPtr> omgeo in this struct.  Granted, it
  has all the OMs, but the 
*/
typedef vector<I3TankGeoPtr> I3StationGeo;
I3_POINTER_TYPEDEFS(I3StationGeo)

typedef map<OMKey, I3OMGeoPtr> I3OMGeoMap;
I3_POINTER_TYPEDEFS(I3OMGeoMap)

typedef map<int, I3StationGeoPtr> I3StationGeoMap;
I3_POINTER_TYPEDEFS(I3StationGeoMap)

struct I3Geometry:public TObject
{
  I3Geometry(){};
  virtual ~I3Geometry();

  I3OMGeoMap omgeo;
  I3StationGeoMap stationgeo;

  I3Time startTime;
  I3Time endTime;

  virtual void ToStream(ostream& o) const
    {
      o<<"[ I3Geometry\n"
	//<<inIce_//<<top_
       <<"]\n";
    }

  I3Geometry(const I3Geometry& geometry);
  const I3Geometry& operator=(const I3Geometry& geometry);

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
};

/** 
 * streaming operator
 */
inline ostream& operator<<(ostream& o,const I3Geometry& geo)
{
  geo.ToStream(o);
  return o;
};

template<>
struct I3FrameTraits<I3Geometry>
{
  static const char* defaultName;
};

template<>
struct I3FrameTraits<const I3Geometry>
{
  static const char* defaultName;
};

I3_POINTER_TYPEDEFS(I3Geometry)

#endif // I3GEOMETRY_H_INCLUDED
