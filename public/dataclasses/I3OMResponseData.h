/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3OMResponseData.h,v 1.13 2004/02/23 17:14:19 pretz Exp $

    @version $Revision: 1.13 $
    @date $Date: 2004/02/23 17:14:19 $
    @author

    @todo

*/
#ifndef I3OMRESPONSEDATA_H
#define I3OMRESPONSEDATA_H

#include "I3OMResponse.h"
#include "StoragePolicy.h"

class I3OMResponseData : public TObject, public VectorPolicy<I3OMResponse>::ThePolicy
{
 public:
  virtual ~I3OMResponseData(){};
  ClassDef(I3OMResponseData,1);
};

#endif
