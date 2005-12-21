#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3RecoPulseSeriesDict.h>

I3RecoPulseSeriesDict::~I3RecoPulseSeriesDict() {}

template <class Archive> void I3RecoPulseSeriesDict::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3RecoPulseSeriesDict", base_object< map<string,I3RecoPulseSeriesPtr> >(*this));
  }


  

I3_SERIALIZABLE(I3RecoPulseSeriesDict);
