#include "dataclasses/I3Hit.h"

ClassImp(I3Hit);
  
I3Hit::I3Hit() {time=0;}

unsigned long I3Hit::GetTime() const              {return(time);}
void          I3Hit::SetTime(unsigned long time_) {time=time_;}

