/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Digital.h,v 1.3 2004/02/25 19:14:26 pretz Exp $
 *
 * A single digital value of fraom a sequence of digital values.
 *
 * @version $Revision: 1.3 $
 * @date $Date: 2004/02/25 19:14:26 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 * @todo
 *
 */
#ifndef I3DIGITAL_H
#define I3DIGITAL_H

#include <TObject.h>

class I3Digital : public TObject
{
  UChar_t fValue;

  public:
  /**
   * default constructor
   */
  I3Digital() { fValue = 0; }

  /**
   * default destructor
   */
  virtual ~I3Digital(){}

  /**
   * copy constructor just uses assignment operator
   */
  I3Digital(const I3Digital& rhs){*this = rhs;}

  /**
   * assignment operator.  Just member-wise assignment.
   */
  const I3Digital& operator=(const I3Digital& rhs){
    if(this == &rhs) return *this;
    TObject::operator=(rhs);
    fValue = rhs.fValue;
    return *this;
  }

  /**
   * @return the value of this signal
   */
  UChar_t Value() const { return fValue; }

  /**
   * @param value the new signal value
   */
  void Value(UChar_t value) { fValue = value; }

 private:
  // ROOT macro
  ClassDef(I3Digital, 1);
};

typedef I3Digital* I3DigitalPtr;

#endif

