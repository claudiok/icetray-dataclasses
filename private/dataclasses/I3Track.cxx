#include "dataclasses/I3Track.h"

ClassImp(I3Track);

I3Track::I3Track()
{
  tracknumber=0;
  particletype=0;
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
}
  
I3Track::~I3Track() {if (childrentrack) {childrentrack->Delete(); delete childrentrack;}}
    
unsigned short I3Track::GetTracknumber() const  {return(tracknumber);}
unsigned short I3Track::GetParticletype() const {return(particletype);}
float          I3Track::GetStarttime() const    {return(starttime);}
float          I3Track::GetStartx() const       {return(startx);}
float          I3Track::GetStarty() const       {return(starty);}
float          I3Track::GetStartz() const       {return(startz);}
float          I3Track::GetStoptime() const     {return(stoptime);}
float          I3Track::GetStopx() const        {return(stopx);}
float          I3Track::GetStopy() const        {return(stopy);}
float          I3Track::GetStopz() const        {return(stopz);}
float          I3Track::GetLength() const       {return(length);}
float          I3Track::GetZenith() const       {return(zenith);}
float          I3Track::GetAzimuth() const      {return(azimuth);}
float          I3Track::GetEnergy() const       {return(energy);}

void I3Track::SetTracknumber(unsigned short tracknumber_)   {tracknumber=tracknumber_;}
void I3Track::SetParticletype(unsigned short particletype_) {particletype=particletype_;}
void I3Track::SetStarttime(float time)                      {starttime=time;}
void I3Track::SetStartx(float x)                            {startx=x;}
void I3Track::SetStarty(float y)                            {starty=y;}
void I3Track::SetStartz(float z)                            {startz=z;}
void I3Track::SetStoptime(float time)                       {stoptime=time;}
void I3Track::SetStopx(float x)                             {stopx=x;}
void I3Track::SetStopy(float y)                             {stopy=y;}
void I3Track::SetStopz(float z)                             {stopz=z;}
void I3Track::SetLength(float length_)                      {length=length_;}
void I3Track::SetZenith(float zenith_)                      {zenith=zenith_;}
void I3Track::SetAzimuth(float azimuth_)                    {azimuth=azimuth_;}
void I3Track::SetEnergy(float energy_)                      {energy=energy_;}
  
bool           I3Track::IsParenttrack() const                 {return((parenttrack==NULL) ? false : true);}
const I3Track& I3Track::GetParenttrack() const                {return((parenttrack==NULL) ? *(I3Track*)NULL : *(I3Track*)parenttrack.GetObject());}
void           I3Track::SetParenttrack(I3Track& parenttrack_) {parenttrack=&parenttrack_;}

unsigned short I3Track::GetNumberChildrentracks() const               {return((childrentrack==NULL) ? 0 : childrentrack->GetLast()+1);}
const I3Track& I3Track::GetChildrentrack(unsigned short number) const {return((GetNumberChildrentracks()<=number) ? *(I3Track*)NULL : *(I3Track*)childrentrack->At(number));}
void           I3Track::AddChildrentrack(I3Track& childrentrack_)     {if(childrentrack==NULL) childrentrack=new TRefArray; childrentrack->Add(&childrentrack_);}
