/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3OMResponseData.h,v 1.10 2004/02/20 21:42:08 troy Exp $

    @version $Revision: 1.10 $
    @date $Date: 2004/02/20 21:42:08 $
    @author

    @todo

*/
#ifndef I3OMRESPONSEDATA_H
#define I3OMRESPONSEDATA_H

#include "I3OMResponse.h"

class I3OMResponseDataHeader { };

typedef StoragePolicy<I3OMResponse> I3OMResponseDataStoragePolicy;

typedef AugVec<I3OMResponseDataHeader, 
			I3OMResponse, 
			I3OMResponseDataStoragePolicy> I3OMResponseData;


#endif
