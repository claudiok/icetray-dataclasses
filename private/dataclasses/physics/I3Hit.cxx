#include <dataclasses/BoostHeaders.h>
#include <dataclasses/physics/I3Hit.h>
I3Hit::~I3Hit() {}
template <class Archive>
  void I3Hit::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("Time", time_);
    ar & make_nvp("HitID", hitID_);
  }
  
  

I3_SERIALIZABLE(I3Hit);
