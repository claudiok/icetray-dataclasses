#ifndef I3MCHITSERIES_H
#define I3MCHITSERIES_H

#include "I3MCHit.h"
#include "StoragePolicy.h"

class I3MCHitSeries : public VectorPolicy<I3MCHit>::ThePolicy 
{
  float fWeight;
 public:
  float Weight() { return fWeight; }
  void Weight(float weight_) { fWeight = weight_; }

  virtual ~I3MCHitSeries() {;}
  ClassDef(I3MCHitSeries,1);
};


#endif
