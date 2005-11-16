#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3NonDirectional.h>

I3NonDirectional::~I3NonDirectional() {}

template <class Archive>
  void I3NonDirectional::serialize(Archive& ar, unsigned version)
  {
    //This method intentionally left blank
  }

  

I3_SERIALIZABLE(I3NonDirectional);
