#include "dataclasses/I3MCTrackList.h"
#include "dataclasses/I3DataExecution.h"
#include "dataclasses/I3TCollectionIterator.h"
#include "dataclasses/I3ZeroItemIterator.h"

ClassImp(I3MCTrackList);

I3MCTrackList::I3MCTrackList()  {mctrack=NULL;  }
I3MCTrackList::~I3MCTrackList() {if(mctrack)  {mctrack->Delete();  delete mctrack;} }

int I3MCTrackList::GetNumberMCTracks() const
{
  return((mctrack==NULL) ? 0 : mctrack->GetEntriesFast());
}

const I3MCTrack& I3MCTrackList::GetMCTrack(unsigned short number) const 
{
  if(GetNumberMCTracks()>number) return (*(I3MCTrack*)mctrack->At(number));
  I3DataExecution::Instance().Fatal("I3MCTrackList::GetMCTrack() asked for an index out of bounds");
  return(*(I3MCTrack*)NULL);
}

void I3MCTrackList::AddMCTrack(I3MCTrack* mctrack_)
{
  if(mctrack==NULL) mctrack = new TObjArray(1); mctrack->Add(mctrack_);
}

I3Iterator<const I3MCTrack>* I3MCTrackList::MakeMCTrackIterator() const
{
  if(!mctrack)
    return new I3ZeroItemIterator<const I3MCTrack>();
  else
    return new I3TCollectionIterator<const I3MCTrack>(mctrack);
}
