#include <dataclasses/BoostHeaders.h>
#include "dataclasses/physics/I3IceCubeResponse.h"

I3IceCubeResponse::~I3IceCubeResponse(){}

template <class Archive>
  void I3IceCubeResponse::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3IceCubeResponse", base_object< I3Map<OMKey,vector<I3DOMLaunch> >(*this));
  }
