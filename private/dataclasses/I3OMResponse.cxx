#include "dataclasses/I3OMResponse.h"

#include "dataclasses/I3DataExecution.h"

#include "dataclasses/I3TCollectionIterator.h"

#include "dataclasses/I3ZeroItemIterator.h"

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
  if (mchitseries)       {delete mchitseries;}
  if (datareadoutlist)   {delete datareadoutlist;}
  if (recohitseriesdata) {delete recohitseriesdata;}
}

unsigned short I3OMResponse::GetOMNumber() const         {return(omnumber);}
void I3OMResponse::SetOMNumber(unsigned short omnumber_) {omnumber=omnumber_;}

bool I3OMResponse::HasGeometry() const
{
  return((geometry.GetObject()==NULL) ? false : true);
}

const I3OMGeo& I3OMResponse::GetGeometry() const
{
  if(HasGeometry()) return(*(I3OMGeo*)geometry.GetObject());
  I3DataExecution::Instance().Fatal("I3OMResponse::GetGeometry() the OMGeo doesn't exist");
  return *(I3OMGeo*)NULL;
}

void I3OMResponse::SetGeometry(I3OMGeo& geometry_) 
{
  if(!HasGeometry()) geometry=&geometry_;
  else I3DataExecution::Instance().Fatal("I3OMResponse::SetGeometry() the OMResponse has already been set.  You're trying to make me leak my memory");
}

bool  I3OMResponse::HasMCHitSeries() const
{
  return((mchitseries==NULL) ? false : true);
}

bool  I3OMResponse::HasDatareadoutList() const   
{
  return((datareadoutlist==NULL) ? false : true);
}

bool  I3OMResponse::HasRecoHitSeriesData() const 
{
  return((recohitseriesdata==NULL) ? false : true);
}

const I3MCHitSeries& I3OMResponse::GetMCHitSeries() const       
{
  if(mchitseries) return *mchitseries;
  I3DataExecution::Instance().Fatal("I3OMResponse::GetMCHitSeries() I3MCHitSeries doesn't exist.  Check first.");
  return *(I3MCHitSeries*)NULL;
}

const I3DatareadoutList& I3OMResponse::GetDatareadoutList() const   
{
  if(datareadoutlist) return *datareadoutlist;
  I3DataExecution::Instance().Fatal("I3OMResponse::GetDatareadoutlist() the data readoutd doesn't exist.  Check first.");
  return *(I3DatareadoutList*)NULL;
}

const I3RecoHitSeriesData& I3OMResponse::GetRecoHitSeriesData() const 
{
  if(recohitseriesdata) return *recohitseriesdata;
  I3DataExecution::Instance().Fatal("I3OMResponse::GetRecoHitSeriesData() there is no reco hit series data");
  return *(I3RecoHitSeriesData*)NULL;
}

void  I3OMResponse::SetMCHitSeries(I3MCHitSeries* mchitseries_)
{
  if(!mchitseries) mchitseries=mchitseries_;             
  else I3DataExecution::Instance().Fatal("I3OMResponse::SetMCHitSeries() MCHitSeries exists already");
}

void  I3OMResponse::SetDatareadoutList(I3DatareadoutList* datareadoutlist_)
{
  if(!datareadoutlist) datareadoutlist=datareadoutlist_;     
  else I3DataExecution::Instance().Fatal("I3OMResponse::SetDataREadoutList() Datareadoutlist exists already");
}

void  I3OMResponse::SetRecoHitSeriesData(I3RecoHitSeriesData* recohitseriesdata_) {
  if(!recohitseriesdata) recohitseriesdata=recohitseriesdata_; 
  else I3DataExecution::Instance().Fatal("I3OMResponse::SetRecoHitSeriesData() RecoHitSeriesData exists already");
}




