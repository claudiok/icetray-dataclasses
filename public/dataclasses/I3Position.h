/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Position.h,v 1.15.2.2 2005/02/04 21:49:05 troy Exp $
 *
 * @file I3Position.h
 * @version $Revision: 1.15.2.2 $
 * @date $Date: 2005/02/04 21:49:05 $
 * @author dule
 */

//***********************************************************
//-- Created: Dusan Turcan UMD 26-05-2004
//   Taken from: Nick van Eijndhoven 06-feb-1999 UU-SAP Utrecht
//***********************************************************

// $Id: I3Position.h,v 1.15.2.2 2005/02/04 21:49:05 troy Exp $

#ifndef I3POSITION_H
#define I3POSITION_H

#include <math.h>
using namespace std;

#include "StoragePolicy.h"
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
class I3Position : public TObject
{
 public:

  /**
   * Possible reference frames.
   */
  enum RefFrame { car, sph, cyl };

  //--------------

  /**
   * Default constructor
   */
  I3Position();

  /**
   * Additional constructor
   */
  I3Position(Double_t x, Double_t y, Double_t z, RefFrame f=car);

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
  void SetPosition(Double_t r1, Double_t r2, Double_t r3, RefFrame f=car);
  void SetPos(Double_t r1, Double_t r2, Double_t r3, RefFrame f=car)
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
  Double_t GetX() const {return fX;}

  /**
   * Provide Y of position in cartesian ref frame
   */
  Double_t GetY() const {return fY;}

  /**
   * Provide Z of position in cartesian ref frame
   */
  Double_t GetZ() const {return fZ;}

  /**
   * Provide R of position in spherical ref frame
   * If non-cartesian have not been calculated, then calculate them first
   */
  Double_t GetR() const {
    if (!IsCalculated) CalcSphCylFromCar();
    return fR;
  }

  /**
   * Provide Theta of position in spherical ref frame
   * If non-cartesian have not been calculated, then calculate them first
   */
  Double_t GetTheta() const {
    if (!IsCalculated) CalcSphCylFromCar();
    return fTheta;
  }

  /**
   * Provide Phi of position in spherical or cylindrical ref frame
   * If non-cartesian have not been calculated, then calculate them first
   */
  Double_t GetPhi() const {
    if (!IsCalculated) CalcSphCylFromCar();
    return fPhi;
  }

  /**
   * Provide Rho of position in cylindrical ref frame
   * If non-cartesian have not been calculated, then calculate them first
   */
  Double_t GetRho() const {
    if (!IsCalculated) CalcSphCylFromCar();
    return fRho;
  }

  //--------------

  /**
   * Set X position while keeping Y,Z constant.  Recalculate SPH and CYL.
   */
  void SetX(Double_t x) {
    fX=x;
    IsCalculated=kFALSE; // when accessing CYL/SPH, they will be recalculated
  }

  /**
   * Set Y position while keeping X,Z constant.  Recalculate SPH and CYL.
   */
  void SetY(Double_t y) {
    fY=y;
    IsCalculated=kFALSE; // when accessing CYL/SPH, they will be recalculated
  }

  /**
   * Set Z position while keeping X,Y constant.  Recalculate SPH and CYL.
   */
  void SetZ(Double_t z) {
    fZ=z;
    IsCalculated=kFALSE; // when accessing CYL/SPH, they will be recalculated
  }

  //--------------

  /**
   * Shift coordinate system by position p (i.e. 'this'='this'-'p')
   */
  void ShiftCoordSystem(const I3Position& p);

  /**
   * Rotate position around X axis by angle
   */
  void RotateX(Double_t angle);

  /**
   * Rotate position around X axis by angle
   */
  void RotateY(Double_t angle);

  /**
   * Rotate position around X axis by angle
   */
  void RotateZ(Double_t amgle);

  /**
   * Provide distance to position p
   */
  Double_t CalcDistance(const I3Position& p) const;

  /**
   * Print out all information about the I3Position to the given ostream
   */
  virtual void ToStream(ostream& o) const;

  /**
   * dump the I3Position to a std::string
   */
  string ToString() const
    {
      ostringstream out;
      ToStream(out);
      return out.str();
    }
  
 protected:
  /**
   * cartesian (car)
   */ 
  Double_t fX, fY, fZ;

  /**
   * spherical (sph)
   */
  mutable Double_t fR, fTheta, fPhi;  

  /**
   * cylindrical (cyl) - Z and Phi are same.
   */
  mutable Double_t fRho;

  /**
   * Did we calculate the positions before?
   */
  mutable Bool_t IsCalculated; 

 private:
  void CalcSphCylFromCar() const;
  void CalcCarCylFromSph();
  void CalcCarSphFromCyl();

  // ROOT macro

};

/**
 * for streaming to an ostream
 */
inline ostream& operator<<(ostream& o,const I3Position& pos)
{
  pos.ToStream(o);
  return o;
}

/**
 * pointer type to insulate users from memory management
 */
typedef PtrPolicy<I3Position>::ThePolicy I3PositionPtr;

#endif
