#include "dataclasses/I3DatareadoutList.h"
#include "dataclasses/I3DataExecution.h"

ClassImp(I3DatareadoutList);

I3DatareadoutList::I3DatareadoutList()  
{
  datareadout=NULL; 
}

I3DatareadoutList::~I3DatareadoutList() {
  if (datareadout)  {
    datareadout->Delete();  
    delete datareadout;
  }  
}

int I3DatareadoutList::GetNumberDatareadouts() const 
{
  return((datareadout==NULL) ? 0 : datareadout->GetEntriesFast());
}

const I3Datareadout& I3DatareadoutList::GetDatareadout(unsigned short number) const 
{
  if(datareadout){
    I3Datareadout* to_return = (I3Datareadout*)datareadout->At(number);
    if(to_return)
      return *to_return;
  }
  I3DataExecution::Instance().Fatal("I3DatareadoutList::GetDatareadout the readout requested doesn't exist.  Check first");
  return *(I3Datareadout*)0;
}

void I3DatareadoutList::AddDatareadout(I3Datareadout* datareadout_) 
{
  if(datareadout==NULL) 
    datareadout = new TObjArray(1); 
  datareadout->Add(datareadout_);
}

