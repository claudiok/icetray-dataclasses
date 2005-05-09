/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file I3Constants.h
 * @version $Revision: 1.9 $
 * @date $Date$
 * @author pretz
 */

#ifndef I3CONSTANTS_H
#define I3CONSTANTS_H

#include "dataclasses/I3Units.h"
#include <cmath>

/**
 * @brief A list of static variables commonly used by physics analysis
 *
 * Just a namespace filled with constants -- add a line
 * <tt> using namespace I3Constants </tt> to get access to them
 * directly, or just use @c I3Constants::pi, for example.
 * 
 * @todo probably need more constants here.   Add them here when you need them.
 */
namespace I3Constants
{
  /**
   * The speed of light
   */
  static const double c = 2.99792458e8 * I3Units::m / (I3Units::second);

  /**
   * The index of refraction of ice
   */
  static const double n_ice = 1.31;

  /**
   * The Cherenkov angle in ice
   */
  static const double theta_cherenkov = std::acos(1/n_ice) * I3Units::rad;
  
  /**
   * pi.
   */
  static const double pi = 3.14159265358979312;
  
  /**
   * Euler's constant
   */
  static const double e = 2.71828182845904509;

  /**
   * Elevation of ice surface (of AMANDA hole 4)
   * From email from Kurt Woschnagg on 08/25/2004
   */
  static const double SurfaceElev = 9284.46*I3Units::feet;

  /**
   * Elevation of IceCube origin (z=0) -- BY DEFINITION
   * From email from Kurt Woschnagg on 08/25/2004
   */
  static const double OriginElev = 2900*I3Units::feet;

  /**
   * Z-coordinate of IceTop (Origin Depth)
   * Obtained from DEFINED elevation of origin and MEASURED surface elevation
   *
   * @todo Make sure that the elevation of IceTop is the same as the elevation
   * of AMANDA hole 4.  If not, then correct for the difference.
   */
  static const double zIceTop = SurfaceElev-OriginElev;
};

#endif
