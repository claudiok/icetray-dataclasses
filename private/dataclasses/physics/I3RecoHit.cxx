#include <dataclasses/BoostHeaders.h>
#include <dataclasses/physics/I3RecoHit.h>

I3RecoHit::~I3RecoHit() {}

template <class Archive>
void 
I3RecoHit::serialize(Archive& ar, unsigned version)
{
  ar & make_nvp("TObject", base_object< TObject >(*this));
  ar & make_nvp("time",time_);
  ar & make_nvp("hitID",hitID_);
}

I3_SERIALIZABLE(I3RecoHit);

I3_SERIALIZABLE(I3RecoHitSeries);

I3_SERIALIZABLE(I3RecoHitSeriesMap);
