/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3NonDirectional.h,v 1.5 2004/06/30 17:20:26 pretz Exp $
 *
 * @file I3NonDirectional.h
 * @version $Revision: 1.5 $
 * @date $Date: 2004/06/30 17:20:26 $
 * @author pretz
 *
 * @todo implement fatal calls
 */
#ifndef I3NONDIRECTIONAL_H
#define I3NONDIRECTIONAL_H

#include "Rtypes.h"

 /**
  * @brief The directional part of an I3Cascade implementation, representing 
  * a cascade for which a direction hasn't been specified.
  */
class I3NonDirectional 
{
 public:
  /**
   * indicates that the cascade doesn't have a direction
   */
  virtual Bool_t HasDirection() const {return true;}

  /**
   * Shouldn't be used.  Calls Fatal().
   */
  virtual Double_t GetZenith() const {return NAN;}

  /**
   * Shouldn't be used.  Calls Fatal().
   */
  virtual Double_t GetAzimuth() const {return NAN;}

  /**
   * Doesn't do anything.  There's nothing to copy.
   */
  void CopyTo(I3Particle&) const {}
 private:
  //ROOT macro
  ClassDef(I3NonDirectional,1);
};

#endif // I3NONDIRECTIONAL
