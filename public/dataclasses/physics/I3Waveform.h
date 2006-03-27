#ifndef I3_WAVEFORM_H
#define I3_WAVEFORM_H

#include <vector>
#include "dataclasses/I3Vector.h"
#include "dataclasses/I3Map.h"
#include "dataclasses/OMKey.h"

class I3Waveform 
{
public:
    enum Source
    {
      ATWD = 0,
      FADC = 10,
      TWR_ELECTRICAL = 20,
      TWR_OPTICAL = 30,
      ETC = 40
    };

private:
  double startTime_;
  double binWidth_;
  std::vector<double> waveform_;
  Source source_;
  
public:
  double GetStartTime() const {return startTime_;}

  void SetStartTime(double startTime){startTime_ = startTime;}

  double GetBinWidth() const {return binWidth_;}

  void SetBinWidth(double binWidth){binWidth_ = binWidth;}

  const std::vector<double>& GetWaveform() const {return waveform_;}

  std::vector<double>& GetWaveform() {return waveform_;}

  void SetWaveform(const std::vector<double>& waveform){waveform_ = waveform;}

  Source GetSource() const{return source_;}

  void SetSource(Source source){source_ = source;}

private:
    friend class boost::serialization::access;
    template<class Archive> void serialize(Archive& ar, unsigned version);
};

typedef I3Vector<I3Waveform> I3WaveformSeries;
typedef I3Map<OMKey, I3WaveformSeries> I3WaveformSeriesMap;

I3_POINTER_TYPEDEFS(I3Waveform);
I3_POINTER_TYPEDEFS(I3WaveformSeries);
I3_POINTER_TYPEDEFS(I3WaveformSeriesMap);



#endif
