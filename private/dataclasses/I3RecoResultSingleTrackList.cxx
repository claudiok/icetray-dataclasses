#include "dataclasses/I3RecoResultSingleTrackList.h"
#include "dataclasses/I3DataExecution.h"

ClassImp(I3RecoResultSingleTrackList);

I3RecoResultSingleTrackList::I3RecoResultSingleTrackList() {;}

bool I3RecoResultSingleTrackList::HasSingleTrackList() const 
{
  return( (GetNumberRecoTrackLists()==1) ? true : false);
}

const I3RecoTrackList& I3RecoResultSingleTrackList::GetSingleTrackList() const 
{
  if(HasSingleTrackList()) return (*(I3RecoTrackList*)recotracklist->At(0));
  I3DataExecution::Instance().Fatal("I3RecoResultSingleTrackList::GetSingleTrackList() asked for a tracklist which doesn't exist");
  return(*(I3RecoTrackList*)NULL);
}

bool I3RecoResultSingleTrackList::SetSingleTrackList(I3RecoTrackList* recotracklist_) 
{
  if(recotracklist)
  {
    I3DataExecution::Instance().Fatal("I3RecoResultSingleTrackList::SetSingleTrackList() the recotracklist has already been set");
    return(false);
  }
  recotracklist = new TObjArray(1); 
  recotracklist->Add(recotracklist_);
  return(true);
}

