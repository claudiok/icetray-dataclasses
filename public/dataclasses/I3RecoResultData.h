/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3RecoResultData.h,v 1.7 2004/02/16 04:19:10 troy Exp $

    @version $Revision: 1.7 $
    @date $Date: 2004/02/16 04:19:10 $
    @author

    @todo

*/
#ifndef I3RECORESULTDATA_H
#define I3RECORESULTDATA_H


#include "I3RecoResult.h"
#include "TClonesPolicy.h"
#include "GarnishedVector.h"



class I3RecoResultDataHeader { };

typedef TClonesPolicy<I3RecoResult> I3RecoResultDataStoragePolicy;

typedef GarnishedVector<I3RecoResultDataHeader, 
			I3RecoResult, 
			I3RecoResultDataStoragePolicy> I3RecoResultData;

#endif

