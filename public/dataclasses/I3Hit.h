/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Hit.h,v 1.9 2004/02/26 18:53:12 pretz Exp $
 *
 * I3Hit is the basic hit class.  Just a time for a PE arrival
 * at a tube.  
 *
 * @version $Revision: 1.9 $
 * @date $Date: 2004/02/26 18:53:12 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 * @todo specify what 'time' is here
 */

#ifndef I3HIT_H
#define I3HIT_H

#include <TObject.h>
#include "StoragePolicy.h"

class I3Hit : public TObject
{
  Double_t fTime;

  public:
  /**
   * constructor
   */
  I3Hit() { fTime = 0; }

  /**
   * copy constructor.
   */
  I3Hit(const I3Hit& rhs) { *this = rhs; }

  /**
   * assignment operator
   */
  const I3Hit& operator=(const I3Hit& rhs) {
    if (this == &rhs) return *this;
    fTime = rhs.fTime;
    return *this;
  }
      
  /**
   * @returns the time of the hit
   */
  Double_t Time() const { return fTime; }

  /**
   * @param time_ the new time of the hit
   */
  void Time(Double_t time) { fTime = time; }

 private:
  // ROOT Macro
  ClassDef(I3Hit, 1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3Hit>::ThePolicy I3HitPtr;

#endif

