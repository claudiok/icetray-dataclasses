#include "dataclasses/I3MCHitSeries.h"

ClassImp(I3MCHitSeries);
  
I3MCHitSeries::I3MCHitSeries() {weight=0;}

float I3MCHitSeries::GetWeight() const        {return(weight);}
void  I3MCHitSeries::SetWeight(float weight_) {weight=weight_;}

const I3MCHit* I3MCHitSeries::GetHit(unsigned short number) const {return((GetNumberHits()<=number) ? NULL : (I3MCHit*)hit->At(number));}
void           I3MCHitSeries::AddHit(I3MCHit* hit_)               {if(hit==NULL) hit = new TObjArray(1); hit->Add(hit_);}
