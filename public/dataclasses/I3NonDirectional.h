/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3NonDirectional.h,v 1.6 2004/07/06 16:41:45 pretz Exp $
 *
 * @file I3NonDirectional.h
 * @version $Revision: 1.6 $
 * @date $Date: 2004/07/06 16:41:45 $
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
  virtual Bool_t HasDirection() const {return kFALSE;}

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
