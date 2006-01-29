#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3Geometry.h>

template <class Archive>
  void I3Geometry::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("inIce",inIce_);
    ar & make_nvp("top",top_);
  }



I3_SERIALIZABLE(I3Geometry);