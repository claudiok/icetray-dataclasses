/**
    $Id: I3TankHit.h,v 1.5.2.2 2005/02/04 21:51:03 troy Exp $
    @file I3TankHit.h
    @version $Revision: 1.5.2.2 $
    @date Tue Jun 22 16:39:23 EDT 2004
    @author rulrich
*/

#ifndef I3TankHit_H
#define I3TankHit_H

#include "dataclasses/StoragePolicy.h"

#include <string>
#include <sstream>

using namespace std;

/**
 * @brief The container for all the Array Hit-related data in the event
 *
 */
class I3TankHit : public TObject {

 protected:

  UShort_t fTankNumber;

  /**
   * the first arrival of a particle at this particular tank
   */
  Float_t fTime;

  /**
   * the signal of the tank (can be different things like track length, charge,
   * #mc-particles, amplitude, ...
   */
  Float_t fSignal;

 public:

  /**
   * constructor
   */
  I3TankHit(UShort_t tank_number = 0) :
    fTankNumber(tank_number), fTime(0), fSignal(0) {}
  
  /**
   * destructor
   */
  virtual ~I3TankHit() {}
  
  /**
   * @return the number of the tank for this response
   */
  UShort_t TankNumber() const { return fTankNumber; }

  /**
   * @param tanknumber the new tanknumber associated with this response
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

  /**
   * implementation problem
   */
  virtual void ToStream(ostream& o) const
    {
      o<<" [ I3TankHit ]\n";
/*        <<"TankNumber: " */
/*        <<fTankNumber */
/*        <<"Signal: " */
/*        <<fSignal */
/*        <<"Time: " */
/*        <<fTime<<"\n"; */
    }

  virtual string ToString() const
    {
      ostringstream out;
      ToStream(out);
      return out.str();
    }
  
 private:
  // copy and assignment are private
  I3TankHit(const I3TankHit&); 
  const I3TankHit& operator=(const I3TankHit&); 

  // ROOT macro

};

inline ostream& operator<<(ostream& o,const I3TankHit& tankhit)
{
  tankhit.ToStream(o);
  return o;
}

/**
 * pointer type to insulate users from memory management
 */
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
