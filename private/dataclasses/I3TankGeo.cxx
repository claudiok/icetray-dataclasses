#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3TankGeo.h>

I3TankGeo::~I3TankGeo() {}

template <class Archive>
  void I3TankGeo::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3SurfModuleGeo",base_object< I3SurfModuleGeo >(*this));
    ar & make_nvp("radius",radius_);
    ar & make_nvp("height",height_);
    ar & make_nvp("fillHeight",fillHeight_);
  }



I3_SERIALIZABLE(I3TankGeo);
