#ifndef I3OMRESPONSE_H
#define I3OMRESPONSE_H

#include <TObject.h>
#include <TObjArray.h>
#include <TRef.h>

#include "I3OMGeo.h"
#include "I3MCHitSeries.h"
#include "I3DataReadoutList.h"
#include "I3RecoHitSeriesData.h"

class I3OMResponse : public TObject
{
  unsigned short omnumber;
  TRef           geometry;

  // with the following, you either put in the two pipes or get
  // "cant instantiate precompiled template
  // even though you can branch an I3MCHitSeries, or whatever.
  // let us all hate root together for a moment
  I3MCHitSeries       mchitseries; //||
  I3DataReadoutList   datareadoutlist; //||
  I3RecoHitSeriesData recohitseriesdata; //||

  public:
  I3OMResponse() { omnumber = 0; geometry = 0;}
  virtual ~I3OMResponse() {;}

  unsigned short OMNumber() const { return omnumber; }
  void           OMNumber(unsigned short omnumber_) { omnumber = omnumber_; }

// bool HasGeometry(){} const;
// const I3OMGeo& GetGeometry() const;
// void SetGeometry(I3OMGeo& geometry_);

  const I3MCHitSeries& GetMCHitSeries() const { return mchitseries; }
  I3MCHitSeries& GetMCHitSeries() { return mchitseries; }

  // const I3DataReadoutList& GetDataReadoutList() const { return datareadoutlist; }
  // I3DataReadoutList& GetDataReadoutList() { return datareadoutlist; }

  // const I3RecoHitSeriesData& GetRecoHitSeriesData() const { return recohitseriesdata; }
  // I3RecoHitSeriesData& GetRecoHitSeriesData() { return recohitseriesdata; }

  ClassDef(I3OMResponse,1);
};
#endif

