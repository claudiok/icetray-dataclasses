/**
    @version $Id$
    @file I3TankHit.h
    @date Tue Jun 22 16:39:23 EDT 2004
*/

#ifndef I3TANKHIT_H_INCLUDED
#define I3TANKHIT_H_INCLUDED


#include "dataclasses/Utility.h"

#include <string>
#include <sstream>

using namespace std;

/**
 * @brief The container for all the Array Hit-related data in the event
 *
 */
class I3TankHit 
{

 protected:

  unsigned short tankNumber_;

  /**
   * the first arrival of a particle at this particular tank
   */
  double time_;

  /**
   * the signal of the tank (can be different things like track length, charge,
   * #mc-particles, amplitude, ...
   */
  double signal_;

 public:

  I3TankHit(unsigned short tank_number = 0) :
    tankNumber_(tank_number), time_(0), signal_(0) {}
  
  virtual ~I3TankHit();
  
  /**
   * @return the number of the tank for this response
   */
  unsigned short TankNumber() const { return tankNumber_; }

  /**
   * @param tanknumber the new tanknumber associated with this response
   */
  void TankNumber(unsigned short tanknumber) { tankNumber_ = tanknumber;}
  
  /**
   * Get the time
   */
  double Time() const {
	  return time_;
  }

  /**
   * Set the time
   */
  void Time (double time) {
	  time_ = time;
  }

  /**
   * Get the Signal
   */
  double Signal () const {
	  return signal_;
  }

  /**
   * Set the Signal
   */
  void Signal (double signal) {
	  signal_ = signal;
  }

  
 private:

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);

};

I3_POINTER_TYPEDEFS(I3TankHit);

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
    tankNumber_( tank_number ) {}

  /**
   * Comparison operator
   */
  bool operator () (I3TankHitPtr tank)
    {
      return tank->TankNumber () == tankNumber_;
    }

 private:
  unsigned short tankNumber_;

};

#endif //I3TANKHIT_H_INCLUDED

