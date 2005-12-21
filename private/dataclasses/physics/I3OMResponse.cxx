#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3OMResponse.h>

I3OMResponse::~I3OMResponse() {}

template <class Archive> void I3OMResponse::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("DataReadoutDict", dataReadoutDict_);
    ar & make_nvp("RecoHitSeriesDict", recoHitSeriesDict_);
    ar & make_nvp("RecoPulseSeriesDict", recoPulseSeriesDict_);
  }

  

I3_SERIALIZABLE(I3OMResponse);
