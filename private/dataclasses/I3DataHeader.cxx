#include <dataclasses/BoostHeaders.h>
#include <dataclasses/I3DataHeader.h>

template <class Archive>
  void I3DataHeader::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("StartTime", startTime_);
    ar & make_nvp("EndTime", endTime_);
  }

  

I3_SERIALIZABLE(I3DataHeader);
