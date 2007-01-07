/**
    copyright  (C) 2006
    the icecube collaboration
    @version $Id: Utility.h 14347 2006-01-15 15:15:08Z pretz $
    @date    $Date: 2006-01-15 10:15:08 -0500 (Sun, 15 Jan 2006) $
*/

#ifndef DATACLASSES_I3VECTOR_H_INCLUDED
#define DATACLASSES_I3VECTOR_H_INCLUDED

#include <icetray/serialization.h>
#include "icetray/I3FrameObject.h"
#include <vector>
#include "dataclasses/Utility.h"
#include "dataclasses/OMKey.h"
template <typename T>
struct I3Vector : public std::vector<T>, public I3FrameObject
{ 
  typedef std::vector<T> base_t;

  I3Vector() { }
  
  I3Vector(typename base_t::size_type s, const T& value) 
    : base_t(s, value) { }
    
  explicit I3Vector(typename base_t::size_type n) : base_t(n) { }

  I3Vector(const I3Vector& rhs) : base_t(rhs) { }

  // strangely, this constructor-from-pair-of-iterators is not visible
  // to users of I3Vector.  When you add it here, it hides all the
  // other constructors, so you add them all, explicitly.

  template <typename Iterator>
  I3Vector(Iterator l, Iterator r) : base_t(l, r) { }

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
typedef I3Vector<unsigned int> I3VectorUnsignedInt;
I3_POINTER_TYPEDEFS(I3VectorUnsignedInt);
I3_POINTER_TYPEDEFS(I3VectorString);
I3_POINTER_TYPEDEFS(I3VectorDouble);
I3_POINTER_TYPEDEFS(I3VectorInt);
I3_POINTER_TYPEDEFS(I3VectorBool);
I3_POINTER_TYPEDEFS(I3VectorOMKey);

#endif // I3VECTOR_H_INCLUDED

