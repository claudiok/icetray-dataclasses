#include "dataclasses/I3OMResponseData.h"

ClassImp(I3OMResponseData);

I3OMResponseData::I3OMResponseData()  {omresponse=NULL;}
I3OMResponseData::~I3OMResponseData() {if (omresponse) {omresponse->Delete(); delete omresponse;} }


int I3OMResponseData::GetNumberOMResponses() const
{
  return((omresponse==NULL) ? 0 : omresponse->GetEntriesFast());
}
  
const I3OMResponse* I3OMResponseData::GetOMResponse(unsigned short index) const 
{
  return((GetNumberOMResponses()<=index) ? NULL : (I3OMResponse*)omresponse->At(index));
}

const I3OMResponse* I3OMResponseData::FindOMResponse(unsigned short om_number) const 
{
  short i_max=GetNumberOMResponses();
  for(short i=0; i<i_max; i++)
  {
    I3OMResponse *h = (I3OMResponse*)omresponse->At(i);
    if (h->GetOMNumber()==om_number) return(h);
  }
  return(NULL);
}
  
void I3OMResponseData::AddOMResponse(I3OMResponse* omresponse_) 
{
  if(omresponse==NULL) omresponse = new TObjArray(1); omresponse->Add(omresponse_);
}
