#ifndef I3_WAVEFORM_H
#define I3_WAVEFORM_H

#include <vector>

using namespace std;

class I3Waveform
{
#warning implement me
  double startTime_;
  double binWidth_;
  vector<double> waveform_;
  enum Source
    {
      TWR,
      ATWD,
      FADC,
      ETC
    };
};

#endif
