
// $Id$


#include <iostream>
#include <dataclasses/BoostHeaders.h>
#include "dataclasses/I3Position.h"
#include "dataclasses/I3Constants.h"
#include "dataclasses/I3Units.h"

using namespace I3Constants;
using namespace I3Units;

//Serialize method
//-----------------------------------------------
template <class Archive> 
  void I3Position::serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("TObject", base_object<TObject>(*this));
    ar & make_nvp("X", x_);
    ar & make_nvp("Y", y_);
    ar & make_nvp("Z", z_);
  }

I3_SERIALIZABLE(I3Position);

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
  isCalculated_=false;

  switch (frame) {
  case car: // Input given in Cartesian coordinates
    x_=r1;
    y_=r2;
    z_=r3;
    //CalcSphCylFromCar();
    break;
      
  case sph: // Input given in Spherical coordinates
    r_=r1;
    theta_=r2;
    phi_=r3;
    CalcCarCylFromSph();
    break;

  case cyl: // Input given in Cylindrical coordinates
    rho_=r1;
    phi_=r2;
    z_=r3;
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
  x_=NAN;
  y_=NAN;
  z_=NAN;
  r_=NAN;
  theta_=NAN;
  phi_=NAN;
  rho_=NAN;
  isCalculated_=false;
}
//-----------------------------------------------------------

//-----------------------------------------------------------
void I3Position::ShiftCoordSystem(const I3Position& p)
{
// Shift coordinate system by position p
// i.e. perform: this=this-p
  SetPosition(x_-p.GetX(), y_-p.GetY(), z_-p.GetZ(), car);
}

//-----------------------------------------------------------
void I3Position::RotateX(double angle)
{
// Rotate around x-axis by angle
  double s=sin(angle);
  double c=cos(angle);
  double y=y_;
  y_=c*y-s*z_;
  z_=s*y+c*z_;
  isCalculated_ = false;
}

//-----------------------------------------------------------
void I3Position::RotateY(double angle)
{
// Rotate around y-axis by angle
  double s=sin(angle);
  double c=cos(angle);
  double z=z_;
  z_=c*z-s*x_;
  x_=s*z+c*x_;
  isCalculated_ = false;
}

//-----------------------------------------------------------
void I3Position::RotateZ(double angle)
{
// Rotate around z-axis by angle
  double s=sin(angle);
  double c=cos(angle);
  double x=x_;
  x_=c*x-s*y_;
  y_=s*x+c*y_;
  isCalculated_ = false;
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
  r_=sqrt(x_*x_+y_*y_+z_*z_);
  theta_=0;
  if (r_ && fabs(z_/r_)<=1.) {
    theta_=acos(z_/r_);
  } else {
    if (z_<0.) theta_=pi;
  }
  if (theta_<0.) theta_+=2.*pi;
  phi_=0;
  if (x_ || y_) phi_=atan2(y_,x_);
  if (phi_<0.) phi_+=2.*pi;
  rho_=r_*sin(theta_);
  isCalculated_=true;
}

//-----------------------------------------------------------
void I3Position::CalcCarCylFromSph()
{
  // Calculate Cartesian and Cylindrical coordinates from Spherical
  rho_=r_*sin(theta_);
  x_=rho_*cos(phi_);
  y_=rho_*sin(phi_);
  z_=r_*cos(theta_);
  isCalculated_=true;
}

//-----------------------------------------------------------
void I3Position::CalcCarSphFromCyl()
{
  // Calculate Cartesian and Spherical coordinates from Cylindrical
  r_=sqrt(rho_*rho_+z_*z_);
  if (phi_<0.) phi_+=2.*pi;
  theta_=0;
  if (r_ && fabs(z_/r_)<=1.) {
    theta_=acos(z_/r_);
  } else {
    if (z_<0.) theta_=pi;
  }
  if (theta_<0.) theta_+=2.*pi;
  x_=rho_*cos(phi_);
  y_=rho_*sin(phi_);
  isCalculated_=true;
}

//-----------------------------------------------------------
