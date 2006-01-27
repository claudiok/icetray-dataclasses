#include <dataclasses/BoostHeaders.h>
#include <dataclasses/physics/I3MCPMTResponse.h>

I3MCPMTResponse::~I3MCPMTResponse(){}

template <class Archive>
void 
I3MCPMTResponse::serialize (Archive& ar, unsigned version)
{
  ar & make_nvp("TObject", base_object< TObject >(*this));
  ar & make_nvp("StartTime", startTime_);
  ar & make_nvp("EndTime", endTime_);
}

  

I3_SERIALIZABLE(I3MCPMTResponse);
