#include "dataclasses/I3RecoTrack.h"

ClassImp(I3RecoTrack);

I3RecoTrack::I3RecoTrack()  {number_used_oms=0; used_om=NULL;}
I3RecoTrack::~I3RecoTrack() {delete [] used_om;}


Int_t        I3RecoTrack::GetNumberusedoms() const {return(number_used_oms);}
const Int_t* I3RecoTrack::GetUsedoms() const {return(used_om);}
void         I3RecoTrack::SetUsedoms(Int_t* used_om_, Int_t number_used_oms_) {used_om=used_om_; number_used_oms=number_used_oms_;}

