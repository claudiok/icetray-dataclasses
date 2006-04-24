#include <dataclasses/BoostHeaders.h>
#include <dataclasses/geometry/I3TankGeo.h>

I3TankGeo::~I3TankGeo() {}

template <class Archive>
  void I3TankGeo::serialize(Archive& ar, unsigned version)
  {

    ar & make_nvp("Position", position);
    ar & make_nvp("Orientation", orientation);
    ar & make_nvp("TankRadius", tankradius);
    ar & make_nvp("TankHeight", tankheight);
    ar & make_nvp("FillHeight", fillheight);
    if (version > 0)
      ar & make_nvp("OMKeyList", omKeyList_);

  }

BOOST_CLASS_VERSION(I3TankGeo, 1);
I3_SERIALIZABLE(I3TankGeo);
