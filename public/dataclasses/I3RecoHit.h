/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3RecoHit.h,v 1.11.4.2 2005/02/04 21:49:05 troy Exp $
 *
 * @file I3RecoHit.h
 * @version $Revision: 1.11.4.2 $
 * @date $Date: 2005/02/04 21:49:05 $
 * @author ehrlich
 * @author troy
 * @author pretz
 */
#ifndef I3RECOHIT_H
#define I3RECOHIT_H

#include "I3Hit.h"

/**
 * @brief A base class for reconstruted hits.  
 *
 * Carries no information beyond 'hit'
 * but can be sub-classed as part of a hit series reconstruction.
 *
 */
class I3RecoHit : public I3Hit
{
  public:
  /**
   * constructor
   */
  I3RecoHit(){}

  /**
   * destructor
   */
  virtual ~I3RecoHit(){}

  /**
   * copy constructor just uses assignment
   */
  I3RecoHit(const I3RecoHit& rhs){*this = rhs;}

  /**
   * assignment is just member-wise assignment
   */
  //const I3RecoHit& operator=(const I3RecoHit& rhs){
  //  if (this == &rhs) return *this; // check for assignment to self
  //  I3Hit::operator=(rhs); // call base class assignment operator
  //  fConfidence = rhs.fConfidence;
  //  return *this;
  //}

 private:
  //ROOT macro

};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3RecoHit>::ThePolicy I3RecoHitPtr;


#endif

