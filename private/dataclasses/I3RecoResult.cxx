#include "dataclasses/I3RecoResult.h"

ClassImp(I3RecoResult);

I3RecoResult::I3RecoResult()  {recotracklist=NULL; bestrecotracklist=NULL;}
I3RecoResult::~I3RecoResult() {if(recotracklist) {recotracklist->Delete(); delete recotracklist;} }

const char* I3RecoResult::GetRecomethod() const  {return(GetName());}

int                    I3RecoResult::GetNumberRecoTrackLists() const                   {return((recotracklist==NULL) ? 0 : recotracklist->GetEntriesFast());}
const I3RecoTrackList& I3RecoResult::GetRecoTrackList(unsigned short index) const      {return((GetNumberRecoTrackLists()<=index) ? *(I3RecoTrackList*)NULL : *(I3RecoTrackList*)recotracklist->At(index));}
void                   I3RecoResult::AddRecoTrackList(I3RecoTrackList* recotracklist_) {if(recotracklist==NULL) recotracklist = new TObjArray(1); recotracklist->Add(recotracklist_);}

bool                   I3RecoResult::IsBestRecoTrackList() const                               {return((bestrecotracklist==NULL) ? false : true);}
const I3RecoTrackList& I3RecoResult::GetBestRecoTrackList() const                              {return((bestrecotracklist==NULL) ? *(I3RecoTrackList*)NULL : *(I3RecoTrackList*)bestrecotracklist.GetObject());}
void                   I3RecoResult::SetBestRecoTrackList(I3RecoTrackList* bestrecotracklist_) {bestrecotracklist=bestrecotracklist_;}
