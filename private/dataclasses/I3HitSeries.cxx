#include "dataclasses/I3HitSeries.h"
#include "dataclasses/I3DataExecution.h"

ClassImp(I3HitSeries);

I3HitSeries::I3HitSeries()  
{
  hit=NULL;
}

I3HitSeries::~I3HitSeries() 
{
  if(hit) {hit->Delete();  delete hit;} 
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
  I3DataExecution::Instance().Fatal("Iterators Not implemented yet");
  return 0;
}
