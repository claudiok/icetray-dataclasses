/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3RecoHitSeries.h,v 1.13 2004/02/24 01:51:35 pretz Exp $

    @version $Revision: 1.13 $
    @date $Date: 2004/02/24 01:51:35 $
    @author

    @todo

*/
#ifndef I3RECOHITSERIES_H
#define I3RECOHITSERIES_H

#include "I3RecoHit.h"
#include "StoragePolicy.h"

class I3RecoHitSeries : public VectorPolicy<I3RecoHit>::ThePolicy
{
  float confidence_;
 public:
  float Confidence() { return confidence_; }
  void Confidence(float confidence__) { confidence_ = confidence__; }

  virtual ~I3RecoHitSeries(){};
  ClassDef(I3RecoHitSeries,1);
};

typedef PtrPolicy<I3RecoHitSeries>::ThePolicy I3RecoHitSeriesPtr;

#endif

