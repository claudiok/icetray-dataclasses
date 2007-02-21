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

// important to use the raw types here.  Don't do I3Vector<int64_t>, as that
// will be I3Vector<long> some places and I3Vector<long long> others, and then
// dynamic casting breaks since the two have different typeids. 
typedef I3Vector<bool> I3VectorBool;
typedef I3Vector<char> I3VectorChar;
typedef I3Vector<short> I3VectorShort;
typedef I3Vector<unsigned short> I3VectorUShort;
typedef I3Vector<int> I3VectorInt;
typedef I3Vector<unsigned int> I3VectorUInt;
typedef I3Vector<long long> I3VectorInt64;
typedef I3Vector<unsigned long long> I3VectorUInt64;
typedef I3Vector<string> I3VectorString;
typedef I3Vector<float> I3VectorFloat;
typedef I3Vector<double> I3VectorDouble;

typedef I3Vector<OMKey> I3VectorOMKey;

I3_POINTER_TYPEDEFS(I3VectorBool);
I3_POINTER_TYPEDEFS(I3VectorChar);
I3_POINTER_TYPEDEFS(I3VectorInt);
I3_POINTER_TYPEDEFS(I3VectorUInt);
I3_POINTER_TYPEDEFS(I3VectorInt64);
I3_POINTER_TYPEDEFS(I3VectorUInt64);
I3_POINTER_TYPEDEFS(I3VectorFloat);
I3_POINTER_TYPEDEFS(I3VectorDouble);
I3_POINTER_TYPEDEFS(I3VectorString);

I3_POINTER_TYPEDEFS(I3VectorOMKey);

// inconsistent... if you take this out, though, you have to be sure
// that you add it to I3Vector.cxx so that I3VectorUnsignedInt is
// always serialized with that name.  
typedef I3Vector<unsigned int> I3VectorUnsignedInt;
I3_POINTER_TYPEDEFS(I3VectorUnsignedInt);

#endif // I3VECTOR_H_INCLUDED

