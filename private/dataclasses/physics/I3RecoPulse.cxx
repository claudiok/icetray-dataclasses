#include <icetray/serialization.h>
#include <dataclasses/physics/I3RecoPulse.h>

I3RecoPulse::~I3RecoPulse() {}

template <class Archive> 
void 
I3RecoPulse::serialize(Archive& ar, unsigned version)
  {
    if (version>i3recopulse_version_)
    log_fatal("Attempting to read version %u from file but running version %u of I3RecoPulse class.",version,i3recopulse_version_);

    ar & make_nvp("Time", time_);
    ar & make_nvp("HitID", hitID_);
    ar & make_nvp("PulseCharge", charge_);
    ar & make_nvp("Width", width_);
  if(version > 0)
    {
      ar & make_nvp("sourceIndex",sourceIndex_);
    }
  }


I3_SERIALIZABLE(I3RecoPulse);

I3_SERIALIZABLE(I3RecoPulseSeriesMap);
I3_SERIALIZABLE(I3RecoPulseMap);
