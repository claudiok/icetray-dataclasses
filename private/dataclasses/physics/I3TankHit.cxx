#include <icetray/serialization.h>
#include <dataclasses/physics/I3TankHit.h>

I3TankHit::~I3TankHit() {}

template <class Archive>
  void I3TankHit::serialize(Archive& ar, unsigned version)
  {
    if (version>i3tankhit_version_)
    log_fatal("Attempting to read version %zu from file but running version %zu of I3TankHit class.",version,i3tankhit_version_);

    ar & make_nvp("TankNumber",tankNumber_);
    ar & make_nvp("Time",time_);
    ar & make_nvp("Signal",signal_);
  }

  

I3_SERIALIZABLE(I3TankHit);
