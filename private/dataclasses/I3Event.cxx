#include "dataclasses/I3Event.h"
#include "dataclasses/I3DataExecution.h"

ClassImp(I3Event);

I3Event::I3Event()
{
  runid=0;
  eventid=0;
  time=0;
  day=0;

  triggerdata=NULL;
  filterdata=NULL;
  mctrackdata=NULL;
  omresponsedata=NULL;
  recoresultdata=NULL;
}
I3Event::~I3Event()
{
  if (triggerdata)    {triggerdata->Delete();    delete triggerdata;}
  if (filterdata)     {filterdata->Delete();     delete filterdata;}
  if (mctrackdata)    {mctrackdata->Delete();    delete mctrackdata;}
  if (omresponsedata) {omresponsedata->Delete(); delete omresponsedata;}
  if (recoresultdata) {recoresultdata->Delete(); delete recoresultdata;}
}

unsigned long I3Event::GetRunID() const   {return(runid);}
unsigned long I3Event::GetEventID() const {return(eventid);}
double        I3Event::GetTime() const    {return(time);}
unsigned long I3Event::GetDay() const     {return(day);}
void I3Event::SetRunID(unsigned long runid_)     {runid=runid_;}
void I3Event::SetEventID(unsigned long eventid_) {eventid=eventid_;}
void I3Event::SetTime(double time_)              {time=time_;}
void I3Event::SetDay(unsigned long day_)         {day=day_;}

bool I3Event::IsTriggerData() const    {return((triggerdata) ? true : false);}
bool I3Event::IsFilterData() const     {return((filterdata) ? true : false);}
bool I3Event::IsMCTrackData() const    {return((mctrackdata) ? true : false);}
bool I3Event::IsOMResponseData() const {return((omresponsedata) ? true : false);}
bool I3Event::IsRecoResultData() const {return((recoresultdata) ? true : false);}
  
I3TriggerData&    I3Event::GetTriggerData() const    {return((triggerdata==NULL) ? *(I3TriggerData*)NULL : *triggerdata);}
I3FilterData&     I3Event::GetFilterData() const     {return((filterdata==NULL) ? *(I3FilterData*)NULL : *filterdata);}
I3MCTrackData&    I3Event::GetMCTrackData() const    {return((mctrackdata==NULL) ? *(I3MCTrackData*)NULL : *mctrackdata);}
I3OMResponseData& I3Event::GetOMResponseData() const {return((omresponsedata==NULL) ? *(I3OMResponseData*)NULL : *omresponsedata);}
I3RecoResultData& I3Event::GetRecoResultData() const {return((recoresultdata==NULL) ? *(I3RecoResultData*)NULL : *recoresultdata);}
  
void I3Event::SetTriggerData(I3TriggerData* triggerdata_)          
{
  if(!triggerdata)  triggerdata=triggerdata_;
  else I3DataExecution::Instance().Fatal("I3Event::SetTriggerData() triggerdata has already been set");
}

void I3Event::SetFilterData(I3FilterData* filterdata_)             
{
  if(!filterdata) filterdata=filterdata_;
  else I3DataExecution::Instance().Fatal("I3Event::SetFilterData() filterdata has already been set");
}

void I3Event::SetMCTrackData(I3MCTrackData* mctrackdata_)          
{
  if(!mctrackdata)  mctrackdata=mctrackdata_;   
  else I3DataExecution::Instance().Fatal("I3Event::SetMCTrackData() mctrackdata has already been set");
}
void I3Event::SetOMResponseData(I3OMResponseData* omresponsedata_) 
{
  if(!omresponsedata) omresponsedata=omresponsedata_; 
  else I3DataExecution::Instance().Fatal("I3Event::SetOMResponseData() omresponsedata has already been set");
}
void I3Event::SetRecoResultData(I3RecoResultData* recoresultdata_) 
{
  if(!recoresultdata) recoresultdata=recoresultdata_; 
  else I3DataExecution::Instance().Fatal("I3Event::SetRecoResultData() recoresultdata has already been set");
}
