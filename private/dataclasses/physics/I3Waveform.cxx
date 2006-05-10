#include <dataclasses/BoostHeaders.h>
#include <dataclasses/physics/I3Waveform.h>


I3Waveform::StatusCompound::~StatusCompound() {}


template <class Archive>
void I3Waveform::StatusCompound::serialize(Archive& ar, unsigned version)
{
  ar & make_nvp("interval", interval_);
  ar & make_nvp("status", status_);
}

I3_SERIALIZABLE(I3Waveform::StatusCompound);


I3Waveform::~I3Waveform() {}


template <class Archive>
void I3Waveform::serialize(Archive& ar, unsigned version)
{
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

BOOST_CLASS_VERSION(I3Waveform, 1);
I3_SERIALIZABLE(I3Waveform);

I3_SERIALIZABLE(I3WaveformSeries);
I3_SERIALIZABLE(I3WaveformSeriesMap);
