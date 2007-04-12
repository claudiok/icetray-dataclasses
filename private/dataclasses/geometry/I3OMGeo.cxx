#include <icetray/serialization.h>
#include <dataclasses/geometry/I3OMGeo.h>

I3OMGeo::~I3OMGeo() { }

template <class Archive>
void 
I3OMGeo::serialize(Archive& ar, unsigned version)
{
  if (version>i3omgeo_version_)
    log_fatal("Attempting to read version %zu from file but running version %zu of I3OMGeo class.",version,i3omgeo_version_);

  ar & make_nvp("Position", position);
  ar & make_nvp("Orientation", orientation);
  ar & make_nvp("OMType", omtype);
  ar & make_nvp("Area", area);
  ar & make_nvp("AziAngle", aziangle);

}

I3_SERIALIZABLE(I3OMGeo);
