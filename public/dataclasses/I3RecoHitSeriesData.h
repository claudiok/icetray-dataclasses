#ifndef I3RECOHITSERIESDATA_H
#define I3RECOHITSERIESDATA_H

#include "I3RecoHitSeries.h"
#include "StoragePolicy.h"

class I3RecoHitSeriesData : public VectorPolicy<I3RecoHitSeries>::ThePolicy
{
 public:
  virtual ~I3RecoHitSeriesData(){};
  ClassDef(I3RecoHitSeriesData,1);
};


#endif

