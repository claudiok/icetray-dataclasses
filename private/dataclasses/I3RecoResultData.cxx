#include "dataclasses/I3RecoResultData.h"
#include "dataclasses/I3DataExecution.h"

#include "dataclasses/I3TCollectionIterator.h"
#include "dataclasses/I3ZeroItemIterator.h"

ClassImp(I3RecoResultData);

I3RecoResultData::I3RecoResultData()  {recoresult=NULL; }
I3RecoResultData::~I3RecoResultData() {if (recoresult)  {recoresult->Delete();  delete recoresult;}  }

int I3RecoResultData::GetNumberRecoResults() const
{
  return((recoresult==NULL) ? 0 : recoresult->GetEntriesFast());
}

const I3RecoResult& I3RecoResultData::GetRecoResult(unsigned short number) const
{
  if(GetNumberRecoResults()>number) return (*(I3RecoResult*)recoresult->At(number));
  I3DataExecution::Instance().Fatal("I3RecoResultData::GetRecoResult() asked for an index out of bounds");
  return(*(I3RecoResult*)NULL);
}

void I3RecoResultData::AddRecoResult(I3RecoResult* recoresult_)
{
  if(recoresult==NULL) recoresult = new TObjArray(1); recoresult->Add(recoresult_);
}

I3Iterator<const I3RecoResult>* I3RecoResultData::MakeRecoResultIterator()
{
  if(!recoresult)
    return new I3ZeroItemIterator<const I3RecoResult>();
  else
    return new I3TCollectionIterator<const I3RecoResult>(recoresult);
}
