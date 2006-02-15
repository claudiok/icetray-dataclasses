#ifndef I3DOUBLE_H
#define I3DOUBLE_H

#include <TObject.h>
#include <dataclasses/Utility.h>

// Basically stole pretz form of I3Bool and made a double out of it

class I3Double : public TObject
{
 public:
  operator double() const
    {
      return value_;
    }
  
  I3Double(double value) : value_(value){}

  I3Double() : value_(0.0){}

  template <typename Archive>
    void serialize(Archive&,unsigned);
 private:
  double value_;
};

I3_POINTER_TYPEDEFS(I3Double);

#endif
