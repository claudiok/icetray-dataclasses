/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3RecoHitSeries.h,v 1.12 2004/02/23 22:36:49 troy Exp $

    @version $Revision: 1.12 $
    @date $Date: 2004/02/23 22:36:49 $
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

typedef PtrPolicy<I3RecoHitSeries> I3RecoHitSeriesPtr;

#endif

