#include "dataclasses/I3RecoHitSeriesData.h"
#include "dataclasses/I3DataExecution.h"

#include "dataclasses/I3ZeroItemIterator.h"
#include "dataclasses/I3TCollectionIterator.h"

ClassImp(I3RecoHitSeriesData);

I3RecoHitSeriesData::I3RecoHitSeriesData()  {recohitseries=NULL;}
I3RecoHitSeriesData::~I3RecoHitSeriesData() {if (recohitseries)  {recohitseries->Delete();  delete recohitseries;} }

I3RecoHitSeriesData::I3RecoHitSeriesData(const I3RecoHitSeriesData& h)
{
  recohitseries=NULL;
  int n=h.GetNumberRecoHitSeries();
  if(n>0)
  {
    recohitseries=new TObjArray(n);
    for(int i=0; i<n; i++) recohitseries->Add(new I3RecoHitSeries(h.GetRecoHitSeries(i)));
  }
}

I3RecoHitSeriesData& I3RecoHitSeriesData::operator=(const I3RecoHitSeriesData& h)
{
  if(this==&h) return(*this);
  if(recohitseries) {recohitseries->Delete(); delete recohitseries;}
  recohitseries=NULL;
  int n=h.GetNumberRecoHitSeries();
  if(n>0)
  {
    recohitseries=new TObjArray(n);
    for(int i=0; i<n; i++) recohitseries->Add(new I3RecoHitSeries(h.GetRecoHitSeries(i)));
  }
  return(*this);
}

int I3RecoHitSeriesData::GetNumberRecoHitSeries() const                    
{
  return((recohitseries==NULL) ? 0 : recohitseries->GetEntriesFast());
}
const I3RecoHitSeries& I3RecoHitSeriesData::GetRecoHitSeries(unsigned short number) const 
{
  if(GetNumberRecoHitSeries()>number) return (*(I3RecoHitSeries*)recohitseries->At(number));
  I3DataExecution::Instance().Fatal("I3RecoHitSeriesData::GetRecoHitSeriesData() asked for an index out of bounds");
  return(*(I3RecoHitSeries*)NULL);
}
void I3RecoHitSeriesData::AddRecoHitSeries(I3RecoHitSeries* recohitseries_) 
{
  if(recohitseries==NULL) recohitseries = new TObjArray(1); recohitseries->Add(recohitseries_);
}

I3Iterator<const I3RecoHitSeries>* I3RecoHitSeriesData::MakeRecoHitSeriesIterator() const
{
  if(!recohitseries)
    return new I3ZeroItemIterator<const I3RecoHitSeries>();
  else
    return new I3TCollectionIterator<const I3RecoHitSeries>(recohitseries);
}

