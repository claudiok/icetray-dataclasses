/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3RecoHit.h,v 1.11 2004/06/30 17:20:26 pretz Exp $
 *
 * @file I3RecoHit.h
 * @version $Revision: 1.11 $
 * @date $Date: 2004/06/30 17:20:26 $
 * @author ehrlich
 * @author troy
 * @author pretz
 */
#ifndef I3RECOHIT_H
#define I3RECOHIT_H

#include <TObject.h>
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
  ClassDef(I3RecoHit, 1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3RecoHit>::ThePolicy I3RecoHitPtr;


#endif

