#ifndef I3ANALOGSERIES_H
#define I3ANALOGSERIES_H

#include "I3DataReadout.h"
#include "I3Analog.h"
#include "dataclasses/I3Iterator.h"

class I3AnalogSeries : public I3DataReadout
{
  protected:
  TObjArray *pulse;

  public:
  I3AnalogSeries();
  ~I3AnalogSeries();
  I3AnalogSeries(const I3AnalogSeries&);
  I3AnalogSeries& operator=(const I3AnalogSeries&);

  int GetNumberPulses() const;
  const I3Analog& GetPulse(unsigned short number) const;
  void  AddPulse(I3Analog* pulse_);
  I3Iterator<const I3Analog>* MakeAnalogIterator() const;

  ClassDef(I3AnalogSeries,1);
};
#endif

