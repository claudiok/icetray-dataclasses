#ifndef I3MCHITSERIES_H
#define I3MCHITSERIES_H

#include "I3HitSeries.h"
#include "I3MCHit.h"

class I3MCHitSeries : public I3HitSeries
{
  float  weight;

  public:
  I3MCHitSeries();

  float GetWeight() const;

  void  SetWeight(float weight_);

  const I3MCHit& GetHit(unsigned short number) const;

  void AddHit(I3MCHit* hit_);

  I3Iterator<const I3MCHit>* MakeMCHitIterator();


  ClassDef(I3MCHitSeries, 1);
};
#endif
