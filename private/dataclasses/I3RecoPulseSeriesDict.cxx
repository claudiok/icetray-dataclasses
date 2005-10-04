#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3RecoPulseSeriesDict.h>

template <class Archive> void I3RecoPulseSeriesDict::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3RecoPulseSeriesDict", base_object< STLMapStoragePolicy<string,I3RecoPulseSeriesPtr> >(*this));
  }


  

I3_SERIALIZABLE(I3RecoPulseSeriesDict);