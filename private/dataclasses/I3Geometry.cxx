#include "dataclasses/I3Geometry.h"
#include "dataclasses/I3DataExecution.h"

ClassImp(I3Geometry);

I3Geometry::I3Geometry()  {time=0; date=0; omgeo=NULL;}
I3Geometry::~I3Geometry() {if(omgeo) {omgeo->Delete(); delete omgeo;}}

double I3Geometry::GetTime() const {return time;}
long   I3Geometry::GetDate() const {return date;}
void I3Geometry::SetTime(double time_) {time=time_;}
void I3Geometry::SetDate(long date_)   {date=date_;}

int I3Geometry::GetNumberOMGeos() const                  
{
  return((omgeo==NULL) ? 0 : omgeo->GetEntriesFast());
}

const I3OMGeo& I3Geometry::GetOMGeo(unsigned short index) const
{
  if(!omgeo)
    I3DataExecution::Instance().Fatal("I3Geometry::GetOMGeo() Nobody's added any OMGeos to this object");
  I3OMGeo* to_return = (I3OMGeo*)omgeo->At(index);
  if(to_return)
    return *to_return;
  I3DataExecution::Instance().Fatal("I3Geometry::GetOMGeo asked for an OMGeo out of range.  Check first");
  return *(I3OMGeo*)0;
}

bool I3Geometry::HasOMGeoNumber(unsigned short omnumber) const
{
  if(0==FindOMGeoPtr(omnumber))
    return false;
  return true;
}

const I3OMGeo& I3Geometry::FindOMGeo(unsigned short omnumber) const
{
  const I3OMGeo* to_return = FindOMGeoPtr(omnumber);
  if(to_return)
    return *to_return;
  I3DataExecution::Instance().Fatal("I3Geometry::FindOMGeo asked for a non-existent OM");
  return *(I3OMGeo*)0;
}

const I3OMGeo* I3Geometry::FindOMGeoPtr(unsigned short omnumber) const 
{ 
  short i_max=GetNumberOMGeos();
  for(short i=0; i<i_max; i++)
  {
    I3OMGeo *h = (I3OMGeo*)omgeo->At(i);
    if (h->GetOMNumber()==omnumber) return(h);
  }
  return(NULL);
}

void I3Geometry::AddOMGeo(I3OMGeo* omgeo_)
{
  if(omgeo==NULL) omgeo = new TObjArray(1); omgeo->Add(omgeo_);
}
 
