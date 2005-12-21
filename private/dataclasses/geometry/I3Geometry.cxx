#include <dataclasses/BoostHeaders.h>
#include <dataclasses/geometry/I3Geometry.h>

I3Geometry::~I3Geometry() {}

template <class Archive>
  void I3Geometry::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("inIce",inIce_);
    ar & make_nvp("top",top_);
  }



I3_SERIALIZABLE(I3Geometry);
