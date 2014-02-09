#ifndef DATACLASSES_I3STRING_H_INCLUDED
#define DATACLASSES_I3STRING_H_INCLUDED

#include <icetray/I3FrameObject.h>
#include <string>

// A holder for a string if you want to put one in the frame.  *Dont*
// use these if you're not putting this thing in the frame!  That's
// messy!

struct I3String : public I3FrameObject
{
  std::string value;
  
  I3String();
  I3String(const std::string& s);
  I3String(const I3String&);
  I3String& operator=(const I3String&);

  template <typename Archive>
    void serialize(Archive& ar, unsigned version);
};

std::ostream& operator<<(std::ostream& oss, const I3String& s);

I3_POINTER_TYPEDEFS(I3String);

#endif
