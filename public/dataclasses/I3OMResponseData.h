/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3OMResponseData.h,v 1.11 2004/02/21 17:38:10 pretz Exp $

    @version $Revision: 1.11 $
    @date $Date: 2004/02/21 17:38:10 $
    @author

    @todo

*/
#ifndef I3OMRESPONSEDATA_H
#define I3OMRESPONSEDATA_H

#include "I3OMResponse.h"

class I3OMResponseDataHeader { };

typedef StoragePolicy<I3OMResponse> I3OMResponseDataStoragePolicy;


class I3OMResponseData : public AugVec<I3OMResponseDataHeader, 
			 I3OMResponse, 
			 I3OMResponseDataStoragePolicy>
{
  ClassDef(I3OMResponseData,1);
};


#endif
