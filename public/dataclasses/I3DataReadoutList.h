#ifndef I3DATAREADOUTLIST_H
#define I3DATAREADOUTLIST_H

#include <TObject.h>
#include <TObjArray.h>

#include "I3DataReadout.h"
#include "I3Iterator.h"

class I3DataReadoutList : public TObject
{
  TObjArray  *datareadout;

  public:
  I3DataReadoutList();
  ~I3DataReadoutList();

  int GetNumberDataReadouts() const;
  const I3DataReadout& GetDataReadout(unsigned short number) const;
  void AddDataReadout(I3DataReadout* datareadout_);
  I3Iterator<const I3DataReadout>* MakeDataReadoutIterator() const ;

  ClassDef(I3DataReadoutList,1);
};
#endif

