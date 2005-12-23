#include <dataclasses/BoostHeaders.h>
#include <dataclasses/physics/I3MCEventHeader.h>

I3MCEventHeader::~I3MCEventHeader() {}

template <class Archive>
  void I3MCEventHeader::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3MCEventHeader", base_object<I3EventHeader>(*this));
  }
  
  

I3_SERIALIZABLE(I3MCEventHeader);
