/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3MCHit.h,v 1.10 2004/02/26 18:53:12 pretz Exp $
 *
 *
 *
 * @version $Revision: 1.10 $
 * @date $Date: 2004/02/26 18:53:12 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 */
#ifndef I3MCHIT_H
#define I3MCHIT_H

#include <TObject.h>
#include "I3Hit.h"
#include "StoragePolicy.h"

class I3MCHit : public I3Hit
{
  Float_t fWeight;
  UShort_t fTrackNum;

 public:
  /**
   * constructor
   */
  I3MCHit() { fWeight = 0; fTrackNum=0;}

  /**
   * copy constructor just uses assignment operator
   */
  I3MCHit(const I3MCHit &rhs) { *this = rhs; } 

  /**
   * assignment operator is a member-wise assignment
   */
  const I3MCHit& operator=(const I3MCHit &rhs) { 
    if (this == &rhs) return *this; // check for assignment to self
    I3Hit::operator=(rhs); // call base class assignment operator
    fWeight = rhs.fWeight;
    fTrackNum = rhs.fTrackNum; 
    return *this;
  }

  /**
   * @return the weight contributed by this MCHit
   */
  Float_t Weight() const { return fWeight; }

  /**
   * @param weight the new weight for the hit
   */
  void Weight(Float_t weight) { fWeight = weight; }

  /**
   * @return the track number which caused this hit
   */
  UShort_t TrackNumber() const { return fTrackNum; }

  /**
   * @param tracknum set the track which caused this hit
   */
  void TrackNumber(UShort_t tracknum) { fTrackNum = tracknum; }

 private:

  //ROOT macro
  ClassDef(I3MCHit, 1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3MCHit>::ThePolicy I3MCHitPtr;

#endif

