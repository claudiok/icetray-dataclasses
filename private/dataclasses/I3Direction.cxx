
// $Id: I3Direction.cxx,v 1.2 2004/09/07 22:30:30 dule Exp $

#include <iostream>
#include "dataclasses/I3Direction.h"
#include "dataclasses/I3Constants.h"

using namespace I3Constants;

ClassImp(I3Direction) // Class implementation to enable ROOT I/O

//-----------------------------------------------------------
I3Direction::I3Direction()
{
// Creation of an I3Direction object and initialization of parameters
  ResetDirection();
}

//-----------------------------------------------------------
I3Direction::I3Direction(Double_t azi, Double_t zen)
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
  fX=0;
  fY=0;
  fZ=0;
  fZenith=0;
  fAzimuth=0;
  IsCalculated=kFALSE;
}

//-----------------------------------------------------------
void I3Direction::NullDirection()
{
// Set null direction for non-existing direction
  SetDirection(NAN,NAN);
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
    <<"SPH coord (zen,azi): "<< GetZenith()<<" "<<GetAzimuth()<<"\n"
    <<"CAR coord (x,y,z): "<< GetX()<<" "<<GetY()<<" "<<GetZ()<<"\n"
    <<"---------------------------------------------------------\n";
}

//-----------------------------------------------------------

//-----------------------------------------------------------
void I3Direction::CalcCarFromSph() const
{
  // Calculate Cartesian coordinates from Spherical
  // Direction is stored on disk in Spherical coordinates only
  Double_t rho = sin(-fZenith);
  fX = rho*cos(-fAzimuth);
  fY = rho*sin(-fAzimuth);
  fZ = cos(-fZenith);
  IsCalculated=kTRUE;
}

//-----------------------------------------------------------
void I3Direction::CalcSphFromCar()
{
  // Calculate Spherical coordinates from Cartesian
  // Direction is stored on disk in Spherical coordinates only
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
  fZenith = -theta;
  fAzimuth = -phi;
  IsCalculated=kTRUE;
}

//-----------------------------------------------------------
