#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3GeometryHeader.h>

I3GeometryHeader::~I3GeometryHeader() {}

template <class Archive>
  void I3GeometryHeader::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3DataHeader",base_object<I3DataHeader>(*this));
    ar & make_nvp("numOMs",numOMs_);
    ar & make_nvp("numStrings",numStrings_);
    ar & make_nvp("arrayName",arrayName_);
  }



I3_SERIALIZABLE(I3GeometryHeader);
