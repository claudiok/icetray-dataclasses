#include <dataclasses/BoostHeaders.h>
#include <dataclasses/physics/I3RecoHit.h>

I3RecoHit::~I3RecoHit() {}

template <class Archive>
void 
I3RecoHit::serialize(Archive& ar, unsigned version)
{
  ar & make_nvp("time",time_);
  ar & make_nvp("hitID",hitID_);
  if(version > 0)
    {
      ar & make_nvp("sourceIndex",sourceIndex_);
    }
}
BOOST_CLASS_VERSION(I3RecoHit, 1);

I3_SERIALIZABLE(I3RecoHit);

I3_SERIALIZABLE(I3RecoHitSeries);

I3_SERIALIZABLE(I3RecoHitSeriesMap);
