/**
 * copyright  (C) 2004
 * the icecube collaboration
 * @version $Id$
 * @file I3OMGeo.h
 * @date $Date$
 */

#ifndef I3OMGEO_H_INCLUDED
#define I3OMGEO_H_INCLUDED

#include <TObject.h>
#include "dataclasses/I3Position.h"
#include <TClass.h>
#include <string>
#include <iostream>
#include <sstream>
#include "dataclasses/OMKey.h"
#include "dataclasses/Utility.h"

using namespace std;


struct I3OMGeo
{

  enum Orientation {Unspecified=0, Up=1, Down=-1};
  enum OMType {AMANDA, IceCube, IceTop};

  I3OMGeo() {Init();}
  //copy constructor just uses assignment
  //I3OMGeo(const I3OMGeo& rhs){*this = rhs;}
  virtual ~I3OMGeo();

  I3Position position; //OM x,y,z position
  OMType omtype; //InIce? IceTop? AMANDA OM? (see enum above)
  Orientation orientation; // Up/Down orientation (see enum above)
  double area; //Effective collection area (use I3Units)
  double aziangle; //relative rotation angle of DOM in azimuth

  /**
   * @todo finish with all the data
   */
  virtual void ToStream(ostream& o) const
    {
      o<<"[ I3OMGeo ]\n"
       <<" X:"
       <<position.GetX()
       <<" Y:"
       <<position.GetY()
       <<" Z:"
       <<position.GetZ()
       <<" ]\n";
    }

  virtual string ToString() const
    {
      ostringstream out;
      ToStream(out);
      return out.str();
    }
  
  void Init() {
    orientation = Unspecified;
  }

  friend class boost::serialization::access;
  template <class Archive>
  void serialize(Archive& ar, unsigned version);
};

/**
 * streams an I3OMGeo to an arbitrary ostream
 */
inline ostream& operator<<(ostream& o,const I3OMGeo& g)
{
  g.ToStream(o); 
  return o;
}

I3_POINTER_TYPEDEFS(I3OMGeo);

#endif //I3OMGEO_H_INCLUDED
