/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Direction.h,v 1.6 2004/09/13 22:49:51 dule Exp $
 *
 * @file I3Direction.h
 * @version $Revision: 1.6 $
 * @date $Date: 2004/09/13 22:49:51 $
 * @author dule
 */

//***********************************************************
//-- Created: Dusan Turcan, UMD, Sep 2, 2004
//   Done similarly to I3Position
//***********************************************************

// $Id: I3Direction.h,v 1.6 2004/09/13 22:49:51 dule Exp $

#ifndef I3DIRECTION_H
#define I3DIRECTION_H

#include <math.h>
using namespace std;

#include "TObject.h"
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
class I3Direction : public TObject
{
 public:

  /**
   * Possible reference frames.
   */
  //enum RefFrame { car, sph, cyl };

  //--------------

  /**
   * Default constructor
   */
  I3Direction();

  /**
   * Additional constructor: 2 arguments mean construct dir. with zen,azi
   */
  //I3Direction(Double_t azi, Double_t zen, Double_t z, RefFrame f=car);
  I3Direction(Double_t azi, Double_t zen);

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

  /**
   * Store direction with azi and zen (2 arguments)
   */
  void SetDirection(Double_t zen, Double_t azi);

  /**
   * Store direction with x, y, z (3 arguments)
   */
  void SetDirection(Double_t x, Double_t y, Double_t z);

  /**
   * Reset direction to 0
   */
  void ResetDirection();

  /**
   * Set null direction for non-existing direction
   */
  void NullDirection();

  //--------------

  /**
   * Provide Zenith of direction in cartesian ref frame
   */
  Double_t GetZenith() const {return fZenith;}

  /**
   * Provide Azimuth of direction in cartesian ref frame
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

  // ROOT macro
  ClassDef(I3Direction,1)
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
