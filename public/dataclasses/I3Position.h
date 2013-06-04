/**
 * copyright  (C) 2004
 * the icecube collaboration
 * @version $Id$
 * @file I3Position.h
 * @date $Date$
 */

//***********************************************************
//-- Created: Dusan Turcan UMD 26-05-2004
//   Taken from: Nick van Eijndhoven 06-feb-1999 UU-SAP Utrecht
//***********************************************************

// $Id$

#ifndef I3POSITION_H_INCLUDED
#define I3POSITION_H_INCLUDED

#include <cmath>

#include "icetray/I3FrameObject.h"
#include "Utility.h"
#include <sstream>

/**
 * @brief The basic position class for IceCube. 
 *
 * All positions in IceCube should be written with this class.
 * Positions can be given in cartesian, spherical, or cylindrical coordinates.
 * 
 * @todo implement "print out" of all information in a uniform way...
 * @todo insure that the temporary data isn't written to disk.
 */
static const unsigned i3position_version_ = 0;

//Forward declaration
class I3Direction;

class I3Position : public I3FrameObject
{
 public:

  /**
   * Possible reference frames.
   */
  enum RefFrame { car = 0, sph = 1, cyl = 2 };

  //--------------

  /**
   * Default constructor
   */
  I3Position():
  x_(NAN),
  y_(NAN),
  z_(NAN),
  isCalculated_(false)
  {}

  /**
   * Constructor for different coordinate systems
   *
   * The meaning of this constructor depends on the value of RefFrame.
   * If it is I3Position::car the three coordinates are treated as
   *   cartesian x, y, and z
   * If it is I3Position::sph the three coordinates are treated as 
   *   spherical r, theta, and phi
   * If it is I3Position::cyl the three coordinates are treated as 
   *   cylindrical rho, phi, and z
   */
  I3Position(double x, double y, double z, RefFrame f) {
    SetPosition(x,y,z,f);
  }

  /**
   * Constructor from cartesian coordinates
   */
  I3Position(double x, double y, double z):
  x_(x),
  y_(y),
  z_(z),
  isCalculated_(false)
  {}

  /**
   * Copy constructor
   */
  I3Position(const I3Position& p):
  x_(p.x_),
  y_(p.y_),
  z_(p.z_),
  isCalculated_(false)
  {}
  
  explicit I3Position(const I3Direction& d);

  //--------------

  /**
   * Store position from position p
   */
  inline void SetPosition(const I3Position& p) __attribute__((deprecated)) {
    x_=p.x_; y_=p.y_; z_=p.z_;
    isCalculated_=false;
  }
  inline void SetPos(const I3Position& p) __attribute__((deprecated)) {
    SetPosition(p); 
  }

  /**
   * Store position r in cartesian ref frame
   */
  inline void SetPosition(double x, double y, double z) __attribute__((deprecated)) {
    x_=x; y_=y; z_=z;
    isCalculated_=false;
  }
  inline void SetPos(double x, double y, double z) __attribute__((deprecated)) {
    SetPosition(x, y, z);
  }

  /**
   * Store position r in ref frame f
   */
  void SetPosition(double r1, double r2, double r3, RefFrame f);
  inline void SetPos(double r1, double r2, double r3, RefFrame f) {
    SetPosition(r1, r2, r3, f);
  }

  /**
   * Reset all elements of I3Position to NAN
   */
  inline void ResetPosition() __attribute__ ((deprecated)) {
    x_=NAN; y_=NAN; z_=NAN;
    isCalculated_=false;
  }
  inline void ResetPos() __attribute__ ((deprecated)) { ResetPosition(); }

  /**
   * Set null position for non-existing position (ResetPosition)
   */
  inline void NullPosition() __attribute__ ((deprecated)) { ResetPosition(); }
  inline void NullPos() __attribute__ ((deprecated)) { ResetPosition(); }

  //--------------

  /**
   * Provide X of position in cartesian ref frame
   */
  inline double GetX() const {return x_;}

  /**
   * Provide Y of position in cartesian ref frame
   */
  inline double GetY() const {return y_;}

  /**
   * Provide Z of position in cartesian ref frame
   */
  inline double GetZ() const {return z_;}

  /**
   * Provide R of position in spherical ref frame
   * If non-cartesian have not been calculated, then calculate them first
   */
  inline double GetR() const {
    if (!isCalculated_) CalcSphCylFromCar();
    return r_;
  }

  /**
   * Provide Theta of position in spherical ref frame
   * If non-cartesian have not been calculated, then calculate them first
   */
  inline double GetTheta() const {
    if (!isCalculated_) CalcSphCylFromCar();
    return theta_;
  }

  /**
   * Provide Phi of position in spherical or cylindrical ref frame
   * If non-cartesian have not been calculated, then calculate them first
   */
  inline double GetPhi() const {
    if (!isCalculated_) CalcSphCylFromCar();
    return phi_;
  }

  /**
   * Provide Rho of position in cylindrical ref frame
   * If non-cartesian have not been calculated, then calculate them first
   */
  inline double GetRho() const {
    if (!isCalculated_) CalcSphCylFromCar();
    return rho_;
  }

  //--------------

  /**
   * Set X position while keeping Y,Z constant.  Recalculate SPH and CYL.
   */
  inline void SetX(double x) {
    x_=x;
    isCalculated_=false; // when accessing CYL/SPH, they will be recalculated
  }

  /**
   * Set Y position while keeping X,Z constant.  Recalculate SPH and CYL.
   */
  inline void SetY(double y) {
    y_=y;
    isCalculated_=false; // when accessing CYL/SPH, they will be recalculated
  }

  /**
   * Set Z position while keeping X,Y constant.  Recalculate SPH and CYL.
   */
  inline void SetZ(double z) {
    z_=z;
    isCalculated_=false; // when accessing CYL/SPH, they will be recalculated
  }

  //--------------

  /**
   * Shift coordinate system by position p (i.e. 'this'='this'-'p')
   */
  inline void ShiftCoordSystem(const I3Position& p) __attribute__ ((deprecated)) {
    SetPosition(x_-p.x_, y_-p.y_, z_-p.z_);
  }

  /**
   * Rotate position around X axis by angle
   */
  void RotateX(double angle);

  /**
   * Rotate position around Y axis by angle
   */
  void RotateY(double angle);

  /**
   * Rotate position around Z axis by angle
   */
  void RotateZ(double angle);

  /**
   * Provide distance to position p
   */
  inline double CalcDistance(const I3Position& p) const __attribute__ ((deprecated)) {
    const double dx = x_-p.x_;
    const double dy = y_-p.y_;
    const double dz = z_-p.z_;
    return std::sqrt(dx*dx+dy*dy+dz*dz);
  }
  
  /**
   * Computes the distance from this position to the origin of the 
   * coordinate system (it's magnitude as a vector)
   */
  double Magnitude() const;
  
  /**
   * Computes the square of the vector magnitude of the position
   */
  double Mag2() const;
  
  /**
   * Vector addition
   */
  I3Position& operator+=(const I3Position&);
  
  /**
   * Vector subtraction
   */
  I3Position& operator-=(const I3Position&);
  
  /**
   * Vector addition
   */
  I3Position operator+(const I3Position&) const;
  
  /**
   * Vector subtraction
   */
  I3Position operator-(const I3Position&) const;
  
  /**
   * Scalar (dot) product
   */
  double operator*(const I3Position&) const;
  
  /**
   * Scalar (dot) product
   */
  double operator*(const I3Direction&) const;
  
  /**
   * Multiplication by a scalar
   */
  I3Position& operator*=(double);
  
  /**
   * Divison by a scalar
   */
  I3Position& operator/=(double);
  
  /**
   * Multiplication by a scalar
   */
  I3Position operator*(double) const;
  
  /**
   * Division by a scalar
   */
  I3Position operator/(double) const;
  
  /**
   * Vector (cross) product
   */
  I3Position Cross(const I3Position&) const;
  
  /**
   * Vector (cross) product
   */
  I3Position Cross(const I3Direction&) const;

 protected:
  /**
   * cartesian (car)
   */ 
  double x_;
  double y_;
  double z_;

  /**
   * spherical (sph)
   */
  mutable double r_;
  mutable double theta_;
  mutable double phi_;

  /**
   * cylindrical (cyl) - Z and Phi are same.
   */
  mutable double rho_;

  /**
   * Whether the coordinates in secondary coordinates systems 
   * (sph and cyl) are already computed
   */
  mutable bool isCalculated_;

 private:

  friend class boost::serialization::access;

  template <class Archive>
  void serialize(Archive& ar, unsigned version);

  void CalcSphCylFromCar() const;
  void CalcCarCylFromSph();
  void CalcCarSphFromCyl();

};

inline bool operator==(const I3Position& lhs, const I3Position& rhs) {
  return ((lhs.GetX() == rhs.GetX()) &&
          (lhs.GetY() == rhs.GetY()) &&
          (lhs.GetZ() == rhs.GetZ()));
}

I3Position operator*(double, const I3Position&);

std::ostream& operator<<(std::ostream& oss, const I3Position& p);


I3_POINTER_TYPEDEFS(I3Position);
BOOST_CLASS_VERSION(I3Position, i3position_version_);

#endif //I3POSITION_H_INCLUDED
