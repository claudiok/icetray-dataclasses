/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3OMResponseData.h,v 1.9 2004/02/18 21:39:46 troy Exp $

    @version $Revision: 1.9 $
    @date $Date: 2004/02/18 21:39:46 $
    @author

    @todo

*/
#ifndef I3OMRESPONSEDATA_H
#define I3OMRESPONSEDATA_H

#include "I3OMResponse.h"

class I3OMResponseDataHeader { };

typedef StoragePolicy<I3OMResponse> I3OMResponseDataStoragePolicy;

typedef GarnishedVector<I3OMResponseDataHeader, 
			I3OMResponse, 
			I3OMResponseDataStoragePolicy> I3OMResponseData;


#endif
