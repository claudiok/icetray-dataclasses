/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3RecoHitSeries.h,v 1.9 2004/02/21 17:38:10 pretz Exp $

    @version $Revision: 1.9 $
    @date $Date: 2004/02/21 17:38:10 $
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

class I3RecoHitSeries : public AugVec<I3RecoHitSeriesHeader, I3RecoHit, I3RecoHitSeriesStoragePolicy> 
{
  ClassDef(I3RecoHitSeries,1);
};


#endif

