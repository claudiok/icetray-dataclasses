#ifndef I3RECOHIT_H
#define I3RECOHIT_H

#include <TObject.h>
#include "I3Hit.h"

class I3RecoHit : public I3Hit
{
  float confidence;

  public:
  I3RecoHit();

  float GetConfidence() const;
  void SetConfidence(float confidence_);

  ClassDef(I3RecoHit, 1);
};
#endif

