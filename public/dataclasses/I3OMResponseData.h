/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3OMResponseData.h,v 1.7 2004/02/16 04:19:10 troy Exp $

    @version $Revision: 1.7 $
    @date $Date: 2004/02/16 04:19:10 $
    @author

    @todo

*/
#ifndef I3OMRESPONSEDATA_H
#define I3OMRESPONSEDATA_H

#include "I3OMResponse.h"

class I3OMResponseDataHeader { };

typedef TClonesPolicy<I3OMResponse> I3OMReponseDataStoragePolicy;

typedef GarnishedVector<I3OMResponseDataHeader, 
			I3OMResponse, 
			I3OMReponseDataStoragePolicy> I3OMResponseData;


#endif
