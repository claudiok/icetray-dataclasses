#ifndef I3RECORESULTLIKELIHOOD_H
#define I3RECORESULTLIKELIHOOD_H

#include "I3RecoResultSingleTrack.h"

class I3RecoResultLikelihood : public I3RecoResultSingleTrack
{
  float likelihood;

  public:
  I3RecoResultLikelihood();

  float GetLikelihood() const;
  void  SetLikelihood(float likelihood_);

  ClassDef(I3RecoResultLikelihood, 1);
};
#endif
