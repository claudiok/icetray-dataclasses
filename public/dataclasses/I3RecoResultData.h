/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3RecoResultData.h,v 1.10 2004/02/23 02:13:50 troy Exp $

    @version $Revision: 1.10 $
    @date $Date: 2004/02/23 02:13:50 $
    @author

    @todo

*/

#ifndef I3RECORESULTDATA_H
#define I3RECORESULTDATA_H

#include "I3RecoResult.h"
#include "StoragePolicy.h"


class I3RecoResultData : public MapPolicy<I3RecoResult>::ThePolicy
{

 public:

  virtual ~I3RecoResultData();
  ClassDef(I3RecoResultData,1);

};

#endif
