/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3RecoResultData.h,v 1.8 2004/02/16 16:13:28 troy Exp $

    @version $Revision: 1.8 $
    @date $Date: 2004/02/16 16:13:28 $
    @author

    @todo fix 

*/
#ifndef I3RECORESULTDATA_H
#define I3RECORESULTDATA_H

// tds:  need to fix this
#if 0

#include "I3RecoResult.h"
#include "TClonesPolicy.h"
#include "GarnishedVector.h"



class I3RecoResultDataHeader { };

typedef TClonesPolicy<I3RecoResult> I3RecoResultDataStoragePolicy;

typedef GarnishedVector<I3RecoResultDataHeader, 
			I3RecoResult, 
			I3RecoResultDataStoragePolicy> I3RecoResultData;

#endif
#endif
