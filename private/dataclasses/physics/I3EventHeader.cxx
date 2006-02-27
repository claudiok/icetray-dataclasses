#include <dataclasses/BoostHeaders.h>
#include <dataclasses/physics/I3EventHeader.h>

I3EventHeader::I3EventHeader() :
  runID_(std::numeric_limits<unsigned int>::max()),
  eventID_(std::numeric_limits<unsigned int>::max())
{
}

I3EventHeader::~I3EventHeader() {}



template <class Archive>
void 
I3EventHeader::serialize(Archive& ar, unsigned version)
{
  ar & make_nvp("I3FrameObject", base_object<I3FrameObject>(*this));
  ar & make_nvp("RunID", runID_);
  ar & make_nvp("EventID", eventID_);
  ar & make_nvp("StartTime",startTime_);
  ar & make_nvp("EndTime",endTime_);
}
  
I3_SERIALIZABLE(I3EventHeader);
