#include "dataclasses/I3MCTrackData.h"

ClassImp(I3MCTrackData);

I3MCTrackData::I3MCTrackData()  {mctracklist=NULL;}
I3MCTrackData::~I3MCTrackData() {if (mctracklist)  {mctracklist->Delete();  delete mctracklist;} }

int                  I3MCTrackData::GetNumberMCTrackLists() const               {return((mctracklist==NULL) ? 0 : mctracklist->GetEntriesFast());}
const I3MCTrackList& I3MCTrackData::GetMCTrackList(unsigned short number) const {return((GetNumberMCTrackLists()<=number) ? *(I3MCTrackList*)NULL : *(I3MCTrackList*)mctracklist->At(number));}
void                 I3MCTrackData::AddMCTrackList(I3MCTrackList& mctracklist_) {if(mctracklist==NULL) mctracklist = new TObjArray(1); mctracklist->Add(&mctracklist_);}
