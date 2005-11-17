#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3TankHit.h>

I3TankHit::~I3TankHit() {}

template <class Archive>
  void I3TankHit::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("TankNumber",tankNumber_);
    ar & make_nvp("Time",time_);
    ar & make_nvp("Signal",signal_);
  }

  

I3_SERIALIZABLE(I3TankHit);
