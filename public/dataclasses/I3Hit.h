/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3Hit.h,v 1.5 2004/02/21 19:30:19 troy Exp $

    @version $Revision: 1.5 $
    @date $Date: 2004/02/21 19:30:19 $
    @author

*/

#ifndef I3HIT_H
#define I3HIT_H

#include <TObject.h>

class I3Hit : public TObject
{
  ULong_t fTime;

  public:

  I3Hit() { fTime = 0; }
  I3Hit(const I3Hit& rhs) { *this = rhs; }
  const I3Hit& operator=(const I3Hit& rhs) {
    if (this == &rhs) return *this;
    fTime = rhs.fTime;
    return *this;
  }
      
  ULong_t Time() const { return fTime; }
  void Time(ULong_t time_) { fTime = time_; }

  ClassDef(I3Hit, 1);
};
#endif

