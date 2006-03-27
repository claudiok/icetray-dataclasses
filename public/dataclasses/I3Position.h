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

#include <math.h>
using namespace std;

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
  I3Position();

  /**
   * Additional constructor
   */
  I3Position(double x, double y, double z, RefFrame f=car);

  /**
   * Copy constructor
   */
  I3Position(const I3Position& p);

  /**
   * Destructor
   */
  virtual ~I3Position();

  //--------------

  /**
   * Store position from position p
   */
  void SetPosition(const I3Position& p);
  void SetPos(const I3Position& p) { SetPosition(p); }

  /**
   * Store position r in ref frame f
   */
  void SetPosition(double r1, double r2, double r3, RefFrame f=car);
  void SetPos(double r1, double r2, double r3, RefFrame f=car)
    { SetPosition(r1, r2, r3, f); }

  /**
   * Reset all elements of I3Position to NAN
   */
  void ResetPosition();
  void ResetPos() { ResetPosition(); }

  /**
   * Set null position for non-existing position (ResetPosition)
   */
  void NullPosition() { ResetPosition(); }
  void NullPos() { ResetPosition(); }

  //--------------

  /**
   * Provide X of position in cartesian ref frame
   */
  double GetX() const {return x_;}

  /**
   * Provide Y of position in cartesian ref frame
   */
  double GetY() const {return y_;}

  /**
   * Provide Z of position in cartesian ref frame
   */
  double GetZ() const {return z_;}

  /**
   * Provide R of position in spherical ref frame
   * If non-cartesian have not been calculated, then calculate them first
   */
  double GetR() const {
    if (!isCalculated_) CalcSphCylFromCar();
    return r_;
  }

  /**
   * Provide Theta of position in spherical ref frame
   * If non-cartesian have not been calculated, then calculate them first
   */
  double GetTheta() const {
    if (!isCalculated_) CalcSphCylFromCar();
    return theta_;
  }

  /**
   * Provide Phi of position in spherical or cylindrical ref frame
   * If non-cartesian have not been calculated, then calculate them first
   */
  double GetPhi() const {
    if (!isCalculated_) CalcSphCylFromCar();
    return phi_;
  }

  /**
   * Provide Rho of position in cylindrical ref frame
   * If non-cartesian have not been calculated, then calculate them first
   */
  double GetRho() const {
    if (!isCalculated_) CalcSphCylFromCar();
    return rho_;
  }

  //--------------

  /**
   * Set X position while keeping Y,Z constant.  Recalculate SPH and CYL.
   */
  void SetX(double x) {
    x_=x;
    isCalculated_=false; // when accessing CYL/SPH, they will be recalculated
  }

  /**
   * Set Y position while keeping X,Z constant.  Recalculate SPH and CYL.
   */
  void SetY(double y) {
    y_=y;
    isCalculated_=false; // when accessing CYL/SPH, they will be recalculated
  }

  /**
   * Set Z position while keeping X,Y constant.  Recalculate SPH and CYL.
   */
  void SetZ(double z) {
    z_=z;
    isCalculated_=false; // when accessing CYL/SPH, they will be recalculated
  }

  //--------------

  /**
   * Shift coordinate system by position p (i.e. 'this'='this'-'p')
   */
  void ShiftCoordSystem(const I3Position& p);

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
  double CalcDistance(const I3Position& p) const;

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

I3_POINTER_TYPEDEFS(I3Position);

#endif //I3POSITION_H_INCLUDED
