#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3MCPMTResponseRomeo.h>

template <class Archive>
    void I3MCPMTResponseRomeo::serialize(Archive& ar, unsigned version){
    ar & make_nvp("I3MCPMTResponse",base_object<I3MCPMTResponse>(*this));
    ar & make_nvp("Waveform",waveform_);
    ar & make_nvp("BinSize",binSize_);
  }


I3_SERIALIZABLE(I3MCPMTResponseRomeo);
