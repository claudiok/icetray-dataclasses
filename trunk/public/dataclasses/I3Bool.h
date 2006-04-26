#ifndef DATACLASSES_I3BOOL_H_INCLUDED
#define DATACLASSES_I3BOOL_H_INCLUDED

#include "icetray/I3FrameObject.h"
#include <dataclasses/Utility.h>

//
//  Dumb-struct holders of PODS should *not* automatically convert
//  to/from the underlying type lest people think that it is necessary
//  to use, say, vector<I3Double> instead of just vector<double>.
//  They are instead holders of values, with member "value".
//
struct I3Bool : public I3FrameObject
{
  bool value;

  I3Bool();
  I3Bool(bool b);
  I3Bool(const I3Bool&);
  I3Bool& operator=(const I3Bool&);

  template <typename Archive>
    void serialize(Archive&,unsigned);

};

I3_POINTER_TYPEDEFS(I3Bool);

#endif
