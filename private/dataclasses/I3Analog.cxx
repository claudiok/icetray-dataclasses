#include "dataclasses/I3Analog.h"

ClassImp(I3Analog);
  
I3Analog::I3Analog()
{
  time=0;
  let=0;
  integratedcharge=0;
  tot=0;
  peak=0;
}

unsigned long  I3Analog::GetTime() const             {return(time);}
unsigned long  I3Analog::GetLet() const              {return(let);}
float          I3Analog::GetIntegratedCharge() const {return(integratedcharge);}
unsigned short I3Analog::GetTot() const              {return(tot);}
float          I3Analog::GetPeak() const             {return(peak);}

void I3Analog::SetTime(unsigned long time_)                 {time=time_;}
void I3Analog::SetLet(unsigned long let_)                   {let=let_;}
void I3Analog::SetIntegratedCharge(float integratedcharge_) {integratedcharge=integratedcharge_;}
void I3Analog::SetTot(unsigned short tot_)                  {tot=tot_;}
void I3Analog::SetPeak(float peak_)                         {peak=peak_;}

