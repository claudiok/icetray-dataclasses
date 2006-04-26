#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3Double.h>

I3Double::I3Double() : value(0) {}

I3Double::I3Double(double d) : value(d) {}

I3Double::I3Double(const I3Double& rhs) : value(rhs.value) {}

I3Double&
I3Double::operator=(const I3Double& rhs)
{
  //check for self-assignment
  if (this != &rhs)
    value = rhs.value;

  return *this;
}

template <class Archive>
void
I3Double::serialize(Archive& ar,unsigned)
{
  ar & make_nvp("I3FrameObject", base_object<I3FrameObject>(*this));
  ar & make_nvp("value",value);
}

I3_SERIALIZABLE(I3Double);

