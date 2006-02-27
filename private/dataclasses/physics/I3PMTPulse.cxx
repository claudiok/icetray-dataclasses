#include <dataclasses/BoostHeaders.h>
#include <dataclasses/physics/I3PMTPulse.h>

I3PMTPulse::~I3PMTPulse() { }
template <class Archive>
    void I3PMTPulse::serialize(Archive& ar, unsigned version)
	{
	  ar & make_nvp("HitNum", hitNum_);
	}
I3_SERIALIZABLE(I3PMTPulse);
I3_SERIALIZABLE(I3PMTPulseSeries);
I3_SERIALIZABLE(I3PMTPulseSeriesMap);
