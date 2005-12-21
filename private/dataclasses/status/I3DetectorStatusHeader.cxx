#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3DetectorStatusHeader.h>

I3DetectorStatusHeader::~I3DetectorStatusHeader(){}

template <class Archive>
  void I3DetectorStatusHeader::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3DataHeader",base_object<I3DataHeader>(*this));
  }



I3_SERIALIZABLE(I3DetectorStatusHeader);
