/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3RecoResultData.h,v 1.13 2004/02/23 22:36:49 troy Exp $

    @version $Revision: 1.13 $
    @date $Date: 2004/02/23 22:36:49 $
    @author

    @todo

*/

#ifndef I3RECORESULTDATA_H
#define I3RECORESULTDATA_H

#include "I3RecoResult.h"
#include "StoragePolicy.h"


class I3RecoResultData : public TObject, public MapPolicy<I3RecoResultPtr>::ThePolicy
{



 public:

  virtual ~I3RecoResultData(){;}
  ClassDef(I3RecoResultData,1);

};

#endif
