#ifndef I3RECOHIT_H
#define I3RECOHIT_H

#include <TObject.h>
#include "I3Hit.h"

class I3RecoHit : public I3Hit
{
  float fConfidence;

  public:
  I3RecoHit();

  float Confidence() const { return fConfidence; }
  void Confidence(float confidence_) { fConfidence = confidence_; }

  ClassDef(I3RecoHit, 1);
};
#endif

