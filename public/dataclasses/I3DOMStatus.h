#ifndef I3DOMSTATUS_H
#define I3DOMSTATUS_H

#include "dataclasses/I3RawDOMStatus.h"
#include "dataclasses/I3CalibratedDOMStatus.h"

class I3DOMStatus 
{
  I3RawDOMStatusPtr rawStatus_;
  I3CalibratedDOMStatusPtr calibratedStatus_;

 public:
  void SetRawStatus(I3RawDOMStatusPtr status)
    {
      rawStatus_ = status;
    }
  
  I3RawDOMStatusPtr GetRawStatus()
    {
      return rawStatus_;
    }

  void SetCalibratedStatus(I3CalibratedDOMStatusPtr status)
    {
      calibratedStatus_ = status;
    }

  I3CalibratedDOMStatusPtr GetCalibratedStatus()
    {
      return calibratedStatus_;
    }
};

#endif