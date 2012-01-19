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
static const unsigned i3position_version_ = 1;

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
  {;}

  /**
   * Additional constructor
   */
  I3Position(double x, double y, double z, RefFrame f) {
    SetPosition(x,y,z,f);
  }

  /**
   * Additional constructor
   */
  I3Position(float x, float y, float z):
  x_(x),
  y_(y),
  z_(z),
  isCalculated_(false)
  {;}

  /**
   * Copy constructor
   */
  I3Position(const I3Position& p):
  x_(p.x_),
  y_(p.y_),
  z_(p.z_),
  isCalculated_(false)
  {;}

  //--------------

  /**
   * Store position from position p
   */
  inline void SetPosition(const I3Position& p) {
    x_=p.x_; y_=p.y_; z_=p.z_;
    isCalculated_=false;
  }
  inline void SetPos(const I3Position& p) {
    SetPosition(p); 
  }

  /**
   * Store position r in cartesian ref frame
   */
  inline void SetPosition(float x, float y, float z) {
    x_=x; y_=y; z_=z;
    isCalculated_=false;
  }
  inline void SetPos(float x, float y, float z) {
    SetPosition(x, y, z);
  }

  /**
   * Store position r in ref frame f
   */
  void SetPosition(double r1, double r2, double r3, RefFrame f=car);
  inline void SetPos(double r1, double r2, double r3, RefFrame f=car) {
    SetPosition(r1, r2, r3, f);
  }

  /**
   * Reset all elements of I3Position to NAN
   */
  inline void ResetPosition() {
    x_=NAN; y_=NAN; z_=NAN;
    isCalculated_=false;
  }
  inline void ResetPos() { ResetPosition(); }

  /**
   * Set null position for non-existing position (ResetPosition)
   */
  inline void NullPosition() { ResetPosition(); }
  inline void NullPos() { ResetPosition(); }

  //--------------

  /**
   * Provide X of position in cartesian ref frame
   */
  inline float GetX() const {return x_;}

  /**
   * Provide Y of position in cartesian ref frame
   */
  inline float GetY() const {return y_;}

  /**
   * Provide Z of position in cartesian ref frame
   */
  inline float GetZ() const {return z_;}

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
  inline void SetX(float x) {
    x_=x;
    isCalculated_=false; // when accessing CYL/SPH, they will be recalculated
  }

  /**
   * Set Y position while keeping X,Z constant.  Recalculate SPH and CYL.
   */
  inline void SetY(float y) {
    y_=y;
    isCalculated_=false; // when accessing CYL/SPH, they will be recalculated
  }

  /**
   * Set Z position while keeping X,Y constant.  Recalculate SPH and CYL.
   */
  inline void SetZ(float z) {
    z_=z;
    isCalculated_=false; // when accessing CYL/SPH, they will be recalculated
  }

  //--------------

  /**
   * Shift coordinate system by position p (i.e. 'this'='this'-'p')
   */
  inline void ShiftCoordSystem(const I3Position& p) {
    SetPosition(x_-p.x_, y_-p.y_, z_-p.z_);
  }

  /**
   * Rotate position around X axis by angle
   */
  void RotateX(double angle);

  /**
   * Rotate position around X axis by angle
   */
  void RotateY(double angle);

  /**
   * Rotate position around X axis by angle
   */
  void RotateZ(double amgle);

  /**
   * Provide distance to position p
   */
  inline double CalcDistance(const I3Position& p) const {
    const double dx = x_-p.x_;
    const double dy = y_-p.y_;
    const double dz = z_-p.z_;
    return std::sqrt(dx*dx+dy*dy+dz*dz);
  }

 protected:
  /**
   * cartesian (car)
   */ 
  float x_;
  float y_;
  float z_;

  /**
   * spherical (sph)
   */
  mutable double r_; //!
  mutable double theta_; //!
  mutable double phi_; //!

  /**
   * cylindrical (cyl) - Z and Phi are same.
   */
  mutable double rho_; //!

  /**
   * Did we calculate the positions before?
   */
  mutable bool isCalculated_; //!

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

std::ostream& operator<<(std::ostream& oss, const I3Position& p);


I3_POINTER_TYPEDEFS(I3Position);
BOOST_CLASS_VERSION(I3Position, i3position_version_);

#endif //I3POSITION_H_INCLUDED
