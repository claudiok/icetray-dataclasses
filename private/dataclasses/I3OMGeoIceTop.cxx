#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3OMGeoIceTop.h>

I3OMGeoIceTop::~I3OMGeoIceTop() {}

template <class Archive>
  void I3OMGeoIceTop::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3OMGeoIceTop",base_object<I3OMGeo>(*this));
  }



I3_SERIALIZABLE(I3OMGeoIceTop);
