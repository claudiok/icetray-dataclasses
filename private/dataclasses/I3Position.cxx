
// $Id: I3Position.cxx,v 1.3 2004/06/17 22:37:15 dule Exp $

#include <iostream>
#include "dataclasses/I3Position.h"
#include "dataclasses/I3Constants.h"

using namespace I3Constants;

ClassImp(I3Position) // Class implementation to enable ROOT I/O

//-----------------------------------------------------------
I3Position::I3Position()
{
// Creation of an I3Position object and initialization of parameters
  ResetPosition();
}

//-----------------------------------------------------------
I3Position::I3Position(Double_t x, Double_t y, Double_t z, RefFrame f)
{
// Creation of an I3Position object and initialization of parameters
  SetPosition(x,y,z,car);
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
  SetPosition(p.X(), p.Y(), p.Z(), car);
}

//-----------------------------------------------------------

//-----------------------------------------------------------
void I3Position::SetPosition(const I3Position& p)
{
// Set position
  SetPosition(p.X(), p.Y(), p.Z(), car);
}

//-----------------------------------------------------------
void I3Position::SetPosition(Double_t r1, Double_t r2, Double_t r3, RefFrame frame)
{
// Store position according to reference frame f

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
  fX=0;
  fY=0;
  fZ=0;
  fR=0;
  fTheta=0;
  fPhi=0;
  fRho=0;
  IsCalculated=kFALSE;
}

//-----------------------------------------------------------
void I3Position::NullPosition()
{
// Set null position for non-existing position
  SetPosition(NAN,NAN,NAN,car);
}

//-----------------------------------------------------------

//-----------------------------------------------------------
void I3Position::ShiftCoordSystem(const I3Position& p)
{
// Shift coordinate system by position p
// i.e. perform: this=this-p
  SetPosition(fX-p.X(), fY-p.Y(), fZ-p.Z(), car);
}

//-----------------------------------------------------------
void I3Position::RotateX(Double_t angle)
{
// Rotate around x-axis by angle
  Double_t s=sin(angle);
  Double_t c=cos(angle);
  Double_t y=fY;
  fY=c*y-s*fZ;
  fZ=s*y+c*fZ;
  CalcSphCylFromCar();
}

//-----------------------------------------------------------
void I3Position::RotateY(Double_t angle)
{
// Rotate around y-axis by angle
  Double_t s=sin(angle);
  Double_t c=cos(angle);
  Double_t z=fZ;
  fZ=c*z-s*fX;
  fX=s*z+c*fX;
  CalcSphCylFromCar();
}

//-----------------------------------------------------------
void I3Position::RotateZ(Double_t angle)
{
// Rotate around z-axis by angle
  Double_t s=sin(angle);
  Double_t c=cos(angle);
  Double_t x=fX;
  fX=c*x-s*fY;
  fY=s*x+c*fY;
  CalcSphCylFromCar();
}

//-----------------------------------------------------------
Double_t I3Position::CalcDistance(const I3Position& p) const
{
// Provide distance of the current I3Position to position p.
  I3Position d;
  d.SetPosition(*this);
  d.ShiftCoordSystem(p);
  return d.R();
}

//-----------------------------------------------------------
void I3Position::PrintPosition()
{
  cout <<"---------------------POSITION-INFO-----------------------"<<endl;
  cout <<"CAR coord (x,y,z): "<< X()<<" "<<Y()<<" "<<Z()<<endl;
  cout <<"SPH coord (r,theta,phi): "<< R()<<" "<<Theta()<<" "<<Phi()<<endl;
  cout <<"CYL coord (rho,phi,z): "<< Rho()<<" "<<Phi()<<" "<<Z()<<endl;
  cout <<"---------------------------------------------------------"<<endl;
}

//-----------------------------------------------------------

//-----------------------------------------------------------
void I3Position::CalcSphCylFromCar()
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
