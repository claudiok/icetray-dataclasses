#ifndef I3RECORESULTDATA_H
#define I3RECORESULTDATA_H

#include <TObject.h>
#include <TObjArray.h>

#include "I3RecoResult.h"


class I3RecoResultData : public TObject
{
  TObjArray    *recoresult;

  public:
           I3RecoResultData();
  virtual ~I3RecoResultData();

  int                 GetNumberRecoResults() const;
  const I3RecoResult& GetRecoResult(unsigned short number) const;
  void                AddRecoResult(I3RecoResult& recoresult_);

  ClassDef(I3RecoResultData, 1);
};
#endif
