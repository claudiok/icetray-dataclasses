#include "dataclasses/I3OMResponseData.h"
#include "dataclasses/I3DataExecution.h"

#include "dataclasses/I3TCollectionIterator.h"
#include "dataclasses/I3ZeroItemIterator.h"

ClassImp(I3OMResponseData);

I3OMResponseData::I3OMResponseData()  
{
  omresponse=NULL;
}

I3OMResponseData::~I3OMResponseData() 
{
  if (omresponse) {omresponse->Delete(); delete omresponse;} 
}


int I3OMResponseData::GetNumberOMResponses() const
{
  return((omresponse==NULL) ? 0 : omresponse->GetEntriesFast());
}

bool I3OMResponseData::HasOMResponseNumber(unsigned short omnumber) const
{
  short i_max=GetNumberOMResponses();
  for(short i=0; i<i_max; i++)
  {
    I3OMResponse &h = *(I3OMResponse*)omresponse->At(i);
    if (h.GetOMNumber()==omnumber) 
      return(true);
  }
  return(false);
}
  
const I3OMResponse& I3OMResponseData::GetOMResponse(unsigned short index) const 
{
  if(GetNumberOMResponses()>index) return (*(I3OMResponse*)omresponse->At(index));
  I3DataExecution::Instance().Fatal("I3OMResponseData::GetOMResponse() asked for an index out of bounds");
  return(*(I3OMResponse*)NULL);
}

const I3OMResponse& I3OMResponseData::FindOMResponse(unsigned short omnumber) const 
{
  short i_max=GetNumberOMResponses();
  for(short i=0; i<i_max; i++)
  {
    I3OMResponse &h = *(I3OMResponse*)omresponse->At(i);
    if (h.GetOMNumber()==omnumber) 
      return(h);
  }
  I3DataExecution::Instance().Fatal("I3OMResponseData::FindOMResponse() was asked for a OMResponse which doesn't exist");
  return *(I3OMResponse*)0;
}
  
void I3OMResponseData::AddOMResponse(I3OMResponse* omresponse_) 
{
  if(omresponse==NULL) omresponse = new TObjArray(1); 
  omresponse->Add(omresponse_);
}

I3Iterator<const I3OMResponse>* I3OMResponseData::MakeOMResponseIterator()
{
  if(!omresponse)
    return new I3ZeroItemIterator<const I3OMResponse>();
  else
    return new I3TCollectionIterator<const I3OMResponse>(omresponse);
}
