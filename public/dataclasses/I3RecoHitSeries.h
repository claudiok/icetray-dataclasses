/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3RecoHitSeries.h,v 1.8 2004/02/20 21:42:08 troy Exp $

    @version $Revision: 1.8 $
    @date $Date: 2004/02/20 21:42:08 $
    @author

    @todo

*/
#ifndef I3RECOHITSERIES_H
#define I3RECOHITSERIES_H

#include "I3RecoHit.h"
#include "StoragePolicy.h"
#include "AugVec.h"

class I3RecoHitSeriesHeader {
  float confidence_;
 public:
  float confidence() { return confidence_; }
  void confidence(float confidence__) { confidence_ = confidence__; }
};

typedef StoragePolicy<I3RecoHit> I3RecoHitSeriesStoragePolicy;
typedef AugVec<I3RecoHitSeriesHeader, I3RecoHit, I3RecoHitSeriesStoragePolicy> I3RecoHitSeries;

#endif

