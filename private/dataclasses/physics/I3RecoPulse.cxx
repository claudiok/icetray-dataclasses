#include <icetray/serialization.h>
#include <dataclasses/physics/I3RecoPulse.h>
#include <dataclasses/physics/I3Waveform.h>

I3RecoPulse::~I3RecoPulse() {}

template <class Archive> 
void 
I3RecoPulse::serialize(Archive& ar, unsigned version)
  {
    if (version>i3recopulse_version_)
    log_fatal("Attempting to read version %u from file but running version %u of I3RecoPulse class.",version,i3recopulse_version_);

	if (version < 2) {
		double t(time_), c(charge_), w(width_);
		int hitid(0);
		ar & make_nvp("Time", t);
		ar & make_nvp("HitID", hitid);
		ar & make_nvp("PulseCharge", c);
		ar & make_nvp("Width", w);
		time_ = t;
		charge_ = c;
		width_ = w;
		if (version > 0) {
			int sourceindex(-1);
			ar & make_nvp("sourceIndex",sourceindex);

			// Try to guess what this was supposed to be,
			// canonicalizing NFE's definition. NFE and FE pulses
			// used different meanings here, which are not actually
			// distinguishable.
			flags_ = 0;
			if (sourceindex == I3Waveform::ATWD)
				flags_ |= I3RecoPulse::ATWD;
			if (sourceindex == I3Waveform::FADC)
				flags_ |= I3RecoPulse::FADC;
			if (sourceindex != I3Waveform::SLC)
				flags_ |= I3RecoPulse::LC;
		}
	} else {
		ar & make_nvp("Time", time_);
		ar & make_nvp("PulseCharge", charge_);
		ar & make_nvp("Width", width_);
		ar & make_nvp("Flags", flags_);
	}
}


bool 
I3RecoPulse::operator==(const I3RecoPulse& rhs) const
{
  return flags_ == flags_ 
    && (time_ == rhs.time_)
    && (charge_ == rhs.charge_)
    && ((std::isnan(width_) && std::isnan(rhs.width_)) || width_ == rhs.width_);
}

I3_SERIALIZABLE(I3RecoPulse);

I3_SERIALIZABLE(I3RecoPulseSeriesMap);
I3_SERIALIZABLE(I3RecoPulseMap);
