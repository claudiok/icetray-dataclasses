#include "dataclasses/I3HitSeries.h"
#include "dataclasses/I3DataExecution.h"
#include "dataclasses/I3TCollectionIterator.h"
#include "dataclasses/I3ZeroItemIterator.h"

ClassImp(I3HitSeries);

I3HitSeries::I3HitSeries()  
{
  hit=NULL;
}

I3HitSeries::~I3HitSeries() 
{
  if(hit) {hit->Delete();  delete hit;} 
}

I3HitSeries::I3HitSeries(const I3HitSeries& h)
{
  hit=NULL;
  int n=h.GetNumberHits();
  if(n>0)
  {
    hit=new TObjArray(n);
    for(int i=0; i<n; i++) hit->Add(new I3Hit(h.GetHit(i)));
  }
}

I3HitSeries& I3HitSeries::operator=(const I3HitSeries& h)
{
  if(this==&h) return(*this);
  if(hit) {hit->Delete(); delete hit;}
  hit=NULL;
  int n=h.GetNumberHits();
  if(n>0)
  {
    hit=new TObjArray(n);
    for(int i=0; i<n; i++) hit->Add(new I3Hit(h.GetHit(i)));
  }
  return(*this);
}

int I3HitSeries::GetNumberHits() const
{
  return((hit==NULL) ? 0 : hit->GetEntriesFast());
}

const I3Hit& I3HitSeries::GetHit(unsigned short number) const 
{
  if(GetNumberHits()>number) return (*(I3Hit*)hit->At(number));
  I3DataExecution::Instance().Fatal("I3HitSeries::GetHit() requested a hit which doesn't exist");
  return(*(I3Hit*)NULL);
}

void I3HitSeries::AddHit(I3Hit* hit_)
{
  if(hit==NULL) hit = new TObjArray(1); 
  hit->Add(hit_);
}

I3Iterator<const I3Hit>* I3HitSeries::MakeHitIterator(){
  if(!hit)
    return new I3ZeroItemIterator<const I3Hit>();
  else
    return new I3TCollectionIterator<const I3Hit>(hit);
}

