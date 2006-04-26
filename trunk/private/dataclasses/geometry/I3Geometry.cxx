#include <dataclasses/BoostHeaders.h>
#include <dataclasses/geometry/I3Geometry.h>

I3Geometry::~I3Geometry() {}

template <class Archive>
void 
I3Geometry::serialize(Archive& ar, unsigned version)
{
  ar & make_nvp("I3FrameObject", base_object<I3FrameObject>(*this));
  ar & make_nvp("OMGeo", omgeo);
  ar & make_nvp("StationGeo", stationgeo);
  ar & make_nvp("StartTime",startTime);
  ar & make_nvp("EndTime",endTime);
}

I3_SERIALIZABLE(I3Geometry);
