#ifndef I3DOMSTATUS_H_INCLUDED
#define I3DOMSTATUS_H_INCLUDED

#include "dataclasses/status/I3RawDOMStatus.h"
#include "dataclasses/status/I3CalibratedDOMStatus.h"

class I3DOMStatus : public TObject
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

I3_POINTER_TYPEDEFS(I3DOMStatus);

#endif //I3DOMSTATUS_H_INCLUDED

