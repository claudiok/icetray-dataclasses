/**
    copyright  (C) 2006
    the icecube collaboration
    @version $Id: Utility.h 14347 2006-01-15 15:15:08Z pretz $
    @date    $Date: 2006-01-15 10:15:08 -0500 (Sun, 15 Jan 2006) $
*/

#ifndef DATACLASSES_I3VECTOR_H_INCLUDED
#define DATACLASSES_I3VECTOR_H_INCLUDED

#include "icetray/I3FrameObject.h"
#include <vector>
#include "dataclasses/Utility.h"
#include "dataclasses/OMKey.h"

template <typename T>
struct I3Vector : public I3FrameObject, public std::vector<T>
{ 
  template <class Archive>
  void serialize(Archive & ar, unsigned version)
  {
    ar & make_nvp("I3FrameObject", base_object<I3FrameObject>(*this));
    ar & make_nvp("vector", base_object< std::vector<T> >(*this));
  }
};

typedef I3Vector<string> I3VectorString;
typedef I3Vector<double> I3VectorDouble;
typedef I3Vector<int> I3VectorInt;
typedef I3Vector<bool> I3VectorBool;
typedef I3Vector<OMKey> I3VectorOMKey;

I3_POINTER_TYPEDEFS(I3VectorString);
I3_POINTER_TYPEDEFS(I3VectorDouble);
I3_POINTER_TYPEDEFS(I3VectorInt);
I3_POINTER_TYPEDEFS(I3VectorBool);
I3_POINTER_TYPEDEFS(I3VectorOMKey);

#endif // I3VECTOR_H_INCLUDED

