#ifndef I3ANALOGSERIES_H
#define I3ANALOGSERIES_H

#include "I3Datareadout.h"
#include "I3Analog.h"

class I3AnalogSeries : public I3Datareadout
{
  protected:
  TObjArray *pulse;

  public:
   I3AnalogSeries();
  ~I3AnalogSeries();

  int             GetNumberPulses() const;
  const I3Analog* GetPulse(unsigned short number) const;
  void            AddPulse(I3Analog* pulse_);

  ClassDef(I3AnalogSeries,1);
};
#endif

