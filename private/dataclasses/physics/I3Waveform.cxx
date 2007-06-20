#include <icetray/serialization.h>
#include <dataclasses/physics/I3Waveform.h>

#include <algorithm>
#include <boost/lambda/bind.hpp>
#include <boost/lambda/lambda.hpp>


using namespace std;
using namespace boost::lambda;


I3Waveform::StatusCompound::~StatusCompound() {}


template <class Archive>
void I3Waveform::StatusCompound::serialize(Archive& ar, unsigned version)
{
  if (version>i3waveform_version_)
    log_fatal("Attempting to read version %u from file but running version %u of I3Waveform class",version,i3waveform_version_);

  ar & make_nvp("interval", interval_);
  ar & make_nvp("status", status_);
}

I3_SERIALIZABLE(I3Waveform::StatusCompound);


I3Waveform::Status I3Waveform::GetStatus(const vector<StatusCompound>& waveformInfo)
{
  Status retVal;
  
  if(waveformInfo.empty()) retVal = VIRGINAL;
  else
    retVal =
      max_element(waveformInfo.begin(), waveformInfo.end(),
                  bind(&StatusCompound::GetStatus, _1) < bind(&StatusCompound::GetStatus, _2))->GetStatus();
    
  return(retVal);
}


I3Waveform::~I3Waveform() {}


template <class Archive>
void I3Waveform::serialize(Archive& ar, unsigned version)
{
  if (version>i3waveform_version_)
    log_fatal("Attempting to read version %u from file but running version %u of I3Waveform class.",version,i3waveform_version_);

  ar & make_nvp("startTime", startTime_);
  ar & make_nvp("binWidth", binWidth_);
  ar & make_nvp("waveform", waveform_);
  // for version > 0 there is a waveform info to be serialized
  if(version > 0)
    ar & make_nvp("waveformInformation", waveformInfo_);
  // for version <= 0 there is no waveform info available
  // clear waveform info instead (assuming the full waveform is "VIRGINAL")
  else
    waveformInfo_.clear();
  ar & make_nvp("source", source_);
}

I3_SERIALIZABLE(I3Waveform);

I3_SERIALIZABLE(I3WaveformSeriesMap);
