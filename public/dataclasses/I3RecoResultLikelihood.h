/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3RecoResultLikelihood.h,v 1.2 2004/02/16 01:31:21 troy Exp $

    @version $Revision: 1.2 $
    @date $Date: 2004/02/16 01:31:21 $
    @author

    @todo

*/
#ifndef I3RECORESULTLIKELIHOOD_H
#define I3RECORESULTLIKELIHOOD_H

#include "I3RecoResultSingleTrack.h"

class I3RecoResultLikelihood : public I3RecoResultSingleTrack
{
  Float_t fLikelihood;

  public:
  I3RecoResultLikelihood() { fLikelihood = 0; }

  Float_t Likelihood() const { return fLikelihood; }
  void  Likelihood(Float_t likelihood_) { fLikelihood = likelihood_; }

  ClassDef(I3RecoResultLikelihood, 1);
};
#endif
