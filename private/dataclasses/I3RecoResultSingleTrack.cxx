#include "dataclasses/I3RecoResultSingleTrack.h"
#include "dataclasses/I3DataExecution.h"

ClassImp(I3RecoResultSingleTrack);

I3RecoResultSingleTrack::I3RecoResultSingleTrack() {;}

const I3RecoTrack& I3RecoResultSingleTrack::GetSingleRecoTrack(unsigned short tracklistindex) const 
{
  if(GetNumberRecoTrackLists()>tracklistindex) return (GetRecoTrackList(tracklistindex).GetRecoTrack(0));
  I3DataExecution::Instance().Fatal("I3RecoResultSingleTrack::GetSingleRecoTrack() asked for an index out of bounds or a track which doesn't exist");
  return(*(I3RecoTrack*)NULL);
}

void I3RecoResultSingleTrack::AddSingleRecoTrack(I3RecoTrack* recotrack_) 
{
  AddRecoTrackList(new I3RecoTrackList); 
  int n=GetNumberRecoTrackLists(); 
  ((I3RecoTrackList&)GetRecoTrackList(n-1)).AddRecoTrack(recotrack_);  //const_cast
} 

