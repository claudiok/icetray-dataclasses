#ifndef I3RECORESULTTENSOR_H
#define I3RECORESULTTENSOR_H

#include "I3RecoResultSingleTrack.h"

class I3RecoResultTensor : public I3RecoResultSingleTrack
{
  Int_t   number;
  Float_t *moment; //[number]

  public:
   I3RecoResultTensor();
  ~I3RecoResultTensor();

  Int_t          GetNumber() const;
  const Float_t* GetMoment() const;
  void           SetMoment(Float_t* moment_, Int_t number_);

  ClassDef(I3RecoResultTensor, 1);
};
#endif
