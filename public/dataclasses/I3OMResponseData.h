#ifndef I3OMRESPONSEDATA_H
#define I3OMRESPONSEDATA_H

#include <TObject.h>
#include <TObjArray.h>

#include "I3OMResponse.h"


class I3OMResponseData: public TObject
{
  TObjArray  *omresponse;
  
 public:
  I3OMResponseData();
  virtual ~I3OMResponseData();
  
  int GetNumberOMResponses() const;
  bool HasOMResponseNumber(unsigned short omnumber) const;
  const I3OMResponse& GetOMResponse(unsigned short index) const;
  const I3OMResponse& FindOMResponse(unsigned short omnumber) const;
  void AddOMResponse(I3OMResponse* omresponse_);
  
  ClassDef(I3OMResponseData, 1);
};
#endif
