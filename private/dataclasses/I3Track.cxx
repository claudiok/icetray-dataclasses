#include "dataclasses/I3Track.h"
#include "dataclasses/I3DataExecution.h"

ClassImp(I3Track);

I3Track::I3Track()
{
  fTrackNumber=0;
  fParticleId=Null;
  fStartTime=0;
  fStartX=0;
  fStartY=0;
  fStartZ=0;
  fStopTime=0;
  fStopX=0;
  fStopY=0;
  fStopZ=0;
  fLength=0;
  fZenith=0;
  fAzimuth=0;
  fEnergy=0;
  parenttrack=NULL;
  childrentrack=NULL;
}
  
I3Track::~I3Track() {if (childrentrack) {childrentrack->Delete(); delete childrentrack;}}
    
bool 
I3Track::HasParentTrack() const
{
  return((parenttrack.GetObject()==NULL) ? false : true);
}

const 
I3Track& I3Track::GetParentTrack() const
{
  if(HasParentTrack()) return (*(I3Track*)parenttrack.GetObject());
  I3DataExecution::Instance().Fatal("I3Track::GetParentTrack() asked for a parenttrack which doesn't exist");
  return(*(I3Track*)NULL);
}

void 
I3Track::SetParentTrack(I3Track& parenttrack_)
{
  if(!HasParentTrack()) parenttrack=&parenttrack_;
  else I3DataExecution::Instance().Fatal("I3Track::SetParentTrack() the parent track has already been set");
}

unsigned short 
I3Track::GetNumberChildrenTracks() const
{
  return((childrentrack==NULL) ? 0 : childrentrack->GetLast()+1);
}

const 
I3Track& I3Track::GetChildrenTrack(unsigned short number) const
{
  if(GetNumberChildrenTracks()>number) return (*(I3Track*)childrentrack->At(number));
  I3DataExecution::Instance().Fatal("I3Track::GetChildrenTracks() asked for an index out of bounds");
  return(*(I3Track*)NULL);
}

void 
I3Track::AddChildrenTrack(I3Track& childrentrack_)
{
  if(childrentrack==NULL) childrentrack=new TRefArray; childrentrack->Add(&childrentrack_);
}
