#ifndef I3MCHITSERIES_H
#define I3MCHITSERIES_H

#include "I3MCHit.h"
#include "TClonesPolicy.h"
#include "GarnishedVector.h"

class I3MCHitSeriesHeader {
  float weight_;
 public:
  float weight() { return weight_; }
  void weight(float weight__) { weight_ = weight__; }
};

typedef TClonesPolicy<I3MCHit> I3MCHitSeriesStoragePolicy;
typedef GarnishedVector<I3MCHitSeriesHeader, I3MCHit, I3MCHitSeriesStoragePolicy> I3MCHitSeries;



#endif
