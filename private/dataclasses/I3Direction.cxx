
// $Id$

#include <iostream>
#include <icetray/serialization.h>
#include <dataclasses/I3Direction.h>
#include <dataclasses/I3Position.h>
#include <cmath>
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

// save XML
template <> 
void 
I3Direction::serialize(boost::archive::xml_oarchive& ar, unsigned version)
{
  if (version!=i3direction_version_)
    log_fatal("Cannot load XML data for I3Direction from an archive with version %u. Only the current version (%u) is supported.",version,i3direction_version_);

  ar & make_nvp("I3FrameObject", base_object<I3FrameObject>(*this));
  ar & make_nvp("zen", zenith_);
  ar & make_nvp("azi", azimuth_);

  double zenDeg = zenith_/I3Units::deg;
  double aziDeg = azimuth_/I3Units::deg;
  ar & make_nvp("zenDeg", zenDeg);
  ar & make_nvp("aziDeg", aziDeg);

  double dx = GetX();
  double dy = GetY();
  double dz = GetZ();
  ar & make_nvp("dx", dx);
  ar & make_nvp("dy", dy);
  ar & make_nvp("dz", dz);

}

// load XML
template <> 
void 
I3Direction::serialize(boost::archive::xml_iarchive& ar, unsigned version)
{
  if (version!=i3direction_version_) 
    log_fatal("Cannot load XML data for I3Direction from an archive with version %u. Only the current version (%u) is supported.",version,i3direction_version_);

  ar & make_nvp("I3FrameObject", base_object<I3FrameObject>(*this));
  ar & make_nvp("zen", zenith_);
  ar & make_nvp("azi", azimuth_);

  // ignore all those fields when reading from XML
  double dummy;
  ar & make_nvp("zenDeg", dummy);
  ar & make_nvp("aziDeg", dummy);

  ar & make_nvp("dx", dummy);
  ar & make_nvp("dy", dummy);
  ar & make_nvp("dz", dummy);
}

I3_SERIALIZABLE(I3Direction);
I3_SERIALIZABLE(I3DirectionVect);

//-----------------------------------------------------------
I3Direction::I3Direction(const I3Position& p):
xDir_(p.GetX()),
yDir_(p.GetY()),
zDir_(p.GetZ())
{
  CalcSphFromCar();
}

//-----------------------------------------------------------
void I3Direction::SetDirection(const I3Direction& d)
{
  *this=d;
}

//-----------------------------------------------------------
void I3Direction::SetDir(const I3Direction& d)
{
  *this=d;
}

//-----------------------------------------------------------
void I3Direction::SetDirection(double zen, double azi)
{
  zenith_=zen;
  azimuth_=azi;
  isCalculated_=false;
}

//-----------------------------------------------------------
void I3Direction::SetDir(double zen, double azi)
{
  zenith_=zen;
  azimuth_=azi;
  isCalculated_=false;
}

//-----------------------------------------------------------
void I3Direction::SetThetaPhi(double theta, double phi)
{
  if (theta>I3Constants::pi) theta = 2.*I3Constants::pi-theta;
  zenith_ = I3Constants::pi-theta;
  double azimuth = I3Constants::pi+phi;
  if (azimuth>=2.*I3Constants::pi) azimuth -= 2*I3Constants::pi;
  azimuth_=azimuth;
  isCalculated_=false;
}

//-----------------------------------------------------------
void I3Direction::SetDirection(double x, double y, double z)
{
  xDir_=x; yDir_=y; zDir_=z;
  CalcSphFromCar();
}

//-----------------------------------------------------------
void I3Direction::SetDir(double x, double y, double z)
{
  xDir_=x; yDir_=y; zDir_=z;
  CalcSphFromCar();
}

//-----------------------------------------------------------
void I3Direction::ResetDirection()
{
  xDir_=yDir_=zDir_=zenith_=azimuth_=NAN;
  isCalculated_=true;
}

//-----------------------------------------------------------
void I3Direction::ResetDir() {
  xDir_=yDir_=zDir_=zenith_=azimuth_=NAN;
  isCalculated_=true;
}

//-----------------------------------------------------------
void I3Direction::NullDirection() {
  xDir_=yDir_=zDir_=zenith_=azimuth_=NAN;
  isCalculated_=true;
}

//-----------------------------------------------------------
void I3Direction::NullDir() {
  xDir_=yDir_=zDir_=zenith_=azimuth_=NAN;
  isCalculated_=true;
}

//-----------------------------------------------------------
void I3Direction::RotateX(double angle)
{
// Rotate around x-axis by angle
  if (!isCalculated_) CalcCarFromSph();
  const double s=std::sin(angle);
  const double c=std::cos(angle);
  const double y=yDir_;
  yDir_=c*y-s*zDir_;
  zDir_=s*y+c*zDir_;
  CalcSphFromCar();
}

//-----------------------------------------------------------
void I3Direction::RotateY(double angle)
{
// Rotate around y-axis by angle
  if (!isCalculated_) CalcCarFromSph();
  const double s=std::sin(angle);
  const double c=std::cos(angle);
  const double z=zDir_;
  zDir_=c*z-s*xDir_;
  xDir_=s*z+c*xDir_;
  CalcSphFromCar();
}

//-----------------------------------------------------------
void I3Direction::RotateZ(double angle)
{
// Rotate around z-axis by angle
  if (!isCalculated_) CalcCarFromSph();
  const double s=std::sin(angle);
  const double c=std::cos(angle);
  const double x=xDir_;
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
  const double theta = I3Constants::pi-zenith_;
  const double phi = azimuth_-I3Constants::pi;
  const double rho = std::sin(theta);
  xDir_ = rho*std::cos(phi);
  yDir_ = rho*std::sin(phi);
  zDir_ = std::cos(theta);
  isCalculated_=true;
}

//-----------------------------------------------------------
void I3Direction::CalcSphFromCar()
{
  // Calculate Spherical coordinates from Cartesian
  // Direction is stored on disk in Spherical coordinates only
  // zenith=pi-theta and azimuth=phi+pi in these IceCube coordinates.
  const double r = std::sqrt(xDir_*xDir_+yDir_*yDir_+zDir_*zDir_);
  double theta = 0.;
  if (r && std::abs(zDir_/r)<=1.) {
    theta=std::acos(zDir_/r);
  } else {
    if (zDir_<0.) theta=I3Constants::pi;
  }
  if (theta<0.) theta+=2.*I3Constants::pi;
  double phi=0;
  if ((xDir_!=0.) || (yDir_!=0.)) phi=std::atan2(yDir_,xDir_);
  if (phi<0.) phi+=2.*I3Constants::pi;
  double zenith = I3Constants::pi-theta;
  double azimuth = phi+I3Constants::pi;
  if (zenith>I3Constants::pi) zenith -= I3Constants::pi-(zenith-I3Constants::pi);
  azimuth -= (int)(azimuth/(2.*I3Constants::pi))*(2.*I3Constants::pi);

  zenith_=zenith;
  azimuth_=azimuth;

  isCalculated_=false;
}

//-----------------------------------------------------------
I3Position I3Direction::Cross(const I3Position& d) const{
  if (!isCalculated_) CalcCarFromSph();
  return I3Position (yDir_*d.GetZ() - zDir_*d.GetY(),
                     zDir_*d.GetX() - xDir_*d.GetZ(),
                     xDir_*d.GetY() - yDir_*d.GetX());
}

//-----------------------------------------------------------
double I3Direction::Dot(const I3Direction& d) {
  if (!isCalculated_) CalcCarFromSph();
  return (xDir_*d.GetX() + yDir_*d.GetY() + zDir_*d.GetZ());
}

//-----------------------------------------------------------
double I3Direction::operator*(const I3Position& other) const{
  if (!isCalculated_) CalcCarFromSph();
  return xDir_*other.GetX() + yDir_*other.GetY() + zDir_*other.GetZ();
}

//-----------------------------------------------------------
I3Position I3Direction::operator*(double a) const{
  return I3Position(a,I3Constants::pi-zenith_,azimuth_-I3Constants::pi,I3Position::sph);
}

//-----------------------------------------------------------
I3Position I3Direction::operator/(double a) const{
  return I3Position(1/a,I3Constants::pi-zenith_,azimuth_-I3Constants::pi,I3Position::sph);
}

//-----------------------------------------------------------
I3Position operator*(double a, const I3Direction& d){
  return(d*a);
}

//-----------------------------------------------------------
std::ostream& operator<<(std::ostream& oss, const I3Direction& d){
  oss << "I3Direction(Zenith (deg): " << d.GetZenith()/I3Units::degree << 
    ", Azimuth(deg): " <<d.GetAzimuth()/I3Units::degree << ")";
  return oss;
}
