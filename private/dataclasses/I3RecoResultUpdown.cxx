#include "dataclasses/I3RecoResultUpdown.h"

ClassImp(I3RecoResultUpdown);

I3RecoResultUpdown::I3RecoResultUpdown() {qualityparameter=0;}

float I3RecoResultUpdown::GetQualityparameter() const                  {return qualityparameter;}
void  I3RecoResultUpdown::SetQualityparameter(float qualityparameter_) {qualityparameter=qualityparameter_;}

bool I3RecoResultUpdown::IsUpdownTrackList() const 
{
  return( (GetNumberRecoTrackLists()==2) ? true : false);
}

const I3RecoTrackList& I3RecoResultUpdown::GetUpTrackList() const   
{
  return((IsUpdownTrackList()) ? *(I3RecoTrackList*)recotracklist->At(0) : *(I3RecoTrackList*)NULL);
}

const I3RecoTrackList& I3RecoResultUpdown::GetDownTrackList() const 
{
  return((IsUpdownTrackList()) ? *(I3RecoTrackList*)recotracklist->At(1) : *(I3RecoTrackList*)NULL);
}

bool I3RecoResultUpdown::SetUpdownTrackList(I3RecoTrackList& uptracklist, I3RecoTrackList& downtracklist) 
{
  if(recotracklist)
  {
    printf("recotracklist exists already\n");
    return(false);
  }
  recotracklist = new TObjArray(2);
  recotracklist->Add(&uptracklist);
  recotracklist->Add(&downtracklist);
  return(true);
}

