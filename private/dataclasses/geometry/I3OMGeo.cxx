#include <dataclasses/BoostHeaders.h>
#include <dataclasses/geometry/I3OMGeo.h>

I3OMGeo::~I3OMGeo() { }

template <class Archive>
void 
I3OMGeo::serialize(Archive& ar, unsigned version)
{
  ar & make_nvp("position",position_);
  ar & make_nvp("orientation",orientation_);
  ar & make_nvp("type",type_);
  ar & make_nvp("relativeQE",relativeQE_);
  ar & make_nvp("area",area_);
}

I3_SERIALIZABLE(I3OMGeo);
