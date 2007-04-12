#include <icetray/serialization.h>
#include <dataclasses/geometry/I3Geometry.h>

I3Geometry::~I3Geometry() {}

template <class Archive>
void 
I3Geometry::serialize(Archive& ar, unsigned version)
{
  if (version>i3geometry_version_)
    log_fatal("Attempting to read version %zu from file but running version %zu of I3Geometry class.", version, i3geometry_version_);

  ar & make_nvp("I3FrameObject", base_object<I3FrameObject>(*this));
  ar & make_nvp("OMGeo", omgeo);
  ar & make_nvp("StationGeo", stationgeo);
  ar & make_nvp("StartTime",startTime);
  ar & make_nvp("EndTime",endTime);
}

I3_SERIALIZABLE(I3Geometry);
