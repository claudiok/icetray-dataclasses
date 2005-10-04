#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3RecoPulse.h>

template <class Archive> void I3RecoPulse::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("Time", time_);
    ar & make_nvp("HitID", hitID_);
    ar & make_nvp("PulseAmp", amp_);
    ar & make_nvp("Width", width_);
  }

  

I3_SERIALIZABLE(I3RecoPulse);