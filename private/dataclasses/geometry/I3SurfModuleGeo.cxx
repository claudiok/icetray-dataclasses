#include <dataclasses/BoostHeaders.h>
#include <dataclasses/geometry/I3SurfModuleGeo.h>

I3SurfModuleGeo::~I3SurfModuleGeo() {}

template <class Archive>
  void I3SurfModuleGeo::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3SurfModuleGeo",
		  base_object< I3Map<OMKey, I3OMGeoPtr> >(*this));
    ar & make_nvp("surfModulePos", surfModulePos_);
    ar & make_nvp("orientation", orientation_);
  }



I3_SERIALIZABLE(I3SurfModuleGeo);
