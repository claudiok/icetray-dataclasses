#include "dataclasses/I3RecoResultSingleTrack.h"

ClassImp(I3RecoResultSingleTrack);

I3RecoResultSingleTrack::I3RecoResultSingleTrack() {;}

const I3RecoTrack& I3RecoResultSingleTrack::GetSingleRecoTrack(unsigned short tracklistindex) const 
{
  return( (GetNumberRecoTrackLists()<=tracklistindex) ? *(I3RecoTrack*)NULL : GetRecoTrackList(tracklistindex).GetRecoTrack(0) );
}

void I3RecoResultSingleTrack::AddSingleRecoTrack(I3RecoTrack* recotrack_) 
{
  AddRecoTrackList(new I3RecoTrackList); 
  int n=GetNumberRecoTrackLists(); 
  ((I3RecoTrackList&)GetRecoTrackList(n-1)).AddRecoTrack(recotrack_);  //const_cast
} 

