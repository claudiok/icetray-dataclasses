#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3EventHeader.h>

I3EventHeader::~I3EventHeader() {}

template <class Archive>
  void I3EventHeader::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3DataHeader", base_object<I3DataHeader>(*this));
    ar & make_nvp("RunID", runID_);
    ar & make_nvp("EventID", eventID_);
  }
  
  

I3_SERIALIZABLE(I3EventHeader);
