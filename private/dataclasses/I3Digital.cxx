#include "dataclasses/I3Digital.h"

ClassImp(I3Digital);
  
I3Digital::I3Digital() {value=0;}

unsigned char I3Digital::GetValue() const                {return(value);}
void          I3Digital::SetValue(unsigned char value_)  {value=value_;}


