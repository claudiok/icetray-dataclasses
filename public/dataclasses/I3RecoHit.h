/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3RecoHit.h,v 1.4 2004/02/19 03:02:47 pretz Exp $

    @version $Revision: 1.4 $
    @date $Date: 2004/02/19 03:02:47 $
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

  ClassDef(I3RecoHit, 1);
};
#endif

