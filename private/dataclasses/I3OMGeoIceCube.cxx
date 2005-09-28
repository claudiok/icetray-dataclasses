#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3OMGeoIceCube.h>

template <class Archive>
  void I3OMGeoIceCube::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3OMGeoIceCube", base_object<I3OMGeo>(*this));
  }



I3_SERIALIZABLE(I3OMGeoIceCube);
