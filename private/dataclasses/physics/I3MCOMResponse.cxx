#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3MCOMResponse.h>

I3MCOMResponse::~I3MCOMResponse(){}

template <class Archive>
    void I3MCOMResponse::serialize(Archive& ar, unsigned version){
    ar & make_nvp("I3OMResponse",base_object<I3OMResponse>(*this));
    ar & make_nvp("MCHitSeries",mCHitSeries_);
    ar & make_nvp("MCPMTResponse",mCPMTResponse_);
    ar & make_nvp("PMTPulseVect",pMTPulseVect_);
  }

  

I3_SERIALIZABLE(I3MCOMResponse);
