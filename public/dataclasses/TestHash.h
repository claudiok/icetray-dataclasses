#ifndef I3TESTHASH_H
#define I3TESTHASH_H

#include "I3MCHit.h"
#include "STLHashStoragePolicy.h"
#include "AugHashMap.h"

class I3TestHashHeader {
  float weight_;
 public:
  float weight() { return weight_; }
  void weight(float weight__) { weight_ = weight__; }
};

typedef STLHashStoragePolicy<I3MCHit> I3TestHashStoragePolicy;
typedef AugHashMap<I3TestHashHeader, I3MCHit, I3TestHashStoragePolicy> I3TestHash;

#endif
