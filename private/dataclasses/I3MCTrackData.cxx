#include "dataclasses/I3MCTrackData.h"
#include "dataclasses/I3DataExecution.h"
#include "dataclasses/I3TCollectionIterator.h"
#include "dataclasses/I3ZeroItemIterator.h"

ClassImp(I3MCTrackData);

I3MCTrackData::I3MCTrackData()  {mctracklist=NULL;}
I3MCTrackData::~I3MCTrackData() {if (mctracklist)  {mctracklist->Delete();  delete mctracklist;} }

int I3MCTrackData::GetNumberMCTrackLists() const
{
  return((mctracklist==NULL) ? 0 : mctracklist->GetEntriesFast());
}

const I3MCTrackList& I3MCTrackData::GetMCTrackList(unsigned short number) const
{
  if(GetNumberMCTrackLists()>number) return (*(I3MCTrackList*)mctracklist->At(number));
  I3DataExecution::Instance().Fatal("I3MCTrackData::GetMCTrackList() asked for an index out of bounds");
  return(*(I3MCTrackList*)NULL);
}

void I3MCTrackData::AddMCTrackList(I3MCTrackList* mctracklist_) 
{
  if(mctracklist==NULL) mctracklist = new TObjArray(1); mctracklist->Add(mctracklist_);
}

I3Iterator<const I3MCTrackList>* I3MCTrackData::MakeTrackListIterator()
{
  if(!mctracklist)
    return new I3ZeroItemIterator<const I3MCTrackList>();
  else
    return new I3TCollectionIterator<const I3MCTrackList>(mctracklist);

}
