/**
    $Id: I3TankHit.h,v 1.1 2004/07/13 15:37:54 niessen Exp $
    @file I3TankHit.h
    @version $Revision: 1.1 $
    @date Tue Jun 22 16:39:23 EDT 2004
    @author rulrich
*/

#ifndef I3TankHit_H
#define I3TankHit_H

#include <TObject.h>
#include <TObjArray.h>

#include "dataclasses/StoragePolicy.h"

/**
 * @brief The container for all the Array Hit-related data in the event
 *
 */
class I3TankHit : public TObject {

 protected:

  UShort_t fTankNumber;

  // the first arrival of a particle at this particular tank
  Float_t fTime;

  // the signal of the tank (can be different things like track length, charge,
  // #mc-particles, amplitude, ...
  Float_t fSignal;

 public:

  /**
   * constructor
   */
  I3TankHit(UShort_t tank_number = 0) :
    fTime(0), fSignal(0), fTankNumber(tank_number) {}
  
  /**
   * destructor
   */
  virtual ~I3TankHit() {}
  
  /**
   * @return the number of the tank for this response
   */
  UShort_t TankNumber() const { return fTankNumber; }

  /**
   * @param omnumber the new tanknumber associated with this response
   */
  void TankNumber(UShort_t tanknumber) { fTankNumber = tanknumber;}
  
  /**
   * Get the time
   */
  Float_t Time () const;

  /**
   * Set the time
   */
  void Time (Float_t time);

  /**
   * Get the Signal
   */
  Float_t Signal () const;

  /**
   * Set the Signal
   */
  void Signal (Float_t signal);

 private:
  // copy and assignment are private
  I3TankHit(const I3TankHit&); 
  const I3TankHit& operator=(const I3TankHit&); 

  // ROOT macro
  ClassDef(I3TankHit,1);
};

typedef PtrPolicy<I3TankHit>::ThePolicy I3TankHitPtr;



/**
 @brief Functor for find_if
 @class I3TankHitMatchesTankNumber
 @author Ralf Ulrich
 
*/
class I3TankHitMatchesTankNumber {
 public:

  /**
   * Constructor, pass on the tank number to look for
   */
  I3TankHitMatchesTankNumber (UShort_t tank_number) :
    fTankNumber( tank_number ) {}

  /**
   * Comparison operator
   */
  bool operator () (I3TankHitPtr tank)
    {
      return tank->TankNumber () == fTankNumber;
    }

 private:
  UShort_t fTankNumber;

};
#endif
