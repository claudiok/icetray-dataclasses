#include "dataclasses/I3RecoResultLikelihood.h"

ClassImp(I3RecoResultLikelihood);

I3RecoResultLikelihood::I3RecoResultLikelihood() {likelihood=0;}

float I3RecoResultLikelihood::GetLikelihood() const            {return likelihood;}
void  I3RecoResultLikelihood::SetLikelihood(float likelihood_) {likelihood=likelihood_;}

