#include "dataclasses/I3OMResponseData.h"
#include "dataclasses/I3DataExecution.h"

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

bool I3OMResponseData::HasOMResponseNumber(unsigned short index) const
{
  if(FindOMResponsePtr(index))
    return true;
  return false;
}
  
const I3OMResponse& I3OMResponseData::GetOMResponse(unsigned short index) const 
{
  I3OMResponse* to_return = (I3OMResponse*)omresponse->At(index);
  if(to_return)
    return *to_return;
  I3DataExecution::Instance().Fatal("I3OMResponseData::GetOMResponse() asked for an index out of bounds");
  return *(I3OMResponse*)NULL;
}

const I3OMResponse& I3OMResponseData::FindOMResponse(unsigned short om_number) const
{
  const I3OMResponse* to_return = FindOMResponsePtr(om_number);
  if(to_return)
    return *to_return;
  I3DataExecution::Instance().Fatal("I3OMResponseData::FindOMResponse() was asked for a OMResponse which doesn't exist");
  return *(I3OMResponse*)0;
}

const I3OMResponse* I3OMResponseData::FindOMResponsePtr(unsigned short om_number) const 
{
  short i_max=GetNumberOMResponses();
  for(short i=0; i<i_max; i++)
  {
    I3OMResponse *h = (I3OMResponse*)omresponse->At(i);
    if (h->GetOMNumber()==om_number) 
      return(h);
  }
  return 0;
}
  
void I3OMResponseData::AddOMResponse(I3OMResponse* omresponse_) 
{
  if(omresponse==NULL) omresponse = new TObjArray(1); 
  omresponse->Add(omresponse_);
}

