#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3OMGeoAMANDA.h>
I3OMGeoAMANDA::~I3OMGeoAMANDA() {}

template <class Archive>
  void I3OMGeoAMANDA::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3OMGeo",base_object<I3OMGeo>(*this));
    ar & make_nvp("tZero",tZero_);
  }



I3_SERIALIZABLE(I3OMGeoAMANDA);
