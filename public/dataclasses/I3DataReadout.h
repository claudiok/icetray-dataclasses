#ifndef I3DATAREADOUT_H
#define I3DATAREADOUT_H

#include <TObject.h>
#include <TObjArray.h>

class I3DataReadout : public TObject
{
  public:
  I3DataReadout(){};
  const char* GetReadoutType() const;

  ClassDef(I3DataReadout,1);
};
#endif

