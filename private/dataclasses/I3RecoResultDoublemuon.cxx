#include "dataclasses/I3RecoResultDoublemuon.h"

ClassImp(I3RecoResultDoublemuon);

I3RecoResultDoublemuon::I3RecoResultDoublemuon() {qualityparameter=0;}

float I3RecoResultDoublemuon::GetQualityparameter() const                  {return qualityparameter;}
void  I3RecoResultDoublemuon::SetQualityparameter(float qualityparameter_) {qualityparameter=qualityparameter_;}

bool I3RecoResultDoublemuon::HasTwoTracks() const 
{
  if(!IsSingleTrackList()) return(false); 
  return( (GetSingleTrackList().GetNumberRecoTracks()==2) ? true : false);
}

const I3RecoTrack& I3RecoResultDoublemuon::GetFirstTrack() const
{
  return((HasTwoTracks()) ? GetSingleTrackList().GetRecoTrack(0) : *(I3RecoTrack*)NULL);
}
  
const I3RecoTrack& I3RecoResultDoublemuon::GetSecondTrack() const
{
  return((HasTwoTracks()) ? GetSingleTrackList().GetRecoTrack(1) : *(I3RecoTrack*)NULL);
}

bool I3RecoResultDoublemuon::SetTracks(I3RecoTrack* firsttrack, I3RecoTrack* secondtrack) 
{
  if(SetSingleTrackList(new I3RecoTrackList))
  {
    ((I3RecoTrackList&)GetSingleTrackList()).AddRecoTrack(firsttrack);    //const_cast
    ((I3RecoTrackList&)GetSingleTrackList()).AddRecoTrack(secondtrack);   //const_cast
    return(true);
  }
  return(false);
}
