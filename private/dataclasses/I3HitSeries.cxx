#include "dataclasses/I3HitSeries.h"
#include "dataclasses/I3DataExecution.h"

ClassImp(I3HitSeries);

I3HitSeries::I3HitSeries()  
{
  hit=NULL;
}

I3HitSeries::~I3HitSeries() 
{
  if(hit) 
    {
      hit->Delete(); 
      delete hit;
    } 
}

int I3HitSeries::GetNumberHits() const
{
  return((hit==NULL) ? 0 : hit->GetEntriesFast());
}

const I3Hit& I3HitSeries::GetHit(unsigned short number) const 
{
  if(hit){
    I3Hit* to_return = (I3Hit*)hit->At(number);
    if(to_return)
      return *to_return;
  }
  I3DataExecution::Instance().Fatal("I3HitSeries::GetHit() the requested hit doesn't exist");
  return *(I3Hit*)0;
}

void I3HitSeries::AddHit(I3Hit* hit_)
{
  if(hit==NULL) hit = new TObjArray(1); hit->Add(hit_);
}
