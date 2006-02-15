#include <dataclasses/BoostHeaders.h>
#include <dataclasses/status/I3DOMStatus.h>

I3DOMStatus::~I3DOMStatus() {}

template <class Archive>
void I3DOMStatus::serialize (Archive& ar, unsigned version)
{
  ar & make_nvp("TObject", base_object< TObject >(*this));
  ar & make_nvp("rawStatus",rawStatus_);
  ar & make_nvp("calibratedStatus",calibratedStatus_);
}



I3_SERIALIZABLE(I3DOMStatus);
