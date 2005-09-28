#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3MCPMTResponse.h>

template <class Archive>
    void I3MCPMTResponse::serialize(Archive& ar, unsigned version){
    ar & make_nvp("StartTime", startTime_);
    ar & make_nvp("EndTime", endTime_);
  }

  

I3_SERIALIZABLE(I3MCPMTResponse);
