#include "dataclasses/I3RecoTrackList.h"
#include "dataclasses/I3DataExecution.h"

ClassImp(I3RecoTrackList);

I3RecoTrackList::I3RecoTrackList()  {recotrack=NULL;}
I3RecoTrackList::~I3RecoTrackList() {if(recotrack)  {recotrack->Delete();  delete recotrack;} }

int I3RecoTrackList::GetNumberRecoTracks() const
{
  return((recotrack==NULL) ? 0 : recotrack->GetEntriesFast());
}
const I3RecoTrack& I3RecoTrackList::GetRecoTrack(unsigned short index) const
{
  if(GetNumberRecoTracks()>index) return (*(I3RecoTrack*)recotrack->At(index));
  I3DataExecution::Instance().Fatal("I3RecoTrackList::GetRecoTrack() asked for an index out of bounds");
  return(*(I3RecoTrack*)NULL);
}
void I3RecoTrackList::AddRecoTrack(I3RecoTrack* recotrack_)
{
  if(recotrack==NULL) recotrack = new TObjArray(1); recotrack->Add(recotrack_);
}

