#include "dataclasses/I3DatareadoutList.h"
#include "dataclasses/I3DataExecution.h"
#include "dataclasses/I3TCollectionIterator.h"
#include "dataclasses/I3ZeroItemIterator.h"

ClassImp(I3DatareadoutList);

I3DatareadoutList::I3DatareadoutList()  
{
  datareadout=NULL; 
}

I3DatareadoutList::~I3DatareadoutList() 
{
  if (datareadout)  {datareadout->Delete();  delete datareadout;}  
}

int I3DatareadoutList::GetNumberDatareadouts() const 
{
  return((datareadout==NULL) ? 0 : datareadout->GetEntriesFast());
}

const I3Datareadout& I3DatareadoutList::GetDatareadout(unsigned short number) const 
{
  if(GetNumberDatareadouts()>number) return (*(I3Datareadout*)datareadout->At(number));
  I3DataExecution::Instance().Fatal("I3DatareadoutList::GetDatareadout() asked for a datareadout which doesn't exists");
  return(*(I3Datareadout*)NULL);
}

void I3DatareadoutList::AddDatareadout(I3Datareadout* datareadout_) 
{
  if(datareadout==NULL) datareadout = new TObjArray(1); 
  datareadout->Add(datareadout_);
}

I3Iterator<const I3Datareadout>* I3DatareadoutList::MakeDatareadoutIterator() const
{
  if(!datareadout)
    return new I3ZeroItemIterator<const I3Datareadout>();
  else
    return new I3TCollectionIterator<const I3Datareadout>(datareadout);

}
