#ifndef I3OMRESPONSE_H
#define I3OMRESPONSE_H

#include <TObject.h>
#include <TObjArray.h>
#include <TRef.h>

#include "I3OMGeo.h"
#include "I3MCHitSeries.h"
#include "I3DatareadoutList.h"
#include "I3RecoHitSeriesData.h"

class I3OMResponse : public TObject
{
  unsigned short omnumber;
  TRef           geometry;

  I3MCHitSeries       *mchitseries;
  I3DatareadoutList   *datareadoutlist;
  I3RecoHitSeriesData *recohitseriesdata;

  public:
   I3OMResponse();
  ~I3OMResponse();

  unsigned short GetOMNumber() const;
  void           SetOMNumber(unsigned short omnumber_);

  bool           IsGeometry() const;
  const I3OMGeo* GetGeometry() const;
  void           SetGeometry(I3OMGeo* geometry_);

  bool  IsMCHitSeries() const;
  bool  IsDatareadoutlist() const;
  bool  IsRecoHitSeriesData() const;
  const I3MCHitSeries*       GetMCHitSeries() const;
  const I3DatareadoutList*   GetDatareadoutList() const;
  const I3RecoHitSeriesData* GetRecoHitSeriesData() const;
  void  SetMCHitSeries(I3MCHitSeries* mchitseries_);
  void  SetDatareadoutList(I3DatareadoutList* datareadoutlist_);
  void  SetRecoHitSeriesData(I3RecoHitSeriesData* recohitseriesdata_);

  ClassDef(I3OMResponse,1);
};
#endif

