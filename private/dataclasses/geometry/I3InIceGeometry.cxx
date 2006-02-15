#include <dataclasses/BoostHeaders.h>
#include <dataclasses/geometry/I3InIceGeometry.h>

I3InIceGeometry::~I3InIceGeometry() {}

template <class Archive>
  void I3InIceGeometry::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3InIceGeometry",
		  base_object< I3Map<OMKey,I3OMGeoPtr> >(*this));
  }



I3_SERIALIZABLE(I3InIceGeometry);
