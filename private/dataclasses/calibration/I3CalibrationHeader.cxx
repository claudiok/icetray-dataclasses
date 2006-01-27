#include <dataclasses/BoostHeaders.h>
#include <dataclasses/calibration/I3CalibrationHeader.h>

I3CalibrationHeader::~I3CalibrationHeader() {}

template <class Archive>
void 
I3CalibrationHeader::serialize(Archive& ar, unsigned version)
{
  ar & make_nvp("I3DataHeader",base_object<I3DataHeader>(*this));
}

I3_SERIALIZABLE(I3CalibrationHeader);
