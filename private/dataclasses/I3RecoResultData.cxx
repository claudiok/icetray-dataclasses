#include "dataclasses/I3RecoResultData.h"

ClassImp(I3RecoResultData);

I3RecoResultData::I3RecoResultData()  {recoresult=NULL; }
I3RecoResultData::~I3RecoResultData() {if (recoresult)  {recoresult->Delete();  delete recoresult;}  }

int                 I3RecoResultData::GetNumberRecoResults() const               {return((recoresult==NULL) ? 0 : recoresult->GetEntriesFast());}
const I3RecoResult& I3RecoResultData::GetRecoResult(unsigned short number) const {return((GetNumberRecoResults()<=number) ? *(I3RecoResult*)NULL : *(I3RecoResult*)recoresult->At(number));}
void                I3RecoResultData::AddRecoResult(I3RecoResult* recoresult_)   {if(recoresult==NULL) recoresult = new TObjArray(1); recoresult->Add(recoresult_);}
