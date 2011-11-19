
// $Id$

#include <iostream>
#include <icetray/serialization.h>
#include <dataclasses/I3Direction.h>
#include <dataclasses/I3Constants.h>
#include <math.h>
#include <icetray/I3Units.h>


template <class Archive> 
void 
I3Direction::serialize(Archive& ar, unsigned version)
{
  if (version>i3direction_version_)
    log_fatal("Attempting to read version %u from file but running version %u of I3Direction class.",version,i3direction_version_);

  ar & make_nvp("I3FrameObject", base_object<I3FrameObject>(*this));
  ar & make_nvp("Zen", zenith_);
  ar & make_nvp("Azi", azimuth_);
}

I3_SERIALIZABLE(I3Direction);
I3_SERIALIZABLE(I3DirectionVect);

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
  if (theta>I3Constants::pi) theta = 2*I3Constants::pi-theta;
  zenith_ = I3Constants::pi-theta;
  azimuth_ = I3Constants::pi+phi;
  if (azimuth_>=2.*I3Constants::pi) azimuth_ -= 2*I3Constants::pi;
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
double I3Direction::CalcTheta() const
{
  double theta = I3Constants::pi - zenith_;
  return theta;
}

//-----------------------------------------------------------
double I3Direction::CalcPhi() const
{
  double phi = I3Constants::pi + azimuth_;
  if (phi >= 2*I3Constants::pi) phi -= 2*I3Constants::pi;
  return phi;
}

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
void I3Direction::CalcCarFromSph() const
{
  // Calculate Cartesian coordinates from Spherical
  // Direction is stored on disk in Spherical coordinates only.
  // theta=pi-zenith and phi=azimuth-pi in these IceCube coordinates.
  double theta = I3Constants::pi-zenith_;
  double phi = azimuth_-I3Constants::pi;
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
    if (zDir_<0.) theta=I3Constants::pi;
  }
  if (theta<0.) theta+=2.*I3Constants::pi;
  double phi=0;
  if (xDir_ || yDir_) phi=atan2(yDir_,xDir_);
  if (phi<0.) phi+=2.*I3Constants::pi;
  zenith_ = I3Constants::pi-theta;
  azimuth_ = phi+I3Constants::pi;
  if (zenith_>I3Constants::pi) zenith_ -= I3Constants::pi-(zenith_-I3Constants::pi);
  azimuth_ -= (int)(azimuth_/(2*I3Constants::pi))*(2*I3Constants::pi);
  isCalculated_=false;
}

//-----------------------------------------------------------


bool operator==(const I3Direction& lhs, const I3Direction& rhs){
  return ( lhs.GetZenith() == rhs.GetZenith() &&
	   lhs.GetAzimuth() == rhs.GetAzimuth()
	   );
}

//-----------------------------------------------------------

std::ostream& operator<<(std::ostream& oss, const I3Direction& d){
  oss << "I3Direction( Zenith (deg):" << d.GetZenith()/I3Units::degree << 
    " , Azimuth(deg)" <<d.GetAzimuth()/I3Units::degree << ")";
  return oss;
}
