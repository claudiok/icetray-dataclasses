#ifndef I3DOMSTATUS_H
#define I3DOMSTATUS_H

#include "dataclasses/physics/I3RawDOMStatus.h"
#include "dataclasses/physics/I3CalibratedDOMStatus.h"

class I3DOMStatus 
{
  I3RawDOMStatusPtr rawStatus_;
  I3CalibratedDOMStatusPtr calibratedStatus_;

 public:
  virtual ~I3DOMStatus();

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

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
};

typedef shared_ptr<I3DOMStatus> I3DOMStatusPtr;

#endif

