/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Constants.h,v 1.3 2004/06/30 17:20:26 pretz Exp $
 *
 * @file I3Constants.h
 * @version $Revision: 1.3 $
 * @date $Date: 2004/06/30 17:20:26 $
 * @author pretz
 */

#ifndef I3CONSTANTS_H
#define I3CONSTANTS_H

#include "dataclasses/I3Units.h"

/**
 * @brief A list of static variables commonly used by physics analysis
 *
 * Speed of light, and pi, for instance.
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
};

#endif
