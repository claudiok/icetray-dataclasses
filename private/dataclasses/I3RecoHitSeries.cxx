#include "dataclasses/I3RecoHitSeries.h"

ClassImp(I3RecoHitSeries);
  
I3RecoHitSeries::I3RecoHitSeries() {confidence=0;}

float I3RecoHitSeries::GetConfidence() const            {return(confidence);}
void  I3RecoHitSeries::SetConfidence(float confidence_) {confidence=confidence_;}

const I3RecoHit* I3RecoHitSeries::GetHit(unsigned short number) const {return((GetNumberHits()<=number) ? NULL : (I3RecoHit*)hit->At(number));}
void             I3RecoHitSeries::AddHit(I3RecoHit* hit_)             {if(hit==NULL) hit = new TObjArray(1); hit->Add(hit_);}

