/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3RecoTrackList.h,v 1.9 2004/02/21 17:38:10 pretz Exp $

    @version $Revision: 1.9 $
    @date $Date: 2004/02/21 17:38:10 $
    @author

    @todo

*/
#ifndef I3RECOTRACKLIST_H
#define I3RECOTRACKLIST_H

#include "I3RecoTrack.h"
#include "StoragePolicy.h"
#include "AugVec.h"

class I3RecoTrackListHeader { };

typedef StoragePolicy<I3RecoTrack> I3RecoTrackListStoragePolicy;
class I3RecoTrackList : public AugVec<I3RecoTrackListHeader, 
			I3RecoTrack, 
			I3RecoTrackListStoragePolicy> 
{
  ClassDef(I3RecoTrackList,1);
};



#endif
