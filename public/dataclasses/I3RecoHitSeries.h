#ifndef I3RECOHITSERIES_H
#define I3RECOHITSERIES_H

#include "I3RecoHit.h"
#include "TClonesPolicy.h"
#include "GarnishedVector.h"

class I3RecoHitSeriesHeader {
  float confidence_;
 public:
  float confidence() { return confidence_; }
  void confidence(float confidence__) { confidence_ = confidence__; }
};

//typedef STLVectorPolicy<I3RecoHit> I3RecoHitSeriesStoragePolicy;
typedef TClonesPolicy<I3RecoHit> I3RecoHitSeriesStoragePolicy;
typedef GarnishedVector<I3RecoHitSeriesHeader, I3RecoHit, I3RecoHitSeriesStoragePolicy> I3RecoHitSeries;

#endif

