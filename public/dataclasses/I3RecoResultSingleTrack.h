/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3RecoResultSingleTrack.h,v 1.4 2004/02/16 01:26:14 troy Exp $

    @version $Revision: 1.4 $
    @date $Date: 2004/02/16 01:26:14 $
    @author

    @todo

*/
#ifndef I3RECORESULTSINGLETRACK_H
#define I3RECORESULTSINGLETRACK_H

#include "I3RecoResult.h"

class I3RecoResultSingleTrack : public I3RecoResult
{
  public:
  I3RecoResultSingleTrack() {;}

  const I3RecoTrack& operator[](unsigned short tracklistindex) const;
  
  ClassDef(I3RecoResultSingleTrack, 1);
};
#endif
