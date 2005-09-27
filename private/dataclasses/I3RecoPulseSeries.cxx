#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3RecoPulseSeries.h>

template <class Archive> void I3RecoPulseSeries::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3RecoPulseSeries", base_object< STLVectorStoragePolicy<I3RecoPulsePtr> >(*this));
  }

  

I3_SERIALIZABLE(I3RecoPulseSeries);
