/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3RecoResult.h,v 1.9 2004/02/16 00:55:12 troy Exp $

    @version $Revision: 1.9 $
    @date $Date: 2004/02/16 00:55:12 $
    @author

    @todo get/set best stuff

*/
#ifndef I3RECORESULT_H
#define I3RECORESULT_H

#include "I3RecoTrackList.h"
#include "TClonesPolicy.h"
#include "GarnishedVector.h"

class I3RecoResultHeader 
{
  TRef          best;

  public:
  I3RecoResultHeader();
  virtual ~I3RecoResultHeader();

  const char* GetRecomethod() const;

  bool HasBest() const;
  const I3RecoTrackList& BestRecoTrackList() const;
  void BestRecoTrackList(I3RecoTrackList& bestrecotracklist_);

};

typedef TClonesPolicy<I3RecoTrackList> I3RecoResultStoragePolicy;
typedef GarnishedVector<I3RecoResultHeader, I3RecoTrackList, I3RecoResultStoragePolicy> I3RecoResult;


#endif
