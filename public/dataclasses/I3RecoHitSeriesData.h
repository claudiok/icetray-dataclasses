#ifndef I3RECOHITSERIESDATA_H
#define I3RECOHITSERIESDATA_H

#include <TObject.h>
#include <TObjArray.h>

#include "I3RecoHitSeries.h"

class I3RecoHitSeriesData : public TObject
{
  TObjArray   *recohitseries;

  public:
   I3RecoHitSeriesData();
  ~I3RecoHitSeriesData();

  int                    GetNumberRecoHitSeries() const;
  const I3RecoHitSeries* GetRecoHitSeriesData(unsigned short number) const;
  void                   AddRecoHitSeries(I3RecoHitSeries* recohitseries_);

  ClassDef(I3RecoHitSeriesData,1);
};
#endif

