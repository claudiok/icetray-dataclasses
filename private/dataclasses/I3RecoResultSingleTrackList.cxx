#include "dataclasses/I3RecoResultSingleTrackList.h"

ClassImp(I3RecoResultSingleTrackList);

I3RecoResultSingleTrackList::I3RecoResultSingleTrackList() {;}

bool I3RecoResultSingleTrackList::IsSingleTrackList() const 
{
  return( (GetNumberRecoTrackLists()==1) ? true : false);
}

const I3RecoTrackList& I3RecoResultSingleTrackList::GetSingleTrackList() const 
{
  return((IsSingleTrackList()) ? *(I3RecoTrackList*)recotracklist->At(0) : *(I3RecoTrackList*)NULL);
}

bool I3RecoResultSingleTrackList::SetSingleTrackList(I3RecoTrackList& recotracklist_) 
{
  if(recotracklist)
  {
    printf("recotracklist exists already\n");
    return(false);
  }
  recotracklist = new TObjArray(1); 
  recotracklist->Add(&recotracklist_);
  return(true);
}

