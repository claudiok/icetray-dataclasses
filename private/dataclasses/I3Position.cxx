
// $Id: I3Position.cxx,v 1.14 2005/04/04 15:49:24 pretz Exp $

#include <iostream>
#include "dataclasses/I3Position.h"
#include "dataclasses/I3Constants.h"
#include "dataclasses/I3Units.h"

using namespace I3Constants;
using namespace I3Units;

ClassImp(I3Position) // Class implementation to enable ROOT I/O

//-----------------------------------------------------------
I3Position::I3Position()
{
// Creation of an I3Position object and initialization of parameters
  ResetPosition();
}

//-----------------------------------------------------------
I3Position::I3Position(double x, double y, double z, RefFrame f)
{
// Creation of an I3Position object and initialization of parameters
  SetPosition(x,y,z,f);
}

//-----------------------------------------------------------
I3Position::~I3Position()
{
// Destructor to delete dynamically allocated memory
}

//-----------------------------------------------------------
I3Position::I3Position(const I3Position& p)
{
// Copy constructor
  SetPosition(p.GetX(), p.GetY(), p.GetZ(), car);
}

//-----------------------------------------------------------

//-----------------------------------------------------------
void I3Position::SetPosition(const I3Position& p)
{
// Set position
  SetPosition(p.GetX(), p.GetY(), p.GetZ(), car);
}

//-----------------------------------------------------------
void I3Position::SetPosition(double r1, double r2, double r3, RefFrame frame)
{
// Store position according to reference frame f
  IsCalculated=kFALSE;

  switch (frame) {
  case car: // Input given in Cartesian coordinates
    fX=r1;
    fY=r2;
    fZ=r3;
    //CalcSphCylFromCar();
    break;
      
  case sph: // Input given in Spherical coordinates
    fR=r1;
    fTheta=r2;
    fPhi=r3;
    CalcCarCylFromSph();
    break;

  case cyl: // Input given in Cylindrical coordinates
    fRho=r1;
    fPhi=r2;
    fZ=r3;
    CalcCarSphFromCyl();
    break;
    
  default: // Unsupported reference frame
    ResetPosition();
    break;
  }
}

//-----------------------------------------------------------
void I3Position::ResetPosition()
{
// Set or Reset the position to 0.
  fX=NAN;
  fY=NAN;
  fZ=NAN;
  fR=NAN;
  fTheta=NAN;
  fPhi=NAN;
  fRho=NAN;
  IsCalculated=kTRUE;
}
//-----------------------------------------------------------

//-----------------------------------------------------------
void I3Position::ShiftCoordSystem(const I3Position& p)
{
// Shift coordinate system by position p
// i.e. perform: this=this-p
  SetPosition(fX-p.GetX(), fY-p.GetY(), fZ-p.GetZ(), car);
}

//-----------------------------------------------------------
void I3Position::RotateX(double angle)
{
// Rotate around x-axis by angle
  double s=sin(angle);
  double c=cos(angle);
  double y=fY;
  fY=c*y-s*fZ;
  fZ=s*y+c*fZ;
  CalcSphCylFromCar();
}

//-----------------------------------------------------------
void I3Position::RotateY(double angle)
{
// Rotate around y-axis by angle
  double s=sin(angle);
  double c=cos(angle);
  double z=fZ;
  fZ=c*z-s*fX;
  fX=s*z+c*fX;
  CalcSphCylFromCar();
}

//-----------------------------------------------------------
void I3Position::RotateZ(double angle)
{
// Rotate around z-axis by angle
  double s=sin(angle);
  double c=cos(angle);
  double x=fX;
  fX=c*x-s*fY;
  fY=s*x+c*fY;
  CalcSphCylFromCar();
}

//-----------------------------------------------------------
double I3Position::CalcDistance(const I3Position& p) const
{
// Provide distance of the current I3Position to position p.
  I3Position d;
  d.SetPosition(*this);
  d.ShiftCoordSystem(p);
  return d.GetR();
}

//-----------------------------------------------------------
void I3Position::ToStream(ostream& o) const
{
  o <<"---------------------POSITION-INFO-----------------------\n"
    <<"CAR coord(x,y,z): "<< GetX()<<" "<<GetY()<<" "<<GetZ()<<"\n"
    <<"SPH coord(r,theta,phi): "<< GetR()<<" "<<GetTheta()/deg<<"deg "
    <<GetPhi()/deg<<"deg\n"
    <<"CYL coord(rho,phi,z): "<< GetRho()<<" "<<GetPhi()/deg<<"deg "
    <<GetZ()<<"\n"
    <<"---------------------------------------------------------\n";
}

//-----------------------------------------------------------

//-----------------------------------------------------------
void I3Position::CalcSphCylFromCar() const
{
  // Calculate Spherical and Cylindrical coordinates from Cartesian
  // Position is stored on disk in Cartesian coordinates only
  fR=sqrt(fX*fX+fY*fY+fZ*fZ);
  fTheta=0;
  if (fR && fabs(fZ/fR)<=1.) {
    fTheta=acos(fZ/fR);
  } else {
    if (fZ<0.) fTheta=pi;
  }
  if (fTheta<0.) fTheta+=2.*pi;
  fPhi=0;
  if (fX || fY) fPhi=atan2(fY,fX);
  if (fPhi<0.) fPhi+=2.*pi;
  fRho=fR*sin(fTheta);
  IsCalculated=kTRUE;
}

//-----------------------------------------------------------
void I3Position::CalcCarCylFromSph()
{
  // Calculate Cartesian and Cylindrical coordinates from Spherical
  fRho=fR*sin(fTheta);
  fX=fRho*cos(fPhi);
  fY=fRho*sin(fPhi);
  fZ=fR*cos(fTheta);
  IsCalculated=kTRUE;
}

//-----------------------------------------------------------
void I3Position::CalcCarSphFromCyl()
{
  // Calculate Cartesian and Spherical coordinates from Cylindrical
  fR=sqrt(fRho*fRho+fZ*fZ);
  if (fPhi<0.) fPhi+=2.*pi;
  fTheta=0;
  if (fR && fabs(fZ/fR)<=1.) {
    fTheta=acos(fZ/fR);
  } else {
    if (fZ<0.) fTheta=pi;
  }
  if (fTheta<0.) fTheta+=2.*pi;
  fX=fRho*cos(fPhi);
  fY=fRho*sin(fPhi);
  IsCalculated=kTRUE;
}

//-----------------------------------------------------------
