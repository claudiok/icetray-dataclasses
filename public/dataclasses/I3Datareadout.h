#ifndef I3DATAREADOUT_H
#define I3DATAREADOUT_H

#include <TObject.h>
#include <TObjArray.h>

class I3Datareadout : public TObject
{
  public:
  I3Datareadout();
  const char* GetReadoutType() const;

  ClassDef(I3Datareadout,1);
};
#endif

