/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3Digital.h,v 1.2 2004/02/15 19:12:14 troy Exp $

    @version $Revision: 1.2 $
    @date $Date: 2004/02/15 19:12:14 $
    @author

    @todo

*/
#ifndef I3DIGITAL_H
#define I3DIGITAL_H

#include <TObject.h>

class I3Digital : public TObject
{
  UChar_t fValue;

  public:
  I3Digital() { fValue = 0; }

  UChar_t Value() const { return fValue; }
  void Value(UChar_t value_) { fValue = value_; }

  ClassDef(I3Digital, 1);
};
#endif

