#include "dataclasses/I3RecoTrackComposite.h"

ClassImp(I3RecoTrackComposite);

I3RecoTrackComposite::I3RecoTrackComposite()  {constituent=NULL;}
I3RecoTrackComposite::~I3RecoTrackComposite() {if(constituent) {constituent->Delete(); delete constituent;}}

unsigned short     I3RecoTrackComposite::GetNumberConstituents() const               {return((constituent==NULL) ? 0 : constituent->GetEntriesFast());}
const I3RecoTrack* I3RecoTrackComposite::GetConstituent(unsigned short number) const {return((GetNumberConstituents()<=number) ? NULL : (I3RecoTrack*)constituent->At(number));}
void               I3RecoTrackComposite::AddConstituent(I3RecoTrack* constituent_)   {if(constituent==NULL) constituent=new TObjArray(1); constituent->Add(constituent_);}

