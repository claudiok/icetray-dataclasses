#ifndef I3_WAVEFORM_H
#define I3_WAVEFORM_H

#include <vector>
#include "dataclasses/I3Vector.h"
#include "dataclasses/I3Map.h"
#include "dataclasses/OMKey.h"

using namespace std;

class I3Waveform 
{
public:
    enum Source
    {
      ATWD,
      FADC,
      TWR_ELECTRICAL,
      TWR_OPTICAL,
      ETC
    };

private:
  double startTime_;
  double binWidth_;
  vector<double> waveform_;
  Source source_;
  
public:
  double GetStartTime() const {return startTime_;}

  void SetStartTime(double startTime){startTime_ = startTime;}

  double GetBinWidth() const {return binWidth_;}

  void SetBinWidth(double binWidth){binWidth_ = binWidth;}

  const vector<double>& GetWaveform() const {return waveform_;}

  void SetWaveform(const vector<double>& waveform){waveform_ = waveform;}

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



#endif
