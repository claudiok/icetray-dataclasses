#include "dataclasses/BoostHeaders.h"
#include "dataclasses/Utility.h"

shared_ptr<I3FrameObject> Clone(shared_ptr<const I3FrameObject> ptr)
{
  std::ostringstream oss;
  boost::archive::portable_binary_oarchive boa(oss);
  boa << make_nvp("obj", ptr);
  shared_ptr<I3FrameObject> newptr(new I3FrameObject());
  std::istringstream iss;
  iss.str(oss.str());
  boost::archive::portable_binary_iarchive bia(iss);
  bia >> make_nvp("obj", newptr);
  return newptr;
}
