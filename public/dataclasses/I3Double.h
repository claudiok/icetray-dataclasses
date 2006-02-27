#ifndef DATACLASSES_I3DOUBLE_H_INCLUDED
#define DATACLASSES_I3DOUBLE_H_INCLUDED

#include "icetray/I3FrameObject.h"
#include <dataclasses/Utility.h>

// Basically stole pretz form of I3Bool and made a double out of it
// Revised by stealing troy's I3Bool revision.

struct I3Double :public I3FrameObject
{
  double value;
  
  I3Double();
  I3Double(double d);
  I3Double(const I3Double&);
  I3Double& operator=(const I3Double&);

  template <typename Archive>
    void serialize(Archive&,unsigned);
};

I3_POINTER_TYPEDEFS(I3Double);

#endif
