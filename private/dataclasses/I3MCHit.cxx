#include "dataclasses/I3MCHit.h"

ClassImp(I3MCHit);
  
I3MCHit::I3MCHit() {weight=0; track_number=0;}

float          I3MCHit::GetWeight() const      {return(weight);}
unsigned short I3MCHit::GetTracknumber() const {return(track_number);}

void I3MCHit::SetWeight(float weight_)                     {weight=weight_;}
void I3MCHit::SetTracknumber(unsigned short track_number_) {track_number=track_number_;}

