#include "dataclasses/I3OMResponse.h"

ClassImp(I3OMResponse);

I3OMResponse::I3OMResponse()
{
  omnumber=0;
  geometry=NULL;
  mchitseries=NULL;
  datareadoutlist=NULL;
  recohitseriesdata=NULL;
}

I3OMResponse::~I3OMResponse()
{
  if (mchitseries)       {mchitseries->Delete();       delete mchitseries;}
  if (datareadoutlist)   {datareadoutlist->Delete();   delete datareadoutlist;}
  if (recohitseriesdata) {recohitseriesdata->Delete(); delete recohitseriesdata;}
}

unsigned short I3OMResponse::GetOMNumber() const         {return(omnumber);}
void           I3OMResponse::SetOMNumber(unsigned short omnumber_) {omnumber=omnumber_;}

bool           I3OMResponse::IsGeometry() const              {return((geometry==NULL) ? false : true);}
const I3OMGeo* I3OMResponse::GetGeometry() const             {return((geometry==NULL) ? NULL : (I3OMGeo*)geometry.GetObject());}
void           I3OMResponse::SetGeometry(I3OMGeo* geometry_) {geometry=geometry_;}

bool  I3OMResponse::IsMCHitSeries() const       {return((mchitseries==NULL) ? false : true);}
bool  I3OMResponse::IsDatareadoutlist() const   {return((datareadoutlist==NULL) ? false : true);}
bool  I3OMResponse::IsRecoHitSeriesData() const {return((recohitseriesdata==NULL) ? false : true);}
const I3MCHitSeries*       I3OMResponse::GetMCHitSeries() const       {return((mchitseries==NULL) ? NULL : mchitseries);}
const I3DatareadoutList*   I3OMResponse::GetDatareadoutList() const   {return((datareadoutlist==NULL) ? NULL : datareadoutlist);}
const I3RecoHitSeriesData* I3OMResponse::GetRecoHitSeriesData() const {return((recohitseriesdata==NULL) ? NULL : recohitseriesdata);}
void  I3OMResponse::SetMCHitSeries(I3MCHitSeries* mchitseries_)                   {if(!mchitseries)       mchitseries=mchitseries_;             else printf("MCHitSeries exists already\n");}
void  I3OMResponse::SetDatareadoutList(I3DatareadoutList* datareadoutlist_)       {if(!datareadoutlist)   datareadoutlist=datareadoutlist_;     else printf("Datareadoutlist exists already\n");}
void  I3OMResponse::SetRecoHitSeriesData(I3RecoHitSeriesData* recohitseriesdata_) {if(!recohitseriesdata) recohitseriesdata=recohitseriesdata_; else printf("RecoHitSeriesData exists already\n");}


