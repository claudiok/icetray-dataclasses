/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3RecoHit.h,v 1.6 2004/02/26 03:51:13 pretz Exp $
 *
 * @version $Revision: 1.6 $
 * @date $Date: 2004/02/26 03:51:13 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 * @todo
 *
 */
#ifndef I3RECOHIT_H
#define I3RECOHIT_H

#include <TObject.h>
#include "I3Hit.h"

class I3RecoHit : public I3Hit
{
  float fConfidence;

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
  const I3RecoHit& operator=(const I3RecoHit& rhs){
    if (this == &rhs) return *this; // check for assignment to self
    I3Hit::operator=(rhs); // call base class assignment operator
    fConfidence = rhs.fConfidence;
    return *this;
  }

  /**
   * @return the confidence in this hit
   */
  float Confidence() const { return fConfidence; }

  /**
   * @param confidence the new confidence for this hit
   */
  void Confidence(float confidence) { fConfidence = confidence; }


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

