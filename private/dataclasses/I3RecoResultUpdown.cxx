#include "dataclasses/I3RecoResultUpdown.h"
#include "dataclasses/I3DataExecution.h"

ClassImp(I3RecoResultUpdown);

I3RecoResultUpdown::I3RecoResultUpdown() {qualityparameter=0;}

float I3RecoResultUpdown::GetQualityparameter() const                  {return qualityparameter;}
void  I3RecoResultUpdown::SetQualityparameter(float qualityparameter_) {qualityparameter=qualityparameter_;}

bool I3RecoResultUpdown::HasUpdownTrackList() const 
{
  return( (GetNumberRecoTrackLists()==2) ? true : false);
}

const I3RecoTrackList& I3RecoResultUpdown::GetUpTrackList() const   
{
  if(HasUpdownTrackList()) return (*(I3RecoTrackList*)recotracklist->At(0));
  I3DataExecution::Instance().Fatal("I3RecoResultUpdown::GetUpTrackList() asked for a tracklist which doesn't exist");
  return(*(I3RecoTrackList*)NULL);
}

const I3RecoTrackList& I3RecoResultUpdown::GetDownTrackList() const 
{
  if(HasUpdownTrackList()) return (*(I3RecoTrackList*)recotracklist->At(1));
  I3DataExecution::Instance().Fatal("I3RecoResultUpdown::GetDwonTrackList() asked for a tracklist which doesn't exist");
  return(*(I3RecoTrackList*)NULL);
}

bool I3RecoResultUpdown::SetUpdownTrackList(I3RecoTrackList* uptracklist, I3RecoTrackList* downtracklist) 
{
  if(recotracklist)
  {
    I3DataExecution::Instance().Fatal("I3RecoResultUpdown::SetUpdownTrackList() the recotracklists have already been set");
    return(false);
  }
  recotracklist = new TObjArray(2);
  recotracklist->Add(uptracklist);
  recotracklist->Add(downtracklist);
  return(true);
}

