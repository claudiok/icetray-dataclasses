/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3Hit.h,v 1.4 2004/02/15 02:20:26 troy Exp $

    @version $Revision: 1.4 $
    @date $Date: 2004/02/15 02:20:26 $
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

  ULong_t Time() const { return fTime; }
  void Time(ULong_t time_) { fTime = time_; }

  ClassDef(I3Hit, 1);
};
#endif

