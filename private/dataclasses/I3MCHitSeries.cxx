#include "dataclasses/I3MCHitSeries.h"

ClassImp(I3MCHitSeries);
  
I3MCHitSeries::I3MCHitSeries() {weight=0;}

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
