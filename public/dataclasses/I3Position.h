///////////////////////////////////////////////////////////////////////////
// Class I3Position
// Handling of positions in various reference frames.
//
// This class is meant to serve as a base class for ICECUBE objects
// that have a unique position in 3-dimensional space.
//
// Note :
// ------
// Positions (r) and reference frames (f) are specified via
//
//    SetPosition(Double_t r1, Double_t r2, Double_t r3, RefFrame f)
//
// under the following conventions :
//
// f=car ==> r in Cartesian coordinates   (x,y,z)
// f=sph ==> r in Spherical coordinates   (r,theta,phi)
// f=cyl ==> r in Cylindrical coordinates (rho,phi,z)
//
// All angles are in radians.
//
// Example :
// ---------
//
// I3Position q;
// q.SetPosition(-1,25,7,car);
// q.GetPosition(r,theta,phi,sph);
//
//***********************************************************
//-- Created: Dusan Turcan UMD 26-05-2004
//   Taken from: Nick van Eijndhoven 06-feb-1999 UU-SAP Utrecht
//***********************************************************
///////////////////////////////////////////////////////////////////////////

// $Id: I3Position.h,v 1.5 2004/06/14 22:28:14 dule Exp $

#ifndef I3POSITION_H
#define I3POSITION_H

#include <math.h>
using namespace std;

#include "TObject.h"

class I3Position
{
 public:

  /**
   * Possible reference frames.
   */
  enum RefFrame { car, sph, cyl };

  /**
   * Internally define pi.
   */
  static Double_t pi() { return 3.14159265358979323846; }

  //--------------

  /**
   * Default constructor
   */
  I3Position();

  /**
   * Additional constructor
   */
  I3Position(Double_t x, Double_t y, Double_t z);

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
  void SetPosition(I3Position& p);

  /**
   * Store position r in ref frame f
   */
  void SetPosition(Double_t r1, Double_t r2, Double_t r3, RefFrame f);

  /**
   * Provide position
   */
  I3Position& GetPosition();

  /**
   * Provide position r in ref frame f
   */
  void GetPosition(Double_t& r1, Double_t& r2, Double_t& r3, RefFrame f);

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
  Double_t X() const {return fX;}

  /**
   * Provide Y of position in cartesian ref frame
   */
  Double_t Y() const {return fY;}

  /**
   * Provide Z of position in cartesian ref frame
   */
  Double_t Z() const {return fZ;}

  /**
   * Provide R of position in spherical ref frame
   */
  Double_t R() const {return fR;}

  /**
   * Provide Theta of position in spherical ref frame
   */
  Double_t Theta() const {return fTheta;}

  /**
   * Provide Phi of position in spherical or cylindrical ref frame
   */
  Double_t Phi() const {return fPhi;}

  /**
   * Provide Rho of position in cylindrical ref frame
   */
  Double_t Rho() const {return fRho;}

  //--------------

  /**
   * Set X position while keeping Y,Z constant.  Recalculate SPH and CYL.
   */
  void X(Double_t x) {
    fX=x;
    CalcSphCylFromCar();
  }

  /**
   * Set Y position while keeping X,Z constant.  Recalculate SPH and CYL.
   */
  void Y(Double_t y) { 
    fY=y;
    CalcSphCylFromCar();
  }

  /**
   * Set Z position while keeping X,Y constant.  Recalculate SPH and CYL.
   */
  void Z(Double_t z) {
    fZ=z;
    CalcSphCylFromCar();
  }

  //--------------

  /**
   * Translate current position by position p (i.e. 'this'='this'-'p')
   */
  void Translate(const I3Position& p);

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
  Double_t CalcDistance(const I3Position& p);

  /**
   * Print out all information about the I3Position
   */
  void PrintPosition();
  

 protected:
  Double_t fX, fY, fZ;        // cartesian (car)
  Double_t fR, fTheta, fPhi;  // spherical (sph)
  Double_t fRho;              // cylindrical (cyl) - Z and Phi are same.
  Bool_t IsCalculated;        // Did we calculat the positions before?


 private:
  void CalcSphCylFromCar();
  void CalcCarCylFromSph();
  void CalcCarSphFromCyl();

  // ROOT macro
  ClassDef(I3Position,1)
};
#endif
