#ifndef I3HIT_H
#define I3HIT_H

#include <TObject.h>

class I3Hit : public TObject
{
  unsigned long  true_time;

  public:
  I3Hit();

  unsigned long GetTruetime() const;
  void SetTruetime(unsigned long true_time_);

  ClassDef(I3Hit, 1);
};
#endif

