/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Position.h,v 1.12 2004/08/12 17:33:33 pretz Exp $
 *
 * @file I3Position.h
 * @version $Revision: 1.12 $
 * @date $Date: 2004/08/12 17:33:33 $
 * @author dule
 */

//***********************************************************
//-- Created: Dusan Turcan UMD 26-05-2004
//   Taken from: Nick van Eijndhoven 06-feb-1999 UU-SAP Utrecht
//***********************************************************

// $Id: I3Position.h,v 1.12 2004/08/12 17:33:33 pretz Exp $

#ifndef I3POSITION_H
#define I3POSITION_H

#include <math.h>
using namespace std;

#include "TObject.h"
#include "StoragePolicy.h"

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

  /**
   * Store position r in ref frame f
   */
  void SetPosition(Double_t r1, Double_t r2, Double_t r3, RefFrame f=car);

  /**
   * Reset position to 0
   */
  void ResetPosition();

  /**
   * Set null position for non-existing position
   */
  void NullPosition();

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
  Double_t GetR() {
    if (!IsCalculated) CalcSphCylFromCar();
    return fR;
  }

  /**
   * Provide Theta of position in spherical ref frame
   * If non-cartesian have not been calculated, then calculate them first
   */
  Double_t GetTheta() {
    if (!IsCalculated) CalcSphCylFromCar();
    return fTheta;
  }

  /**
   * Provide Phi of position in spherical or cylindrical ref frame
   * If non-cartesian have not been calculated, then calculate them first
   */
  Double_t GetPhi() {
    if (!IsCalculated) CalcSphCylFromCar();
    return fPhi;
  }

  /**
   * Provide Rho of position in cylindrical ref frame
   * If non-cartesian have not been calculated, then calculate them first
   */
  Double_t GetRho() {
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
   * Print out all information about the I3Position
   */
  void PrintPosition();
  
 protected:
  /**
   * cartesian (car)
   */ 
  Double_t fX, fY, fZ;

  /**
   * spherical (sph)
   */
  Double_t fR, fTheta, fPhi;  

  /**
   * cylindrical (cyl) - Z and Phi are same.
   */
  Double_t fRho;

  /**
   * Did we calculate the positions before?
   */
  Bool_t IsCalculated; 

 private:
  void CalcSphCylFromCar();
  void CalcCarCylFromSph();
  void CalcCarSphFromCyl();

  // ROOT macro
  ClassDef(I3Position,1)
};

/**
 * pointer type to insulate users from memory management
 */
typedef PtrPolicy<I3Position>::ThePolicy I3PositionPtr;

#endif
