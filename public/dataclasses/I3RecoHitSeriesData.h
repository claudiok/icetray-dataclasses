#ifndef I3RECOHITSERIESDATA_H
#define I3RECOHITSERIESDATA_H

#include <TObject.h>
#include <TObjArray.h>

#include "I3RecoHitSeries.h"
#include "dataclasses/I3Iterator.h"

class I3RecoHitSeriesData : public TObject
{
  TObjArray   *recohitseries;

  public:
   I3RecoHitSeriesData();
  ~I3RecoHitSeriesData();

  int GetNumberRecoHitSeries() const;
  const I3RecoHitSeries& GetRecoHitSeriesData(unsigned short number) const;
  void AddRecoHitSeries(I3RecoHitSeries* recohitseries_);
  I3Iterator<const I3RecoHitSeries>* MakeRecoHitSeriesIterator();

  ClassDef(I3RecoHitSeriesData,1);
};
#endif

