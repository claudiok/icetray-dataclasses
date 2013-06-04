
// $Id$


#include <iostream>
#include <icetray/serialization.h>
#include "dataclasses/I3Position.h"
#include "dataclasses/I3Direction.h"
#include "dataclasses/I3Constants.h"
#include "icetray/I3Units.h"

using namespace I3Constants;
using namespace I3Units;

//Serialize method
//-----------------------------------------------
template <class Archive> 
void 
I3Position::serialize(Archive& ar, unsigned version)
{
  if (version>i3position_version_)
    log_fatal("Attempting to read version %u from file but running version %u of I3Position class.",version,i3position_version_);

  ar & make_nvp("I3FrameObject", base_object<I3FrameObject>(*this));
  ar & make_nvp("X", x_);
  ar & make_nvp("Y", y_);
  ar & make_nvp("Z", z_);
}

I3_SERIALIZABLE(I3Position);

//-----------------------------------------------------------
I3Position::I3Position(const I3Direction& d):
x_(d.GetX()),
y_(d.GetY()),
z_(d.GetY()),
r_(1),
theta_(d.CalcTheta()),
phi_(d.CalcPhi()),
rho_(sin(theta_)),
isCalculated_(true)
{}

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
    log_fatal("Unsupported reference frame passed to I3Position::SetPosition: %i",frame);
    break;
  }
}

//-----------------------------------------------------------
void I3Position::RotateX(double angle)
{
// Rotate around x-axis by angle
  const double s=std::sin(angle);
  const double c=std::cos(angle);
  const double y=y_;
  const double z=z_;
  y_=c*y-s*z;
  z_=s*y+c*z;
  isCalculated_ = false;
}

//-----------------------------------------------------------
void I3Position::RotateY(double angle)
{
// Rotate around y-axis by angle
  const double s=std::sin(angle);
  const double c=std::cos(angle);
  const double x=x_;
  const double z=z_;
  z_=c*z-s*x;
  x_=s*z+c*x;
  isCalculated_ = false;
}

//-----------------------------------------------------------
void I3Position::RotateZ(double angle)
{
// Rotate around z-axis by angle
  const double s=std::sin(angle);
  const double c=std::cos(angle);
  const double x=x_;
  const double y=y_;
  x_=c*x-s*y;
  y_=s*x+c*y;
  isCalculated_ = false;
}

//-----------------------------------------------------------
double I3Position::Magnitude() const{
  if(isCalculated_)
    return r_;
  //otherwise use self dot-product
  return sqrt(*this * *this);
}

//-----------------------------------------------------------
double I3Position::Mag2() const{
  if(isCalculated_)
    return r_*r_;
  //otherwise use self dot-product
  return *this * *this;
}

//-----------------------------------------------------------
I3Position& I3Position::operator+=(const I3Position& rhs){
  x_+=rhs.x_;
  y_+=rhs.y_;
  z_+=rhs.z_;
  isCalculated_=false;
  return *this;
}

//-----------------------------------------------------------
I3Position& I3Position::operator-=(const I3Position& rhs){
  x_-=rhs.x_;
  y_-=rhs.y_;
  z_-=rhs.z_;
  isCalculated_=false;
  return *this;
}

//-----------------------------------------------------------
I3Position I3Position::operator+(const I3Position& rhs) const{
  return I3Position(*this)+=rhs;
}

//-----------------------------------------------------------
I3Position I3Position::operator-(const I3Position& rhs) const{
  return I3Position(*this)-=rhs;
}

//-----------------------------------------------------------
double I3Position::operator*(const I3Position& rhs) const{
  return x_*rhs.x_ + y_*rhs.y_ + z_*rhs.z_;
}

//-----------------------------------------------------------
double I3Position::operator*(const I3Direction& rhs) const{
  return x_*rhs.GetX() + y_*rhs.GetY() + z_*rhs.GetZ();
}

//-----------------------------------------------------------
I3Position& I3Position::operator*=(double a){
  x_*=a;
  y_*=a;
  z_*=a;
  isCalculated_=false;
  return *this;
}

//-----------------------------------------------------------
I3Position& I3Position::operator/=(double a){
  x_/=a;
  y_/=a;
  z_/=a;
  isCalculated_=false;
  return *this;
}

//-----------------------------------------------------------
I3Position I3Position::operator*(double a) const{
  return I3Position(*this)*=a;
}

//-----------------------------------------------------------
I3Position I3Position::operator/(double a) const{
  return I3Position(*this)/=a;
}

//-----------------------------------------------------------
I3Position I3Position::Cross(const I3Position& d) const{
  return I3Position (y_*d.z_ - z_*d.y_,
                     z_*d.x_ - x_*d.z_,
                     x_*d.y_ - y_*d.x_);
}

//-----------------------------------------------------------
I3Position I3Position::Cross(const I3Direction& d) const{
  return I3Position (y_*d.GetZ() - z_*d.GetY(),
                     z_*d.GetX() - x_*d.GetZ(),
                     x_*d.GetY() - y_*d.GetX());
}

//-----------------------------------------------------------
void I3Position::CalcSphCylFromCar() const
{
  // Calculate Spherical and Cylindrical coordinates from Cartesian
  // Position is stored on disk in Cartesian coordinates only
  r_=std::sqrt(x_*x_+y_*y_+z_*z_);
  theta_=0;
  if ((r_!=0.) && std::abs(z_/r_)<=1.) {
    theta_=std::acos(z_/r_);
  } else {
    if (z_<0.) theta_=pi;
  }
  if (theta_<0.) theta_+=2.*pi;
  phi_=0;
  if ((x_!=0.f) || (y_!=0.f)) phi_=std::atan2(y_,x_);
  if (phi_<0.) phi_+=2.*pi;
  rho_=r_*std::sin(theta_);
  isCalculated_=true;
}

//-----------------------------------------------------------
void I3Position::CalcCarCylFromSph()
{
  // Calculate Cartesian and Cylindrical coordinates from Spherical
  rho_=r_*std::sin(theta_);
  x_=rho_*std::cos(phi_);
  y_=rho_*std::sin(phi_);
  z_=r_*std::cos(theta_);
  isCalculated_=true;
}

//-----------------------------------------------------------
void I3Position::CalcCarSphFromCyl()
{
  // Calculate Cartesian and Spherical coordinates from Cylindrical
  r_=std::sqrt(rho_*rho_+z_*z_);
  if (phi_<0.) phi_+=2.*pi;
  theta_=0;
  if ((r_!=0.) && std::abs(z_/r_)<=1.) {
    theta_=std::acos(z_/r_);
  } else {
    if (z_<0.) theta_=pi;
  }
  if (theta_<0.) theta_+=2.*pi;
  x_=rho_*std::cos(phi_);
  y_=rho_*std::sin(phi_);
  isCalculated_=true;
}

//-----------------------------------------------------------
I3Position operator*(double a, const I3Position& p){
  return(p*a);
}

//-----------------------------------------------------------
std::ostream& operator<<(std::ostream& oss, const I3Position& p){
  oss << "I3Position(" << p.GetX() << "," <<p.GetY() << "," << p.GetZ() << ")";
  return oss;
}
