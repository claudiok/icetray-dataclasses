#include "dataclasses/I3RecoHitSeriesData.h"

ClassImp(I3RecoHitSeriesData);

I3RecoHitSeriesData::I3RecoHitSeriesData()  {recohitseries=NULL;}
I3RecoHitSeriesData::~I3RecoHitSeriesData() {if (recohitseries)  {recohitseries->Delete();  delete recohitseries;} }

int                    I3RecoHitSeriesData::GetNumberRecoHitSeries() const                    {return((recohitseries==NULL) ? 0 : recohitseries->GetEntriesFast());}
const I3RecoHitSeries* I3RecoHitSeriesData::GetRecoHitSeriesData(unsigned short number) const {return((GetNumberRecoHitSeries()<=number) ? NULL : (I3RecoHitSeries*)recohitseries->At(number));}
void                   I3RecoHitSeriesData::AddRecoHitSeries(I3RecoHitSeries* recohitseries_) {if(recohitseries==NULL) recohitseries = new TObjArray(1); recohitseries->Add(recohitseries_);}


