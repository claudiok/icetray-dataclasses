#include <icetray/serialization.h>
#include <dataclasses/physics/I3EventHeader.h>

I3EventHeader::I3EventHeader() :
  runID_(std::numeric_limits<unsigned int>::max()),
  subRunID_(std::numeric_limits<unsigned int>::max()),
  eventID_(std::numeric_limits<unsigned int>::max())
{
}

I3EventHeader::~I3EventHeader() {}



template <class Archive>
void 
I3EventHeader::serialize(Archive& ar, unsigned version)
{
  if (version>i3eventheader_version_)
    log_fatal("Attempting to read version %u from file but running version %u of I3EventHeader class.",version,i3eventheader_version_);

  ar & make_nvp("I3FrameObject", base_object<I3FrameObject>(*this));
  ar & make_nvp("RunID", runID_);
  if(version > 1)
    {
      ar & make_nvp("SubRunID", subRunID_);
    }
  else
    {
      //in version 0 and 1 the sub run ID was always zero. Hence if we are
      //reading data of that version we have to make sure that it is always
      //zero as well. Also the subrunID changed from an unsigned to an int.
      unsigned temp = 0;
      ar & make_nvp("SubRunID", temp);
      subRunID_ = temp;
    }
  ar & make_nvp("EventID", eventID_);
  ar & make_nvp("StartTime",startTime_);
  ar & make_nvp("EndTime",endTime_);
}
  
I3_SERIALIZABLE(I3EventHeader);
