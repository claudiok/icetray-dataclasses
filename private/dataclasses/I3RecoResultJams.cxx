#include "dataclasses/I3RecoResultJams.h"

ClassImp(I3RecoResultJams);

I3RecoResultJams::I3RecoResultJams() {qualityparameter=0;}

float I3RecoResultJams::GetQualityparameter() const                  {return qualityparameter;}
void  I3RecoResultJams::SetQualityparameter(float qualityparameter_) {qualityparameter=qualityparameter_;}
