#include "dataclasses/I3MCHitSeries.h"
#include "dataclasses/I3ZeroItemIterator.h"
#include "dataclasses/I3TCollectionIterator.h"

ClassImp(I3MCHitSeries);
  
I3MCHitSeries::I3MCHitSeries() {weight=0;}

I3MCHitSeries::I3MCHitSeries(const I3MCHitSeries& h)
{
  hit=NULL;
  int n=h.GetNumberHits();
  if(n>0)
  {
    hit=new TObjArray(n);
    for(int i=0; i<n; i++) hit->Add(new I3MCHit(h.GetHit(i)));
  }
  weight=h.weight;
}

I3MCHitSeries& I3MCHitSeries::operator=(const I3MCHitSeries& h)
{
  if(this==&h) return(*this);
  if(hit) {hit->Delete(); delete hit;}
  hit=NULL;
  int n=h.GetNumberHits();
  if(n>0)
  {
    hit=new TObjArray(n);
    for(int i=0; i<n; i++) hit->Add(new I3MCHit(h.GetHit(i)));
  }
  weight=h.weight;
  return(*this);
}

float I3MCHitSeries::GetWeight() const        {return(weight);}
void  I3MCHitSeries::SetWeight(float weight_) {weight=weight_;}

const I3MCHit& I3MCHitSeries::GetHit(unsigned short number) const 
{
  return (I3MCHit&)I3HitSeries::GetHit(number);
}

void I3MCHitSeries::AddHit(I3MCHit* hit_)
{
  I3HitSeries::AddHit(hit_);
}

I3Iterator<const I3MCHit>* I3MCHitSeries::MakeMCHitIterator() const
{
  if(!hit)
    return new I3ZeroItemIterator<const I3MCHit>();
  else
    return new I3TCollectionIterator<const I3MCHit>(hit);

}
