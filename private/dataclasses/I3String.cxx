#include <icetray/serialization.h>
#include <dataclasses/I3String.h>

#include <string>

using namespace std;

I3String::I3String() { }

I3String::I3String(const std::string& s) : value(s) {}

I3String::I3String(const I3String& rhs) : value(rhs.value) {}

I3String&
I3String::operator=(const I3String& rhs)
{
  //check for self-assignment
  if (this != &rhs)
    value = rhs.value;

  return *this;
}

template <class Archive>
void
I3String::serialize(Archive& ar,unsigned)
{
  ar & make_nvp("I3FrameObject", base_object<I3FrameObject>(*this));
  ar & make_nvp("value",value);
}

I3_SERIALIZABLE(I3String);

