#include <dataclasses/BoostHeaders.h>
#include <dataclasses/geometry/I3TankGeo.h>

I3TankGeo::~I3TankGeo() {}

template <class Archive>
  void I3TankGeo::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("TObject", base_object< TObject >(*this));
    ar & make_nvp("Position", position);
    ar & make_nvp("Orientation", orientation);
    ar & make_nvp("TankRadius", tankradius);
    ar & make_nvp("TankHeight", tankheight);
    ar & make_nvp("FillHeight", fillheight);

  }



I3_SERIALIZABLE(I3TankGeo);
