#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3MCEventHeader.h>

template <class Archive>
  void I3MCEventHeader::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3MCEventHeader", base_object<I3EventHeader>(*this));
  }
  
  

I3_SERIALIZABLE(I3MCEventHeader);