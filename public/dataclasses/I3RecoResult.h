/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3RecoResult.h,v 1.14 2004/02/23 16:31:25 pretz Exp $

    @version $Revision: 1.14 $
    @date $Date: 2004/02/23 16:31:25 $
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

typedef I3RecoResult* I3RecoResultPtr;

#endif
