/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3NonDirectional.h,v 1.8.4.1 2005/01/26 03:59:37 troy Exp $
 *
 * @file I3NonDirectional.h
 * @version $Revision: 1.8.4.1 $
 * @date $Date: 2005/01/26 03:59:37 $
 * @author pretz
 *
 * @todo implement fatal calls
 */
#ifndef I3NONDIRECTIONAL_H
#define I3NONDIRECTIONAL_H

#include "StoragePolicy.h"

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
   * Doesn't do anything.  There's nothing to copy.
   */
  void CopyTo(I3Particle&) const {}

  virtual void ToStream(ostream& o) const
    {
      o<<"Direction: NonDirectional\n";
    }
 private:
  //ROOT macro
  ClassDef(I3NonDirectional,1);
};

#endif // I3NONDIRECTIONAL
