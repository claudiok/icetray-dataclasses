/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3RecoResult.h,v 1.15 2004/02/23 22:36:49 troy Exp $

    @version $Revision: 1.15 $
    @date $Date: 2004/02/23 22:36:49 $
    @author

    @todo get/set best stuff

*/
#ifndef I3RECORESULT_H
#define I3RECORESULT_H

#include "I3RecoTrackList.h"

#include "StoragePolicy.h"

class I3RecoResult : public VectorPolicy<I3RecoTrackList>::ThePolicy
{

 public:
  I3RecoResult(){}
  virtual ~I3RecoResult() {}

  ClassDef(I3RecoResult, 1);
};

typedef PtrPolicy<I3RecoResult> I3RecoResultPtr;

#endif
