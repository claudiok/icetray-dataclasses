/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file I3Direction.h
 * @version $Revision: 1.16 $
 * @date $Date$
 * @author dule
 */

//***********************************************************
//-- Created: Dusan Turcan, UMD, Sep 2, 2004
//   Done similarly to I3Position
//***********************************************************

// $Id$

#ifndef I3DIRECTION_H
#define I3DIRECTION_H

#include <math.h>
#include <sstream>
#include "TObject.h"
#include "StoragePolicy.h"
#include "dataclasses/I3Constants.h"
#include "dataclasses/I3Units.h"

using namespace I3Constants;
using namespace I3Units;
using namespace std;

/**
 * @brief The basic position class for IceCube. 
 *
 * All directions in IceCube should be written with this class.
 * Directions can be given in zenith/azimuth or direction cosines.
 * Optionally, they can also be set with theta/phi.
 * 
 * See the graphic of the definitions of Zenith/Azimuth and theta/Phi 
 * direction angles:
 * http://icecube.umd.edu/dule/icecube/axes.html
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
  I3Direction(double zen, double azi);

  /**
   * Additional constructor: 3 arguments mean construct dir. with x,y,z
   */
  I3Direction(double x, double y, double z);

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
  void SetDirection(double zen, double azi);
  void SetDir(double zen, double azi) { SetDirection(zen, azi); }

  /**
   * Store direction with x, y, z (3 arguments)
   */
  void SetDirection(double x, double y, double z);
  void SetDir(double x, double y, double z) { SetDirection(x, y, z); }

  /**
	* Store direction with theta, phi
	*/
  void SetThetaPhi(double theta, double phi);

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
  double GetZenith() const {return zenith_;}

  /**
   * Provide Azimuth of direction
   */
  double GetAzimuth() const {return azimuth_;}

  /**
   * Provide X of direction in cartesian ref frame
   */
  double GetX() const {
    if (!isCalculated_) CalcCarFromSph();
    return xDir_;
  }

  /**
   * Provide Y of direction in cartesian ref frame
   */
  double GetY() const {
    if (!isCalculated_) CalcCarFromSph();
    return yDir_;
  }

  /**
   * Provide Z of direction in cartesian ref frame
   */
  double GetZ() const {
    if (!isCalculated_) CalcCarFromSph();
    return zDir_;
  }

  /**
   * Calculate Theta of direction
   */
  double CalcTheta() const {
    double theta = pi - zenith_;
    return theta;
  }

  /**
   * Calculate Phi of direction
   */
  double CalcPhi() const {
    double phi = pi + azimuth_;
    if (phi >= 2*pi) phi -= 2*pi;
    return phi;
  }

  //--------------

  /**
   * Rotate direction around X axis by angle
   */
  void RotateX(double angle);

  /**
   * Rotate direction around Y axis by angle
   */
  void RotateY(double angle);

  /**
   * Rotate direction around Z axis by angle
   */
  void RotateZ(double angle);

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
  double zenith_, azimuth_;
  mutable double xDir_, yDir_, zDir_;

  /**
   * Did we calculate the directions before?
   */
  mutable bool isCalculated_; 

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

  friend class boost::serialization::access;

  template <class Archive>
  void serialize(Archive& ar, unsigned version);

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
typedef shared_ptr<I3Direction>  I3DirectionPtr;

#endif
