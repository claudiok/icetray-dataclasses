#ifndef I3DATAREADOUTLIST_H
#define I3DATAREADOUTLIST_H

#include <TObject.h>
#include <TObjArray.h>

#include "I3Datareadout.h"
#include "I3Iterator.h"

class I3DatareadoutList : public TObject
{
  TObjArray  *datareadout;

  public:
  I3DatareadoutList();
  ~I3DatareadoutList();

  int GetNumberDatareadouts() const;
  const I3Datareadout& GetDatareadout(unsigned short number) const;
  void AddDatareadout(I3Datareadout* datareadout_);
  I3Iterator<const I3Datareadout>* MakeDatareadoutIterator() const ;

  ClassDef(I3DatareadoutList,1);
};
#endif

