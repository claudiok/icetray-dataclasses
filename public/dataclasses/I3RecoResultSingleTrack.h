#ifndef I3RECORESULTSINGLETRACK_H
#define I3RECORESULTSINGLETRACK_H

#include "I3RecoResult.h"

class I3RecoResultSingleTrack : public I3RecoResult
{
  public:
  I3RecoResultSingleTrack();

  const I3RecoTrack& GetSingleRecoTrack(unsigned short tracklistindex) const;
  void               AddSingleRecoTrack(I3RecoTrack& recotrack_);
  
  ClassDef(I3RecoResultSingleTrack, 1);
};
#endif
