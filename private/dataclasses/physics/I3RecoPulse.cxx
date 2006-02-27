#include <dataclasses/BoostHeaders.h>
#include <dataclasses/physics/I3RecoPulse.h>

I3RecoPulse::~I3RecoPulse() {}

template <class Archive> 
void 
I3RecoPulse::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("Time", time_);
    ar & make_nvp("HitID", hitID_);
    ar & make_nvp("PulseAmp", amp_);
    ar & make_nvp("Width", width_);
  }

  

I3_SERIALIZABLE(I3RecoPulse);

I3_SERIALIZABLE(I3RecoPulseSeries);

I3_SERIALIZABLE(I3RecoPulseSeriesMap);
