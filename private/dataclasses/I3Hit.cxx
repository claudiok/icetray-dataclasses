#include "dataclasses/I3Hit.h"

ClassImp(I3Hit);
  
I3Hit::I3Hit() {true_time=0;}

unsigned long I3Hit::GetTruetime() const                   {return(true_time);}
void          I3Hit::SetTruetime(unsigned long true_time_) {true_time=true_time_;}

