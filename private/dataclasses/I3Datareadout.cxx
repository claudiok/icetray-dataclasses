#include "dataclasses/I3Datareadout.h"
#include "TClass.h"

ClassImp(I3Datareadout);

I3Datareadout::I3Datareadout() {;}
 
const char* I3Datareadout::GetReadoutType() const 
{
  return this->IsA()->GetName();
}

