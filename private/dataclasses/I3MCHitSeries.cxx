#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3MCHitSeries.h>

I3MCHitSeries::~I3MCHitSeries() {}

template <class Archive>
  void I3MCHitSeries::serialize(Archive& ar, unsigned version){
  ar & make_nvp("I3MCHitSeries",base_object< vector<I3MCHit> >(*this));
  ar & make_nvp("Weight", weight_ );
 }

  

I3_SERIALIZABLE(I3MCHitSeries);
