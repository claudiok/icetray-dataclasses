#include "dataclasses/I3Track.h"
#include "dataclasses/I3DataExecution.h"

ClassImp(I3Track);

/**
 * taken straight from rdmc.h
 */
const I3Track::Type I3Track::Null = 0; 
const I3Track::Type I3Track::Unknown = -100;
const I3Track::Type I3Track::Gamma = 1;
const I3Track::Type I3Track::EPlus = 2;
const I3Track::Type I3Track::EMinus = 3;
const I3Track::Type I3Track::Nu = 4;
const I3Track::Type I3Track::MuPlus = 5;
const I3Track::Type I3Track::MuMinus = 6 ;
const I3Track::Type I3Track::Pi0 = 7; 
const I3Track::Type I3Track::PiPlus = 8;
const I3Track::Type I3Track::PiMinus = 9;
const I3Track::Type I3Track::PPlus = 14;
const I3Track::Type I3Track::PMinus = 15;
const I3Track::Type I3Track::TauPlus = 33;
const I3Track::Type I3Track::TauMinus = 34;
const I3Track::Type I3Track::NuE = 201;
const I3Track::Type I3Track::NuMu = 202;
const I3Track::Type I3Track::NuTau = 203;
const I3Track::Type I3Track::NuEBar = 204;
const I3Track::Type I3Track::NuMuBar = 205;
const I3Track::Type I3Track::NuTauBar = 206;
const I3Track::Type I3Track::Brems = 1001;
const I3Track::Type I3Track::DeltaE = 1002;
const I3Track::Type I3Track::PairProd = 1003;
const I3Track::Type I3Track::NuclInt = 1004;
const I3Track::Type I3Track::MuPair = 1005;
const I3Track::Type I3Track::Hadrons = 1006;
const I3Track::Type I3Track::FiberLaser = 2100;
const I3Track::Type I3Track::N2Laser = 2101; 
const I3Track::Type I3Track::YAGLaser = 2201;
const I3Track::Type I3Track::ZPrimary = 3000;
const I3Track::Type I3Track::APrimary = 3500; 
const I3Track::Type I3Track::Elph = 9999;


I3Track::I3Track()
{
  tracknumber=0;
  particleid=Null;
  starttime=0;
  startx=0;
  starty=0;
  startz=0;
  stoptime=0;
  stopx=0;
  stopy=0;
  stopz=0;
  length=0;
  zenith=0;
  azimuth=0;
  energy=0;
  parenttrack=NULL;
  childrentrack=NULL;
  TRef r=this;
}
  
I3Track::~I3Track() {if (childrentrack) {childrentrack->Delete(); delete childrentrack;}}
    
unsigned short I3Track::GetTrackNumber() const  {return(tracknumber);}
I3Track::Type  I3Track::GetParticleID() const   {return(particleid);}
float          I3Track::GetStartTime() const    {return(starttime);}
float          I3Track::GetStartX() const       {return(startx);}
float          I3Track::GetStartY() const       {return(starty);}
float          I3Track::GetStartZ() const       {return(startz);}
float          I3Track::GetStopTime() const     {return(stoptime);}
float          I3Track::GetStopX() const        {return(stopx);}
float          I3Track::GetStopY() const        {return(stopy);}
float          I3Track::GetStopZ() const        {return(stopz);}
float          I3Track::GetLength() const       {return(length);}
float          I3Track::GetZenith() const       {return(zenith);}
float          I3Track::GetAzimuth() const      {return(azimuth);}
float          I3Track::GetEnergy() const       {return(energy);}

void I3Track::SetTrackNumber(unsigned short tracknumber_)   {tracknumber=tracknumber_;}
void I3Track::SetParticleID(Type particleid_)               {particleid=particleid_;}
void I3Track::SetStartTime(float time)                      {starttime=time;}
void I3Track::SetStartX(float x)                            {startx=x;}
void I3Track::SetStartY(float y)                            {starty=y;}
void I3Track::SetStartZ(float z)                            {startz=z;}
void I3Track::SetStopTime(float time)                       {stoptime=time;}
void I3Track::SetStopX(float x)                             {stopx=x;}
void I3Track::SetStopY(float y)                             {stopy=y;}
void I3Track::SetStopZ(float z)                             {stopz=z;}
void I3Track::SetLength(float length_)                      {length=length_;}
void I3Track::SetZenith(float zenith_)                      {zenith=zenith_;}
void I3Track::SetAzimuth(float azimuth_)                    {azimuth=azimuth_;}
void I3Track::SetEnergy(float energy_)                      {energy=energy_;}
  
bool I3Track::HasParentTrack() const
{
  return((parenttrack.GetObject()==NULL) ? false : true);
}
const I3Track& I3Track::GetParentTrack() const
{
  if(HasParentTrack()) return (*(I3Track*)parenttrack.GetObject());
  I3DataExecution::Instance().Fatal("I3Track::GetParentTrack() asked for a parenttrack which doesn't exist");
  return(*(I3Track*)NULL);
}
void I3Track::SetParentTrack(I3Track& parenttrack_)
{
  if(!HasParentTrack()) parenttrack=&parenttrack_;
  else I3DataExecution::Instance().Fatal("I3Track::SetParentTrack() the parent track has already been set");
}

unsigned short I3Track::GetNumberChildrenTracks() const
{
  return((childrentrack==NULL) ? 0 : childrentrack->GetLast()+1);
}
const I3Track& I3Track::GetChildrenTrack(unsigned short number) const
{
  if(GetNumberChildrenTracks()>number) return (*(I3Track*)childrentrack->At(number));
  I3DataExecution::Instance().Fatal("I3Track::GetChildrenTracks() asked for an index out of bounds");
  return(*(I3Track*)NULL);
}
void I3Track::AddChildrenTrack(I3Track& childrentrack_)
{
  if(childrentrack==NULL) childrentrack=new TRefArray; childrentrack->Add(&childrentrack_);
}
