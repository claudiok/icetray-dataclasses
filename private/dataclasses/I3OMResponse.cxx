#include "dataclasses/I3OMResponse.h"

#include "dataclasses/I3DataExecution.h"

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

unsigned short I3OMResponse::GetOMNumber() const         
{
  return(omnumber);
}

void I3OMResponse::SetOMNumber(unsigned short omnumber_) 
{
  omnumber=omnumber_;
}

bool I3OMResponse::HasGeometry() const
{
  return((geometry==NULL) ? false : true);
}

const I3OMGeo& I3OMResponse::GetGeometry() const
{
  I3OMGeo* to_return = (I3OMGeo*)geometry.GetObject();
  if(to_return)
    return *to_return;
  I3DataExecution::Instance().Fatal("I3OMResponse::GetGeometry() the OMGeo doesn't exits");
  return *(I3OMGeo*)0;
}

void I3OMResponse::SetGeometry(I3OMGeo& geometry_) 
{

  if(!geometry.GetObject())
    geometry=&geometry_;
  else
    I3DataExecution::Instance().Fatal("I3OMResponse::SetGeometry() the OMResponse has already been set.  You're trying to make me leak my memory");
}

bool  I3OMResponse::HasMCHitSeries() const
{
  return((mchitseries==NULL) ? false : true);
}

bool  I3OMResponse::HasDatareadoutlist() const   
{
  return((datareadoutlist==NULL) ? false : true);
}

bool  I3OMResponse::HasRecoHitSeriesData() const 
{
  return((recohitseriesdata==NULL) ? false : true);
}

const I3MCHitSeries& I3OMResponse::GetMCHitSeries() const       
{
  if(mchitseries)
    return *mchitseries;
  I3DataExecution::Instance().Fatal("I3OMResponse::GetMCHitSeries() I3MCHitSeries doesn't exist.  Check first.");
  return *(I3MCHitSeries*)0;
}

const I3DatareadoutList& I3OMResponse::GetDatareadoutList() const   
{
  if(datareadoutlist)
    return *datareadoutlist;
  I3DataExecution::Instance().Fatal("I3OMResponse::GetDatareadoutlist() the data readoutd doesn't exist.  Check first.");
  return *(I3DatareadoutList*)0;
}

const I3RecoHitSeriesData& I3OMResponse::GetRecoHitSeriesData() const {
  if(recohitseriesdata)
    return *recohitseriesdata;
  I3DataExecution::Instance().Fatal("I3OMResponse::GetRecoHitSeriesData() there is no reco hit series data");
  return *(I3RecoHitSeriesData*)0;
}

void  I3OMResponse::SetMCHitSeries(I3MCHitSeries* mchitseries_)
{
  if(!mchitseries)       
    mchitseries=mchitseries_;             
  else printf("MCHitSeries exists already\n");
}

void  I3OMResponse::SetDatareadoutList(I3DatareadoutList* datareadoutlist_)
{
  if(!datareadoutlist)
    datareadoutlist=datareadoutlist_;     
  else printf("Datareadoutlist exists already\n");
}

void  I3OMResponse::SetRecoHitSeriesData(I3RecoHitSeriesData* recohitseriesdata_) {
  if(!recohitseriesdata) 
    recohitseriesdata=recohitseriesdata_; 
  else 
    printf("RecoHitSeriesData exists already\n");
}


