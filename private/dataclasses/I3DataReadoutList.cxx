#include "dataclasses/I3DataReadoutList.h"
#include "dataclasses/I3DataExecution.h"
#include "dataclasses/I3TCollectionIterator.h"
#include "dataclasses/I3ZeroItemIterator.h"

ClassImp(I3DataReadoutList);

I3DataReadoutList::I3DataReadoutList()  
{
  datareadout=NULL; 
}

I3DataReadoutList::~I3DataReadoutList() 
{
  if (datareadout)  {datareadout->Delete();  delete datareadout;}  
}

int I3DataReadoutList::GetNumberDataReadouts() const 
{
  return((datareadout==NULL) ? 0 : datareadout->GetEntriesFast());
}

const I3DataReadout& I3DataReadoutList::GetDataReadout(unsigned short number) const 
{
  if(GetNumberDataReadouts()>number) return (*(I3DataReadout*)datareadout->At(number));
  I3DataExecution::Instance().Fatal("I3DataReadoutList::GetDataReadout() asked for a datareadout which doesn't exists");
  return(*(I3DataReadout*)NULL);
}

void I3DataReadoutList::AddDataReadout(I3DataReadout* datareadout_) 
{
  if(datareadout==NULL) datareadout = new TObjArray(1); 
  datareadout->Add(datareadout_);
}

I3Iterator<const I3DataReadout>* I3DataReadoutList::MakeDataReadoutIterator() const
{
  if(!datareadout)
    return new I3ZeroItemIterator<const I3DataReadout>();
  else
    return new I3TCollectionIterator<const I3DataReadout>(datareadout);

}
