#include <dataclasses/BoostHeaders.h>
#include <dataclasses/status/I3DaqRawDOMStatus.h>

I3DaqRawDOMStatus::~I3DaqRawDOMStatus() {}

template <class Archive>
  void I3DaqRawDOMStatus::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3RawDOMStatus", base_object<I3RawDOMStatus>(*this));
    ar & make_nvp("trigMode",trigMode_);
    ar & make_nvp("lcMode",lcMode_);
    ar & make_nvp("lcWindowPre",lcWindowPre_);
    ar & make_nvp("lcWindowPost",lcWindowPost_);
    ar & make_nvp("statusFADC",statusFADC_);
    ar & make_nvp("pmtHV",pmtHV_);
    ar & make_nvp("speThreshold",speThreshold_);
    ar & make_nvp("fePedestal",fePedestal_);
    ar & make_nvp("dacTriggerBias0",dacTriggerBias0_);
    ar & make_nvp("dacTriggerBias1",dacTriggerBias1_);
  }



I3_SERIALIZABLE(I3DaqRawDOMStatus);
