/**
 *  $Id$
 *  
 *  Copyright (C) 2007
 *  Troy D. Straszheim  <troy@icecube.umd.edu>
 *  and the IceCube Collaboration <http://www.icecube.wisc.edu>
 *  
 *  This file is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 3 of the License, or
 *  (at your option) any later version.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>
 *  
 */

//
//  Partial specialization of Map<OMKey, *> to take advantage of the fact
//  that it is really easy and fast to hash OMKeys.
//
#ifndef DATACLASSES_I3MAPOMKEY_H_INCLUDED
#define DATACLASSES_I3MAPOMKEY_H_INCLUDED

#include <icetray/serialization.h>
#include "icetray/I3Logging.h"
#include <map>
#include <string>

#include <dataclasses/Utility.h>
#include <icetray/I3Logging.h>
#include <icetray/I3FrameObject.h>
#include "icetray/OMKey.h"

#include <boost/lexical_cast.hpp>
#include <ext/hash_map>

template <typename Value>
struct I3Map<OMKey, Value> : public I3FrameObject, public __gnu_cxx::hash_map<OMKey, Value, OMKey::hash>
{ 
  typedef __gnu_cxx::hash_map<OMKey, Value, OMKey::hash> hashmap_t;

  //
  // DANGER MAGIC NUMBERS
  //
  // For optimum performance these maps of OMKey->whatever should be preallocated so that
  // OMKeys don't collide in the map and so that it is not necessary to resize the map.
  // preallocating these 6336 locations 
  // (80 Icecube strings + 19 amanda strings + the 'zero' string, 64 oms/string)
  // should only cost on the order of 6336 pointers worth of space, and no time
  //
  I3Map<OMKey, Value>() : hashmap_t((80+19)*64) { }

  template <class Archive>
  void 
  serialize (Archive & ar, unsigned version)
  {
    ar & make_nvp("I3FrameObject", base_object<I3FrameObject>(*this));
    if (version == 0)
      {
	std::map<OMKey, Value> regular_map;
	ar & make_nvp("map", regular_map);
	// copy that into our map
	// we're reading-only at this point.
	for (typename std::map<OMKey, Value>::iterator iter = regular_map.begin();
	     iter != regular_map.end();
	     iter++)
	  insert(*iter);
      }
    else // version == 1
      {
	ar & make_nvp("hash_map", base_object< __gnu_cxx::hash_map<OMKey, Value, OMKey::hash> >(*this));
      }
  }

  virtual ~I3Map<OMKey, Value>();

  const Value& 
  at(const OMKey& where) const
  {
    typename hashmap_t::const_iterator iter = this->find(where);
    if (iter == this->end())
      log_fatal("Map contains nothing at %s.", boost::lexical_cast<std::string>(where).c_str());

    return iter->second;
  }

  Value& 
  at(const OMKey& where) 
  {
    typename hashmap_t::iterator iter = this->find(where);
    if (iter == this->end())
      log_fatal("Map contains nothing at %s.", boost::lexical_cast<std::string>(where).c_str());

    return iter->second;
  }
};

template <typename Value>
I3Map<OMKey, Value>::~I3Map(){ }

typedef I3Map<OMKey, vector<double> > I3MapKeyVectorDouble;
typedef I3Map<OMKey, vector<int> > I3MapKeyVectorInt;

I3_POINTER_TYPEDEFS(I3MapKeyVectorDouble);
I3_POINTER_TYPEDEFS(I3MapKeyVectorInt);

#endif // I3MAP_H_INCLUDED



