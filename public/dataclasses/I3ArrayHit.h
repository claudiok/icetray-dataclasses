/**
    $Id: I3ArrayHit.h,v 1.3.2.1 2004/07/19 22:24:20 ehrlich Exp $
    @file I3ArrayHit.h
    @version $Revision: 1.3.2.1 $
    @date Fri Jul  9 10:50:16 EDT 2004 
    @author rulrich
*/

#ifndef I3ArrayHit_H
#define I3ArrayHit_H

#include <TObject.h>

#include "dataclasses/I3StationHit.h"
#include "dataclasses/StoragePolicy.h"

/**
 * @brief The base class to store Array-Hit-Data
 *
 * this is just some basic interface, the actual stuff saved can be different.
 * For example just number of different particle types per tank, 
 * or track length or electronic response (Amplitude, Signal, 
 * Charge, Waveforms ...)
 */
class I3ArrayHit : public TObject, 
	 public VecPointainerPolicy<I3StationHitPtr>::ThePolicy  {

 public:
  /**
   * constructor
   */
  I3ArrayHit() {}
  
  /**
   * destructor
   */
  virtual ~I3ArrayHit() {}
  

 private:
  // copy and assignment are private
  I3ArrayHit(const I3ArrayHit&); 
  const I3ArrayHit& operator=(const I3ArrayHit&); 

  // ROOT macro
  ClassDef(I3ArrayHit,1);
};


typedef PtrPolicy<I3ArrayHit>::ThePolicy I3ArrayHitPtr;

#endif
