/**
    $Id: I3TankHit.h,v 1.6 2005/04/04 15:49:25 pretz Exp $
    @file I3TankHit.h
    @version $Revision: 1.6 $
    @date Tue Jun 22 16:39:23 EDT 2004
    @author rulrich
*/

#ifndef I3TankHit_H
#define I3TankHit_H

#include <TObject.h>
#include <TObjArray.h>

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

  unsigned short fTankNumber;

  /**
   * the first arrival of a particle at this particular tank
   */
  float fTime;

  /**
   * the signal of the tank (can be different things like track length, charge,
   * #mc-particles, amplitude, ...
   */
  float fSignal;

 public:

  /**
   * constructor
   */
  I3TankHit(unsigned short tank_number = 0) :
    fTankNumber(tank_number), fTime(0), fSignal(0) {}
  
  /**
   * destructor
   */
  virtual ~I3TankHit() {}
  
  /**
   * @return the number of the tank for this response
   */
  unsigned short TankNumber() const { return fTankNumber; }

  /**
   * @param tanknumber the new tanknumber associated with this response
   */
  void TankNumber(unsigned short tanknumber) { fTankNumber = tanknumber;}
  
  /**
   * Get the time
   */
  float Time () const;

  /**
   * Set the time
   */
  void Time (float time);

  /**
   * Get the Signal
   */
  float Signal () const;

  /**
   * Set the Signal
   */
  void Signal (float signal);

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
  ClassDef(I3TankHit,1);
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
  I3TankHitMatchesTankNumber (unsigned short tank_number) :
    fTankNumber( tank_number ) {}

  /**
   * Comparison operator
   */
  bool operator () (I3TankHitPtr tank)
    {
      return tank->TankNumber () == fTankNumber;
    }

 private:
  unsigned short fTankNumber;

};
#endif
