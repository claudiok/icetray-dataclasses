#include "dataclasses/I3RecoTrackComposite.h"
#include "dataclasses/I3DataExecution.h"

ClassImp(I3RecoTrackComposite);

I3RecoTrackComposite::I3RecoTrackComposite()  {constituent=NULL;}
I3RecoTrackComposite::~I3RecoTrackComposite() {if(constituent) {constituent->Delete(); delete constituent;}}

UShort_t I3RecoTrackComposite::GetNumberConstituents() const
{
  return((constituent==NULL) ? 0 : constituent->GetEntriesFast());
}
const I3RecoTrack& I3RecoTrackComposite::GetConstituent(UShort_t number) const
{
  if(GetNumberConstituents()>number) return (*(I3RecoTrack*)constituent->At(number));
  I3DataExecution::Instance().Fatal("I3RecoTrackComposite::GetConstituent() asked for an index out of bounds");
  return(*(I3RecoTrack*)NULL);
}
void I3RecoTrackComposite::AddConstituent(I3RecoTrack* constituent_)
{
  if(constituent==NULL) constituent=new TObjArray(1); constituent->Add(constituent_);
}

