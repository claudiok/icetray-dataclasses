#include "dataclasses/I3RecoResult.h"
#include "dataclasses/I3DataExecution.h"

ClassImp(I3RecoResult);

I3RecoResult::I3RecoResult()  {recotracklist=NULL; bestrecotracklist=NULL;}
I3RecoResult::~I3RecoResult() {if(recotracklist) {recotracklist->Delete(); delete recotracklist;} }

const char* I3RecoResult::GetRecomethod() const  {return(GetName());}

int I3RecoResult::GetNumberRecoTrackLists() const
{
  return((recotracklist==NULL) ? 0 : recotracklist->GetEntriesFast());
}

const I3RecoTrackList& I3RecoResult::GetRecoTrackList(unsigned short index) const
{
  if(GetNumberRecoTrackLists()>index) return (*(I3RecoTrackList*)recotracklist->At(index));
  I3DataExecution::Instance().Fatal("I3RecoResult::GetRecoTrackList() asked for an index out of bounds");
  return(*(I3RecoTrackList*)NULL);
}

void I3RecoResult::AddRecoTrackList(I3RecoTrackList* recotracklist_) 
{
  if(recotracklist==NULL) recotracklist = new TObjArray(1); recotracklist->Add(recotracklist_);
}

bool I3RecoResult::HasBestRecoTrackList() const
{
  return((bestrecotracklist==NULL) ? false : true);
}

const I3RecoTrackList& I3RecoResult::GetBestRecoTrackList() const
{
  if(HasBestRecoTrackList()) return (*(I3RecoTrackList*)bestrecotracklist.GetObject());
  I3DataExecution::Instance().Fatal("I3RecoResult::GetBestRecoTrackList() asked for a best recotracklist which doesn't exist");
  return(*(I3RecoTrackList*)NULL);
}

void I3RecoResult::SetBestRecoTrackList(I3RecoTrackList& bestrecotracklist_)
{
  bestrecotracklist=&bestrecotracklist_;
}
