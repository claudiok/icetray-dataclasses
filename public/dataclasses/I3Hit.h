#ifndef I3HIT_H
#define I3HIT_H

#include <TObject.h>

class I3Hit : public TObject
{
  unsigned long  time;

  public:
  I3Hit();

  unsigned long GetTime() const;
  void SetTime(unsigned long time_);

  ClassDef(I3Hit, 1);
};
#endif

