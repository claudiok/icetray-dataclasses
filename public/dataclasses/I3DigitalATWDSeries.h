#ifndef I3DIGITALATWDSERIES_H
#define I3DIGITALATWDSERIES_H

#include "I3DigitalSeries.h"

class I3DigitalATWDSeries : public I3DigitalSeries
{
  float gain;
  public:
  I3DigitalATWDSeries();

  float GetGain() const;
  void  SetGain(float gain_);

  ClassDef(I3DigitalATWDSeries,1);
};
#endif

