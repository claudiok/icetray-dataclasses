#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3RecoHitSeries.h>

I3RecoHitSeries::~I3RecoHitSeries() {}

template <class Archive>
  void I3RecoHitSeries::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3RecoHitSeries", base_object< STLVectorStoragePolicy<I3RecoHitPtr> >(*this));
  }



  

I3_SERIALIZABLE(I3RecoHitSeries);
