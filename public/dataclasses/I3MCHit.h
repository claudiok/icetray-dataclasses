#ifndef I3MCHIT_H
#define I3MCHIT_H

#include <TObject.h>
#include "I3Hit.h"

class I3MCHit : public I3Hit
{
  float          weight;
  unsigned short track_number;

  public:
  I3MCHit();

  float          GetWeight() const;
  unsigned short GetTracknumber() const;

  void SetWeight(float weight_);
  void SetTracknumber(unsigned short track_number_);

  ClassDef(I3MCHit, 1);
};
#endif

