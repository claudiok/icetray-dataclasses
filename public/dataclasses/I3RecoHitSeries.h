#ifndef I3RECOHITSERIES_H
#define I3RECOHITSERIES_H

#include "I3HitSeries.h"
#include "I3RecoHit.h"

class I3RecoHitSeries : public I3HitSeries
{
  float  confidence;

  public:
  I3RecoHitSeries();

  float GetConfidence() const;
  void  SetConfidence(float confidence_);

  const I3RecoHit& GetHit(unsigned short number) const;
  void AddHit(I3RecoHit* hit_);
  I3Iterator<const I3RecoHit>* MakeRecoHitIterator();

  ClassDef(I3RecoHitSeries, 1);
};
#endif

