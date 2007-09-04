#include <icetray/serialization.h>
#include <dataclasses/physics/I3EventHeader.h>

#include <limits>


I3EventHeader::I3EventHeader()
  : runID_(std::numeric_limits<unsigned int>::max()),
    subRunID_(std::numeric_limits<int>::max()),
    eventID_(std::numeric_limits<unsigned int>::max())
{
}


I3EventHeader::~I3EventHeader()
{
}


template <class Archive>
void 
I3EventHeader::serialize(Archive& ar, unsigned version)
{
  if(version > i3eventheader_version_)
    log_fatal("Attempting to read version %u from file but running version %u of I3EventHeader class.",version,i3eventheader_version_);

  ar & make_nvp("I3FrameObject", base_object<I3FrameObject>(*this));
  ar & make_nvp("RunID", runID_);
  if(version > 1)
    {
      ar & make_nvp("SubRunID", subRunID_);
    }
  else if(version > 0)
    {
      // in version 1 the sub run ID was not signed, but unsigned
      // ... no problem at all for sub run IDs <= INT_MAX
      // ... using INT_MAX for sub run ID > INT_MAX
      unsigned temp = 0;
      ar & make_nvp("SubRunID", temp);
      subRunID_ = (temp > static_cast<unsigned>(std::numeric_limits<int>::max())) ?
                  std::numeric_limits<int>::max() : temp;
    }
  else
    {
      // in version 0 there was no sub run ID
      // ... using 0 as a default value
      subRunID_ = 0;
    }
  ar & make_nvp("EventID", eventID_);
  ar & make_nvp("StartTime", startTime_);
  ar & make_nvp("EndTime", endTime_);
}
  
I3_SERIALIZABLE(I3EventHeader);
