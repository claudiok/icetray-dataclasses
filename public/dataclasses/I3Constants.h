/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Constants.h,v 1.6 2004/08/02 17:24:22 dule Exp $
 *
 * @file I3Constants.h
 * @version $Revision: 1.6 $
 * @date $Date: 2004/08/02 17:24:22 $
 * @author pretz
 */

#ifndef I3CONSTANTS_H
#define I3CONSTANTS_H

#include "dataclasses/I3Units.h"

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
  static const Double_t c = 2.99792458e8 * I3Units::m / (I3Units::second);
  
  /**
   * pi.
   */
  static const Double_t pi = 3.14159265358979312;
  
  /**
   * Euler's constant
   */
  static const Double_t e = 2.71828182845904509;

  /**
   * Z-coordinate of IceTop (Origin Depth)
   * @todo This number needs to be checked and decided upon... It's wrong.
   */
  static const Double_t zIceTop = 2900*I3Units::feet;
};

#endif
