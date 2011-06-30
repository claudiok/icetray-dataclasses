/**
 * copyright  (C) 2004
 * the icecube collaboration
 * @version $Id$
 * @file I3OMGeo.h
 * @date $Date$
 */

#ifndef I3OMGEO_H_INCLUDED
#define I3OMGEO_H_INCLUDED

#include "dataclasses/I3Position.h"
#include <string>
#include <iostream>
#include <sstream>
#include "icetray/OMKey.h"
#include "dataclasses/Utility.h"


static const unsigned i3omgeo_version_ = 0;

//Simple struct to contain all pertinent OM info.  
//See I3Geometry.h for more info

struct I3OMGeo 
{

  enum Orientation {Unspecified=0, Up=1, Down=-1};
  enum OMType {UnknownType = 0, AMANDA = 10, IceCube = 20, IceTop = 30};

  I3OMGeo() {Init();}
  //copy constructor just uses assignment
  //I3OMGeo(const I3OMGeo& rhs){*this = rhs;}
  virtual ~I3OMGeo();

  I3Position position; //OM x,y,z position
  OMType omtype; //InIce? IceTop? AMANDA OM? (see enum above)
  Orientation orientation; // Up/Down orientation (see enum above)
  double area; //Effective collection area (use I3Units)
  double aziangle; //relative rotation angle of DOM in azimuth

  void Init() {
    orientation = Unspecified;
  }

  friend class boost::serialization::access;
  template <class Archive>
  void serialize(Archive& ar, unsigned version);
};

I3_POINTER_TYPEDEFS(I3OMGeo);
BOOST_CLASS_VERSION(I3OMGeo, i3omgeo_version_);

#endif //I3OMGEO_H_INCLUDED
