#ifndef I3MCHITSERIES_H
#define I3MCHITSERIES_H

#include "I3MCHit.h"
#include "StoragePolicy.h"
#include "AugVec.h"

class I3MCHitSeriesHeader {
  float weight_;
 public:
  float weight() { return weight_; }
  void weight(float weight__) { weight_ = weight__; }
};

typedef StoragePolicy<I3MCHit> I3MCHitSeriesStoragePolicy;
class I3MCHitSeries : public AugVec<I3MCHitSeriesHeader, I3MCHit, I3MCHitSeriesStoragePolicy>
{
  ClassDef(I3MCHitSeries,1);
};

#endif
