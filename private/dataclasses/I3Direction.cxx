
// $Id: I3Direction.cxx,v 1.8.2.1 2005/02/04 21:51:03 troy Exp $

#include <iostream>
#include "dataclasses/I3Direction.h"
#include "dataclasses/I3Constants.h"
#include "dataclasses/I3Units.h"

using namespace I3Constants;
using namespace I3Units;

//ClassImp(I3Direction) // Class implementation to enable ROOT I/O

//-----------------------------------------------------------
I3Direction::I3Direction()
{
// Creation of an I3Direction object and initialization of parameters
  ResetDirection();
}

//-----------------------------------------------------------
I3Direction::I3Direction(Double_t zen, Double_t azi)
{
// Creation of an I3Direction object and initialization of parameters
  SetDirection(zen,azi);
}

//-----------------------------------------------------------
I3Direction::I3Direction(Double_t x, Double_t y, Double_t z)
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
void I3Direction::SetDirection(Double_t zen, Double_t azi)
{
// Store direction in zen, azi
  fZenith = zen;
  fAzimuth = azi;
  CalcCarFromSph();
}      

//-----------------------------------------------------------
void I3Direction::SetDirection(Double_t x, Double_t y, Double_t z)
{
// Store direction in x, y, z
  fX=x;
  fY=y;
  fZ=z;
  CalcSphFromCar();
}      

//-----------------------------------------------------------
void I3Direction::ResetDirection()
{
// Set or Reset the direction to 0.
  fX=NAN;
  fY=NAN;
  fZ=NAN;
  fZenith=NAN;
  fAzimuth=NAN;
  IsCalculated=kTRUE;
}

//-----------------------------------------------------------

//-----------------------------------------------------------
void I3Direction::RotateX(Double_t angle)
{
// Rotate around x-axis by angle
  if (!IsCalculated) CalcCarFromSph();
  Double_t s=sin(angle);
  Double_t c=cos(angle);
  Double_t y=fY;
  fY=c*y-s*fZ;
  fZ=s*y+c*fZ;
  CalcSphFromCar();
}

//-----------------------------------------------------------
void I3Direction::RotateY(Double_t angle)
{
// Rotate around y-axis by angle
  if (!IsCalculated) CalcCarFromSph();
  Double_t s=sin(angle);
  Double_t c=cos(angle);
  Double_t z=fZ;
  fZ=c*z-s*fX;
  fX=s*z+c*fX;
  CalcSphFromCar();
}

//-----------------------------------------------------------
void I3Direction::RotateZ(Double_t angle)
{
// Rotate around z-axis by angle
  if (!IsCalculated) CalcCarFromSph();
  Double_t s=sin(angle);
  Double_t c=cos(angle);
  Double_t x=fX;
  fX=c*x-s*fY;
  fY=s*x+c*fY;
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
  Double_t theta = pi-fZenith;
  Double_t phi = fAzimuth-pi;
  Double_t rho = sin(theta);
  fX = rho*cos(phi);
  fY = rho*sin(phi);
  fZ = cos(theta);
  IsCalculated=kTRUE;
}

//-----------------------------------------------------------
void I3Direction::CalcSphFromCar()
{
  // Calculate Spherical coordinates from Cartesian
  // Direction is stored on disk in Spherical coordinates only
  // zenith=pi-theta and azimuth=phi+pi in these IceCube coordinates.
  Double_t fR = sqrt(fX*fX+fY*fY+fZ*fZ);
  Double_t theta = 0;
  if (fR && fabs(fZ/fR)<=1.) {
    theta=acos(fZ/fR);
  } else {
    if (fZ<0.) theta=pi;
  }
  if (theta<0.) theta+=2.*pi;
  Double_t phi=0;
  if (fX || fY) phi=atan2(fY,fX);
  if (phi<0.) phi+=2.*pi;
  fZenith = pi-theta;
  fAzimuth = phi+pi;
  IsCalculated=kTRUE;
}

//-----------------------------------------------------------
