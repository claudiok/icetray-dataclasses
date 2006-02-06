/**
    @version $Id$
    @file I3TankHit.h
    @date Tue Jun 22 16:39:23 EDT 2004
*/

#ifndef I3TANKHIT_H_INCLUDED
#define I3TANKHIT_H_INCLUDED

#include <TObject.h>
#include <TObjArray.h>

#include "dataclasses/Utility.h"

#include <string>
#include <sstream>

using namespace std;

/**
 * @brief The container for all the Array Hit-related data in the event
 *
 */
class I3TankHit : public TObject {

 protected:

  unsigned short tankNumber_;

  /**
   * the first arrival of a particle at this particular tank
   */
  float time_;

  /**
   * the signal of the tank (can be different things like track length, charge,
   * #mc-particles, amplitude, ...
   */
  float signal_;

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
  float Time() const {
	  return time_;
  }

  /**
   * Set the time
   */
  void Time (float time) {
	  time_ = time;
  }

  /**
   * Get the Signal
   */
  float Signal () const {
	  return signal_;
  }

  /**
   * Set the Signal
   */
  void Signal (float signal) {
	  signal_ = signal;
  }

  /**
   * implementation problem
   */
  virtual void ToStream(ostream& o) const
    {
      o<<" [ I3TankHit ]\n";
/*        <<"TankNumber: " */
/*        <<tankNumber_ */
/*        <<"Signal: " */
/*        <<signal_ */
/*        <<"Time: " */
/*        <<time_<<"\n"; */
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

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
// ROOT macro
  //ClassDef(I3TankHit,1);
};

inline ostream& operator<<(ostream& o,const I3TankHit& tankhit)
{
  tankhit.ToStream(o);
  return o;
}

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

