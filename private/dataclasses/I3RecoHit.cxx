#include "dataclasses/I3RecoHit.h"

ClassImp(I3RecoHit);

I3RecoHit::I3RecoHit() {confidence=0;}

float I3RecoHit::GetConfidence() const            {return(confidence);}
void  I3RecoHit::SetConfidence(float confidence_) {confidence=confidence_;}

