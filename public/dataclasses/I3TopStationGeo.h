/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3TopStationGeo.h,v 1.7 2004/08/16 16:22:13 pretz Exp $
 *
 * @file I3TopStationGeo.h
 * @version $Revision: 1.7 $
 * @date $Date: 2004/08/16 16:22:13 $
 * @author PN/RU Tue Jun 22 10:30:16 EDT 2004
 */
#ifndef __I3TopStationGEO_H_
#define __I3TopStationGEO_H_

#include <iostream>

#include <TObject.h>

#include "dataclasses/I3TankMaterial.h"
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
  
  virtual void ToStream(ostream& o) const
    {
      o<<"[ I3TopStationGeo: \n";
      I3TopStationGeo::const_iterator iter;
      for(iter=begin();iter!=end();iter++)
	{
	  if(*iter == I3TankGeoPtr((I3TankGeo*)0))
	    o<<"Null I3TankGeo";
	  else
	    o<<*(*iter);
	}
      o<<"]\n";
    }

  private:
  //ROOT macro

  ClassDef(I3TopStationGeo,1);
};

inline ostream& operator<<(ostream& o, const I3TopStationGeo& geo)
{
  geo.ToStream(o);
  return o;
}

/**
 * pointer type to insulate users from memory management
 */
typedef PtrPolicy<I3TopStationGeo>::ThePolicy I3TopStationGeoPtr;

#endif

