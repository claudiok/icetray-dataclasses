/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3RecoHit.h,v 1.3 2004/02/18 21:39:46 troy Exp $

    @version $Revision: 1.3 $
    @date $Date: 2004/02/18 21:39:46 $
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
  I3RecoHit();

  float Confidence() const { return fConfidence; }
  void Confidence(float confidence_) { fConfidence = confidence_; }

  ClassDef(I3RecoHit, 1);
};
#endif

