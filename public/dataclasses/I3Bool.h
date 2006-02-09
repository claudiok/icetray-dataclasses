#ifndef I3BOOL_H
#define I3BOOL_H

#include <TObject.h>

// This works for me, but others may want to design it better.
// Feel free to change it. (pretz)
class I3Bool : public TObject
{
 public:
  operator bool()
    {
      return value_;
    }
  
  I3Bool(bool value) : value_(value){}

  I3Bool() : value_(false){}

  template <typename Archive>
    void serialize(Archive&,unsigned);
 private:
  bool value_;
};

#endif
