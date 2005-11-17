#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3InIceGeometry.h>

I3InIceGeometry::~I3InIceGeometry() {}

template <class Archive>
  void I3InIceGeometry::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3IceCubeStatus",
		  base_object< STLMapStoragePolicy<OMKey,I3OMGeoPtr> >(*this));
  }



I3_SERIALIZABLE(I3InIceGeometry);
