/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Direction.h,v 1.10.2.2 2005/02/04 21:51:03 troy Exp $
 *
 * @file I3Direction.h
 * @version $Revision: 1.10.2.2 $
 * @date $Date: 2005/02/04 21:51:03 $
 * @author dule
 */

//***********************************************************
//-- Created: Dusan Turcan, UMD, Sep 2, 2004
//   Done similarly to I3Position
//***********************************************************

// $Id: I3Direction.h,v 1.10.2.2 2005/02/04 21:51:03 troy Exp $

#ifndef I3DIRECTION_H
#define I3DIRECTION_H

#include <math.h>
#include <sstream>
#include "StoragePolicy.h"
#include "dataclasses/I3Constants.h"
#include "dataclasses/I3Units.h"

using namespace I3Constants;
using namespace I3Units;
using namespace std;

/**
 * @brief The basic position class for IceCube. 
 *
 * All positions in IceCube should be written with this class.
 * Positions can be given in cartesian, spherical, or cylindrical coordinates.
 * 
 * @todo implement "print out" of all information in a uniform way...
 * @todo insure that the temporary data isn't written to disk.
 */
class I3Direction : public TObject
{
 public:

  /**
   * Default constructor
   */
  I3Direction();

  /**
   * Additional constructor: 2 arguments mean construct dir. with zen,azi
   */
  I3Direction(Double_t zen, Double_t azi);

  /**
   * Additional constructor: 3 arguments mean construct dir. with x,y,z
   */
  I3Direction(Double_t x, Double_t y, Double_t z);

  /**
   * Copy constructor
   */
  I3Direction(const I3Direction& d);

  /**
   * Destructor
   */
  virtual ~I3Direction();

  //--------------

  /**
   * Store direction from direction d
   */
  void SetDirection(const I3Direction& d);
  void SetDir(const I3Direction& d) { SetDirection(d); }

  /**
   * Store direction with zen and azi (2 arguments)
   */
  void SetDirection(Double_t zen, Double_t azi);
  void SetDir(Double_t zen, Double_t azi) { SetDirection(zen, azi); }

  /**
   * Store direction with x, y, z (3 arguments)
   */
  void SetDirection(Double_t x, Double_t y, Double_t z);
  void SetDir(Double_t x, Double_t y, Double_t z) { SetDirection(x, y, z); }

  /**
   * Reset all elements of I3Direction to NAN
   */
  void ResetDirection();
  void ResetDir() { ResetDirection(); }

  /**
   * Set null direction for non-existing direction (ResetDirection)
   */
  void NullDirection() { ResetDirection(); }
  void NullDir() { ResetDirection(); }

  //--------------

  /**
   * Provide Zenith of direction
   */
  Double_t GetZenith() const {return fZenith;}

  /**
   * Provide Azimuth of direction
   */
  Double_t GetAzimuth() const {return fAzimuth;}

  /**
   * Provide X of direction in cartesian ref frame
   */
  Double_t GetX() const {
    if (!IsCalculated) CalcCarFromSph();
    return fX;
  }

  /**
   * Provide Y of direction in cartesian ref frame
   */
  Double_t GetY() const {
    if (!IsCalculated) CalcCarFromSph();
    return fY;
  }

  /**
   * Provide Z of direction in cartesian ref frame
   */
  Double_t GetZ() const {
    if (!IsCalculated) CalcCarFromSph();
    return fZ;
  }

  /**
   * Calculate Theta of direction
   */
  Double_t CalcTheta() const {
    Double_t theta = 180*deg - fZenith;
    if (theta > 180*deg) theta = 360*deg - theta;
    if (theta < 0) theta = -theta;
    return theta;
  }

  /**
   * Calculate Phi of direction
   */
  Double_t CalcPhi() const {
    Double_t phi = fAzimuth + 180*deg;
    if (phi >= 360*deg) phi -= 360*deg;
    if (phi < 0) phi += 360*deg;
    return phi;
  }

  //--------------

  /**
   * Rotate direction around X axis by angle
   */
  void RotateX(Double_t angle);

  /**
   * Rotate direction around Y axis by angle
   */
  void RotateY(Double_t angle);

  /**
   * Rotate direction around Z axis by angle
   */
  void RotateZ(Double_t angle);

  /**
   * Print out all information about the I3Direction to the given ostream
   */
  virtual void ToStream(ostream& o) const;

  /**
   * dump the I3Direction to a std::string
   */
  string ToString() const
    {
      ostringstream out;
      ToStream(out);
      return out.str();
    }
  
  //--------------


 protected:
  /**
   * direction coordinates
   */ 
  Double_t fZenith, fAzimuth;
  mutable Double_t fX, fY, fZ;

  /**
   * Did we calculate the directions before?
   */
  mutable Bool_t IsCalculated; 

 private:
  /**
   * Change zenith,azimuth coordinates into x,y,z directional coordinates.
   * The three numbers x,y,z are calculated to add up (in quadrature) to 1.
   * theta=pi-zenith and phi=azimuth-pi in these IceCube coordinates.
   */
  void CalcCarFromSph() const;

  /**
   * Change x,y,z directional coordinates to zenith,azimuth coordinates.
   * zenith=pi-theta and azimuth=phi+pi in these IceCube coordinates.
   * The three numbers DO NOT have to add up (in quadrature) to 1.
   * Even if they don't, the direction that they define is stored.
   * SO BE CAREFUL IF YOU SPECIFY THE DIRECTION IN THIS WAY!
   */
  void CalcSphFromCar();

  //void CalcSphCylFromCar() const;
  //void CalcCarCylFromSph();
  //void CalcCarSphFromCyl();

};

/**
 * for streaming to an ostream
 */
inline ostream& operator<<(ostream& o,const I3Direction& dir)
{
  dir.ToStream(o);
  return o;
}

/**
 * pointer type to insulate users from memory management
 */
typedef PtrPolicy<I3Direction>::ThePolicy I3DirectionPtr;

#endif
