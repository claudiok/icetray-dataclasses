/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3RecoHit.h,v 1.5 2004/02/22 14:26:36 pretz Exp $

    @version $Revision: 1.5 $
    @date $Date: 2004/02/22 14:26:36 $
    @author

    @todo

*/
#ifndef I3RECOHIT_H
#define I3RECOHIT_H

#include <TObject.h>
#include "I3Hit.h"

class I3RecoHit : public I3Hit
{
  float fConfidence;

  public:
  I3RecoHit(){}

  float Confidence() const { return fConfidence; }
  void Confidence(float confidence_) { fConfidence = confidence_; }
  I3RecoHit(const I3RecoHit& rhs){*this = rhs;}
  const I3RecoHit& operator=(const I3RecoHit& rhs){
    if (this == &rhs) return *this; // check for assignment to self
    I3Hit::operator=(rhs); // call base class assignment operator
    fConfidence = rhs.fConfidence;
    return *this;
  }

  ClassDef(I3RecoHit, 1);
};
#endif

