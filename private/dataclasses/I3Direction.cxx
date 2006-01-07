
// $Id$

#include <iostream>
#include <dataclasses/BoostHeaders.h>
#include "dataclasses/I3Direction.h"
#include "dataclasses/I3Constants.h"
#include "dataclasses/I3Units.h"

using namespace I3Constants;
using namespace I3Units;

template <class Archive> 
void 
I3Direction::serialize (Archive& ar, unsigned version)
{
  ar & make_nvp("Zen", zenith_);
  ar & make_nvp("Azi", azimuth_);
}

I3_SERIALIZABLE(I3Direction);

//-----------------------------------------------------------
I3Direction::I3Direction()
{
// Creation of an I3Direction object and initialization of parameters
  ResetDirection();
}

//-----------------------------------------------------------
I3Direction::I3Direction(double zen, double azi)
{
// Creation of an I3Direction object and initialization of parameters
  SetDirection(zen,azi);
}

//-----------------------------------------------------------
I3Direction::I3Direction(double x, double y, double z)
{
// Creation of an I3Direction object and initialization of parameters
  SetDirection(x,y,z);
}

//-----------------------------------------------------------
I3Direction::I3Direction(const I3Direction& d)
{
// Copy constructor
  SetDirection(d.GetZenith(), d.GetAzimuth());
}

//-----------------------------------------------------------
I3Direction::~I3Direction()
{
// Destructor to delete dynamically allocated memory
}

//-----------------------------------------------------------

//-----------------------------------------------------------
void I3Direction::SetDirection(const I3Direction& d)
{
// Set direction
  SetDirection(d.GetZenith(), d.GetAzimuth());
}

//-----------------------------------------------------------
void I3Direction::SetDirection(double zen, double azi)
{
// Store direction in zen, azi
  zenith_ = zen;
  azimuth_ = azi;
  CalcCarFromSph();
}      

//-----------------------------------------------------------
void I3Direction::SetDirection(double x, double y, double z)
{
// Store direction in x, y, z
  xDir_=x;
  yDir_=y;
  zDir_=z;
  CalcSphFromCar();
}
    
//-----------------------------------------------------------
void I3Direction::SetThetaPhi(double theta, double phi)
{
  if (theta>pi) theta = 2*pi-theta;
  zenith_ = pi-theta;
  azimuth_ = pi+phi;
  if (azimuth_>=2.*pi) azimuth_ -= 2*pi;
  CalcCarFromSph();
}

//-----------------------------------------------------------
void I3Direction::ResetDirection()
{
// Set or Reset the direction to 0.
  xDir_=NAN;
  yDir_=NAN;
  zDir_=NAN;
  zenith_=NAN;
  azimuth_=NAN;
  isCalculated_=false;
}

//-----------------------------------------------------------

//-----------------------------------------------------------
void I3Direction::RotateX(double angle)
{
// Rotate around x-axis by angle
  if (!isCalculated_) CalcCarFromSph();
  double s=sin(angle);
  double c=cos(angle);
  double y=yDir_;
  yDir_=c*y-s*zDir_;
  zDir_=s*y+c*zDir_;
  CalcSphFromCar();
}

//-----------------------------------------------------------
void I3Direction::RotateY(double angle)
{
// Rotate around y-axis by angle
  if (!isCalculated_) CalcCarFromSph();
  double s=sin(angle);
  double c=cos(angle);
  double z=zDir_;
  zDir_=c*z-s*xDir_;
  xDir_=s*z+c*xDir_;
  CalcSphFromCar();
}

//-----------------------------------------------------------
void I3Direction::RotateZ(double angle)
{
// Rotate around z-axis by angle
  if (!isCalculated_) CalcCarFromSph();
  double s=sin(angle);
  double c=cos(angle);
  double x=xDir_;
  xDir_=c*x-s*yDir_;
  yDir_=s*x+c*yDir_;
  CalcSphFromCar();
}

//-----------------------------------------------------------
void I3Direction::ToStream(ostream& o) const
{
  o <<"---------------------DIRECTION-INFO-----------------------\n"
    <<"SPH coord (zen,azi): "<< GetZenith()/deg<<"deg "
    <<GetAzimuth()/deg<<"deg\n"
    <<"CAR coord (x,y,z): "<< GetX()<<" "<<GetY()<<" "<<GetZ()<<"\n"
    <<"----------------------------------------------------------\n";
}

//-----------------------------------------------------------

//-----------------------------------------------------------
void I3Direction::CalcCarFromSph() const
{
  // Calculate Cartesian coordinates from Spherical
  // Direction is stored on disk in Spherical coordinates only.
  // theta=pi-zenith and phi=azimuth-pi in these IceCube coordinates.
  double theta = pi-zenith_;
  double phi = azimuth_-pi;
  double rho = sin(theta);
  xDir_ = rho*cos(phi);
  yDir_ = rho*sin(phi);
  zDir_ = cos(theta);
  isCalculated_=true;
}

//-----------------------------------------------------------
void I3Direction::CalcSphFromCar()
{
  // Calculate Spherical coordinates from Cartesian
  // Direction is stored on disk in Spherical coordinates only
  // zenith=pi-theta and azimuth=phi+pi in these IceCube coordinates.
  double r = sqrt(xDir_*xDir_+yDir_*yDir_+zDir_*zDir_);
  double theta = 0;
  if (r && fabs(zDir_/r)<=1.) {
    theta=acos(zDir_/r);
  } else {
    if (zDir_<0.) theta=pi;
  }
  if (theta<0.) theta+=2.*pi;
  double phi=0;
  if (xDir_ || yDir_) phi=atan2(yDir_,xDir_);
  if (phi<0.) phi+=2.*pi;
  zenith_ = pi-theta;
  azimuth_ = phi+pi;
  if (zenith_>pi) zenith_ -= pi-(zenith_-pi);
  azimuth_ -= (int)(azimuth_/(2*pi))*(2*pi);
  isCalculated_=true;
}

//-----------------------------------------------------------
