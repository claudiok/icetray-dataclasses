#include <dataclasses/BoostHeaders.h>
#include <dataclasses/geometry/I3Geometry.h>

const char* I3FrameTraits<I3Geometry>::defaultName = "Geometry";

const char* I3FrameTraits<const I3Geometry>::defaultName = "Geometry";

I3Geometry::~I3Geometry() {}

template <class Archive>
void 
I3Geometry::serialize(Archive& ar, unsigned version)
{
  ar & make_nvp("TObject", base_object< TObject >(*this));
  ar & make_nvp("inIce",inIce_);
  ar & make_nvp("top",top_);
  ar & make_nvp("StartTime",startTime_);
  ar & make_nvp("EndTime",endTime_);
}

I3_SERIALIZABLE(I3Geometry);
