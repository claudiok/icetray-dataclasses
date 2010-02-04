/**
    copyright  (C) 2004
    the icecube collaboration
    @version $Id: Utility.h 14347 2006-01-15 15:15:08Z pretz $
    @date    $Date: 2006-01-15 10:15:08 -0500 (Sun, 15 Jan 2006) $
*/

#ifndef DATACLASSES_I3MAP_H_INCLUDED
#define DATACLASSES_I3MAP_H_INCLUDED

#include <icetray/serialization.h>
#include "icetray/I3Logging.h"
#include <map>
#include <string>

#include <dataclasses/Utility.h>
#include <icetray/I3Logging.h>
#include <icetray/I3FrameObject.h>
#include "icetray/OMKey.h"

#ifndef __CINT__  // it puts the lotion in the basket
#include <boost/lexical_cast.hpp>
#endif

template <typename Key, typename Value>
struct I3Map : public I3FrameObject, public std::map<Key, Value>
{ 
  template <class Archive>
  void serialize(Archive & ar, unsigned version)
  {
    ar & make_nvp("I3FrameObject", base_object<I3FrameObject>(*this));
    ar & make_nvp("map", base_object< std::map<Key, Value> >(*this));
  }

  virtual ~I3Map();

  const Value& 
  at(const Key& where) const
  {
    typename std::map<Key, Value>::const_iterator iter = this->find(where);
    if (iter == this->end())
      log_fatal("Map contains nothing at %s.", boost::lexical_cast<std::string>(where).c_str());

    return iter->second;
  }

  Value& 
  at(const Key& where) 
  {
    typename std::map<Key, Value>::iterator iter = this->find(where);
    if (iter == this->end())
      log_fatal("Map contains nothing at %s.", boost::lexical_cast<std::string>(where).c_str());

    return iter->second;
  }

};

template <typename Key, typename Value>
I3Map<Key, Value> :: ~I3Map() { }

#ifdef I3_USE_FAST_OMKEY_MAP
#include <dataclasses/I3MapOMKey.h>
#endif


typedef I3Map<std::string, double> I3MapStringDouble;
typedef I3Map<std::string, int> I3MapStringInt;
typedef I3Map<std::string, bool> I3MapStringBool;

typedef I3Map<std::string, std::vector<double> > I3MapStringVectorDouble;


typedef I3Map<std::string, I3MapStringDouble> I3MapStringStringDouble;

typedef I3Map<unsigned, unsigned> I3MapUnsignedUnsigned;
typedef I3Map<unsigned short, unsigned short> I3MapUShortUShort;

typedef I3Map<int, vector<int> > I3MapIntVectorInt;
typedef I3Map<OMKey, vector<double> > I3MapKeyVectorDouble;
typedef I3Map<OMKey, vector<int> > I3MapKeyVectorInt;
typedef I3Map<OMKey, double > I3MapKeyDouble;

I3_POINTER_TYPEDEFS(I3MapStringDouble);
I3_POINTER_TYPEDEFS(I3MapStringInt);
I3_POINTER_TYPEDEFS(I3MapStringBool);
I3_POINTER_TYPEDEFS(I3MapStringVectorDouble);
I3_POINTER_TYPEDEFS(I3MapStringStringDouble);
I3_POINTER_TYPEDEFS(I3MapUnsignedUnsigned);
I3_POINTER_TYPEDEFS(I3MapUShortUShort);
I3_POINTER_TYPEDEFS(I3MapIntVectorInt);
#ifdef I3_USE_FAST_OMKEY_MAP
BOOST_CLASS_VERSION(I3MapKeyVectorDouble, 1);
#endif
I3_POINTER_TYPEDEFS(I3MapKeyVectorDouble);
#ifdef I3_USE_FAST_OMKEY_MAP
BOOST_CLASS_VERSION(I3MapKeyVectorInt, 1);
#endif
I3_POINTER_TYPEDEFS(I3MapKeyVectorInt);
I3_POINTER_TYPEDEFS(I3MapKeyDouble);

#endif // I3MAP_H_INCLUDED



