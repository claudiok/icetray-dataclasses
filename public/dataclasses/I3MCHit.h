/**
   copyright  (C) 2004
   the icecube collaboration
   $Id: I3MCHit.h,v 1.8 2004/02/25 20:10:24 pretz Exp $

   @version $Revision: 1.8 $
   @date $Date: 2004/02/25 20:10:24 $
   @author

*/
#ifndef I3MCHIT_H
#define I3MCHIT_H

#include <TObject.h>
#include "I3Hit.h"
#include "StoragePolicy.h"

class I3MCHit : public I3Hit
{
  Float_t          fWeight;
  UShort_t fTrackNum;

 public:
  I3MCHit() { fWeight = 0; fTrackNum=0;}

  // copy constructor just uses assignment operator
  I3MCHit(const I3MCHit &rhs) { *this = rhs; } 

  const I3MCHit& operator=(const I3MCHit &rhs) { 
    if (this == &rhs) return *this; // check for assignment to self
    I3Hit::operator=(rhs); // call base class assignment operator
    fWeight = rhs.fWeight;
    fTrackNum = rhs.fTrackNum; 
    return *this;
  }

  Float_t Weight() const { return fWeight; }
  void Weight(Float_t weight_) { fWeight = weight_; }

  short TrackNumber() const { return fTrackNum; }
  void TrackNumber(UShort_t tracknum_) { fTrackNum = tracknum_; }


  ClassDef(I3MCHit, 1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3MCHit>::ThePolicy I3MCHitPtr;

#endif

