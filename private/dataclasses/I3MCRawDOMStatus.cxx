#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3MCRawDOMStatus.h>

template <class Archive>
  void I3MCRawDOMStatus::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3RawDOMStatus", base_object<I3RawDOMStatus>(*this));
    ar & make_nvp("trigMode",trigMode_);
    ar & make_nvp("lcMode",lcMode_);
    ar & make_nvp("lcWindowUpPre",lcWindowUpPre_);
    ar & make_nvp("lcWindowDownPre",lcWindowDownPre_);
    ar & make_nvp("lcWindowUpPost",lcWindowUpPost_);
    ar & make_nvp("lcWindowDownPost",lcWindowDownPost_);
    ar & make_nvp("statusATWDa",statusATWDa_);
    ar & make_nvp("statusATWDb",statusATWDb_);
    ar & make_nvp("statusFADC",statusFADC_);
    ar & make_nvp("pmtHV",pmtHV_);
    ar & make_nvp("speThreshold",speThreshold_);
    ar & make_nvp("fePedestal",fePedestal_);
    ar & make_nvp("dacTriggerBias0",dacTriggerBias0_);
    ar & make_nvp("dacTriggerBias1",dacTriggerBias1_);
    ar & make_nvp("nBinsATWD0",nBinsATWD0_);
    ar & make_nvp("nBinsATWD1",nBinsATWD1_);
    ar & make_nvp("nBinsATWD2",nBinsATWD2_);
    ar & make_nvp("nBinsATWD3",nBinsATWD3_);
    ar & make_nvp("nBinsFADC",nBinsFADC_);
  }



I3_SERIALIZABLE(I3MCRawDOMStatus);
