#ifndef I3POSITION_H
#define I3POSITION_H
/* Copyright(c) 1998-1999, ALICE Experiment at CERN, All rights reserved.
 * See cxx source for full Copyright notice                            */

// $Id: I3Position.h,v 1.4 2004/06/09 21:56:34 dule Exp $

#include <math.h>
using namespace std;

#include "TObject.h"
#include "TVector3.h"

class I3Position : public TVector3
{
 public:

  enum RefFrame { car, sph, cyl }; // possible reference frames

  static Double_t pi() { return 3.14159265358979323846; } // define PI

  /**
   * Default constructor
   */
  I3Position(); // ok

  /**
   * Additional constructor
   */
  I3Position(Double_t x, Double_t y, Double_t z); // ok

  /**
   * Destructor
   */
  virtual ~I3Position(); // ok

  /**
   * Copy constructor
   */
  I3Position(const I3Position& p); // ????


  /**
   * Store position r in ref frame f
   */
  virtual void SetPosition(Double_t r1, Double_t r2, Double_t r3, RefFrame f); // ok

  /**
   * Provide position r in ref frame f
   */
  virtual void GetPosition(Double_t& r1, Double_t& r2, Double_t& r3, RefFrame f); // ok

  /**
   * Provide R of position in spherical ref frame
   */
  Double_t R() {return fR;}

  /**
   * Provide Theta of position in spherical ref frame
   */
  Double_t Theta() {return fTheta;}

  /**
   * Provide Phi of position in spherical or cylindrical ref frame
   */
  Double_t Phi() {return fPhi;}

  /**
   * Provide Rho of position in cylindrical ref frame
   */
  Double_t Rho() {return fRho;}

  /**
   * Reset position to 0
   */
  void ResetPosition(); // ok

  /**
   * Save position to disk (only save x,y,z)
   */
  void SavePosition(Double_t& x, Double_t& y, Double_t& z); // ok

  /**
   * Store position p
   */
  virtual void SetPosition(TVector3& p); // ok

  /**
   * Provide position
   */
  I3Position& GetPosition(); // ok


  /**
   * Provide distance to position p
   */
  Double_t CalcDistance(const I3Position& p) const;


  /**
   * Set unit scale (w.r.t. m) for the position coordinates (cm=0.01)
   */
  void SetUnitScale(Float_t s);

  /**
   * Provide unit scale (w.r.t. m) for the position coordinates (cm=0.01)
   */
  Float_t GetUnitScale() const;


  /**
   * Store position r in ref frame f
   */
  virtual void SetPositionErr(Double_t r1, Double_t r2, Double_t r3, RefFrame f); // ????

  /**
   * Provide position r in ref frame f
   */
  virtual void GetPositionErr(Double_t& r1, Double_t& r2, Double_t& r3, RefFrame f); // ????

  /**
   * Translate position by position p (i.e. 'this' - 'p')
   */
  void Translate(const I3Position& p);

  /**
   * Print out all information about the I3Position
   */
  void PrintPosition();
  

 protected:
  // The unit scale used for the position coordinates
  Float_t fScale;

  // Position coordinates in different reference frames
  Double_t fR, fTheta, fPhi;  // spherical (sph)
  Double_t fRho;              // cylindrical (cyl) - Z and Phi are same.
  Bool_t IsCalculated;        // Did we calculat the positions before?


 private:
  void CalcSphCylFromCar(); // ok
  void CalcCarCylFromSph(); // ok
  void CalcCarSphFromCyl(); // ok

  // ROOT macro
  ClassDef(I3Position,1)
};
#endif
