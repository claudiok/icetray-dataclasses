#ifndef I3DIGITAL_H
#define I3DIGITAL_H

#include <TObject.h>

class I3Digital : public TObject
{
  unsigned char value;

  public:
  I3Digital();

  unsigned char GetValue() const;
  void SetValue(unsigned char value_);

  ClassDef(I3Digital, 1);
};
#endif

