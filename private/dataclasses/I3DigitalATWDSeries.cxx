#include "dataclasses/I3DigitalATWDSeries.h"

ClassImp(I3DigitalATWDSeries);
  
I3DigitalATWDSeries::I3DigitalATWDSeries() {gain=0;}

float I3DigitalATWDSeries::GetGain() const       {return(gain);}
void  I3DigitalATWDSeries::SetGain(float gain_)  {gain=gain_;}


