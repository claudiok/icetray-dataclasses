#ifndef I3RECOTRACKLIST_H
#define I3RECOTRACKLIST_H

#include <TObject.h>
#include <TObjArray.h>
#include "I3RecoTrack.h"

class I3RecoTrackList : public TObject
{
  TObjArray  *recotrack;

  public:
           I3RecoTrackList();
  virtual ~I3RecoTrackList();

  int                GetNumberRecoTracks() const;
  const I3RecoTrack& GetRecoTrack(unsigned short index) const;
  void               AddRecoTrack(I3RecoTrack& recotrack_);

  ClassDef(I3RecoTrackList, 1);
};
#endif
