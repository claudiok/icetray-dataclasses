#ifndef I3ORDER_H
#define I3ORDER_H

#include <string.h>
#include <TObject.h>

class I3Order : public TObject
{
  int  index;
  char eventtype[50];

  public:
  I3Order();
  int         GetIndex();
  const char* GetEventtype();
  void        SetIndex(int i);
  void        SetEventtype(const char* c);

  ClassDef(I3Order,1);
};
#endif
