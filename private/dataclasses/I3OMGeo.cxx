#include "dataclasses/I3OMGeo.h"
#include <TRef.h>

ClassImp(I3OMGeo);

I3OMGeo::I3OMGeo()
{
  omnumber=0;
  x=0;
  y=0;
  z=0;
  orientation=0;
  version=0;
  TRef r=this;
}

unsigned short I3OMGeo::GetOMNumber() const                   {return(omnumber);}
void           I3OMGeo::SetOMNumber(unsigned short omnumber_) {omnumber=omnumber_;}

double        I3OMGeo::GetX() const           {return(x);}
double        I3OMGeo::GetY() const           {return(y);}
double        I3OMGeo::GetZ() const           {return(z);}
bool          I3OMGeo::GetOrientation() const {return(orientation);}
unsigned char I3OMGeo::GetVersion() const     {return(version);}

void I3OMGeo::SetX(double x_)                    {x=x_;}
void I3OMGeo::SetY(double y_)                    {y=y_;}
void I3OMGeo::SetZ(double z_)                    {z=z_;}
void I3OMGeo::SetOrientation(bool orientation_)  {orientation=orientation_;}
void I3OMGeo::SetVersion(unsigned char version_) {version=version_;}

