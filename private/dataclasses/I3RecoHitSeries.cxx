#include "dataclasses/I3RecoHitSeries.h"
#include "dataclasses/I3ZeroItemIterator.h"
#include "dataclasses/I3TCollectionIterator.h"

ClassImp(I3RecoHitSeries);
  
I3RecoHitSeries::I3RecoHitSeries() {confidence=0;}

I3RecoHitSeries::I3RecoHitSeries(const I3RecoHitSeries& h)
{
  hit=NULL;
  int n=h.GetNumberHits();
  if(n>0)
  {
    hit=new TObjArray(n);
    for(int i=0; i<n; i++) hit->Add(new I3RecoHit(h.GetHit(i)));
  }
  confidence=h.confidence;
}

I3RecoHitSeries& I3RecoHitSeries::operator=(const I3RecoHitSeries& h)
{
  if(this==&h) return(*this);
  if(hit) {hit->Delete(); delete hit;}
  hit=NULL;
  int n=h.GetNumberHits();
  if(n>0)
  {
    hit=new TObjArray(n);
    for(int i=0; i<n; i++) hit->Add(new I3RecoHit(h.GetHit(i)));
  }
  confidence=h.confidence;
  return(*this);
}

float I3RecoHitSeries::GetConfidence() const            {return(confidence);}
void  I3RecoHitSeries::SetConfidence(float confidence_) {confidence=confidence_;}

const I3RecoHit& I3RecoHitSeries::GetHit(unsigned short number) const 
{
  return (I3RecoHit&)I3HitSeries::GetHit(number);
}

void I3RecoHitSeries::AddHit(I3RecoHit* hit_)             
{
  I3HitSeries::AddHit(hit_);
}

I3Iterator<const I3RecoHit>* I3RecoHitSeries::MakeRecoHitIterator()
{
  if(!hit)
    return new I3ZeroItemIterator<const I3RecoHit>();
  else
    return new I3TCollectionIterator<const I3RecoHit>(hit);
}
