#include "dataclasses/I3DataReadout.h"
#include "TClass.h"

ClassImp(I3DataReadout);

I3DataReadout::I3DataReadout() {;}
 
const char* I3DataReadout::GetReadoutType() const 
{
  return this->IsA()->GetName();
}

