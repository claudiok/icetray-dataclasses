#include "dataclasses/I3MCTrack.h"

ClassImp(I3MCTrack);
  
I3MCTrack::I3MCTrack() {weight=0; }

float I3MCTrack::GetWeight() const        {return(weight);}
void  I3MCTrack::SetWeight(float weight_) {weight=weight_;}

