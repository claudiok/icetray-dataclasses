#include "dataclasses/I3MCTrackList.h"

ClassImp(I3MCTrackList);

I3MCTrackList::I3MCTrackList()  {mctrack=NULL;  }
I3MCTrackList::~I3MCTrackList() {if(mctrack)  {mctrack->Delete();  delete mctrack;} }

int              I3MCTrackList::GetNumberMCTracks() const               {return((mctrack==NULL) ? 0 : mctrack->GetEntriesFast());}
const I3MCTrack& I3MCTrackList::GetMCTrack(unsigned short number) const {return((GetNumberMCTracks()<=number) ? *(I3MCTrack*)NULL : *(I3MCTrack*)mctrack->At(number));}
void             I3MCTrackList::AddMCTrack(I3MCTrack* mctrack_)         {if(mctrack==NULL) mctrack = new TObjArray(1); mctrack->Add(mctrack_);}
