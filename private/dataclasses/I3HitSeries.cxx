#include "dataclasses/I3HitSeries.h"

ClassImp(I3HitSeries);

I3HitSeries::I3HitSeries()  {hit=NULL;}
I3HitSeries::~I3HitSeries() {if(hit) {hit->Delete(); delete hit;} }

int          I3HitSeries::GetNumberHits() const               {return((hit==NULL) ? 0 : hit->GetEntriesFast());}
const I3Hit* I3HitSeries::GetHit(unsigned short number) const {return((GetNumberHits()<=number) ? NULL : (I3Hit*)hit->At(number));}
void         I3HitSeries::AddHit(I3Hit* hit_)                 {if(hit==NULL) hit = new TObjArray(1); hit->Add(hit_);}
